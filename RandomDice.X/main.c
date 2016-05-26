/* 
 * File:   main.c
 * Author: m1bs1h
 *
 * Created on 30 janvier 2014, 14:20
 */

#include "main.h"

void setup(){
    TRISA=out;
    TRISB=in;
    ANSELBbits.ANSB0=0;
    INTCON2bits.INTEDG0=1;          // interrupt is rising edge
    INTCONbits.INT0IF=0;            //
    INTCONbits.GIE=1;               // enable global interrupts   
}
void leds(unsigned char port){
    port=~port;
    LATA=port;
    __delay_ms(25);
}
void stop(){                        //Fonction pour arrêter le défilement des leds en cas d'appui sur le bouton
    INTCONbits.INT0IF=0;            //Initialisation du bit à 0
    while(push!=1){                 //Tant que le bit est différent de 1 on reste dans la boucle while
        __delay_ms(1);
    }
}
unsigned char init(){               //Fonction d'initialisation du programme
      unsigned char stopled;        //Premier cycle: Start, Stop, Repries
      INTCONbits.INT0IF=0;          //Initialisation du bit à 0
      stopled=chenillard(0x01);     //stopled prend la valeur de chenillard(0x01)
      stop();                       //Appel de la fonction stop en cas d'appui sur le bouton(changement de valeur de INT0IF
    return stopled;                 //Retourne la valeur stopled
}
unsigned char chenillard(unsigned char Leds){
    unsigned char tmp;              //Initialisation d'une variable tmp
    INTCONbits.INT0IF=0;            //Initialisation du bit à 0
        while(push == 0 ){          //Tant que le bouton n'est pas pressé, les leds chenillent
            leds(Leds);
            Leds=Leds << 1;
            if (Leds==0x40){
                Leds=0x01;
            }
            tmp=Leds;
        }
    return tmp;
}
void program(unsigned char firststop){
      unsigned char stopled1;       //Initialisation d'une variable stopled1
      INTCONbits.INT0IF=0;          //Initialisation du bit à 0
      stopled1 = chenillard(firststop); //stopled1 prend la valeur du chenillard au premier arrêt
      stop();                           //appel de la fonction stop
      chenillard(stopled1);             //Reprise du chenillard à la diode ou l'on s'était arrêté (stopled1)
      stop();                           //Appel de la fonction stop
}
int main() {
    unsigned char firststop;        //Initialisation d'une variable firstop
    setup();                        //Initialisation de port via la fonction setup
    firststop = init();             //Initialisation de la première valeur dans firstop
    while(1){
        program(firststop);         
    }
    return (EXIT_SUCCESS);
}


