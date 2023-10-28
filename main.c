#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b);
void permutador(int *cidades, int inicio, int N, int T, int M[T][T], int *menor_custo, int *percurso);
void matriz_aleatoria(int T, int matriz[T][T]);
void prepara_cidades(int *cidades, int *N, int partida);
void imprime_resultados(FILE *arquivo, int cidades[], int N, int T, int M[T][T], int menor_custo, int percurso[], double elapsed_time);
void por_matriz_aleatoria(FILE *arquivo);
void por_arquivo(FILE *arquivo);

int main(){
    FILE *arquivo;

    printf("1 - Matriz aleatoria\n2 - Ler arquivo\nChoose your path or die: ");
    int aux;
    scanf("%i", &aux);

    if (aux == 1){
        por_matriz_aleatoria(arquivo);

    }else if (aux == 2){
        por_arquivo(arquivo);

    }else{
        printf("\nOpção inválida\n");
    }
    
    return 0;
}