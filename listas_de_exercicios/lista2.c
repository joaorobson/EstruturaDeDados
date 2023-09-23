#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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


int buscaSequencialPorNome(ListaAlunos* listaAlunos, char* nome){
    int posicao = 0;

    while(posicao < listaAlunos->numElem){
        if(strcmp(listaAlunos->alunos[posicao].nome, nome) == 0){
            return posicao;
        }
        posicao++;
    }
    return -1;
}
int buscaSequencialPorNomeComSentinela(ListaAlunos* listaAlunos, char* nome){
    int posicao = 0;

    strcpy(listaAlunos->alunos[listaAlunos->numElem].nome, nome); // sentinela

    while(strcmp(listaAlunos->alunos[posicao].nome, nome) != 0){
        posicao++;
    }
    
    strcpy(listaAlunos->alunos[listaAlunos->numElem].nome, "");

    if(posicao == listaAlunos->numElem){
        return -1;
    }

    return posicao;
}

int buscaSequencialPorMatricula(ListaAlunos* listaAlunos, int matricula){
    int posicao = 0;

    while(posicao < listaAlunos->numElem){
        if(listaAlunos->alunos[posicao].matricula == matricula){
            return posicao;
        }
        posicao++;
    }
    return -1;
}

int buscaBinariaPorNome(ListaAlunos *listaAlunos, char* nome){
    int esq, dir, meio;
    esq = 0;
    dir = listaAlunos->numElem - 1;
    
    while(esq <= dir){ // tenho só 1 elemento na lista
        meio = (esq + dir)/2;
        if(strcmp(listaAlunos->alunos[meio].nome, nome) == 0){
            return meio;
        } else {
            if(strcmp(listaAlunos->alunos[meio].nome, nome) < 0){ // se nome tiver a direita do nome do meio
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }
    }
    return -1;

}


void preencheAluno(Aluno* ptrAluno, 
                   int matricula,
                   float nota,
                   char* nome){
    (*ptrAluno).matricula = matricula;
    (*ptrAluno).nota = nota;
    strcpy((*ptrAluno).nome, nome);
}

void inicializaLista(ListaAlunos* listaAlunos){
    listaAlunos->numElem = 0;
}

void exibeLista(ListaAlunos* listaAlunos){
    int index;
    printf("Exibindo lista...\n");
    for(index = 0; index < listaAlunos->numElem;index++){
        printf("Aluno %d\n", index);
        printf("Nome: %s\n", listaAlunos->alunos[index].nome);
        printf("Matricula: %d\n", listaAlunos->alunos[index].matricula);
        printf("Nota: %.1f\n", listaAlunos->alunos[index].nota);
    }
}

bool insereAlunoNaListaOrdenada(ListaAlunos* listaAlunos, 
                                Aluno aluno){
    if(buscaSequencialPorMatricula(listaAlunos, aluno.matricula) >= 0){
        printf("Insercao invalida! Ja existe aluno com a matricula %d na lista!!!\n", aluno.matricula);
        return false;
    }
    printf("Inserindo %s na lista de alunos de forma ordenada...\n", aluno.nome);

    int posicao = listaAlunos->numElem;
    while(posicao > 0 && strcmp(listaAlunos->alunos[posicao - 1].nome, aluno.nome) > 0){
        listaAlunos->alunos[posicao] = listaAlunos->alunos[posicao - 1];
        posicao--;
    }
    listaAlunos->alunos[posicao].matricula = aluno.matricula;
    listaAlunos->alunos[posicao].nota = aluno.nota;
    strcpy(listaAlunos->alunos[posicao].nome, aluno.nome);
    listaAlunos->numElem++;

    return true;
}



bool insereAlunoNaLista(ListaAlunos* listaAlunos, 
                        Aluno aluno,
                        int posicao){
    if((listaAlunos->numElem >= MAXSIZE) || 
       (posicao < 0) || 
       (posicao > MAXSIZE) ||
       (posicao > listaAlunos->numElem)){
        printf("Insercao em posicao invalida!!!\n");
        return false;
    }
    if(buscaSequencialPorMatricula(listaAlunos, aluno.matricula) >= 0){
        printf("Insercao invalida! Ja existe aluno com a matricula %d na lista!!!\n", aluno.matricula);
        return false;
    }

    printf("Inserindo %s na lista de alunos...\n", aluno.nome);
    int index;
    for(index = listaAlunos->numElem; index > posicao;index--){
        listaAlunos->alunos[index] = listaAlunos->alunos[index-1];
    }
    listaAlunos->alunos[posicao] = aluno;
    listaAlunos->numElem++;
    return true;
}

bool excluiElementoDaLista(ListaAlunos* listaAlunos, int posicao){
    if((listaAlunos->numElem >= MAXSIZE) || 
       (posicao < 0) || 
       (posicao > MAXSIZE) ||
       (posicao > listaAlunos->numElem)){
        printf("Exclusao em posicao invalida!!!\n");
        return false;
    }

    int index;
    for(index = posicao; index < listaAlunos->numElem - 1;index++){
        listaAlunos->alunos[index] = listaAlunos->alunos[index+1];
    }

    listaAlunos->alunos[index].matricula = -1;
    listaAlunos->alunos[index].nota = -1;
    strcpy(listaAlunos->alunos[index].nome, "");

    listaAlunos->numElem--;
    return true;
}


char* retornaEnesimoAluno(ListaAlunos* listaAlunos, int posicao){
    if(posicao < 0 || posicao >= listaAlunos->numElem){
        printf("Posicao invalida!!!\n");
        return "";
    }

    return listaAlunos->alunos[posicao].nome;
}


int main(){

    ListaAlunos listaAlunos;
    inicializaLista(&listaAlunos);

    Aluno aluno0, aluno1, aluno2, aluno3, aluno4;
    preencheAluno(&aluno0, 15424242, 9.5, "Joao");
    preencheAluno(&aluno1, 10101011, 10, "Ana");
    preencheAluno(&aluno2, 22222222, 7, "Bia");
    preencheAluno(&aluno3, 00000000, 7.5, "Gabriel");
    preencheAluno(&aluno4, 33333333, 7, "Arthur");
    
    insereAlunoNaListaOrdenada(&listaAlunos, aluno0);
    insereAlunoNaListaOrdenada(&listaAlunos, aluno1);
    insereAlunoNaListaOrdenada(&listaAlunos, aluno2);
    insereAlunoNaListaOrdenada(&listaAlunos, aluno3);
    insereAlunoNaListaOrdenada(&listaAlunos, aluno4);
    insereAlunoNaListaOrdenada(&listaAlunos, aluno2);

    printf("=============== Lista ordenada =======================\n");
    exibeLista(&listaAlunos);
    printf("======================================================\n\n\n");

    printf("Buscando por \"Maria\" usando sentinela...\n");
    int posicao = buscaSequencialPorNomeComSentinela(&listaAlunos, "Maria");
    printf("Posicao de \"Maria\": %d\n", posicao);

    posicao = buscaSequencialPorMatricula(&listaAlunos, 15424242);
    printf("Posicao de \"Joao\": %d\n", posicao);

    printf("Nome do aluno na posicao %d: %s\n", 2, retornaEnesimoAluno(&listaAlunos, 2));

    printf("Excluindo elemento.............\n");
    excluiElementoDaLista(&listaAlunos, 1);
    printf("========== Lista sem elemento da posicao 1 ===========\n");
    exibeLista(&listaAlunos);
    printf("======================================================\n");

    return 0;
}