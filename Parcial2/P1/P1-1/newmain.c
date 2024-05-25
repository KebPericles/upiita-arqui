/*
 * Descripci?n: Practica 1. Configurar el puerto A 
 */
 
 //Definiciones
#define _XTAL_FREQ 4000000

//Archuivos cabecera
#include <xc.h>

// Palabra de configuraci?n 1: CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT	// Selector de oscilador
#pragma config WDTE = OFF       // Deshabilita WDT
#pragma config PWRTE = OFF      // Desabilita PWRT
#pragma config MCLRE = ON       // Pin RE3/MCLR funciona como MCLR
#pragma config CP = OFF         // Protecci?n por c?digo deshabilitado
#pragma config CPD = OFF        // Dato de Protecci?n por c?digo deshabilitado 
#pragma config BOREN = OFF      // Reset por Brown-Out deshabilitado
#pragma config IESO = ON        // Inversi?n entre Reloj Interno/Externo habilitado
#pragma config FCMEN = ON       // Monitoreo de reloj seguro habilitado
#pragma config LVP = OFF         // Bajo voltaje de programaci?n en RB3/PGM deshabilitado

// Palabra de configuraci?n 2: CONFIG2
#pragma config BOR4V = BOR40V   // Selector de voltaje de Brown-Out Reset
#pragma config WRT = OFF        // Escritura segura en Flash deshabilitado
//END CONFIG

//Funci?n main
void main(void) {
    //Configuraci?n de recursos (perif?ricos)
       //Configuar PORTA como salida 
        ANSEL = 0b00000000; //Habilar los pines en modo digital 
        //ANSEL = 0x00;
        //ANSEL = 0;
        TRISA = 0b11110000; //Configura PORTA como salida .
        
    //Aplicaci?n
        PORTA = 0;
    while(1){
        if(PORTAbits.RA7 == 1){       
        PORTAbits.RA0 = 1; 
        PORTAbits.RA1 = 0; 
       __delay_ms(100); 
        PORTAbits.RA0= 0; //PARTE ALTA DURA MAS ESTA PARTE, EL DOBLE
        PORTAbits.RA1 = 1; 
        __delay_ms(100); 
        
        }
        else {
            PORTAbits.RA0 = 0; 
            PORTAbits.RA1 = 0; 
        }
    }    
    return;
}