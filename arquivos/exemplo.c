#include <stdio.h>

void removeLinhaDoArquivo(char* nomeArquivo, int linhaParaRemover){
    FILE* file = fopen(nomeArquivo, "r");
    FILE *tempFile = fopen("tmp.txt", "w");

    if(file == NULL){
        printf("Erro na abertura do arquivo!!!\n");
        exit(1);
    }
    char textoLinha[100];
    int linhaAtual = 1;
    while(1){
        fgets(textoLinha, 100, file);
        if(feof(file)){
            break;
        }
        if(linhaAtual != linhaParaRemover){
            fputs(textoLinha, tempFile);
        }
        linhaAtual++;
    }
    fclose(tempFile);
    fclose(file);
    remove(nomeArquivo);
    rename("tmp.txt", nomeArquivo);
}

void imprimeArquivo(char* nomeArquivo){
    FILE *file = fopen(nomeArquivo, "r");
    
    if(file == NULL){
        printf("Erro na abertura do arquivo!!!\n");
        exit(1);
    }
    char textoLinha[100];

    while(1){
        fgets(textoLinha, 100, file);

        if(feof(file)){
            printf("Fim do arquivo!!!\n");
            break;
        } 
        printf("%s", textoLinha);   
    }
    fclose(file);
}

void imprimeArquivoAPartirDoCaractereN(char* nomeArquivo, int charN){
    FILE *file = fopen(nomeArquivo, "r");
    char textoLinha[100];
    if(file == NULL){
        printf("Erro na abertura do arquivo!!!\n");
        exit(1);
    }

    fseek(file, charN, SEEK_SET); // lembre-se que cada linha tem os caracteres visíveis + 

    while(1){
        fgets(textoLinha, 100, file);

        if(feof(file)){
            printf("Fim do arquivo!!!\n");
            break;
        }
            printf("%s", textoLinha);
        
    }
    fclose(file);

}

void insereLinhaAoFinalDoArquivo(char* nomeArquivo, char* linha){
    FILE *file = fopen(nomeArquivo, "a");
    
    if(file == NULL){
        printf("Erro na abertura do arquivo!!!\n");
        exit(1);
    }
    fputs(linha, file);
    fclose(file);
}

int main(){
    char arquivo[100];
    strcpy(arquivo, "teste.txt");
    
    printf("Texto lido do arquivo:\n");
    imprimeArquivo(arquivo);
    imprimeArquivoAPartirDoCaractereN(arquivo, 5); 
    removeLinhaDoArquivo(arquivo, 2);
    imprimeArquivo(arquivo);

    return 0;
}