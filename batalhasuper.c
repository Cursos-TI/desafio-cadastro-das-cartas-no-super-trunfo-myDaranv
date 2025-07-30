#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define limparBuffer() fflush(stdin)
#else
    #include <stdio_ext.h>
    #define limparBuffer() __fpurge(stdin)
#endif

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void lerTexto(char *mensagem, char *destino, int tamanho) {
    printf("%s", mensagem);
    limparBuffer();
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0'; // remove o \n do final
}

void lerCarta(Carta *c, int numero) {
    printf("\n=============================\n");
    printf("   Cadastro da Carta %d\n", numero);
    printf("=============================\n\n");

    lerTexto("Estado:\n> ", c->estado, 50);

    printf("\nCodigo:\n> ");
    scanf("%d", &c->codigo);

    lerTexto("\nNome do local:\n> ", c->nome, 50);

    printf("\nPopulacao (apenas numeros, sem ponto):\n> ");
    scanf("%lu", &c->populacao);

    printf("\nArea em km² (use ponto, ex: 1234.56):\n> ");
    scanf("%f", &c->area);

    printf("\nPIB em reais (use ponto, ex: 12345678.90):\n> ");
    scanf("%f", &c->pib);

    printf("\nNumero de pontos turisticos:\n> ");
    scanf("%d", &c->pontos_turisticos);

    printf("\n✅ Carta %d cadastrada com sucesso!\n", numero);
}

void calcularAtributos(Carta *c) {
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;

    float populacao_f = (float)c->populacao;
    float pontos_f = (float)c->pontos_turisticos;
    float densidade_inv = 1.0f / c->densidade_populacional;

    c->super_poder = populacao_f + c->area + c->pib + pontos_f + c->pib_per_capita + densidade_inv;
}

void compararCartas(Carta c1, Carta c2) {
    printf("\n=============================\n");
    printf("   Comparacao de Cartas\n");
    printf("=============================\n\n");

    int v;

    v = c1.populacao > c2.populacao;
    printf("Populacao: Carta %d venceu (%d)\n", v ? 1 : 2, v);

    v = c1.area > c2.area;
    printf("Area: Carta %d venceu (%d)\n", v ? 1 : 2, v);

    v = c1.pib > c2.pib;
    printf("PIB: Carta %d venceu (%d)\n", v ? 1 : 2, v);

    v = c1.pontos_turisticos > c2.pontos_turisticos;
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", v ? 1 : 2, v);

    v = c1.densidade_populacional < c2.densidade_populacional;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", v ? 1 : 2, v);

    v = c1.pib_per_capita > c2.pib_per_capita;
    printf("PIB per Capita: Carta %d venceu (%d)\n", v ? 1 : 2, v);

    v = c1.super_poder > c2.super_poder;
    printf("Super Poder: Carta %d venceu (%d)\n", v ? 1 : 2, v);

    printf("\n=============================\n");
    printf("       Comparacao Final\n");
    printf("=============================\n");
}

int main() {
    Carta carta1, carta2;

    lerCarta(&carta1, 1);
    calcularAtributos(&carta1);

    lerCarta(&carta2, 2);
    calcularAtributos(&carta2);

    compararCartas(carta1, carta2);

    return 0;
}