# U4C5A1
Repositório para a atividade 1 da unidade 4 e capítulo 5:  Temporizador periódico.

__Aluno:__
Lucas Carneiro de Araújo Lima

## ATIVIDADE 
__Descrição:__
O projeto consiste na implementação de um semáforo utilizando a Raspberry Pi Pico W, controlado por um temporizador periódico configurado com a função `add_repeating_timer_ms()` do Pico SDK. Três LEDs (vermelho, amarelo e verde) e três resistores de 330 Ω são usados para simular as luzes do semáforo, alternando seus estados a cada 3 segundos. A lógica de controle, implementada via GPIO, segue a sequência vermelho → amarelo → verde, garantindo a temporização correta do sistema.

__Para este trabalho, os seguintes componentes e ferramentas se fazem necessários:__
1) Microcontrolador Raspberry Pi Pico W.
2) Simulador de Sistemas Embarcados Wokwi.
3) Ambiente de trabalho VSCode.
4) 3 LEDs
5) 3 Resistores 330 Ω
6) 1 Botão Pull-Up
7) Ferramenta educacional BitDogLab.

<div align="center">
  <img src="https://github.com/user-attachments/assets/a881ff6b-153c-425a-ad8e-13f210549b1b" alt="GIF demonstrativo" width="300"/>
</div>

## Instruções de Uso

### 1. Clone o repositório
Abra o terminal e execute o comando abaixo para clonar o repositório em sua máquina:
```bash
git clone https://github.com/LucasCarneiro3301/U4C4O12T.git
```

### 2. Configure o ambiente de desenvolvimento
Certifique-se de que o [SDK do Raspberry Pi Pico](https://github.com/LucasCarneiro3301/U4C5A1.git) esteja instalado e configurado corretamente no seu sistema.

### 3. Configure a extensão do simulador Wokwi
Certifique-se de que a extensão [Wokwi para VS Code](https://docs.wokwi.com/pt-BR/vscode/getting-started) esteja instalada e configurada corretamente no seu sistema.

### 4. Conexão com a Rapberry Pico
1. Conecte o Raspberry Pi Pico ao seu computador via USB.
2. Inicie o modo de gravação pressionando o botão **BOOTSEL** e **RESTART**.
3. O Pico será montado como um dispositivo de armazenamento USB.
4. Execute através do comando **RUN** a fim de copiar o arquivo `U4C5A1.uf2` para o Pico.
5. O Pico reiniciará automaticamente e executará o programa.

### 4. Observações (IMPORTANTE !!!)
1. O projeto é compatível **tanto** com o simulador Wokwi **quanto** com a placa BitDogLab.
2. Manuseie a placa com cuidado.

## Recursos e Funcionalidades

### 1. Semáforo

Composto por um led vermelho, amarelo e verde, seguindo a sequência vermelho → amarelo → verde a cada 3000 ms (3 segundos). Na placa BitDogLab o semáforo é representado pelo LED RGB, seguindo a sequência verde → azul → vermelho.

### 2. Temporização Periódica

Implementa a rotina de temporização `add_repeating_timer_ms` para alternar os estados do semáforo a cada 3 segundos. A principal vantagem de usar `add_repeating_timer_ms` é que ele permite a alternância dos estados do semáforo de forma não bloqueante, ou seja, o microcontrolador pode executar outras tarefas enquanto o temporizador gerencia a temporização automaticamente. 

### 4. Monitoramento Serial

É possível acompanhar o funcionamento do programa através do monitor. A partir de _prints_, o programa avisa ao usuário cada vez que se passa 1 segundo.







