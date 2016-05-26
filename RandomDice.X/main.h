/* 
 * File:   main.h
 * Author: m1bs1h
 *
 * Created on 30 janvier 2014, 14:39
 */

#ifndef MAIN_H
#define	MAIN_H

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <pic18f46k22.h>
#include "config.h"

#define out 0x00
#define in 0xFF
#define AVECIT                      // mode Interrupt sur RB0 ou Pooling bloquant
#define push INTCONbits.INT0IF

unsigned char chenillard(unsigned char);
unsigned char init(void);
int main(void);
void program(unsigned char);
void stop(void);
void setup(void);
void leds(unsigned char);


#endif	/* MAIN_H */

