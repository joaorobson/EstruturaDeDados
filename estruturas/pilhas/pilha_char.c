#include <stdio.h>
#include <stdlib.h>



typedef struct pilha {
    int topo;
    int capacidade;
    char *itens;
} Pilha;

void inicializaPilha(Pilha *p, int capacidade){
    printf("inicializando pilha...\n");
    p->topo = -1;
    p->capacidade = capacidade;
    p->itens = (char*) malloc(capacidade * sizeof(char));
}

int insereItemNaPilha(Pilha *p, char item){
    printf("item a ser inserido: %c\n", item);
    if(p->topo == p->capacidade - 1){ // checa se pilha já está cheia
        return -1;
    }
    p->topo++;
    p->itens[p->topo] = item;
    return 1;
}

char removeItemDaPilha(Pilha *p){
    if(p->topo < 0){ // checa se pilha não está vazia
        return -1;
    }

    char item = p->itens[p->topo];
    p->topo--;
    return item;
}

int main(){
    Pilha* pilha;
    pilha = (Pilha*) malloc(sizeof(Pilha));
    int item, i = 0;
    char stringInvertida[10];

    inicializaPilha(pilha, 10);
    insereItemNaPilha(pilha, 'a');
    insereItemNaPilha(pilha, 'b');
    insereItemNaPilha(pilha, 'c');
    insereItemNaPilha(pilha, 'd');
    insereItemNaPilha(pilha, 'e');
    insereItemNaPilha(pilha, 'f');

    // a pilha armazena os itens na ordem de inserção
    // no vetor de itens
    printf("string armazenada na pilha: %s\n", pilha->itens);

    // somente a função de remoção que retorna os itens
    // na ordem inversa
    while(pilha->topo >= 0){
        item = removeItemDaPilha(pilha);
        stringInvertida[i] = item;
        i++;
        printf("item do topo da pilha: %c\n", item);
    }
    
    stringInvertida[i] = '\0';
    printf("string removida invertida da pilha: %s\n", stringInvertida);


    return 0;
}