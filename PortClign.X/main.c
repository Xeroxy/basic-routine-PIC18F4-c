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

#define out 0x00
#define in 0xFF

void setup(){
    TRISA=out;
    TRISE=out;
}
void delay(){
    int time =0;
    do{
        time++;
    }while(time<8000);
}
void leds(unsigned char port){
    LATA=port;
    if(port & 0x40){
        LATE=LATE | 0x01;
    }
    else LATE=LATE & ~0x01;
    if(port & 0x80){
        LATE=LATE | 0x02;
    } else LATE=LATE & ~0x02;
}
void program(){
    leds(0x0F);
    __delay_ms(190);
    leds(0x00);
    __delay_ms(190);
}
int main(int argc, char** argv) {
    setup();
    while(1){
        program();
    }
    return (EXIT_SUCCESS);
}

