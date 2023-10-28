#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b);
void permutador(int cidades[], int inicio, int N, int T, int M[T][T], int *menor_custo, int *percurso);
void matriz_aleatoria(int T, int matriz[T][T]);
void prepara_cidades(int *cidades, int *N, int partida);
void imprime_resultados(int cidades[], int N, int T, int M[T][T], int menor_custo, int percurso[]);

int main(){
    int N, T, aux; // T é pro vetor e N pro array
    int custo = 0, menor_custo = 99999;

    clock_t start_time, end_time;
    double elapsed_time;

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
        printf("\nPartida = %i", partida);

        // Preparando o vetor cidades
        int cidades[N+1];
        prepara_cidades(cidades, &N, partida);


        int menor_custo = 99999;
        int percurso[N];

        start_time = clock(); // Pra considerar apenas as permutações

        permutador(cidades, 0, N, T, M, &menor_custo, percurso);
        imprime_resultados(cidades, N, T, M, menor_custo, percurso);

        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        //elapsed_time = (double)(end_time - start_time);
        printf("Tempo de execução: %f segundos\n\n", elapsed_time);
    }

    return 0;
}

// Prepara o vetor de cidades, colocando a "partida" no primeiro e no ultimo elemento
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

    printf("\nCidades: ");
    for (int i = 0; i < (*N); i++) printf("%i ", cidades[i]);
    printf("\n\n");
}

void imprime_resultados(int cidades[], int N, int T, int M[T][T], int menor_custo, int percurso[]){

/*  printf("\nMatriz aleatória:\n");
    for (int i = 0; i < T; i++){
        for (int j = 0; j < T; j++){
            //printf("%i ", M[i][j]);
            printf("Posição[%i][%i] = %i\n", i, j, M[i][j]);
        }
        printf("\n");
    }
    printf("\n"); 
*/

    printf("\nMenor custo = %i\n", menor_custo);
    printf("Percurso feito = ");
    for (int i = 0; i < N; i++)
    {
        printf("%i ", percurso[i]);
    }
    printf("\n");
}

// Função para gerar permutações recursivamente
void permutador(int cidades[], int inicio, int N, int T, int M[T][T], int *menor_custo, int *percurso){
    
    if (inicio+1 == N-1) {
        for (int i = 0; i < N; i++) {
            printf("%i ", cidades[i]);
        }

        // Usando a matriz pra calcular o custo de cada rota/percuso
        int custo = 0;
        for (int i = 0; i < T; i++) {
            int cidade_atual = cidades[i];
            int proxima_cidade = cidades[i + 1];
            custo += M[cidade_atual][proxima_cidade];
        }

        // Aqui captura o menor custo e o seu percurso
        printf("| Custo = %i\n", custo);
        if (custo < (*menor_custo)){
            (*menor_custo) = custo;
            for (int  i = 0; i < N; i++) percurso[i] = cidades[i];
        }

    } else {
        for (int i = inicio+1; i < N-1; i++) {  // permutação go brr
            trocar(&cidades[inicio+1], &cidades[i]);
            permutador(cidades, inicio+1, N, T, M, menor_custo, percurso);
            trocar(&cidades[inicio+1], &cidades[i]);
        }
    }
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