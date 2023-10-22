#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b);
void permutador(int cidades[],int inicio, int N);
void matriz_aleatoria(int N);

int main(){

    int N=5;
    int M[N][N];
    int aux;

    // Preparando o vetor cidades
    int cidades[N];
    for (int i = 0; i < N; i++) cidades[i] = i+1;
    

    printf("1 - Matriz aleatoria\n2 - Ler arquivo\nChoose your path or die: ");
    scanf("%i", &aux);
    switch (aux)
    {
    case 1:
        printf("Qual o tamanho da matriz? ");
        scanf("%i", &N);
        matriz_aleatoria(N);
        break;
    
    case 2:
        
        break;

    default:
        break;
    }

    permutador(cidades, 0, N);

    return 0;
}

// Função para trocar dois elementos em um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para gerar permutações recursivamente
void permutador(int elementos[], int inicio, int N) {
    if (inicio == N) {
        for (int i = 0; i < N; i++) {
            printf("%i ", elementos[i]);
        }
        printf("\n");
    } else {
        for (int i = inicio; i < N; i++) {
            trocar(&elementos[inicio], &elementos[i]);
            permutador(elementos, inicio + 1, N);
            trocar(&elementos[inicio], &elementos[i]);
        }
    }
}

void matriz_aleatoria(int N){

    srand(time(NULL));
    int matriz[N][N];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            if (i == j) matriz[i][j] = 0;
            else matriz[i][j] = rand() % 100;
        }
    }

    printf("Matriz aleatória\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            printf("%.2i|", matriz[i][j]);
        }
        printf("\n");
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