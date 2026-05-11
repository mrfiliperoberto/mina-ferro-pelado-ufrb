// Biblioteca padrão de entrada e saída
#include <stdio.h>

// Constantes do sistema: quantidade de graus e custo/salário por tonelada
#define NUM_GRAUS   5
#define SALARIO_POR_TONELADA 106.96f

// Estrutura para armazenar as informações de cada grau de minério
typedef struct {
    const char *nome;
    float valor;
    float faturamento;
    float lucro;
    float toneladas;
} Grau;

// Função para registrar a quantidade vendida de um pedido específico e atualizar os valores
void coletar_pedido(Grau *g, int pedido) {
    float qtd;
    printf("\nPedido %d — %s (quantidade em toneladas): ", pedido + 1, g->nome);
    scanf("%f", &qtd);
    
    // Validação para garantir que a quantidade não seja negativa
    while (qtd < 0) {
        printf("Valor invalido. Digite novamente: ");
        scanf("%f", &qtd);
    }
    
    // Calcula e acumula o faturamento, lucro e total de toneladas
    float fat = qtd * g->valor;
    g->faturamento += fat;
    g->lucro      += fat - (qtd * SALARIO_POR_TONELADA);
    g->toneladas  += qtd;
}

// Função para calcular e exibir o relatório final de faturamento, lucro e destaques
void imprimir_relatorio(Grau graus[], int n) {
    // Variáveis para armazenar os totais e os índices dos maiores valores
    float fat_total = 0, lucro_total = 0;
    int i_mais_fat = 0, i_mais_ton = 0;

    // Percorre os graus para calcular totais e encontrar os destaques (maior faturamento/toneladas)
    for (int i = 0; i < n; i++) {
        fat_total   += graus[i].faturamento;
        lucro_total += graus[i].lucro;
        if (graus[i].faturamento > graus[i_mais_fat].faturamento) i_mais_fat = i;
        if (graus[i].toneladas  > graus[i_mais_ton].toneladas)   i_mais_ton = i;
    }

    // Exibe os resultados gerais
    printf("\n=== LUCRO TOTAL: R$ %.2f ===\n", lucro_total);
    printf("=== FATURAMENTO TOTAL: R$ %.2f ===\n", fat_total);
    printf("Maior receita: %s (R$ %.2f)\n", graus[i_mais_fat].nome, graus[i_mais_fat].faturamento);
    printf("Mais toneladas: %s (%.2f t)\n", graus[i_mais_ton].nome, graus[i_mais_ton].toneladas);

    // Exibe o faturamento detalhado por cada grau
    printf("\n--- Faturamento por grau ---\n");
    for (int i = 0; i < n; i++)
        printf("  %-30s R$ %.2f\n", graus[i].nome, graus[i].faturamento);
}

// Função principal
int main(void) {
    int reiniciar;
    int num_pedidos;
    
    // Laço principal que permite reiniciar o programa ao final da execução
    do {
        // Inicializa o vetor de graus com seus nomes e zera os acumuladores
        Grau graus[NUM_GRAUS] = {
            {"Alto Grau (>=95%%)",              0, 0, 0, 0},
            {"Grau Medio Nacional (>=85%%)",    0, 0, 0, 0},
            {"Grau Medio Internacional (>=80%%)",0, 0, 0, 0},
            {"Grau Medio (>=75%%)",             0, 0, 0, 0},
            {"Grau Baixo (<75%%)",              0, 0, 0, 0},
        };

        // Pergunta ao usuário a quantidade de pedidos
        printf("\nDigite a quantidade de pedidos para esta simulacao: ");
        scanf("%d", &num_pedidos);
        while (num_pedidos <= 0) {
            printf("Quantidade invalida. Digite um valor maior que zero: ");
            scanf("%d", &num_pedidos);
        }

        // Lê o valor de venda por tonelada para cada grau de minério
        for (int i = 0; i < NUM_GRAUS; i++) {
            printf("Digite o valor por tonelada — %s: ", graus[i].nome);
            scanf("%f", &graus[i].valor);
        }

        // Coleta os dados de todos os pedidos para cada grau
        for (int p = 0; p < num_pedidos; p++)
            for (int g = 0; g < NUM_GRAUS; g++)
                coletar_pedido(&graus[g], p);

        // Gera e imprime o relatório final
        imprimir_relatorio(graus, NUM_GRAUS);

        // Pergunta ao usuário se deseja reiniciar o sistema
        printf("\nReiniciar? (1 = sim / outro = nao): ");
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);

    printf("Encerrando. Ate logo!\n");
    return 0;
}