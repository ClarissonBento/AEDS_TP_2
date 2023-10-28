#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b);
void permutador(int cidades[], int inicio, int N, int T, int M[T][T], int *menor_custo, int *percurso);
void matriz_aleatoria(int T, int matriz[T][T]);
void prepara_cidades(int *cidades, int *N, int partida);
void imprime_resultados(FILE *arquivo, int cidades[], int N, int T, int M[T][T], int menor_custo, int percurso[]);
void por_matriz_aleatoria(FILE *arquivo);

int main(){
    clock_t start_time, end_time;
    double elapsed_time;
    start_time = clock();

    FILE *arquivo;

    printf("1 - Matriz aleatoria\n2 - Ler arquivo\nChoose your path or die: ");
    int aux;
    scanf("%i", &aux);

    if (aux == 1){
        por_matriz_aleatoria(arquivo);
    }else if (aux == 2)
    {
        /* code */
    }else{
        printf("\nOpção inválida\n");
    }
    

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %f segundos\n\n", elapsed_time);

    return 0;
}