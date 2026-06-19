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
        //TRIS_SCL = ;
        //TRIS_SDA = ;
    //configurar la velocidad de comunicación
    //configurar el flanco 
}

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
