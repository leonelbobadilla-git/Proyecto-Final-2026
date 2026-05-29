/*============================================================================
 * Licencia:
 * Autor: Leonel Bobadilla
 * Fecha: 07.04.2026
 *===========================================================================*/
/** @file
 * @brief	Contiene macros y definiciones de user
 * 
 * Aquí se definen macros, tipos de datos y se declaran las funciones y datos 
 * externos de user
 */
#ifndef MPU6050_H
#define MPU6050_H
/*==================[inclusiones]============================================*/
#include <xc.h>         /* para las definiciones de no sé qué */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/
/* User Level #define Macros                                                 */
/* TODO: Los parámetros de user.c pueden ponerse aquí */

/**/
/*
 * ACÁ SE PONE LO DE
 *  #define DISPLAY_PORT PORTD
 */
/**/

/*==================[tipos de datos declarados por el usuario]===============*/
// Estructura para almacenar todas las lecturas
typedef struct {
    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;
    int16_t temp;
    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;
} MPU6050_Data;

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void MPU6050_Init(void); /* Rutina para despertar el MPU6050 (debe llamarse una vez al inicio) */
void MPU6050_UpdateData(MPU6050_Data* data);    /* Rutina principal para obtener todos los datos */
/*==================[fin del archivo]========================================*/
#endif// USER_H
