/*
    Aluno: Lucas Carneiro de Araújo Lima
*/

#include <stdio.h>
#include "pico/stdlib.h"  
#include "hardware/timer.h"

#define RED 13 //VERDE no wokwi
#define BLUE 12 //AMARELO no wokwi
#define GREEN 11 //VERMELHO no Wokwi

unsigned short int counter = 0; // Contador utilizado para definir o turno de cada LED

static bool repeating_timer_callback(struct repeating_timer *t); // Prototipação da rotina de temporização
static void setup(); // Prototipação da função que define os LEDs RGB como saídas

int main() {
    stdio_init_all(); // Inicialização dos recursos de entrada e saída padrão

    setup(); // Inicialização e configuração dos LEDs

    struct repeating_timer timer; // Timer

    absolute_time_t next_time = delayed_by_us(get_absolute_time(), 3e6); // Registra o tempo absoluto a cada 3 seg

    add_repeating_timer_ms(3e3, repeating_timer_callback, NULL, &timer); // Inicializa o temporizador periódico que chama o callback a cada 3 segundos

    while (true) {
        sleep_ms(1e3); // Delay de 1 seg
        
        if(time_reached(next_time)) { // Se atingiu 3 seg, gera um print com uma quebra de linha a mais a fim de facilitar a visualização
            printf("Passou 1 segundo...\n\n");
            next_time = delayed_by_us(get_absolute_time(), 3e6);
        } else printf("Passou 1 segundo...\n"); // Avisa ao usuário que já se passou 1 seg
    }
    return 0;
}

// Configura o estado de cada um dos 3 LEDs
void semaforo(unsigned short int state) {
    gpio_put(RED,state & 0x100);
    gpio_put(BLUE,state & 0x010);
    gpio_put(GREEN,state & 0x001);
}

// Rotina de temporização. A cada 3 seg um LED é ligado e os outros 2 LEDs são desligados
bool repeating_timer_callback(struct repeating_timer *t) {
    if (counter == 0) semaforo(0x010);
    else if (counter == 1) semaforo(0x100);
    else if (counter == 2) semaforo(0x001);

    counter = (counter + 1)%3; //  Mantém o contador no ciclo de 0 à 2

    return true;
}

// Inicializa e configura os LEDs RGB como saída. Inicializa e configura os botões como entradas.
void setup() {
    gpio_init(RED);
    gpio_set_dir(RED, GPIO_OUT); 

    gpio_init(BLUE);
    gpio_set_dir(BLUE, GPIO_OUT); 

    gpio_init(GREEN);
    gpio_set_dir(GREEN, GPIO_OUT);
    gpio_put(GREEN,true); 
}