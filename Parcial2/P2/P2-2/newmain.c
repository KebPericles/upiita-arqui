/*
 * Descripci�n: Genera parpadeo en PORTB, se visualiza en LEDs
 */
 
 //Definiciones
#define _XTAL_FREQ 4000000

//Archuivos cabecera
#include <xc.h>

// Palabra de configuraci�n 1: CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT	// Selector de oscilador
#pragma config WDTE = OFF       // Deshabilita WDT
#pragma config PWRTE = OFF      // Desabilita PWRT
#pragma config MCLRE = ON       // Pin RE3/MCLR funciona como MCLR
#pragma config CP = OFF         // Protecci�n por c�digo deshabilitado
#pragma config CPD = OFF        // Dato de Protecci�n por c�digo deshabilitado 
#pragma config BOREN = OFF      // Reset por Brown-Out deshabilitado
#pragma config IESO = ON        // Inversi�n entre Reloj Interno/Externo habilitado
#pragma config FCMEN = ON       // Monitoreo de reloj seguro habilitado
#pragma config LVP = OFF         // Bajo voltaje de programaci�n en RB3/PGM deshabilitado

// Palabra de configuraci�n 2: CONFIG2
#pragma config BOR4V = BOR40V   // Selector de voltaje de Brown-Out Reset
#pragma config WRT = OFF        // Escritura segura en Flash deshabilitado
//END CONFIG

//Funci�n main
void main(void) {
    //Configuraci�n de recursos (perif�ricos)
    ANSELH = 0;
    TRISB = 0;
    
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PSA = 1;
    OPTION_REGbits.PS = 0b111; // Configurar preescalador a 1:256
    
    TMR0=0;//Clear TMRO
    
    //Aplicaci�n
    while(1){
        PORTB = TMR0;
        PORTBbits.RB0 = ~PORTBbits.RB0;
    }    
    return;
}