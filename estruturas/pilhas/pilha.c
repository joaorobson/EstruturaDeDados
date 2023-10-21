#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int topo;
    int capacidade;
    int *itens;
} Pilha;

void inicializaPilha(Pilha *p, int capacidade){
    p->topo = -1;
    p->capacidade = capacidade;
    p->itens = (int*) malloc(capacidade * sizeof(int));
}

int insereItemNaPilha(Pilha *p, int item){
    if(p->topo == p->capacidade - 1){ // checa se pilha já está cheia
        return -1;
    }
    p->topo++;
    p->itens[p->topo] = item;
    return 1;
}

int removeItemDaPilha(Pilha *p){
    if(p->topo < 0){ // checa se pilha não está vazia
        return -1;
    }

    int item = p->itens[p->topo];
    p->topo--;
    return item;
}

int main(){
    Pilha* pilha;
    pilha = (Pilha*) malloc(sizeof(Pilha));
    int item;

    inicializaPilha(pilha, 10);
    insereItemNaPilha(pilha, 1);
    insereItemNaPilha(pilha, 2);
    insereItemNaPilha(pilha, 3);
    insereItemNaPilha(pilha, 4);
    
    while(pilha->topo >= 0){
        item = removeItemDaPilha(pilha);
        printf("item do topo da pilha: %d\n", item);
    }
    
    return 0;
}