#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b);
void permutador(int cidades[], int inicio, int N, int M[][N], int partida);
void matriz_aleatoria(int N, int matriz[][N]);

int main(){
    int N;

    printf("1 - Matriz aleatoria\n2 - Ler arquivo\nChoose your path or die: ");
    int aux;
    scanf("%i", &aux);

    if (aux == 1){
        printf("Qual o tamanho da matriz? ");
        scanf("%i", &N);

        int M[N][N];
        matriz_aleatoria(N, M);

        printf("Matriz aleatória:\n");
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
            {
                printf("%.2i|", M[i][j]);
            }
            printf("\n");
        }

        // Preparando o vetor cidades
        int cidades[N];
        for (int i = 0; i < N; i++) cidades[i] = i+1;

        // Ponto de partica com a matricula 4005
        int partida = (4+0+0+5)%N;
        printf("Partida = %i\n", partida);

        permutador(cidades, 0, N, M, partida);

    }

    return 0;
}

// Função para trocar dois elementos em um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para gerar permutações recursivamente
void permutador(int cidades[], int inicio, int N, int M[][N], int partida) {
    if (inicio == N) {
        int custo = 0;
        int atual = partida;

        for (int i = 0; i < N; i++) {
            custo = custo + M[atual][cidades[i]];
            atual = cidades[i];
            printf("%i ", cidades[i]);
        }
        printf("Custo = %i\n", custo);
    } else {
        for (int i = inicio; i < N; i++) {
            trocar(&cidades[inicio], &cidades[i]);
            permutador(cidades, inicio + 1, N, M, partida);
            trocar(&cidades[inicio], &cidades[i]);
        }
    }
}

void matriz_aleatoria(int N, int matriz[][N]){

    srand(time(NULL));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            if (i == j) matriz[i][j] = 0;
            else matriz[i][j] = rand() % 100;
        }
    }
}

/*
void ler_Matriz(const char *nomeArquivo, int ***matriz, int *N) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lenndo o tamanho da matriz na primeira linha do arquvio
    if (fscanf(arquivo, "%i", N) != 1) {
        printf("Erro ao ler o tamanho da matriz do arquivo.\n");
        fclose(arquivo);
        exit(1);
    }

    // Declara a matriz
    int matriz[*N][*N];

    // Lê os valores da matriz a partir das linhas seguintes do arquivo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fscanf(arquivo, "%i", &(*matriz)[i][j]) != 1) {
                printf("Erro ao ler os valores da matriz do arquivo.\n");
                fclose(arquivo);
                exit(1);
            }
        }
    }

    // Fecha o arquivo após a leitura
    fclose(arquivo);
}
*/