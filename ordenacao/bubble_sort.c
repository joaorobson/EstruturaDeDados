#include <stdio.h>

void imprimeLista(int lista[], int lenLista){
    for(int i = 0; i < lenLista;i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main(){
    //int vetor[10] = {7, 5, 2, 1, 3, 6, 8, 10, 9, 4};

    int vetor[10] = {1, 2, 5, 6, 3, 4, 7, 8, 9, 10};

    int N = sizeof(vetor)/sizeof(vetor[0]);
    int teveTroca = 0;

    printf("Vetor inicial: ");
    imprimeLista(vetor, N);
    printf("==============================\n");

    // percorre os elementos do vetor N vezes
    for(int numElem = 0;numElem < N;numElem++){
        printf("Passo %d:\n", numElem + 1);
        for(int j = 0;j < N - numElem - 1;j++){
            // checa se é preciso realizar troca dos elementos
            if(vetor[j] > vetor[j+1]){
                teveTroca = 1;
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
            imprimeLista(vetor, N);
        }
        // se não tiver troca, vetor já está ordenado
        if(teveTroca == 0){
            printf("Vetor ja ordenado!\n");
            break;
        }
        teveTroca = 0;
    }
    imprimeLista(vetor, N);


    return 0;
}