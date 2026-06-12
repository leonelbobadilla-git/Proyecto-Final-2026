/*============================================================================
 * Licencia:
 * Autor: Leonel Bobadilla
 * Fecha: 24.04.2026
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de user
 * 
 * Aquí se encuentra la implementación de users, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

#include "system.h"     /* Funciones/Parametros System, como conf de osc/perif */
#include "user.h"       /* Funciones/Parametros User, como InitApp */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/
//char datoUser; //Ejemplo

/*==================[declaraciones de funciones internas]====================*/
//static void funcUser(void); //Ejemplo

/*==================[definiciones de funciones internas]=====================*/
//static void funcUser(void){ //Ejemplo
//}; 

/*==================[definiciones de funciones externas]=====================*/
/**
 * @brief	Inicializa Ports, Periféricos e Interrupciones
 * @return	Nada
 */
void appInit(void) {
    /* TODO: Inicializar Ports/Periféricos/Interrupciones */

    /* Configura funciones analógicas y dirección de los Ports de I/O */
    ANSEL = 0;
    ANSELH = 0;
    
    __delay_ms(100); //Espera que se estabilice la fuente
    
    /* TODO: Habilita Interrupciones si es necesario*/
    //TMR2IE = 1;
    //PEIE = 1;
    //GIE = 1;  
}

/*==================[fin del archivo]========================================*/

/*// Define la frecuencia de tu cristal (ej. 8MHz) - ¡Ajusta esto a tu hardware!
#define _XTAL_FREQ 8000000 

void I2C_Init(const unsigned long clock_freq) {
    SSPCON = 0b00101000;  // Habilita SSP, modo I2C Master
    SSPCON2 = 0;
    SSPADD = (_XTAL_FREQ / (4 * clock_freq)) - 1; // Configura la velocidad (baud rate)
    SSPSTAT = 0;
    TRISC3 = 1; // Configura RC3 (SCL) como entrada (el hardware toma el control)
    TRISC4 = 1; // Configura RC4 (SDA) como entrada
}

void I2C_Wait() {
    // Espera a que el bus esté libre y termine la operación actual
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Start() {
    I2C_Wait();
    SEN = 1; // Inicia condición de START
}

void I2C_Repeated_Start() {
    I2C_Wait();
    RSEN = 1; // Inicia condición de RESTART
}

void I2C_Stop() {
    I2C_Wait();
    PEN = 1; // Inicia condición de STOP
}

void I2C_Write(unsigned char data) {
    I2C_Wait();
    SSPBUF = data; // Carga el dato a enviar
}

unsigned char I2C_Read(unsigned char ack) {
    unsigned char temp;
    I2C_Wait();
    RCEN = 1;      // Habilita la recepción
    I2C_Wait();
    temp = SSPBUF; // Lee el dato recibido
    I2C_Wait();
    ACKDT = (ack) ? 0 : 1; // 0 = ACK (quiero más datos), 1 = NACK (no quiero más datos)
    ACKEN = 1;     // Envía el bit de ACK/NACK
    return temp;
}*/