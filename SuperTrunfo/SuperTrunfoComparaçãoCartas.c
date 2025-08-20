#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo
// Tema 3(Lógica do jogo) - Comparação de Cartas
// Autor: Erick

int main() {

    //CARTA 1
    char codigo1[10];
    char estado1[50]; 
    char nome1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos1;
    float densidade1;
    float pib_percapta1;

    //CARTA 2
    char codigo2[10];
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
    scanf("%s", codigo1);

    printf("Digite o estado da cidade 1: \n");
    scanf("%s", estado1); 

    printf("Digite o nome da cidade 1: \n");
    scanf("%s", nome1);

    printf("Digite a populacao da cidade 1: \n");
    scanf("%d", &populacao1);

    printf("Digite a area da cidade 1 (km²): \n");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade 1: \n");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos da cidade 1: \n");
    scanf("%d", &pontos1);

    printf("\n");

    // Cadastro da Carta 2
    printf("Digite o codigo da cidade 2: \n");
    scanf("%s", codigo2);

    printf("Digite o estado da cidade 2: \n");
    scanf("%s", estado2);

    printf("Digite o nome da cidade 2: \n");
    scanf("%s", nome2);

    printf("Digite a populacao da cidade 2: \n");
    scanf("%d", &populacao2);

    printf("Digite a area da cidade 2 (km²): \n");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade 2: \n");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos da cidade 2: \n");
    scanf("%d", &pontos2);

    // Cálculos
    densidade1 = (float)populacao1 / area1;
    pib_percapta1 = pib1 / populacao1;

    densidade2 = (float)populacao2 / area2;
    pib_percapta2 = pib2 / populacao2;

    // Comparação das cartas
    // Escolha do atributo (População)
    
    printf("\n=== Comparacao de Cartas ===\n");
    printf("Atributo escolhido: Populacao\n\n");

    printf("Carta 1 - %s (%s): %d\n", nome1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d\n", nome2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", nome1);
    } else if (populacao2 > populacao1) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}