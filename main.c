#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void por_arquivo();
void por_matriz_aleatoria();

int main(){

    printf("1 - Matriz aleatoria\n2 - Ler arquivo\nEscolha: ");
    int aux;
    scanf("%i", &aux);

    if (aux == 1){
        por_matriz_aleatoria();

    }else if (aux == 2){
        por_arquivo();

    }else{
        printf("\nOpção inválida\n");
    }
    
    return 0;
}