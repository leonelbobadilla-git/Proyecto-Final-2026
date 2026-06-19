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
#ifndef USER_H
#define USER_H
/*==================[inclusiones]============================================*/
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/
/* User Level #define Macros                                                 */
/* TODO: Los parámetros de user.c pueden ponerse aquí */

#define ASDFASDFGHJKLLKAJSDFLKHJGHAFJ PORTD
#define ASDFASDFGHJKLLKAJSDFLKHJGHAFJ TRISD

/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void);     /* Inicializa las I/O y los periféricos */
/*==================[fin del archivo]========================================*/
#endif// USER_H
