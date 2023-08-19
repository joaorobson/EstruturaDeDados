#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10


typedef struct Aluno {
    char nome[20];
    int matricula;
    float nota;
} Aluno;


typedef struct ListaAlunos {
    Aluno alunos[MAXSIZE];
    int numElem;
} ListaAlunos;


void preencheAluno(Aluno* ptrAluno, 
                   int matricula,
                   float nota,
                   char* nome){
    (*ptrAluno).matricula = matricula;
    (*ptrAluno).nota = nota;
    strcpy((*ptrAluno).nome, nome);
}

int main(){

    // Estática
    // Aluno aluno[10];

    // Dinâmica
    // 1
    //Aluno* aluno;
    //aluno = (Aluno*)malloc(10*sizeof(Aluno));
    //aluno[7].nome

    // 2
    Aluno* aluno[3];
    int i;
    char nome[20];
    int matricula;
    float nota;
    for(i = 0;i < 3;i++){
        aluno[i] = (Aluno*)malloc(sizeof(Aluno));
        printf("nome:");
        scanf("%s", &nome);
        printf("matricula:");
        scanf("%d", &matricula);
        printf("nota:");
        scanf("%f", &nota);
        preencheAluno(aluno[i], matricula, nota, nome);
    }
    
    for(i = 0;i < 3;i++){
        printf("nome: %s\n", aluno[i]->nome);
        printf("matricula: %d\n", aluno[i]->matricula);
        printf("nota: %f\n", aluno[i]->nota);
    }
    




    return 0;
}