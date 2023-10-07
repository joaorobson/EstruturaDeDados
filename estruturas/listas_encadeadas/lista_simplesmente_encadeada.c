#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int valor;
    struct item* prox;
} Item;

Item* inicio;
Item* fim;

Item* inicializaLista(int valor){
    Item* elem = (Item*) malloc(sizeof(Item));

    if(elem == NULL){
        printf("Erro ao alocar item!!!\n");
    }

    elem->valor = valor;
    elem->prox = NULL;
    inicio = elem;
    fim = elem;
    return elem;
}

void exibeLista(){
    Item* itemAtual = inicio;

    while(itemAtual != NULL){
        printf("%d\n", itemAtual->valor);
        itemAtual = itemAtual->prox;
    }
}

// adiciona elemento ao fim da lista
void adicionaElemento(int valor){
    Item* elem = (Item*) malloc(sizeof(Item));

    if(elem == NULL){
        printf("Erro ao alocar item!!!\n");
    }

    elem->valor = valor;
    elem->prox = NULL;
    fim->prox = elem;
    fim = elem;
}

int buscaPorElemento(int valor){
    Item* itemAtual = inicio;
    int ix = 0;
    while(itemAtual != NULL){
        if(itemAtual->valor == valor){
            printf("Elemento com valor %d encontrado!\n", valor);
            return ix;
        }
        itemAtual = itemAtual->prox;
        ix++;
    }
    return -1;
}



int removeElemento(int valor){
    Item* itemAtual = inicio;
    Item* itemAnterior = NULL;
    while(itemAtual != NULL){
        if(itemAtual->valor == valor){
            printf("Elemento com valor %d encontrado! Removendo elemento...\n", valor);
            if(itemAtual == inicio){ // removendo primeiro elemento
                inicio = itemAtual->prox; // atualizar ponteiro para início da lista
                itemAtual->prox = NULL;
            } else if(itemAtual == fim){ // removendo último elemento
                itemAnterior->prox = NULL; // atualizar ponteiro para fim da lista
                fim = itemAnterior;
            } else {
                itemAnterior->prox = itemAtual->prox;
                itemAtual->prox = NULL;
            }
            free(itemAtual);
            break;
        }
        itemAnterior = itemAtual;
        itemAtual = itemAtual->prox;
    }
}


int tamanhoLista(){
    int tam = 0;
    Item* itemAtual = inicio;

    if(itemAtual == NULL){
        return 0;
    }

    while(itemAtual != NULL){
        tam++;
        itemAtual = itemAtual->prox;
    }

    return tam;
}


int main(){

    printf("Tamanho da lista inicialmente: %d\n", tamanhoLista());

    inicializaLista(0);
    adicionaElemento(1);
    adicionaElemento(1);
    adicionaElemento(2);
    adicionaElemento(3);
    adicionaElemento(5);
    exibeLista();

    printf("Tamanho da lista apos as adicoes: %d\n", tamanhoLista());

    removeElemento(2);
    exibeLista();
    printf("Tamanho da lista apos remocao: %d\n", tamanhoLista());

    int ixElem = buscaPorElemento(5);
    printf("Indice do elemento 21: %d\n", ixElem);
    
    return 0;
}