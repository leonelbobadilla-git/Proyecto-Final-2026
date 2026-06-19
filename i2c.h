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
#ifndef I2C_H
#define I2C_H
/*==================[inclusiones]============================================*/
#include <xc.h>         /* para las definiciones de no sé qué */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/
/* User Level #define Macros                                                 */
/* TODO: Los parámetros de user.c pueden ponerse aquí */

//PIN 14
#define PIN_SCL     PORTCbits.RC3
#define TRIS_SCL    TRISCbits.TRISC3

//PIN 15
#define PIN_SDA     PORTCbits.RC4
#define TRIS_SDA    TRISCbits.TRISC4

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
void i2cInit(void); /* Configuración del protocolo I2C (debe llamarse una vez al inicio) */
/*==================[fin del archivo]========================================*/
#endif// I2C_H
