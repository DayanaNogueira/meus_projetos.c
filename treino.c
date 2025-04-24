#include <stdio.h>
#include <string.h>

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

void limpar_enter(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void ler_carta(Carta *carta) {
    char buffer[100];

    printf("Digite o nome do estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    limpar_enter(carta->estado);

    printf("Digite o código da carta: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &carta->codigo);

    printf("Digite o nome da carta: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    limpar_enter(carta->nome);

    printf("Digite a população: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &carta->pontos_turisticos);
}

void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao;

    float inverso_densidade = 1.0f / carta->densidade_populacional;

    carta->super_poder =
        (float)carta->populacao + carta->area + carta->pib +
        (float)carta->pontos_turisticos + carta->pib_per_capita + inverso_densidade;
}

void comparar_cartas(Carta *c1, Carta *c2) {
    printf("\nComparação de Cartas:\n\n");

    printf("População: Carta %d venceu (%d)\n",
           (c1->populacao > c2->populacao) ? 1 : 2,
           (c1->populacao > c2->populacao) ? 1 : 0);

    printf("Área: Carta %d venceu (%d)\n",
           (c1->area > c2->area) ? 1 : 2,
           (c1->area > c2->area) ? 1 : 0);

    printf("PIB: Carta %d venceu (%d)\n",
           (c1->pib > c2->pib) ? 1 : 2,
           (c1->pib > c2->pib) ? 1 : 0);

    printf("Pontos Turísticos: Carta %d venceu (%d)\n",
           (c1->pontos_turisticos > c2->pontos_turisticos) ? 1 : 2,
           (c1->pontos_turisticos > c2->pontos_turisticos) ? 1 : 0);

    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           (c1->densidade_populacional < c2->densidade_populacional) ? 1 : 2,
           (c1->densidade_populacional < c2->densidade_populacional) ? 1 : 0);

    printf("PIB per Capita: Carta %d venceu (%d)\n",
           (c1->pib_per_capita > c2->pib_per_capita) ? 1 : 2,
           (c1->pib_per_capita > c2->pib_per_capita) ? 1 : 0);

    printf("Super Poder: Carta %d venceu (%d)\n",
           (c1->super_poder > c2->super_poder) ? 1 : 2,
           (c1->super_poder > c2->super_poder) ? 1 : 0);
}

int main() {
    Carta carta1, carta2;

    printf("---- Preenchendo Carta 1 ----\n");
    ler_carta(&carta1);
    calcular_atributos(&carta1);

    printf("\n---- Preenchendo Carta 2 ----\n");
    ler_carta(&carta2);
    calcular_atributos(&carta2);

    comparar_cartas(&carta1, &carta2);

    return 0;
}
