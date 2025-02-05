#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERMELHO 12
#define LED_VERDE 13
#define LED_AZUL 11
#define BOTAO 5

bool LED_LIGADO = false;
volatile int ESTADO = 0;

void config_pin() {
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
}

int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if(ESTADO == 1) {
        gpio_put(LED_AZUL, false);
        ESTADO = 2;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if(ESTADO == 2) {
        gpio_put(LED_VERMELHO, false);
        ESTADO = 3;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if(ESTADO == 3) {
        gpio_put(LED_VERDE, false);
        ESTADO = 0;
        LED_LIGADO = false;
    }
}

int main() {
    stdio_init_all();
    config_pin();

    while (true) {
        if(gpio_get(BOTAO) == 0 && !LED_LIGADO) {
            sleep_ms(50);

            if(gpio_get(BOTAO) == 0) {
                gpio_put(LED_VERMELHO, true);
                gpio_put(LED_VERDE, true);
                gpio_put(LED_AZUL, true);

                LED_LIGADO = true;
                ESTADO = 1;
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

        sleep_ms(10);
    }
    return 0;
}