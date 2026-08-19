/*============================================================================
 * Licencia:
 * Autor: Homero y Dante Alighieri
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
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "i2c.h"        /* Funciones/Parametros I2C */
#include "mpu6050.h"    /* Funciones/Parametros MPU6050 */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[funcion principal]======================================*/
void main(void) {
    /* TODO: Agregar el Cod1iogo de la Aplicación aquí */
    appInit();      /* Inicializa I/O y Periféricos de la aplicación */
    i2cInit();      /* Inicializa I/O y Periféricos del protocolo I2C */
    MPU6050Init();  /* Inicializa I/O y Periféricos del módulo MPU6050 */
    
    while(1){
        //TODO
    }
}

/* 
 * ID del integrado
 * Puerto sincrónico y half duplex (el maestro habla  primero)
 * 
 */

/*
 * El giróscopo se alimenta con 3V3
 */

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
