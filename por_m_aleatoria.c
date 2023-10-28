#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b);
void permutador(int cidades[], int inicio, int N, int T, int M[T][T], int *menor_custo, int *percurso);
void matriz_aleatoria(int T, int matriz[T][T]);
void prepara_cidades(int *cidades, int *N, int partida);
void imprime_resultados(FILE *arquivo, int cidades[], int N, int T, int M[T][T], int menor_custo, int percurso[]);
void por_matriz_aleatoria(FILE *arquivo);

void por_matriz_aleatoria(FILE *arquivo){

    int N, T; // T é pro vetor e N pro array
    char nome_aquivo[50];

    printf("Qual o tamanho da matriz? ");
    scanf("%i", &N);

    sprintf(nome_aquivo, "aleatoria_%ix%i.txt", N, N);
    arquivo = fopen(nome_aquivo, "w");

    if (arquivo == NULL) printf("Erro ao abrir o arquivo.");
    
    T = N;
    int M[T][T];
    matriz_aleatoria(T, M);

    // Ponto de partida com as matriculas
    int partida = (4005 + 5795 + 5378) % N;
    //printf("\nPartida = %i", partida);

    // Preparando o vetor cidades
    int cidades[N+1];
    prepara_cidades(cidades, &N, partida);

    int menor_custo = 99999;
    int percurso[N];

    permutador(cidades, 0, N, T, M, &menor_custo, percurso);
    imprime_resultados(arquivo, cidades, N, T, M, menor_custo, percurso);

    fclose(arquivo);
}