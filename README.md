# Proyecto-Final-2026
## Prefacio
Es un proyecto etc.
*Ejemplo de texto en itálica*. **Ejemplo de texto en negrita**.

***

## Hardware
Estos son los módulos a utilizar:

### Raspberry
Es el microcontrolador principal.

### MPU6050
Es el giróscopo y acelerómetro.
Está conectado por cuatro pines con el Raspberry:
- SDA y SCL: para el protocolo I2C.
- INT: para las interrupciones del MPU6050 de cada vez que éste sale del SLEEP mode,  mide y vuelve a dormir.
- Una para el clock.

### SIM 800L
Se conecta a la red GSM

### Detector de pulso
Mide el pulso cardíaco

***

## Software
El código escrito en C consiste de los siguientes módulos:

### main.c
Contiene el código principal.

### user.c y user.h
Define los periféricos del Raspberry.

### mpu6050.c y mpu6050.h
Permite comunicación entre el MPU6050 y el microprocesador Raspberry por protocolo I2C.
