/*============================================================================
 * Licencia:
 * Autor: Leonel Bobadilla
 * Fecha: 13.05.2026
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
#include "i2c.h"        /* Funciones/Parametros protocolo I2C */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
void i2cInit(void){ //Inicializa el protocolo I2C
    //i2c_init(I2C_PORT, 400 * 1000);
    //configurar sus pines como I/O
        //TRIS_SCL = 0;
        //TRIS_SDA = 1;
    //configurar la velocidad de comunicación
    //configurar el flanco 
}

void i2cInit(void){ //Inicializa el protocolo I2C
    //i2c_init(I2C_PORT, 400 * 1000);
    //configurar sus pines como I/O
        //TRIS_SCL = 0;
        //TRIS_SDA = 1;
    //configurar la velocidad de comunicación
    //configurar el flanco 
}

void I2C_Init(const unsigned long clock_freq) {
    /*SPCON = 0b00101000;
    SSPCON2 = 0;
    SSPADD = (8000000 / (4 * clock_freq)) - 1;
    SSPSTAT = 0;
    TRISC3 = 1;
    TRISC4 = 1;*/
}

void I2C_Wait() {
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Start() {
    I2C_Wait();
    SEN = 1;
}

void I2C_Repeated_Start() {
    I2C_Wait();
    RSEN = 1;
}

void I2C_Stop() {
    I2C_Wait();
    PEN = 1;
}

void I2C_Write(unsigned char data) {
    I2C_Wait();
    SSPBUF = data;
}

unsigned char I2C_Read(unsigned char ack) {
    unsigned char temp;
    I2C_Wait();
    RCEN = 1;
    I2C_Wait();
    temp = SSPBUF;
    I2C_Wait();
    ACKDT = (ack) ? 0 : 1;
    ACKEN = 1;
    return temp;
}

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
