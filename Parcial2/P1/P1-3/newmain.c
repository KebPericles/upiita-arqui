/*
 * Descripción: Genera parpadeo en PORTB, se visualiza en LEDs
 */

// Definiciones
#define _XTAL_FREQ 4000000

// Archivos cabecera
#include <xc.h>

// Palabra de configuración 1: CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT    // Selector de oscilador
#pragma config WDTE = OFF               // Deshabilita WDT
#pragma config PWRTE = OFF              // Desabilita PWRT
#pragma config MCLRE = ON               // Pin RE3/MCLR funciona como MCLR
#pragma config CP = OFF                 // Protección por código deshabilitado
#pragma config CPD = OFF                // Dato de Protección por código deshabilitado 
#pragma config BOREN = OFF              // Reset por Brown-Out deshabilitado
#pragma config IESO = ON                // Inversión entre Reloj Interno/Externo habilitado
#pragma config FCMEN = ON               // Monitoreo de reloj seguro habilitado
#pragma config LVP = OFF                // Bajo voltaje de programación en RB3/PGM deshabilitado

// Palabra de configuración 2: CONFIG2
#pragma config BOR4V = BOR40V           // Selector de voltaje de Brown-Out Reset
#pragma config WRT = OFF                // Escritura segura en Flash deshabilitado
// END CONFIG

// Declaración de la función tabla_ac
int tabla_ac(int num_decimal);

// Función main
void main(void) {
    // Configuración de recursos (periféricos)
    TRISD = 255;      // Configura PORTD como entrada
    PORTA = 0;        // Limpia PORTA
    PORTB = 0;        // Limpia PORTB
    PORTD = 0;        // Limpia PORTD
    ANSEL = 0;        // Configura los pines analógicos como digitales
    TRISA = 0;        // Configura PORTA como salida
    ANSELH = 0;       // Configura los pines analógicos como digitales
    TRISB = 0;        // Configura PORTB como salida

    // Aplicación
        while (1) {
        unsigned int i = PORTD;
        unsigned int digit, uni, dec, cen, umi;

        digit = i % 10;
        uni = tabla_ac(digit);
        digit = (i / 10) % 10;
        dec = tabla_ac(digit);
        digit = (i / 100) % 10;
        cen = tabla_ac(digit);
        digit = (i / 1000) % 10;
        umi = tabla_ac(digit);

        // Mostrar unidades
        PORTAbits.RA0 = 0;  // Encender el segmento correspondiente
        PORTB = uni;
        __delay_ms(5);
        PORTAbits.RA0 = 1;  // Apagar el segmento

        // Mostrar decenas
        PORTAbits.RA1 = 0;  // Encender el segmento correspondiente
        PORTB = dec;
        __delay_ms(5);
        PORTAbits.RA1 = 1;  // Apagar el segmento

        // Mostrar centenas
        PORTAbits.RA2 = 0;  // Encender el segmento correspondiente
        PORTB = cen;
        __delay_ms(5);
        PORTAbits.RA2 = 1;  // Apagar el segmento

        // Mostrar unidades de millar
        PORTAbits.RA3 = 0;  // Encender el segmento correspondiente
        PORTB = umi;
        __delay_ms(5);
        PORTAbits.RA3 = 1;  // Apagar el segmento
    }
}

// Función para convertir un número decimal a su correspondiente código de 7 segmentos para un display de ánodo común
int tabla_ac(int num_decimal) {
    int cod_7seg = 0;
    if (num_decimal == 0) {
        cod_7seg = 0b11000000;
    } else if (num_decimal == 1) {
        cod_7seg = 0b11111001;
    } else if (num_decimal == 2) {
        cod_7seg = 0b10100100;
    } else if (num_decimal == 3) {
        cod_7seg = 0b10110000;
    } else if (num_decimal == 4) {
        cod_7seg = 0b10011001;
    } else if (num_decimal == 5) {
        cod_7seg = 0b10010010;
    } else if (num_decimal == 6) {
        cod_7seg = 0b10000010;
    } else if (num_decimal == 7) {
        cod_7seg = 0b11111000;
    } else if (num_decimal == 8) {
        cod_7seg = 0b10000000;
    } else if (num_decimal == 9) {
        cod_7seg = 0b10011000;
    } else {
        cod_7seg = 0b11111111;  // Apagar todos los segmentos si el valor es inválido
    }
    return cod_7seg;
}
