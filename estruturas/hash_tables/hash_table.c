#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[50];
} Aluno;

void inicializaHashTable(Aluno* alunos){
    for(int i = 0;i < 50;i++){
        alunos[i].matricula = -1;
    }
}

int geraHash(int matricula){
    return matricula % 50;
}

Aluno inicializaAluno(){
    Aluno aluno;
    printf("Insira a matricula do aluno: ");
    scanf("%d", &aluno.matricula);
    printf("Insira o nome do aluno: ");
    fflush(stdin);
    fgets(aluno.nome, 50, stdin);

    return aluno;
}

void insereAlunos(Aluno *alunos, int numAlunos){
    for(int i = 0;i < numAlunos;i++){
        Aluno aluno = inicializaAluno();
        int index = geraHash(aluno.matricula);
        printf("hash gerada: %d\n", index);
        while(alunos[index].matricula != -1){ // matricula já foi preenchida
            index = geraHash(aluno.matricula + 1);
            printf("hash gerada: %d\n", index);
        }
        alunos[index] = aluno;
    }
}

void insereAluno(Aluno *alunos, Aluno aluno){
    int index = geraHash(aluno.matricula);
    while(alunos[index].matricula != -1){ // matricula já foi preenchida
        index = geraHash(aluno.matricula + 1);
    }
    alunos[index] = aluno;
    
}


char* buscaPorAluno(Aluno* alunos, int matricula){
    int index = geraHash(matricula);
    while(alunos[index].matricula != -1){
        if(matricula == alunos[index].matricula){
            return alunos[index].nome;
        }
        index = geraHash(matricula + 1);
    }
    return "";
}

void removeAluno(Aluno* alunos, int matricula){
    int index = geraHash(matricula);
    while(alunos[index].matricula != -1){
        if(matricula == alunos[index].matricula){
            alunos[index].matricula = -1;
            strcpy(alunos[index].nome, "");
            break;
        }
        index = geraHash(matricula + 1);
    }
}

void exibeAlunos(Aluno* alunos){
    for(int i = 0;i < 50;i++){
        if(alunos[i].matricula != -1){
            printf("matricula: %d\n", alunos[i].matricula);
            printf("nome: %s\n", alunos[i].nome);
            printf("================================\n");
        }
    }
}

int main(){
    Aluno alunos[50];
    inicializaHashTable(alunos);
    //insereAlunos(alunos, 3);
    Aluno a1 = {50, "joao"};
    Aluno a2 = {100, "maria"};
    Aluno a3 = {42, "jose"};

    insereAluno(alunos, a1);
    insereAluno(alunos, a2);
    insereAluno(alunos, a3);
    exibeAlunos(alunos);
    char nome[50];

    strcpy(nome, buscaPorAluno(alunos, 50));
    printf("aluno com matricula 50: %s\n", nome);

    strcpy(nome, buscaPorAluno(alunos, 100));
    printf("aluno com matricula 100: %s\n", nome);

    strcpy(nome, buscaPorAluno(alunos, 42));
    printf("aluno com matricula 42: %s\n", nome);
    
    strcpy(nome, buscaPorAluno(alunos, 1));
    printf("aluno com matricula 1: %s\n", nome);

    removeAluno(alunos, 100);
    strcpy(nome, buscaPorAluno(alunos, 100));
    printf("aluno com matricula 100: %s\n", nome);

    return 0;
}