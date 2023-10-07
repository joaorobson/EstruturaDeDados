#include <stdio.h>
#include <stdlib.h>

void imprimeLista(int lista[], int lenLista){
    for(int i = 0; i < lenLista;i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}


int main(){
    int vetor[10] = {7, 5, 2, 1, 3, 6, 8, 10, 9, 4};
    int lenVetor = sizeof(vetor)/sizeof(vetor[0]);

    printf("Vetor inicial: ");
    imprimeLista(vetor, lenVetor);
    printf("==============================\n");
    for(int index = 0;index < lenVetor;index++){
        int valorAtual = vetor[index];
        int posicao = index;
        printf("Ordenando vetor[%d] = %d:\n", index, vetor[index]);

        while(posicao > 0 && valorAtual < vetor[posicao - 1]){
            imprimeLista(vetor, lenVetor);
            vetor[posicao] = vetor[posicao - 1];
            vetor[posicao - 1] = valorAtual;
            posicao--;
        }
        vetor[posicao] = valorAtual;
        imprimeLista(vetor, lenVetor);
        
    }
    imprimeLista(vetor, lenVetor);
    return 0;
}