#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
// Criando Tabuleiro (Matriz 10x10)
    int tabuleiro[10][10];
    
// Inicializando o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

// Posicionando navio horizontal (ocupa 3 posições)
    int navio_horizontal[3] = {2, 3, 4};  // Coloca o navio nas colunas 2, 3 e 4 na linha 2
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][navio_horizontal[i]] = 3;  // Marca as posições do navio com 3
    }

// Posicionando navio vertical (ocupa 3 posições)
    int navio_vertical[3] = {3, 4, 5};  // Coloca o navio nas linhas 3, 4 e 5 na coluna 7
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio_vertical[i]][7] = 3;  // Marca as posições do navio com 3
    }

// Posicionando navio diagonal (da esquerda superior para a direita inferior)
    int navio_diagonal1[3] = {2, 3, 4};  // Linha e coluna aumentam
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[navio_diagonal1[i]][navio_diagonal1[i] - 2] == 0) {
            tabuleiro[navio_diagonal1[i]][navio_diagonal1[i] - 2] = 3;  // Marca as posições do navio com 3
        }
    }

// Posicionando navio diagonal (da direita superior para a esquerda inferior)
    int navio_diagonal2[3] = {0, 1, 2};  // Linha aumenta e coluna diminui
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[navio_diagonal2[i]][9 - navio_diagonal2[i]] == 0) {
            tabuleiro[navio_diagonal2[i]][9 - navio_diagonal2[i]] = 3;  // Marca as posições do navio com 3
        }
    }

// Exibindo o tabuleiro
    printf("   ");  // Para alinhar as letras de A até J
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]);  // Imprime as letras de A a J
    }

    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);  // Imprime os números das linhas (1 a 10)
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);  // Imprime o valor de cada posição
        }

        printf("\n");
    }

    return 0;
}
