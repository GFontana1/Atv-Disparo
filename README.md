# Atividade 2 - Disparo - Tarefa 29/01 Embarcatech

## Descrição do projeto

O programa implementa um temporizador de um disparo ao utilizar:

- 1 *LED Vermelho*
- 1 *LED Azul*
- 1 *LED Verde*
- 1 *Botão de pressão*

O sistema aciona um conjunto de LEDs ao pressionar um botão e os desliga gradualmente com um intervalo de 3 segundos entre cada mudança de estado.


## Como Rodar o código

1. *Compilar o código*:
   - Tenha o SDK do Raspberry Pi Pico W configurado.
   - Compile o código utilizando CMake e GCC ARM.
   - Abra o diagram.json para ver o simulador do Wokwi

2. *Transferir para o Raspberry Pi Pico W*:
   - Conecte sua placa ao computador com ela no modo **Bootsel**.
   - Monte a unidade **RPI-RP2** no computador.
   - Copie o arquivo compilado `.uf2` para a unidade montada ou aperte em Run na interface do VS Code caso tenha configurado a placa com o Zadig.
