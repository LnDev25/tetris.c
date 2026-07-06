# tetris.c
Trabalho da Faculdade de ADS - Pilhas e Filas

Nível Novato - Check 1.0
# 🧱 Tetris Stack - Gerenciador de Peças (Nível Novato)

Bem-vindo ao repositório do **Tetris Stack**, um simulador de gerenciamento de fluxo de dados baseado no clássico jogo de blocos. Este projeto foi desenvolvido para aplicar os conceitos fundamentais de Estruturas de Dados na linguagem C.

## 🎯 Objetivo da Fase 1 (Novato)
Implementar uma **Fila Circular (Queue)** utilizando arrays estáticos para simular a "esteira" de peças que o jogador receberá durante a partida. O uso da lógica circular garante a otimização da memória, reutilizando espaços liberados sem a necessidade de realocar todos os elementos.

## ⚙️ Mecânicas e Funcionalidades
* **Gerador Automático de Peças:** As peças (I, O, T, L) são geradas de forma aleatória e recebem um identificador (`id`) único e sequencial utilizando variáveis estáticas.
* **Enqueue (Inserção Segura):** Adiciona peças ao final da esteira utilizando a fórmula do módulo `(f->fim + 1) % MAX`, com bloqueio automático caso a capacidade máxima seja atingida.
* **Dequeue (Remoção FIFO):** Retira a peça mais antiga da esteira para ser "jogada", garantindo a regra *First In, First Out*.
* **Display em Tempo Real:** Varredura iterativa circular para mostrar as peças ativas na esteira após cada interação do usuário.

## 🚀 Como Executar
1. Compile o código-fonte via terminal:
   ```bash
   gcc tetris_stack.c -o tetris

   ./tetris

----------------------------------------------------------------------------------------------------------------------------------

Nível Aventureiro 2.0 - CHECK

# 🧱 Tetris Stack - Gerenciador de Peças

Bem-vindo ao repositório do **Tetris Stack**, um simulador de gerenciamento de fluxo de dados baseado no clássico jogo de blocos. Este projeto foi desenvolvido para aplicar os conceitos fundamentais de Estruturas de Dados na linguagem C, integrando diferentes formatos de armazenamento em memória.

## 🎯 Objetivo da Fase 1 (Novato) - Concluído
Implementar uma **Fila Circular (Queue)** utilizando arrays estáticos (capacidade: 5) para simular a "esteira" de peças que o jogador receberá. O uso da lógica circular garante a otimização da memória, reutilizando espaços liberados sem a necessidade de realocar todos os elementos.

## ⚔️ Objetivo da Fase 2 (Aventureiro) - Concluído
Implementar uma **Pilha Linear (Stack)** (capacidade: 3) para servir como "Baú de Reserva", permitindo a integração de dados entre a Fila e a Pilha, além de automatizar o fluxo de peças.

## ⚙️ Mecânicas e Funcionalidades Atuais
* **Gerador Aleatório Sequencial:** Peças (I, O, T, L) geradas com `id` único usando variáveis estáticas.
* **Auto-Refill (Fila):** A esteira nunca para. Sempre que uma peça é retirada (`dequeue`), uma nova peça é gerada e inserida automaticamente (`enqueue`), mantendo a esteira sempre com 5 elementos.
* **Reserva LIFO (Pilha):** O jogador pode guardar uma peça da esteira no baú (`push`) e resgatá-la posteriormente (`pop`). O baú obedece a regra *Last In, First Out* e possui travas de segurança contra *overflow* (capacidade máxima de 3 peças).
* **Display em Tempo Real:** Renderização do estado atual de ambas as estruturas (Fila e Pilha) após cada turno.

## 🚀 Como Executar
1. Compile o código-fonte via terminal:
   ```bash
   gcc tetris_stack.c -o tetris
   
   ------------------------------------------------------------------------------------------------------------------------------------------------

   Nível Mestre 3.0 - CHECK

   # 🧱 Tetris Stack - Gerenciador de Peças (Versão Final - Nível Mestre)

Bem-vindo ao repositório do **Tetris Stack**, um simulador de gerenciamento de fluxo de dados baseado no clássico jogo de blocos. Este projeto foi desenvolvido para aplicar os conceitos fundamentais de Estruturas de Dados na linguagem C, integrando diferentes formatos de armazenamento em memória.

## 🎯 Objetivo da Fase 1 (Novato) - Concluído
Implementar uma **Fila Circular (Queue)** utilizando arrays estáticos (capacidade: 5) para simular a "esteira" de peças que o jogador receberá. O uso da lógica circular garante a otimização da memória.

## ⚔️ Objetivo da Fase 2 (Aventureiro) - Concluído
Implementar uma **Pilha Linear (Stack)** (capacidade: 3) para servir como "Baú de Reserva", permitindo a integração de dados entre a Fila e a Pilha, com *auto-refill* da esteira.

## 🧙‍♂️ Objetivo da Fase 3 (Mestre) - Concluído
Implementar a **Manipulação Direta de Memória (Swap)**, permitindo que o jogador troque peças de lugar entre as duas estruturas de dados dinamicamente, sem retirá-las do jogo.

## ⚙️ Mecânicas e Funcionalidades Atuais
* **Gerador Aleatório Sequencial:** Peças geradas com `id` único.
* **Auto-Refill (Fila):** A esteira nunca para, mantendo sempre 5 elementos.
* **Reserva LIFO (Pilha):** Baú de limite máximo de 3 peças.
* **Troca Simples:** Permite alternar a 1ª peça da esteira com a peça do topo da reserva.
* **Mega Swap:** Alterna as 3 primeiras peças da esteira com as 3 peças da reserva simultaneamente (exige que o baú esteja cheio).
* **Display em Tempo Real:** Renderização visual limpa e separada para UX otimizada.

## 🚀 Como Executar
1. Compile o código-fonte via terminal:
   ```bash
   gcc tetris_stack.c -o tetris