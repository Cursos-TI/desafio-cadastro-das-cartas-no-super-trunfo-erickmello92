#include <stdio.h>
#include <string.h>

int main() {
    // ===== Declaração das variáveis =====
    // CARTA 1
    char codigo1[10], estado1[50], nome1[50];
    int populacao1, pontos1;
    float area1, pib1, densidade1, pib_percapta1;

    // CARTA 2
    char codigo2[10], estado2[50], nome2[50];
    int populacao2, pontos2;
    float area2, pib2, densidade2, pib_percapta2;

    int opcao;

    // ===== Cadastro da Carta 1 =====
    printf("Digite o codigo da cidade 1: ");
    scanf("%s", codigo1);

    printf("Digite o estado da cidade 1: ");
    scanf("%s", estado1);

    printf("Digite o nome da cidade 1: ");
    scanf("%s", nome1);

    printf("Digite a populacao da cidade 1: ");
    scanf("%d", &populacao1);

    printf("Digite a area da cidade 1 (km²): ");
    scanf("%f", &area1); // removi \n por ser um float

    printf("Digite o PIB da cidade 1: ");
    scanf("%f", &pib1); // REMOVIDO \n por ser um float

    printf("Digite o numero de pontos turisticos da cidade 1: ");
    scanf("%d", &pontos1);

    // ===== Cadastro da Carta 2 =====
    printf("\nDigite o codigo da cidade 2: ");
    scanf("%s", codigo2);

    printf("Digite o estado da cidade 2: ");
    scanf("%s", estado2);

    printf("Digite o nome da cidade 2: ");
    scanf("%s", nome2);

    printf("Digite a populacao da cidade 2: ");
    scanf("%d", &populacao2); 

    printf("Digite a area da cidade 2 (km²): ");
    scanf("%f", &area2); 

    printf("Digite o PIB da cidade 2: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos da cidade 2: ");
    scanf("%d", &pontos2);

    // Cálculos
    densidade1 = populacao1 / area1;
    pib_percapta1 = pib1 / populacao1;

    densidade2 = populacao2 / area2;
    pib_percapta2 = pib2 / populacao2;

    // Menu Interativo
    printf("\n=== MENU DE COMPARACAO ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("6 - PIB per capita\n");
    printf("Escolha o atributo para comparacao: ");
    scanf("%d", &opcao);

    // Comparação com switch
    switch(opcao) {
        case 1: // População
            printf("\nComparacao por Populacao:\n");
            printf("%s: %d habitantes\n", nome1, populacao1);
            printf("%s: %d habitantes\n", nome2, populacao2);

            if (populacao1 > populacao2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (populacao2 > populacao1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("\nComparacao por Area:\n");
            printf("%s: %.2f km²\n", nome1, area1);
            printf("%s: %.2f km²\n", nome2, area2);

            if (area1 > area2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (area2 > area1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("\nComparacao por PIB:\n");
            printf("%s: %.2f\n", nome1, pib1);
            printf("%s: %.2f\n", nome2, pib2);

            if (pib1 > pib2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (pib2 > pib1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("\nComparacao por Pontos Turisticos:\n");
            printf("%s: %d pontos\n", nome1, pontos1);
            printf("%s: %d pontos\n", nome2, pontos2);

            if (pontos1 > pontos2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (pontos2 > pontos1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade Demográfica (o menor é que vence)
            printf("\nComparacao por Densidade Demografica:\n");
            printf("%s: %.2f hab/km²\n", nome1, densidade1);
            printf("%s: %.2f hab/km²\n", nome2, densidade2);

            if (densidade1 < densidade2)
                printf("Resultado: %s venceu (menor densidade)!\n", nome1);
            else if (densidade2 < densidade1)
                printf("Resultado: %s venceu (menor densidade)!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 6: // PIB per capita
            printf("\nComparacao por PIB per capita:\n");
            printf("%s: %.2f\n", nome1, pib_percapta1);
            printf("%s: %.2f\n", nome2, pib_percapta2);

            if (pib_percapta1 > pib_percapta2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (pib_percapta2 > pib_percapta1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
    }

    return 0;
}