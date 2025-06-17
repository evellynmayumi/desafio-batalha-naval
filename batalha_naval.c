#include <stdio.h> 

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  "); // Espaço para alinhar com os números das colunas
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
}

/*
 * Função para posicionar um navio no tabuleiro.
 * Retorna 1 se o posicionamento foi bem-sucedido, 0 caso contrário (se houver colisão ou fora dos limites).
 * Parametros:
 * tabuleiro: A matriz do tabuleiro
 * linha_inicio: Coordenada da linha inicial do navio
 * coluna_inicio: Coordenada da coluna inicial do navio
 * orientacao: 0 para horizontal, 1 para vertical
 */
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                    int linha_inicio, int coluna_inicio, int orientacao) {

    // 1. Validação de Limites
    if (orientacao == 0) { // Horizontal
        // Verifica se o navio cabe horizontalmente
        if (coluna_inicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
            return 0; // Fora dos limites
        }
    } else { // Vertical
        // Verifica se o navio cabe verticalmente
        if (linha_inicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
            return 0; // Fora dos limites
        }
    }

    // 2. Validação de Sobreposição (antes de posicionar)
    // Percorre as posições que o navio ocuparia para verificar se já há algo (um 3)
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        if (orientacao == 0) { // Horizontal
            if (tabuleiro[linha_inicio][coluna_inicio + k] == 3) {
                printf("Erro: Sobreposição detectada para navio horizontal.\n");
                return 0; // Sobreposição
            }
        } else { // Vertical
            if (tabuleiro[linha_inicio + k][coluna_inicio] == 3) {
                printf("Erro: Sobreposição detectada para navio vertical.\n");
                return 0; // Sobreposição
            }
        }
    }

    // 3. Posicionamento do Navio (se as validações passarem)
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        if (orientacao == 0) { // Horizontal
            tabuleiro[linha_inicio][coluna_inicio + k] = 3; 
        } else { // Vertical
            tabuleiro[linha_inicio + k][coluna_inicio] = 3; 
        }
    }
    return 1; // Posicionamento bem-sucedido
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Declara a matriz do tabuleiro

    inicializarTabuleiro(tabuleiro);

    // Posicionamento dos Navios 
    int navio1_linha = 2;
    int navio1_coluna = 3;
    int navio1_orientacao = 0;

    int navio2_linha = 5; 
    int navio2_coluna = 2;
    int navio2_orientacao = 1; 

    
    printf("Tentando posicionar Navio 1 (Horizontal):\n");
    if (posicionarNavio(tabuleiro, navio1_linha, navio1_coluna, navio1_orientacao)) {
        printf("Navio 1 posicionado com sucesso!\n");
    } else {
        printf("Falha ao posicionar Navio 1.\n");
    }
    printf("\n");

    
    printf("Tentando posicionar Navio 2 (Vertical):\n");
    if (posicionarNavio(tabuleiro, navio2_linha, navio2_coluna, navio2_orientacao)) {
        printf("Navio 2 posicionado com sucesso!\n");
    } else {
        printf("Falha ao posicionar Navio 2.\n");
    }
    printf("\n"); 
    
    printf("--- Tabuleiro Final ---\n");
    exibirTabuleiro(tabuleiro);

    return 0; 
}