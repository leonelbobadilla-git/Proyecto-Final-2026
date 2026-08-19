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

// Definiciones de hardware
#define I2C_PORT    i2c0
#define PIN_SDA     4
#define PIN_SCL     5

// Dirección I2C del MPU6050 (AD0 a GND)
#define MPU_ADDR    0x68

// Registros del MPU6050
#define REG_PWR_MGMT_1      0x6B
#define REG_ACCEL_XOUT_H    0x3B
#define REG_GYRO_XOUT_H     0x43

/*==================[tipos de datos declarados por el usuario]===============*/
// Estructura para almacenar todas las lecturas
typedef struct {    //Estructura para el buz de data que el MPU6050 nos va a brindar
    int16_t accel_x;    //Aceleración en eje X
    int16_t accel_y;    //Aceleración en eje Y
    int16_t accel_z;    //Aceleración en eje Z
    int16_t temp;       //Temperatura del MPU6050
    int16_t gyro_x;     //Ángulo de inclinación en eje X
    int16_t gyro_y;     //Ángulo de inclinación en eje Y
    int16_t gyro_z;     //ÁNgulo de inclinación en eje Z
}   MPU6050_Buz;

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void MPU6050Init(void); /* Rutina para despertar el MPU6050 (debe llamarse una vez al inicio) */
void MPU6050Read(MPU6050_Buz* buz, len); /* Rutina principal para obtener todos los datos; buz es la info, y len es la longitud de la info */
/*==================[fin del archivo]========================================*/
#endif// MPU6050_H
