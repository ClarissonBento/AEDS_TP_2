#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos em um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para gerar permutações recursivamente
void permutador(int *cidades, int inicio, int N, int T, int M[T][T], int *menor_custo, int *percurso){
    
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

    //printf("\nCidades: ");
    //for (int i = 0; i < (*N); i++) printf("%i ", cidades[i]);
    //printf("\n\n");
}

void imprime_resultados(FILE *arquivo, int cidades[], int N, int T, int M[T][T], int menor_custo, int percurso[], double elapsed_time){

    // Printando no terminal
    //-----------------------------------------------------------------------------------------------
    printf("\nMatriz:\n");
    for (int i = 0; i < T; i++){
        for (int j = 0; j < T; j++){
            printf("%i ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n"); 

    printf("Menor custo = %i\n", menor_custo);
    printf("Percurso feito = [ ");
    for (int i = 0; i < N; i++) printf("%i ", percurso[i]);
    printf("]\n");

    printf("Tempo de execução: %f segundos\n", elapsed_time);
    //------------------------------------------------------------------------------------------------

    // Pritando no arquivo
    //------------------------------------------------------------------------------------------------
    fprintf(arquivo, "Para N = %i\n", N-1);
    fprintf(arquivo, "Menor custo = %i\n", menor_custo);
    fprintf(arquivo, "Percurso feito = [ ");
    for (int i = 0; i < N; i++) {
        fprintf(arquivo, "%i ", percurso[i]);
    }
    fprintf(arquivo, "]\n");
    fprintf(arquivo, "Tempo de execução: %f segundos\n", elapsed_time);

    fprintf(arquivo, "\nMatriz:\n");
    for (int i = 0; i < T; i++){
        for (int j = 0; j < T; j++){
            fprintf(arquivo, "%i ", M[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fprintf(arquivo, "\nFormato alternativo para fins de checagem dos calculos\n");
    for (int i = 0; i < T; i++){
        for (int j = 0; j < T; j++){
            fprintf(arquivo, "Posição[%i][%i] = %i   ", i, j, M[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    //------------------------------------------------------------------------------------------------
}

// Função pra gerar uma matriz aleatória
void matriz_aleatoria(int T, int matriz[T][T]){
    srand(time(NULL));

    for (int i = 0; i < T; i++){
        for (int j = 0; j < T; j++)
        {
            if (i == j) matriz[i][j] = 0;
            else matriz[i][j] = (rand() % 9) + 1;
        }
    }
}