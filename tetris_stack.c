// Nível Novato - Começo //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Capacidade máxima da esteira
#define MAX 5 

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
    Peca vetor[MAX];
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

// Main
int main () {
    Fila esteira;
    inicializarFila(&esteira);

    // Aleatoridade
    srand(time(NULL)) ;

    // Menu
    int opcao = 0;
    do {

        printf ("\n=== TETRIS STACK ===\n");
        printf ("\n1. Jogar peça (dequeue)") ;
        printf ("\n2. Inserir nova peça (enqueue)") ;
        printf ("\n0. Sair.") ;
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 1: {
            Peca p = dequeue(&esteira); 
            if (p.id != -1) {
                printf("\n[JOGO] Voce jogou a peca %c (ID: %d)!\n", p.nome, p.id);
                }
            }
            break;

        case 2: {
            Peca nova = gerarPeca();
            enqueue(&esteira, nova);
            }
            break;

        case 0:
            printf("\nSaindo do Tetris Stack...\n");
            break;

        default:
            break;
        }

    mostrarFila(esteira) ;

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
        printf("[SISTEMA] Sucesso") ;
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

// Nível Novato - Fim //