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
#include "mpu6050.h"    /* Funciones/Parametros MPU6050, como InitMPU6050 */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/
#define MPU6050_WRITE_ADDR 0xD0
#define MPU6050_READ_ADDR  0xD1

/*==================[definiciones de datos externos]=========================*/
//char datoUser; //Ejemplo

/*==================[declaraciones de funciones internas]====================*/
//static void funcUser(void); //Ejemplo

/*==================[definiciones de funciones internas]=====================*/
//static void funcUser(void){ //Ejemplo
//}; 

/*==================[definiciones de funciones externas]=====================*/
/**
 * @brief	Rutina para despertar el MPU6050 (debe llamarse una vez al inicio)
 * @return	Nada
 */
void MPU6050Init(void) {
    //Primero lo despierto
    //Luego verifico y configuro las direcciones y registros que correspondan
    //Después declaro el tipo de flanco (debe ser igual al declarado para el I2C)
    I2C_Start();
    I2C_Write(MPU6050_WRITE_ADDR);
    I2C_Write(0x6B); // Registro PWR_MGMT_1
    I2C_Write(0x00); // 0x00 para despertar
    I2C_Stop();
}

/**
 * @brief	Rutina principal para obtener todos los datos
 * @return	Nada
 */
void MPU6050Read(MPU6050_Buz* buz, len) {
    I2C_Start();                    //
    I2C_Write(MPU6050_WRITE_ADDR); // Apuntamos al sensor para escribir
    I2C_Write(0x3B);               // Registro inicial (ACCEL_XOUT_H)
    
    I2C_Repeated_Start();          // Cambiamos el modo de comunicación
    I2C_Write(MPU6050_READ_ADDR);  // Apuntamos al sensor para LEER
    
    // Leemos secuencialmente los 14 bytes
    // Mandamos un "1" (ACK) para seguir leyendo, y un "0" (NACK) en el último byte
    /* hay que verificar que el primero byte de cada eje es el H o el L, y en base a eso tratar ambos bytes de modo que me queden en el orden HL y no LH */
    /* Se recibe H y luego L, por lo que queda HL */
    buz->accel_x = (I2C_Read(1) << 8) | I2C_Read(1);
    buz->accel_y = (I2C_Read(1) << 8) | I2C_Read(1);
    buz->accel_z = (I2C_Read(1) << 8) | I2C_Read(1);
    
    buz->temp    = (I2C_Read(1) << 8) | I2C_Read(1);
    
    buz->gyro_x  = (I2C_Read(1) << 8) | I2C_Read(1);
    buz->gyro_y  = (I2C_Read(1) << 8) | I2C_Read(1);
    buz->gyro_z  = (I2C_Read(1) << 8) | I2C_Read(0); // Último byte: NACK (0)
    
    I2C_Stop();
}

/*==================[fin del archivo]========================================*/
