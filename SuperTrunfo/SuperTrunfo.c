#include <stdio.h> 

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste Erick

#include <stdio.h> 

int main() {
    // CARTA 1
    int codigo1;
    char estado1[50]; 
    char nome1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos1;
    float densidade1;
    float pib_percapta1;

    // CARTA 2
    int codigo2;
    char estado2[50]; 
    char nome2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos2;
    float densidade2;
    float pib_percapta2;

    // Cadastro da Carta 1
    printf("Digite o codigo da cidade 1: \n");
    scanf("%d", &codigo1);

    printf("Digite o estado da cidade 1: \n");
    scanf(" %[^\n]", estado1); 

    printf("Digite o nome da cidade 1: \n");
    scanf(" %[^\n]", nome1);

    printf("Digite a populacao da cidade 1: \n");
    scanf("%d", &populacao1);

    printf("Digite a area da cidade 1 (km²): \n");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade 1 (em bilhoes): \n");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos da cidade 1: \n");
    scanf("%d", &pontos1);

    printf("\n");

    // Cadastro da Carta 2
    printf("Digite o codigo da cidade 2: \n");
    scanf("%d", &codigo2);

    printf("Digite o estado da cidade 2: \n");
    scanf(" %[^\n]", estado2);

    printf("Digite o nome da cidade 2: \n");
    scanf(" %[^\n]", nome2);

    printf("Digite a populacao da cidade 2: \n");
    scanf("%d", &populacao2);

    printf("Digite a area da cidade 2 (km²): \n");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade 2 (em bilhoes): \n");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos da cidade 2: \n");
    scanf("%d", &pontos2);

    // Cálculos
    densidade1 = (float)populacao1 / area1;
    pib_percapta1 = (pib1 * 1000000000) / populacao1;

    densidade2 = (float)populacao2 / area2;
    pib_percapta2 = (pib2 * 1000000000) / populacao2;

    // Resultado
    printf("\n--- Dados da Carta 1 ---\n");
    printf("Codigo: %d\n", codigo1);
    printf("Estado: %s\n", estado1);
    printf("Nome: %s\n", nome1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos turisticos: %d\n", pontos1);
    printf("Densidade demografica: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f R$\n", pib_percapta1);

    printf("\n--- Dados da Carta 2 ---\n");
    printf("Codigo: %d\n", codigo2);
    printf("Estado: %s\n", estado2);
    printf("Nome: %s\n", nome2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos turisticos: %d\n", pontos2);
    printf("Densidade demografica: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f R$\n", pib_percapta2);

    return 0;
}
