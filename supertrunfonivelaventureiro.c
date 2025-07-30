#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define limparBuffer() fflush(stdin)
#else
    #include <stdio_ext.h>
    #define limparBuffer() __fpurge(stdin)
#endif

// Estrutura de dados da carta
typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

// Função para cadastrar cartas (com dados fixos neste nível)
void cadastrarCartas(Carta *c1, Carta *c2) {
    // Carta 1
    strcpy(c1->pais, "Brasil");
    c1->populacao = 215000000;
    c1->area = 8515767.0;
    c1->pib = 1800000000000.0;
    c1->pontos_turisticos = 12;
    c1->densidade = c1->populacao / c1->area;

    // Carta 2
    strcpy(c2->pais, "Japao");
    c2->populacao = 125000000;
    c2->area = 377975.0;
    c2->pib = 5100000000000.0;
    c2->pontos_turisticos = 18;
    c2->densidade = c2->populacao / c2->area;
}

// Função para exibir menu
void exibirMenu() {
    printf("\n======= MENU DE COMPARACAO =======\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha uma opcao: ");
}

// Função para comparar as cartas com base na escolha
void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\n========== COMPARACAO ==========\n");

    switch (opcao) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("%s: %d habitantes\n", c1.pais, c1.populacao);
            printf("%s: %d habitantes\n", c2.pais, c2.populacao);

            if (c1.populacao > c2.populacao) {
                printf("Resultado: %s venceu!\n", c1.pais);
            } else if (c2.populacao > c1.populacao) {
                printf("Resultado: %s venceu!\n", c2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", c1.pais, c1.area);
            printf("%s: %.2f km²\n", c2.pais, c2.area);

            if (c1.area > c2.area) {
                printf("Resultado: %s venceu!\n", c1.pais);
            } else if (c2.area > c1.area) {
                printf("Resultado: %s venceu!\n", c2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f\n", c1.pais, c1.pib);
            printf("%s: R$ %.2f\n", c2.pais, c2.pib);

            if (c1.pib > c2.pib) {
                printf("Resultado: %s venceu!\n", c1.pais);
            } else if (c2.pib > c1.pib) {
                printf("Resultado: %s venceu!\n", c2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d pontos\n", c1.pais, c1.pontos_turisticos);
            printf("%s: %d pontos\n", c2.pais, c2.pontos_turisticos);

            if (c1.pontos_turisticos > c2.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", c1.pais);
            } else if (c2.pontos_turisticos > c1.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", c2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade demográfica (menor vence!)
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.2f hab/km²\n", c1.pais, c1.densidade);
            printf("%s: %.2f hab/km²\n", c2.pais, c2.densidade);

            if (c1.densidade < c2.densidade) {
                printf("Resultado: %s venceu!\n", c1.pais);
            } else if (c2.densidade < c1.densidade) {
                printf("Resultado: %s venceu!\n", c2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
    }

    printf("=================================\n");
}

int main() {
    Carta carta1, carta2;
    int escolha;

    // Cadastro fixo das duas cartas
    cadastrarCartas(&carta1, &carta2);

    // Exibe o menu e recebe a escolha
    exibirMenu();
    scanf("%d", &escolha);

    // Compara baseado na escolha do usuário
    compararCartas(carta1, carta2, escolha);

    return 0;
}
