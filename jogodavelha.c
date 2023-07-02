#include <stdio.h>

// Função para exibir o tabuleiro
void exibir_tabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

// Função para verificar se há um vencedor
char verificar_vencedor(char tabuleiro[3][3]) {
    int i;

    // Verificar linhas
    for (i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
            return tabuleiro[i][0];
    }

    // Verificar colunas
    for (i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
            return tabuleiro[0][i];
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2])
        return tabuleiro[0][0];

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])
        return tabuleiro[0][2];

    // Se não houver vencedor
    return ' ';
}

int main() {
    char tabuleiro[3][3];
    int linha, coluna;
    int jogador = 1;
    char marca;
    char vencedor = ' ';
    int jogadas = 0;

    // Inicializar o tabuleiro
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            tabuleiro[linha][coluna] = ' ';
        }
    }

    // Loop principal do jogo
    while (vencedor == ' ' && jogadas < 9) {
        // Exibir o tabuleiro
        exibir_tabuleiro(tabuleiro);

        // Determinar a marca do jogador atual
        if (jogador == 1) {
            marca = 'X';
        } else {
            marca = 'O';
        }

        // Obter a jogada do jogador
        printf("Jogador %d, faça sua jogada (linha coluna): ", jogador);
        scanf("%d %d", &linha, &coluna);

        // Verificar se a jogada é válida
        if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        // Fazer a jogada
        tabuleiro[linha][coluna] = marca;
        jogadas++;

        // Verificar se há um vencedor
        vencedor = verificar_vencedor(tabuleiro);

        // Alternar para o próximo jogador
        jogador = (jogador == 1) ? 2 : 1;
    }

    // Exibir o resultado do jogo
    exibir_tabuleiro(tabuleiro);

    if (vencedor == 'X') {
        printf("Parabéns, Jogador 1 (X) venceu!\n");
    } else if (vencedor == 'O') {
        printf("Parabéns, Jogador 2 (O) venceu!\n");
    } else {
        printf("O jogo empatou!\n");
    }

    return 0;
}
