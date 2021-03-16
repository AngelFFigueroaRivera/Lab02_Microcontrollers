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
void larsondisplay(void)

//+++++++++++++++++++++++++++++Main Function+++++++++++++++++++++++++++++++++++
void main( void ) {
	// CONFIGURATIONS**********************************************************
	portsInit();                          // calls the function of ports configuration.
    while( 1 ) {                          //loop that helps to repeat infinite the actions
        srand(time(NULL));
		int randomNumber = rand() % 7;
        int mytime;
        switch (randomNumber) {
            case 0:
                mytime = clock();
                while(clock() < mytime + 500) {
                    TRISAbits.TRISA0 = led_ON;
                    if (PORTDbits.RD0 == pushed) {
                        TRISAbits.TRISA0 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }            
                break;
            case 1:
                mytime = clock();
                while(clock() < mytime + 500) {
                    TRISAbits.TRISA1 = led_ON;
                    if (PORTDbits.RD01 == pushed) {
                        TRISAbits.TRISA1 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 2:
                mytime = clock();
                while(clock() < mytime + 500) {
                    TRISAbits.TRISA2 = led_ON;
                    if (PORTDbits.RD2 == pushed) {
                        TRISAbits.TRISA2 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 3:
                mytime = clock();
                while(clock() < mytime + 500) {
                    TRISAbits.TRISA3 = led_ON;
                    if (PORTDbits.RD3 == pushed) {
                        TRISAbits.TRISA3 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 4:
                mytime = clock();
                while(clock() < mytime + 500) {
                    TRISAbits.TRISA4 = led_ON;
                    if (PORTDbits.RD4 == pushed) {
                        TRISAbits.TRISA4 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 5:
                mytime = clock();
                while(clock() < mytime + 500) {
                    TRISAbits.TRISA5 = led_ON;
                    if (PORTDbits.RD5 == pushed) {
                        TRISAbits.TRISA5 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 6:
                mytime = clock();
                while(clock() < mytime + 500) {
                    TRISAbits.TRISA6 = led_ON;
                    if (PORTDbits.RD6 == pushed) {
                        TRISAbits.TRISA6 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            case 7:
                mytime = clock();
                while(clock() < mytime + 500) {
                    TRISAbits.TRISA7 = led_ON;
                    if (PORTDbits.RD7 == pushed) {
                        TRISAbits.TRISA7 = led_OFF;
                        larsondisplay();
                        break;
                    }
                }
                break;
            default:
                break;
        }
        TRISAbits.TRISA0 = led_OFF;
        TRISAbits.TRISA1 = led_OFF;
        TRISAbits.TRISA2 = led_OFF;
        TRISAbits.TRISA3 = led_OFF;
        TRISAbits.TRISA4 = led_OFF;
        TRISAbits.TRISA5 = led_OFF;
        TRISAbits.TRISA6 = led_OFF;
        TRISAbits.TRISA7 = led_OFF;
        int mytime2 = clock(); 
        while(clock() < mytime2 + 1000) {
        }
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
                TRISAbits.TRISA0 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA0 = led_OFF;
                break;
            case 1:
                TRISAbits.TRISA1 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA1 = led_OFF;
                break;
            case 2:
                TRISAbits.TRISA2 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA2 = led_OFF;
                break;
            case 3:
                TRISAbits.TRISA3 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA3 = led_OFF;
                break;
            case 4:
                TRISAbits.TRISA4 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA4 = led_OFF;
                break;
            case 5:
                TRISAbits.TRISA5 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA5 = led_OFF;
                break;
            case 6:
                TRISAbits.TRISA6 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA6 = led_OFF;
                break;
            case 7:
                TRISAbits.TRISA7 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA7 = led_OFF;
                break;
        }
        int larsontime = clock(); 
        while(clock() < larsontime + 300) {
        }
    }
    for (int i = 7; i>=0; --i) {
        switch (i) {
            case 0:
                TRISAbits.TRISA0 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA0 = led_OFF;
                break;
            case 1:
                TRISAbits.TRISA1 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA1 = led_OFF;
                break;
            case 2:
                TRISAbits.TRISA2 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA2 = led_OFF;
                break;
            case 3:
                TRISAbits.TRISA3 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA3 = led_OFF;
                break;
            case 4:
                TRISAbits.TRISA4 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA4 = led_OFF;
                break;
            case 5:
                TRISAbits.TRISA5 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA5 = led_OFF;
                break;
            case 6:
                TRISAbits.TRISA6 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA6 = led_OFF;
                break;
            case 7:
                TRISAbits.TRISA7 = led_ON;
                __delay_ms( ThreeMS_SECOND );
                TRISAbits.TRISA7 = led_OFF;
                break;
        }
        int larsonTimeBack = clock(); 
        while(clock() < larsonTimeBack + 300) {
        }
    }
}