#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permutador(int *cidades, int inicio, int N, int T, int M[T][T], int *menor_custo, int *percurso);
void matriz_aleatoria(int T, int matriz[T][T]);
void prepara_cidades(int *cidades, int *N, int partida);
void imprime_resultados(FILE *arquivo, int cidades[], int N, int T, int M[T][T], int menor_custo, int percurso[], double elapsed_time);

void por_matriz_aleatoria(){
    clock_t start_time, end_time;
    double elapsed_time;
    start_time = clock();

    FILE *arquivo;

    int N, T; // T é pro vetor e N pro array
    char nome_aquivo[50];

    printf("Qual o tamanho da matriz? ");
    scanf("%i", &N);

    sprintf(nome_aquivo, "saidas_aleatorias/aleatoria_%ix%i.txt", N, N);
    arquivo = fopen(nome_aquivo, "w");

    if (arquivo == NULL) printf("Erro ao abrir o arquivo.");
    
    T = N;
    int M[T][T];
    matriz_aleatoria(T, M);

    // Ponto de partida com as matriculas
    int partida = ((4+0+0+5) + (5+7+9+5) + (5+3+7+8)) % N;
    //printf("\nPartida = %i", partida);

    // Preparando o vetor cidades
    int cidades[N+1];
    prepara_cidades(cidades, &N, partida);

    int menor_custo = 99999;
    int percurso[N+1];

    permutador(cidades, 0, N, T, M, &menor_custo, percurso);
    
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    imprime_resultados(arquivo, cidades, N, T, M, menor_custo, percurso, elapsed_time);

    fclose(arquivo);
}