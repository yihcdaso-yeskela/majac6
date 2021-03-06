#ifndef HARDWARE_H
#define	HARDWARE_H
/*settings*/

/*build target*/
#define pic12f675_xc8
/*select build target*/
#ifdef pic12f675_xc8
/*xc8 do not use attributes*/
#define __attribute__(a)

#include <pic12f675.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#define BUILD_VERSION 0x00000001

#define __FREQ       4000000
#define __CFREQ      (__FREQ/4)

#ifdef CORE_H
/*pic12f675 conf*/
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = ON       // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON       // Power-Up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)   
#endif

#else
#error build target must be selected
#endif

typedef enum{
    SUCCESS = 0,
    BUSY,
    DONE,
    ERROR = 0x80,   //after this value error codes
}result_t;


#endif	/* HARDWARE_H */
