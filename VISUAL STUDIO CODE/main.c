#include <stdio.h>
#include "pico/stdlib.h"
//#include "pico/cyw43_arch.h"
#include "hardware/uart.h"

// UART defines
// By default the stdout UART is `uart0`, so we will use the second one
#define UART_ID uart1
#define BAUD_RATE 115200

// Use pins 4 and 5 for UART1
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define UART_TX_PIN 4
#define UART_RX_PIN 5
#define PIN_SDA 2
#define PIN_SCL 3
#define PIN_LED 25
#define PIN_SENSOR_DE_PULSO 26
#define PIN_MEDIR_BATERIA 27

int main()
{
    stdio_init_all();

    //inicializo cyw43_arch
    //cyw43_arch_init();
    
    // Inicializo el LED
    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED, GPIO_OUT);

    // Set up our UART
    uart_init(UART_ID, BAUD_RATE);
    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
    // Use some the various UART functions to send out data
    // In a default system, printf will also output via the default UART
    
    // Send out a string, with CR/LF conversions
    uart_puts(UART_ID, " Hello, UART!\n");
    
    // For more examples of UART use see https://github.com/raspberrypi/pico-examples/tree/master/uart

    printf("\n\n\n");
    for(int i=0; i<30; i++){
        printf("Wait\n");
        sleep_ms(1000);
    }

    printf("Hello, world!\n");

    while(true) {
        printf("LED ON\n");
        gpio_put(PIN_LED, true);
        sleep_ms(1000);
        printf("LED OFF\n");
        gpio_put(PIN_LED, false);
        sleep_ms(1000);
    }
}
