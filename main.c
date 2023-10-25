#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b);
void permutador(int cidades[], int inicio, int N, int M[][N]);
void matriz_aleatoria(int N, int matriz[N][N]);

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

        // Ponto de partida com as matriculas
        int partida = (4005 + 5795 + 5378) % N;
        printf("Partida = %i\n", partida);

        // Preparando o vetor cidades
        int cidades[N];
        for (int i = 0; i < N; i++) cidades[i] = i;

        // Removendo o valor de partida do vetor cidades
        for (int i = 0; i < N; i++){
            if (cidades[i] == partida){

                for (int j = i; j < N - 1; j++){
                    cidades[j] = cidades[j + 1];
                }
                N--; // Reduz o tamanho do vetor cidades, mas será que precisa mesmo?
                break; // Sai do loop
            }
        }

        // Colocando a partida na primeira e na última posição
        N = N+2;
        for (int i = N - 1; i >= 1; i--) {
            cidades[i] = cidades[i - 1];
        }
        cidades[0] = partida;
        cidades[N - 1] = partida;

        printf("Cidades: ");
        for (int i = 0; i < N; i++){
            printf("%i ", cidades[i]);
        }
        printf("\n");

        permutador(cidades, 0, N, M);
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
void permutador(int cidades[], int inicio, int N, int M[N][N]){

    if (inicio+1 == N-1) {
        for (int i = 0; i < N; i++) {
            printf("%i ", cidades[i]);
        }
        printf("\n");

    } else {
        for (int i = inicio+1; i < N-1; i++) {
            trocar(&cidades[inicio+1], &cidades[i]);
            permutador(cidades, inicio+1, N, M);
            trocar(&cidades[inicio+1], &cidades[i]);
        }
    }
}

void calcula_custo(int cidades[], int N, int M[N][N]){

}

void matriz_aleatoria(int N, int matriz[N][N]){

    srand(time(NULL));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            if (i == j) matriz[i][j] = 0;
            else matriz[i][j] = rand() % 10;
        }
    }
/*
    printf("Matriz aleatória:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            printf("%.2i|", matriz[i][j]);
        }
        printf("\n");
    }
*/
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