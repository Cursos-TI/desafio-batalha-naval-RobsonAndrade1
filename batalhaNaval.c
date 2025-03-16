#include <stdio.h>

#define TAMANHO 10

// Função para inicializar o tabuleiro com água (0)
    void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;  // Inicializa com água
        }
    }
}
// Função para aplicar uma matriz de habilidade ao tabuleiro
    void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int matriz[5][5], int x, int y) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int posX = x + i - 2;
            int posY = y + j - 2;

            // Verifica se a posição ajustada está dentro dos limites do tabuleiro
            if (posX >= 0 && posX < TAMANHO && posY >= 0 && posY < TAMANHO && matriz[i][j] == 1) {
                tabuleiro[posX][posY] = 5; // Marca área de efeito
            }
        }
    }
}
// Função para exibir o tabuleiro no console
    void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

    int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Declara a matriz do tabuleiro
    inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro com água
    
    
    // Matriz da habilidade Cone (5x5)
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    // Matriz da habilidade Cruz (5x5)
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    
    // Matriz da habilidade Octaedro (5x5)
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
// Aplicando habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);  
    aplicarHabilidade(tabuleiro, cruz, 7, 2);  
    aplicarHabilidade(tabuleiro, octaedro, 3, 7); 

// Exibe o tabuleiro atualizado com as habilidades aplicadas
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

