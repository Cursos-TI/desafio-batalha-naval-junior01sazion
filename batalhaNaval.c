#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define SUCESSO 1
#define FALHA 0

// Função para inicializar o tabuleiro com água
int inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    return SUCESSO;
}

// Função para verificar se um navio pode ser posicionado em uma determinada posição
int verificarPosicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, int orientacao) {
    if (orientacao == 0) { // Horizontal
        if (coluna + tamanho > TAMANHO_TABULEIRO) {
            return FALHA; // Fora dos limites
        }
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] == NAVIO) {
                return FALHA; // Sobreposição
            }
        }
    } else { // Vertical
        if (linha + tamanho > TAMANHO_TABULEIRO) {
            return FALHA; // Fora dos limites
        }
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                return FALHA; // Sobreposição
            }
        }
    }
    return SUCESSO; // Posição válida
}

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, int orientacao) {
    if (orientacao == 0) { // Horizontal
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else { // Vertical
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    return SUCESSO;
}

// Função para exibir o tabuleiro
int exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return SUCESSO;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int resultado;

    printf("Inicializando o tabuleiro...\n");
    resultado = inicializarTabuleiro(tabuleiro);
    if (resultado == SUCESSO) {
        printf("Tabuleiro inicializado com sucesso.\n");
    } else {
        printf("Erro ao inicializar o tabuleiro.\n");
        return 1; // Indica erro na execução
    }

    // Define as coordenadas iniciais e orientações dos navios
    int linhaNavio1 = 8;
    int colunaNavio1 = 9;
    int orientacaoNavio1 = 0; // 0 para horizontal, 1 para vertical

    int linhaNavio2 = 6;
    int colunaNavio2 = 1;
    int orientacaoNavio2 = 1; // 0 para horizontal, 1 para vertical

    printf("\nPosicionando navios...\n");

    // Posiciona o primeiro navio
    if (verificarPosicao(tabuleiro, linhaNavio1, colunaNavio1, TAMANHO_NAVIO, orientacaoNavio1) == SUCESSO) {
        resultado = posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, TAMANHO_NAVIO, orientacaoNavio1);
        if (resultado == SUCESSO) {
            printf("Navio 1 posicionado em (%d, %d) horizontalmente.\n", linhaNavio1, colunaNavio1);
        } else {
            printf("Erro ao posicionar o Navio 1 em (%d, %d) horizontalmente.\n", linhaNavio1, colunaNavio1);
        }
    } else {
        printf("Erro ao verificar a posição do Navio 1 em (%d, %d) horizontalmente. Posição inválida ou sobreposição.\n", linhaNavio1, colunaNavio1);
    }

    // Posiciona o segundo navio
    if (verificarPosicao(tabuleiro, linhaNavio2, colunaNavio2, TAMANHO_NAVIO, orientacaoNavio2) == SUCESSO) {
        resultado = posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, TAMANHO_NAVIO, orientacaoNavio2);
        if (resultado == SUCESSO) {
            printf("Navio 2 posicionado em (%d, %d) verticalmente.\n", linhaNavio2, colunaNavio2);
        } else {
            printf("Erro ao posicionar o Navio 2 em (%d, %d) verticalmente.\n", linhaNavio2, colunaNavio2);
        }
    } else {
        printf("Erro ao verificar a posição do Navio 2 em (%d, %d) verticalmente. Posição inválida ou sobreposição.\n", linhaNavio2, colunaNavio2);
    }

    printf("\nTabuleiro com os navios posicionados:\n");
    resultado = exibirTabuleiro(tabuleiro);
    if (resultado != SUCESSO) {
        printf("Erro ao exibir o tabuleiro.\n");
        return 1; // Indica erro na execução
    }

    return 0; // Indica execução bem-sucedida
}