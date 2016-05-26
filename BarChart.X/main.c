/* 
 * File:   main.c
 * Author: m1bs1h
 *
 * Created on 30 janvier 2014, 14:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f46k22.h>
#include "config.h"
#include "main.h"
#include "math.h"

#define out 0x00
#define in 0xFF

void setup(){
    TRISA=out;
    TRISE=out;
}
void leds(unsigned char port){
    LATA=~port;
    if(~port & 0x40){
        LATE=LATE | 0x01;
    }
    else LATE=LATE & ~0x01;
    if(~port & 0x80){
        LATE=LATE | 0x02;
    } else LATE=LATE & ~0x02;
}
void program(){
    unsigned char imLed=0x00;
    int i=0, j=0;

        for(i=0;i<9;i++){
            leds(imLed);
            imLed=imLed+((unsigned char)pow((double)2,(double)i));
            __delay_ms(100);

                if (imLed==0xFF){
                    for (j=9;j>-1;j--){
                    imLed=imLed-((unsigned char)pow((double)2,(double)((j-1))));
                    leds(imLed);
                    __delay_ms(100);
                    }
                }
        }
}

int main(int argc, char** argv) {
    setup();
    while(1){
        program();
    }
    return (EXIT_SUCCESS);
}


