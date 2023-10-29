#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permutador(int *cidades, int inicio, int N, int T, int M[T][T], int *menor_custo, int *percurso);
void matriz_aleatoria(int T, int matriz[T][T]);
void prepara_cidades(int *cidades, int *N, int partida);
void imprime_resultados(FILE *arquivo, int cidades[], int N, int T, int M[T][T], int menor_custo, int percurso[], double elapsed_time);

void por_arquivo() {
    clock_t start_time, end_time;
    double elapsed_time;
    start_time = clock();

    FILE *arquivo_Entrada, *arquivo_Saida;

    int N;

    arquivo_Entrada = fopen("teste_moodle.txt", "r");

    if (arquivo_Entrada == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lendo o tamanho da matriz na primeira linha do arquivo
    if (fscanf(arquivo_Entrada, "%i", &N) != 1) {
        printf("Erro ao ler o tamanho da matriz do arquivo.\n");
        fclose(arquivo_Entrada);
        exit(1);
    }

    int T; // T é pro vetor e N pro array
    T = N;
    printf("Teste 1: %i\n", N);

    // Declara a matriz
    int M[T][T];

    // Lê os valores da matriz a partir das linhas seguintes do arquivo
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            if (i == j) {
                M[i][j] = 0;
            } else {
                if (fscanf(arquivo_Entrada, "%i", &M[i][j]) != 1) {
                    printf("Erro ao ler os valores da matriz do arquivo.\n");
                    fclose(arquivo_Entrada);
                    exit(1);
                }
            }
        }
    }

    // Ponto de partida com as matriculas
    int partida = ((4+0+0+5) + (5+7+9+5) + (5+3+7+8)) % T;
    //printf("\nPartida = %i", partida);

    // Preparando o vetor cidades
    int cidades[N+1];
    prepara_cidades(cidades, &N, partida);

    printf("Teste 2: %i\n", N);

    int menor_custo = 99999;
    int percurso[N+1];

    permutador(cidades, 0, N, T, M, &menor_custo, percurso);
    
    char nome_saida[50];
    sprintf(nome_saida, "saidas_porArquivo/porArquivo_%ix%i.txt", T, T);
    arquivo_Saida = fopen(nome_saida, "w");

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    imprime_resultados(arquivo_Saida, cidades, N, T, M, menor_custo, percurso, elapsed_time);

    fclose(arquivo_Entrada);
    fclose(arquivo_Saida);
}