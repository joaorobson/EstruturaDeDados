#include <stdio.h>

int len(int vetor[]){
    return sizeof(vetor)/sizeof(vetor[0]);
}

void imprimeLista(int lista[], int lenLista){
    for(int i = 0; i < lenLista;i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int particao(int vetor[], int esq, int dir){
    int pivo = vetor[(esq+dir)/2]; // pivô é elemento do meio da partição

    int indexEsq = esq - 1;
    int indexDir = dir + 1;

    while(1){
        // procura elemento a esquerda que é maior que pivô
        do{
            indexEsq++;
        } while(vetor[indexEsq] < pivo);

        // procura elemento a direta que é menor que pivô
        do{
            indexDir--;
        } while(vetor[indexDir] > pivo);

        if(indexEsq >= indexDir){
            return indexDir;
        }

        // Faz o swap dos valores selecionados
        int aux = vetor[indexDir];
        vetor[indexDir] = vetor[indexEsq];
        vetor[indexEsq] = aux;
    }
}


void quicksort(int vetor[], int esq, int dir){

    if(esq >= 0 && dir >= 0 && esq < dir){
        printf("======= executando quicksort ========\n");
        imprimeLista(vetor, dir - esq + 1);
        printf("==================================\n");
        int pivo = particao(vetor, esq, dir);
        printf("pivo selecionado: %d\n", pivo);
        printf("Ordenando elementos a esquerda de %d\n", pivo);
        quicksort(vetor, esq, pivo); // ordenar elementos a esquerda de p
        printf("Ordenando elementos a direita de %d\n", pivo);
        quicksort(vetor, pivo + 1, dir); // orderna elementos a direita de p
    }
}

int main(){
    int vetor[10] = {7, 5, 2, 1, 3, 6, 8, 10, 9, 4};
    int N = sizeof(vetor)/sizeof(vetor[0]);

    quicksort(vetor, 0, 9);
    imprimeLista(vetor, N);


}