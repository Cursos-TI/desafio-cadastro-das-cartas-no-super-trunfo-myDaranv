#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define limparBuffer() fflush(stdin)
#else
    #include <stdio_ext.h>
    #define limparBuffer() __fpurge(stdin)
#endif

// Estrutura da carta
typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

// Função para cadastrar as duas cartas fixas
void cadastrarCartas(Carta *c1, Carta *c2) {
    // Carta 1 - Brasil
    strcpy(c1->pais, "Brasil");
    c1->populacao = 215000000;
    c1->area = 8515767.0;
    c1->pib = 1800000000000.0;
    c1->pontos_turisticos = 12;
    c1->densidade = c1->populacao / c1->area;

    // Carta 2 - Japão
    strcpy(c2->pais, "Japao");
    c2->populacao = 125000000;
    c2->area = 377975.0;
    c2->pib = 5100000000000.0;
    c2->pontos_turisticos = 18;
    c2->densidade = c2->populacao / c2->area;
}

// Função para exibir o menu com os atributos disponíveis
void exibirMenu(int escolhido) {
    printf("\n===== ESCOLHA UM ATRIBUTO =====\n");
    if (escolhido != 1) printf("1 - Populacao\n");
    if (escolhido != 2) printf("2 - Area\n");
    if (escolhido != 3) printf("3 - PIB\n");
    if (escolhido != 4) printf("4 - Pontos Turisticos\n");
    if (escolhido != 5) printf("5 - Densidade Demografica\n");
    printf("Escolha uma opcao: ");
}

// Função para obter o valor de um atributo de uma carta
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade;
        default: return -1;
    }
}

// Função para retornar o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Desconhecido";
    }
}

// Função para comparar dois valores com base na regra
int comparar(float v1, float v2, int atributo) {
    if (atributo == 5) {
        // Densidade: menor vence
        return (v1 < v2) ? 1 : (v2 < v1) ? 2 : 0;
    } else {
        // Demais: maior vence
        return (v1 > v2) ? 1 : (v2 > v1) ? 2 : 0;
    }
}

int main() {
    Carta carta1, carta2;
    int atributo1 = 0, atributo2 = 0;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2, soma1, soma2;

    // Cadastra cartas fixas
    cadastrarCartas(&carta1, &carta2);

    // Escolha do primeiro atributo
    do {
        exibirMenu(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo (diferente do primeiro)
    do {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
            printf("Opcao invalida ou repetida. Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Obtem valores dos atributos
    valor1_c1 = obterValor(carta1, atributo1);
    valor1_c2 = obterValor(carta2, atributo1);
    valor2_c1 = obterValor(carta1, atributo2);
    valor2_c2 = obterValor(carta2, atributo2);

    // Soma dos atributos
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    // Comparações individuais
    int vencedor1 = comparar(valor1_c1, valor1_c2, atributo1);
    int vencedor2 = comparar(valor2_c1, valor2_c2, atributo2);

    // Resultado final
    printf("\n===== RESULTADO DA COMPARACAO =====\n");
    printf("Carta 1: %s\n", carta1.pais);
    printf("Carta 2: %s\n", carta2.pais);
    printf("-----------------------------------\n");

    printf("%s:\n", nomeAtributo(atributo1));
    printf(" - %s: %.2f\n", carta1.pais, valor1_c1);
    printf(" - %s: %.2f\n", carta2.pais, valor1_c2);
    printf("Vencedor do atributo: %s\n", vencedor1 == 1 ? carta1.pais : vencedor1 == 2 ? carta2.pais : "Empate");

    printf("\n%s:\n", nomeAtributo(atributo2));
    printf(" - %s: %.2f\n", carta1.pais, valor2_c1);
    printf(" - %s: %.2f\n", carta2.pais, valor2_c2);
    printf("Vencedor do atributo: %s\n", vencedor2 == 1 ? carta1.pais : vencedor2 == 2 ? carta2.pais : "Empate");

    printf("\nSoma dos atributos:\n");
    printf(" - %s: %.2f\n", carta1.pais, soma1);
    printf(" - %s: %.2f\n", carta2.pais, soma2);

    // Resultado final
    printf("\nVencedor da rodada: ");
    if (soma1 > soma2)
        printf("%s venceu!\n", carta1.pais);
    else if (soma2 > soma1)
        printf("%s venceu!\n", carta2.pais);
    else
        printf("Empate!\n");

    printf("===================================\n");

    return 0;
}
