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