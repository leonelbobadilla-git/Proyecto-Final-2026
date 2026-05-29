/*============================================================================
 * Licencia:
 * Autor: Leonel Bobadilla
 * Fecha: 24.04.2026
 *===========================================================================*/
/** @file
 * @brief	Contiene la función principal
 * 
 * Aquí se encuentra la implementación de la función principal
 */
/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* Para las definiciones de uint8_t por ej.*/
#include <stdio.h>      /* Archivo de Encabezados StdIO */
#include "system.h"     /* Funciones/Parametros System, como osc/peripheral config */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "mpu6050.h"       /* Funciones/Parametros User, como InitApp */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[funcion principal]======================================*/
void main() {
    // Variable global o local para guardar los datos
    MPU6050_Data mis_datos_mpu;

    // Inicializa el I2C a 100 kHz (Estándar I2C)
    I2C_Init(100000); 
    
    // Despierta el sensor
    MPU6050_Init();
    
    while(1) {
        // Llamas a tu rutina pasándole la dirección de memoria de tu estructura
        MPU6050_UpdateData(&mis_datos_mpu);
        
        // ¡Listo! Aquí ya puedes pasar 'mis_datos_mpu' a tus funciones de análisis
        // evaluar_reposo(mis_datos_mpu.accel_x, mis_datos_mpu.accel_y, mis_datos_mpu.accel_z);
        // ...
        
        __delay_ms(100); // Pequeño retardo entre lecturas
    }
}

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
