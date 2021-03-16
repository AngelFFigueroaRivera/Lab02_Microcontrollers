/*
 * File:   main.c
 * Author: Andrés González Olea A01039725; Angel Francisco Figueroa A00820475; Dalia Lizeth Hurtado A01281887; Ricardo Plata Galaviz A00821598
 *
 * Created on March 2, 2021, 8:03 PM
 */

//++++++++++++++++++++++++LIBRARIEs/HEADEAs SECTION++++++++++++++++++++++++++++ 
#include "device_config.h"               // calls a header file where the default configuration is set
#include <math.h>
#include <stdio.h> 
#include <time.h>

//++++++++++++++++++++++++++++DIRECTIVEs SECTION+++++++++++++++++++++++++++++++
#define _XTAL_FREQ 1000000               // sets de delay function
#define ONE_SECOND 1000                  // sets de variable one_second the numeric val 
#define TWOMS_SECOND 250
#define ThreeMS_SECOND 300
#define FiveMS_SECOND 500


//names to integral constants, the names make a program easy to read and 
//maintain. 

enum por_dir{ output, input };           // output = 0, input = 1 
enum por_ACDC{ digital, analog };        // digital = 0, analog = 1
enum resistor_state{ set_ON, res_ON };   // set_ON = 0, res_ON = 1
enum led_state{ led_OFF, led_ON };       // led_OFF = 0, led_ON = 1
enum butto_state{ pushed, no_pushed };   // pushed = 0, no_pushed = 1
enum exponent{bbase = 2, limit = 8 };

//+++++++++++++++++ISRs SECTION++++++++++++++++++++++++++++++++++ 
void __interrupt ( high_priority ) high_isr( void );  //ISR for high-priority 

void __interrupt ( low_priority ) low_isr( void );    //ISR for low-priority

//++++++++++++++++++++++++FUNCTIONs DECLARATION++++++++++++++++++++++++++++++++ 
void portsInit( void );                   // Ports configuration function.
void larsondisplay(void);
// __delay_ms
//+++++++++++++++++++++++++++++Main Function+++++++++++++++++++++++++++++++++++
void main( void ) {
	// CONFIGURATIONS**********************************************************
	portsInit();                          // calls the function of ports configuration.
    while( 1 ) {                          //loop that helps to repeat infinite the actions
        int randomNumber = rand() % 7;
        int mytime = 20000;
        switch (randomNumber) {
            case 0:
                LATAbits.LATA0 = led_ON;
                for (int i = 0; i < mytime; ++i) {    
                    if (PORTDbits.RD0 == pushed) {
                        LATAbits.LATA0 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }         
                break;
            case 1:
                LATAbits.LATA1 = led_ON;
                for (int i = 0; i < mytime; ++i) {    
                    if (PORTDbits.RD1 == pushed) {
                        LATAbits.LATA1 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 2:
                LATAbits.LATA2 = led_ON;
                for (int i = 0; i < mytime; ++i) {
                    if (PORTDbits.RD2 == pushed) {
                        LATAbits.LATA2 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 3:
                LATAbits.LATA3 = led_ON;
                for (int i = 0; i < mytime; ++i) {    
                    if (PORTDbits.RD3 == pushed) {
                        LATAbits.LATA3 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 4:
                LATAbits.LATA4 = led_ON;
                for (int i = 0; i < mytime; ++i) {
                    if (PORTDbits.RD4 == pushed) {
                        LATAbits.LATA4 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 5:
                LATAbits.LATA5 = led_ON;
                for (int i = 0; i < mytime; ++i) {    
                    if (PORTDbits.RD5 == pushed) {
                        LATAbits.LATA5 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 6:
                LATAbits.LATA6 = led_ON;
                for (int i = 0; i < mytime; ++i) {
                    if (PORTDbits.RD6 == pushed) {
                        LATAbits.LATA6 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 7:
                LATAbits.LATA7 = led_ON;
                for (int i = 0; i < mytime; ++i) {
                    if (PORTDbits.RD7 == pushed) {
                        LATAbits.LATA7 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            default:
                break;
        }
        LATAbits.LATA0 = led_OFF;
        LATAbits.LATA1 = led_OFF;
        LATAbits.LATA2 = led_OFF;
        LATAbits.LATA3 = led_OFF;
        LATAbits.LATA4 = led_OFF;
        LATAbits.LATA5 = led_OFF;
        LATAbits.LATA6 = led_OFF;
        LATAbits.LATA7 = led_OFF;
        __delay_ms( 1000 );
	}
}

//++++++++++++++++++++++++FUNCTIONs SECTION++++++++++++++++++++++++++++++++ 
void portsInit( void ) {				  // Functions that starts with no parameters and no returns
	ANSELA = digital;                     // Sets PortA as digital
	TRISAbits.TRISA0 = output;            // Sets RA0 as an output
	TRISAbits.TRISA1 = output;            // Sets RA1 as an output
    TRISAbits.TRISA2 = output;            // Sets RA2 as an output
	TRISAbits.TRISA3 = output;            // Sets RA3 as an output
    TRISAbits.TRISA4 = output;            // Sets RA4 as an output
	TRISAbits.TRISA5 = output;            // Sets RA5 as an output
    TRISAbits.TRISA6 = output;            // Sets RA6 as an output
	TRISAbits.TRISA7 = output;            // Sets RA7 as an output

	ANSELD = digital;                     // Sets PortB as digital
	TRISDbits.TRISD0 = input;			  // Sets RD0 as an input
    TRISDbits.TRISD1 = input;			  // Sets RD1 as an input
    TRISDbits.TRISD2 = input;			  // Sets RD2 as an input
    TRISDbits.TRISD3 = input;			  // Sets RD3 as an input
    TRISDbits.TRISD4 = input;			  // Sets RD4 as an input
    TRISDbits.TRISD5 = input;			  // Sets RD5 as an input
    TRISDbits.TRISD6 = input;			  // Sets RD6 as an input
    TRISDbits.TRISD7 = input;			  // Sets RD7 as an input

}

void larsondisplay(void) {
    for (int i = 0; i < 8; ++i) {
        switch (i) {
            case 0:
                LATAbits.LATA0 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA0 = led_OFF;
                break;
            case 1:
                LATAbits.LATA1 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA1 = led_OFF;
                break;
            case 2:
                LATAbits.LATA2 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA2 = led_OFF;
                break;
            case 3:
                LATAbits.LATA3 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA3 = led_OFF;
                break;
            case 4:
                LATAbits.LATA4 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA4 = led_OFF;
                break;
            case 5:
                LATAbits.LATA5 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA5 = led_OFF;
                break;
            case 6:
                LATAbits.LATA6 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA6 = led_OFF;
                break;
            case 7:
                LATAbits.LATA7 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA7 = led_OFF;
                break;
        }
        __delay_ms( ThreeMS_SECOND );
    }
    for (int i = 7; i>=0; --i) {
        switch (i) {
            case 0:
                LATAbits.LATA0 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA0 = led_OFF;
                break;
            case 1:
                LATAbits.LATA1 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA1 = led_OFF;
                break;
            case 2:
                LATAbits.LATA2 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA2 = led_OFF;
                break;
            case 3:
                LATAbits.LATA3 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA3 = led_OFF;
                break;
            case 4:
                LATAbits.LATA4 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA4 = led_OFF;
                break;
            case 5:
                LATAbits.LATA5 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA5 = led_OFF;
                break;
            case 6:
                LATAbits.LATA6 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA6 = led_OFF;
                break;
            case 7:
                LATAbits.LATA7 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                LATAbits.LATA7 = led_OFF;
                break;
        }
        __delay_ms( ThreeMS_SECOND );
    }
}