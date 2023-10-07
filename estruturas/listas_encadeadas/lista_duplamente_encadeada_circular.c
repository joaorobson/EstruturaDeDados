#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int valor;
    struct item* prox;
    struct item* ant;
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
    elem->ant = NULL;
    inicio = elem;
    fim = elem;
    return elem;
}

void exibeLista(Item* itemInicial){

    if(itemInicial == inicio){
        Item* itemAtual = inicio;

        while(itemAtual != NULL){
            printf("%d\n", itemAtual->valor);
            itemAtual = itemAtual->prox;
        }
    } else {
        Item* itemAtual = fim;

        while(itemAtual != NULL){
            printf("%d\n", itemAtual->valor);
            itemAtual = itemAtual->ant;
        }
    }
   
}

// adiciona elemento ao fim da lista
void adicionaElemento(int valor){
    Item* elem = (Item*) malloc(sizeof(Item));

    if(elem == NULL){
        printf("Erro ao alocar item!!!\n");
    }

    elem->valor = valor;
    elem->prox = inicio; // ponteiro para prox. do último elemento aponta pro começo da lista
    elem->ant = fim;
    fim->prox = elem;
    fim = elem;
    inicio->ant = fim; // ponteiro para ant. do primeiro elemento aponta pro fim da lista
}

int buscaPorElemento(int valor){
    Item* itemAtual = inicio;
    int ix = 0;
    while(1){
        if(itemAtual->valor == valor){
            printf("Elemento com valor %d encontrado!\n", valor);
            return ix;
        }
        itemAtual = itemAtual->prox;
        if(itemAtual == inicio){
            break;
        }
        ix++;
    }
    return -1;
}



int removeElemento(int valor){
    Item* itemAtual = inicio;
    Item* itemAnterior = NULL;
    while(1){
        if(itemAtual->valor == valor){
            printf("Elemento com valor %d encontrado! Removendo elemento...\n", valor);
            if(itemAtual == inicio){ // removendo primeiro elemento
                inicio = itemAtual->prox; // atualizar ponteiro para início da lista
                inicio->ant = NULL;
                itemAtual->prox = NULL;
            } else if(itemAtual == fim){ // removendo último elemento
                itemAtual->ant = NULL;
                itemAnterior->prox = NULL; // atualizar ponteiro para fim da lista
                fim = itemAnterior;
            } else {
                itemAnterior->prox = itemAtual->prox;
                itemAtual->prox->ant = itemAnterior;
                itemAtual->prox = NULL;
            }
            free(itemAtual);
            break;
        }
        itemAnterior = itemAtual;
        itemAtual = itemAtual->prox;
        if(itemAtual == inicio){
            break;
        }
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
    printf("Exibindo lista na ordem de insercao:\n");
    exibeLista(inicio);

    printf("Exibindo lista de tras para frente:\n");
    exibeLista(fim);


    printf("Tamanho da lista apos as adicoes: %d\n", tamanhoLista());

    removeElemento(2);

    exibeLista(inicio);
    printf("Tamanho da lista apos remocao: %d\n", tamanhoLista());

    int ixElem = buscaPorElemento(5);
    printf("Indice do elemento 21: %d\n", ixElem);
    
    return 0;
}