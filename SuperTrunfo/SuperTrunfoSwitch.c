#include <stdio.h>
#include <string.h>

// Variaveis
typedef struct {
    char codigo[10];
    char estado[3];
    char nome[50];
    long long populacao;
    float area;
    double pib;
    int pontos;
    float densidade;
} Carta;

void mostrarMenuAtributos(int excluir) {
    printf("\nEscolha um atributo para comparar:\n");
    if (excluir != 1) printf("1 - Populacao\n");
    if (excluir != 2) printf("2 - Area\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turisticos\n");
    if (excluir != 5) printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
}

double obterValorAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return (double)c.populacao;
        case 2: return (double)c.area;
        case 3: return (double)c.pib;
        case 4: return (double)c.pontos;
        case 5: return (double)c.densidade;
        default: return 0;
    }
}

int main() {
    Carta c1, c2;

    // Cadastro 
    printf("Digite o codigo da cidade 1: ");
    scanf("%s", c1.codigo);
    printf("Digite o estado da cidade 1: ");
    scanf("%s", c1.estado);
    printf("Digite o nome da cidade 1: ");
    scanf("%s", c1.nome);
    printf("Digite a populacao da cidade 1: ");
    scanf("%lld", &c1.populacao);
    printf("Digite a area da cidade 1 (km²): ");
    scanf("%f", &c1.area);
    printf("Digite o PIB da cidade 1: ");
    scanf("%lf", &c1.pib);
    printf("Digite o numero de pontos turisticos da cidade 1: ");
    scanf("%d", &c1.pontos);

    // Calculo densidade
    c1.densidade = (float)c1.populacao / c1.area;

    printf("\nDigite o codigo da cidade 2: ");
    scanf("%s", c2.codigo);
    printf("Digite o estado da cidade 2: ");
    scanf("%s", c2.estado);
    printf("Digite o nome da cidade 2: ");
    scanf("%s", c2.nome);
    printf("Digite a populacao da cidade 2: ");
    scanf("%lld", &c2.populacao);
    printf("Digite a area da cidade 2 (km²): ");
    scanf("%f", &c2.area);
    printf("Digite o PIB da cidade 2: ");
    scanf("%lf", &c2.pib);
    printf("Digite o numero de pontos turisticos da cidade 2: ");
    scanf("%d", &c2.pontos);

    c2.densidade = (float)c2.populacao / c2.area;

    // Escolha dos atributos
    int attr1, attr2;

    mostrarMenuAtributos(0);
    scanf("%d", &attr1);

    mostrarMenuAtributos(attr1);
    scanf("%d", &attr2);

    // Valores dos atributos escolhidos
    double v1_attr1 = obterValorAtributo(c1, attr1);
    double v2_attr1 = obterValorAtributo(c2, attr1);

    double v1_attr2 = obterValorAtributo(c1, attr2);
    double v2_attr2 = obterValorAtributo(c2, attr2);

    // Comparação atributo 1
    int vencedor1;
    if (attr1 == 5) { // densidade -> menor vence
        vencedor1 = (v1_attr1 < v2_attr1) ? 1 : (v1_attr1 > v2_attr1 ? 2 : 0);
    } else {
        vencedor1 = (v1_attr1 > v2_attr1) ? 1 : (v1_attr1 < v2_attr1 ? 2 : 0);
    }

    // Comparação atributo 2
    int vencedor2;
    if (attr2 == 5) { // densidade -> menor vence
        vencedor2 = (v1_attr2 < v2_attr2) ? 1 : (v1_attr2 > v2_attr2 ? 2 : 0);
    } else {
        vencedor2 = (v1_attr2 > v2_attr2) ? 1 : (v1_attr2 < v2_attr2 ? 2 : 0);
    }

    // Soma final
    double soma1 = v1_attr1 + v1_attr2;
    double soma2 = v2_attr1 + v2_attr2;

    int vencedorFinal = (soma1 > soma2) ? 1 : (soma1 < soma2 ? 2 : 0);

    // Resultado
    printf("\n======= RESULTADO =======\n");
    printf("Pais 1: %s | Pais 2: %s\n", c1.nome, c2.nome);

    printf("\nAtributo 1 escolhido: %d\n", attr1);
    printf("%s: %.2lf | %s: %.2lf\n", c1.nome, v1_attr1, c2.nome, v2_attr1);
    printf("Vencedor atributo 1: %s\n", vencedor1 == 1 ? c1.nome : (vencedor1 == 2 ? c2.nome : "Empate"));

    printf("\nAtributo 2 escolhido: %d\n", attr2);
    printf("%s: %.2lf | %s: %.2lf\n", c1.nome, v1_attr2, c2.nome, v2_attr2);
    printf("Vencedor atributo 2: %s\n", vencedor2 == 1 ? c1.nome : (vencedor2 == 2 ? c2.nome : "Empate"));

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2lf | %s: %.2lf\n", c1.nome, soma1, c2.nome, soma2);

    if (vencedorFinal == 0) {
        printf("\nResultado final: EMPATE!\n");
    } else {
        printf("\nResultado final: %s VENCEU!\n", vencedorFinal == 1 ? c1.nome : c2.nome);
    }

    return 0;
}
