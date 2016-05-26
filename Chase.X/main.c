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
#define out 0xFF

#define led LATDbits.LATD0
#define push PORTBbits.RB0


void setup(){
    TRISA=out;
    // As the LED1 pin is also an analog input pin we have to declare it as
    // digital by writing the port configuration control bits(PCFG<3:0>) in
    // ADCON1 Register - Refer to the datasheet for more details
    ADCON1 = 0x00001111;
    // Set PORTD bit 0 as digital output, LED1 is connected on this pin
    TRISAbits = 0; // out ??
    TRISBbits.TRISB0 = 1; // Set the Button Pin as input
}
void leds(unsigned char port){
    port=~port;
    LATA=port
    __delay_ms(50);
    return;
}
void program(){
    unsigned char Leds=0x01;
    while(1){
        if (push == 0){
            while(push == 0){
                   leds(Leds);
            }
        }
        else {
        leds(Leds);
        Leds=Leds >> 1;
        }
    }
    return;
}

int main(int argc, char** argv) {
    setup();
    while(1){
        program();
    }
    return (EXIT_SUCCESS);
}


