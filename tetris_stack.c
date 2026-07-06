// Nível Novato/Aventureiro - Começo //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Capacidade máxima 
#define MAX 5 // Capacidade da fila (Esteira)
#define MAX_PILHA 3 // Capacidade da Pilha (Reserva)

// Struct da Peça
typedef struct {
    char nome ;
    int id ;
} Peca ;

// Struct da Fila
typedef struct {
    Peca vetor [MAX] ;
    int inicio ;
    int fim ;
    int total ; 
} Fila ;

// Struct da Pilha
typedef struct {
    Peca vetor[MAX_PILHA];
    int topo;
} Pilha;

// Iniciando
void inicializarPilha(Pilha *p) {
    p->topo = -1; 
}

// Funções
void inicializarFila(Fila *f) ;
Peca gerarPeca();
void enqueue(Fila *f, Peca p) ;
Peca dequeue(Fila *f);
void mostrarFila(Fila f);

// Motor da pilha (push, pop e mostrarPilha)
void push(Pilha *p, Peca peca) {
    if (p->topo == MAX_PILHA -1) {
        printf("\n [SISTEMA] Reserva cheia") ;
        return ;
    } else {
        p->topo++ ;
        p->vetor[p->topo] = peca;
    }
}

Peca pop(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[SISTEMA] Reserva Vazia") ;
        Peca vazia ;
        vazia.id = -1;
        return vazia ;
    } else {
        Peca retirada = p->vetor[p->topo];
        p->topo-- ;
        return retirada;
    }
}

void mostrarPilha(Pilha p) {
    if (p.topo == -1 ) {
        printf("\n[Vazia]");
    } else {
        for (int i = p.topo; i >= 0; i--) {
           printf("[%c %d] ", p.vetor[i].nome, p.vetor[i].id); 
        }
    }
}                                                                                                        

// Main
int main () {
    Fila esteira;
    inicializarFila(&esteira) ;

    Pilha reserva;
    inicializarPilha(&reserva) ;

    // Aleatoridade
    srand(time(NULL)) ;

    // Pré-preenchendo a esteira com 5 peças (Auto-Refill Inicial)
    for (int i = 0; i < MAX; i++) {
        enqueue(&esteira, gerarPeca());
    }

    // Menu
    int opcao = 0;
    do {

        printf("\n1. Jogar peca");
        printf("\n2. Reservar peca");
        printf("\n3. Usar peca reservada");
        printf("\n0. Sair");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: { // Jogar Peça
                Peca p = dequeue(&esteira); 
                if (p.id != -1) {
                    printf("\n[JOGO] Voce jogou a peca %c (ID: %d)!\n", p.nome, p.id);
                    enqueue(&esteira, gerarPeca());
                }
                break;
            }

            case 2: { // Reservar Peça
                if (reserva.topo < MAX_PILHA - 1) {
                    Peca p = dequeue(&esteira);
                    push(&reserva, p);
                    enqueue(&esteira, gerarPeca());
                } else {
                    printf("\n[SISTEMA] Operacao cancelada: A reserva esta cheia!\n");
                }
                break;
            }

            case 3: { // Usar Reserva
                Peca p = pop(&reserva);
                if (p.id != -1) {
                    printf("\n[JOGO] Voce usou a reserva: %c (ID: %d)!\n", p.nome, p.id);
                }
                break;
            }

            case 0:
                printf("\nSaindo do Tetris Stack...\n");
                break;

            default:
                printf("\nOpcao Invalida!\n");
                break;
        }

    mostrarFila(esteira) ;
    mostrarPilha(reserva) ;

    } while (opcao != 0);
    printf("\n");

    return 0;
}

// Motor de partida 
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->total = 0;
}

// Sorteador de peças
Peca gerarPeca() {
    static int contador_id = 0; 
    Peca nova_peca;
    
    nova_peca.id = contador_id;
    contador_id++; 
    
    // Sorteia uma letra entre 'I', 'O', 'T', 'L'
    char tipos[4] = {'I', 'O', 'T', 'L'};
    int sorteio = rand() % 4; 
    nova_peca.nome = tipos[sorteio];
    
    return nova_peca;
}

// Função enqueue
void enqueue(Fila *f, Peca p) {
    if (f->total == MAX) {
        printf("\n[SISTEMA] A fila esta cheia...") ;
        return ;
    } else {
        f->fim = (f->fim + 1) % MAX;
        f->vetor[f->fim] = p;
        f->total++;
    }
}

// Função dequeue
Peca dequeue(Fila *f) {
    if (f->total == 0) {
        printf("\n[SISTEMA] A esteira esta vazia! Nao ha pecas para jogar.\n");
        Peca vazia;
        vazia.id = -1; 
        return vazia;
    } else {           
        Peca jogada = f->vetor[f->inicio]; 
        f->inicio = (f->inicio + 1) % MAX;         
        f->total--;
        return jogada;
    }
}

// Mostrando a fila
void mostrarFila(Fila f) {
    if (f.total == 0) {
        printf("\n[SISTEMA] Fila vazia");
    } else {
        for (int i = 0; i < f.total; i++) {
            int indice = (f.inicio + i) % MAX;
            printf("[%c %d] ", f.vetor[indice].nome, f.vetor[indice].id);
        }
    }
}

// Nível Novato/Aventureiro - Fim //