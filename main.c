#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b);
void permutador(int cidades[], int inicio, int N, int T, int M[T][T]);
void matriz_aleatoria(int T, int matriz[T][T]);
int calcula_custo(int cidades[], int T, int M[T][T]);
void prepara_cidades(int *cidades, int *N, int partida);

int main(){
    int N, T, aux; // T é pro vetor e N pro array
    int custo = 0;
    int menor_custo = 99999;

    printf("1 - Matriz aleatoria\n2 - Ler arquivo\nChoose your path or die: ");
    scanf("%i", &aux);

    if (aux == 1){
        printf("Qual o tamanho da matriz? ");
        scanf("%i", &N);
        T = N;

        int M[T][T];
        matriz_aleatoria(T, M);

        // Ponto de partida com as matriculas
        int partida = (4005 + 5795 + 5378) % N;
        printf("Partida = %i\n", partida);

        // Preparando o vetor cidades
        int cidades[N];
        prepara_cidades(cidades, &N, partida);
        
        printf("Cidades: ");
        for (int i = 0; i < N; i++){
            printf("%i ", cidades[i]);
        }
        printf("\n");

        printf("\nMatriz aleatória:\n");
        for (int i = 0; i < T; i++){
            for (int j = 0; j < T; j++){
                //printf("%i ", M[i][j]);
                printf("Posição[%i][%i] = %i\n", i, j, M[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        permutador(cidades, 0, N, T, M);
    }

    return 0;
}

// Depois eu explico
void prepara_cidades(int *cidades, int *N, int partida){

    for (int i = 0; i < (*N); i++) cidades[i] = i;

    // Removendo o valor de partida do vetor cidades
    for (int i = 0; i < (*N); i++){
        if (cidades[i] == partida){

            for (int j = i; j < (*N) - 1; j++){
                cidades[j] = cidades[j + 1];
            }
            (*N)--; // Reduz o tamanho do vetor cidades, mas será que precisa mesmo?
            break;
        }
    }

    // Colocando a partida na primeira e na última posição
    (*N) = (*N) + 2;
    for (int i = (*N) - 1; i >= 1; i--) {
        cidades[i] = cidades[i - 1];
    }
    cidades[0] = partida;
    cidades[(*N) - 1] = partida;
}

// Função para gerar permutações recursivamente
void permutador(int cidades[], int inicio, int N, int T, int M[T][T]){
    
    if (inicio+1 == N-1) {
        for (int i = 0; i < N; i++) {
            printf("%i ", cidades[i]);
        }
        calcula_custo(cidades, T, M);

    } else {
        for (int i = inicio+1; i < N-1; i++) {
            trocar(&cidades[inicio+1], &cidades[i]);
            permutador(cidades, inicio+1, N, T, M);
            trocar(&cidades[inicio+1], &cidades[i]);
        }
    }
}

int menor_custo = 9999;
int calcula_custo(int cidades[], int T, int M[T][T]){
    int custo = 0;

    for (int i = 0; i < T; i++) {
        int cidade_atual = cidades[i];
        int proxima_cidade = cidades[i + 1];
        custo += M[cidade_atual][proxima_cidade];
    }

    printf("Custo = %i\n", custo);
    if (custo < menor_custo) menor_custo = custo;
    printf("Menor custo = %i\n", menor_custo);

    return custo;
}

// Função para trocar dois elementos em um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função pra gerar uma matriz aleatória
void matriz_aleatoria(int T, int matriz[T][T]){
    srand(time(NULL));

    for (int i = 0; i < T; i++){
        for (int j = 0; j < T; j++)
        {
            if (i == j) matriz[i][j] = 0;
            else matriz[i][j] = rand() % 10;
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