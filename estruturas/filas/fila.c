#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int capacidade;
    int primeiro;
    int ultimo;
    int* itens;
    int numItens;
} Fila;


void inicializaFila(Fila* fila, int capacidade){
    fila->capacidade = capacidade;
    fila->itens = (int*) malloc(fila->capacidade * sizeof(int));
    fila->primeiro = -1;
    fila->ultimo = -1;
    fila->numItens = 0;
}

int insereItemNaFila(Fila *fila, int item){
    if(fila->numItens == fila->capacidade){ // checa se a fila está cheia
        return -1;
    }
    printf("Inserindo item %d\n", item);
    fila->primeiro = 0;
    fila->ultimo++;
    fila->numItens++;
    fila->itens[fila->ultimo] = item;
}

int removeItemDaFila(Fila* fila){
    int item = fila->itens[fila->primeiro];
    fila->primeiro++;
    fila->numItens--;
    return item;
}


int main(){
    Fila *fila;
    fila = (Fila*) malloc(sizeof(Fila));
    int item;
    inicializaFila(fila, 10);

    insereItemNaFila(fila, 1);
    insereItemNaFila(fila, 2);
    insereItemNaFila(fila, 3);
    insereItemNaFila(fila, 4);

    while(fila->numItens){
        item = removeItemDaFila(fila);
        printf("item do fim da fila: %d\n", item);
    }


    return 0;
}