#include <stdio.h>

int main(){
    int num = 10;
    int* ptr = &num;
    printf("Valor de \"num\": %d\n", num);
    printf("Endereco de memoria de \"num\": %d\n", &num);
    printf("Valor de \"ptr\": %d\n", ptr);
    printf("Endereco de memoria de \"ptr\": %d\n", &ptr);
    printf("Valor da variavel para qual \"ptr\" aponta: %d\n", *ptr);
}