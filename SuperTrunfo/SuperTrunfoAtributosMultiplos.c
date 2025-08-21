#include <stdio.h>
#include <string.h>

// ESTRUTURA
typedef struct {
    char codigo[3];
    char estado[3];
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

//CADASTRO DE CARTA
void cadastrarCarta(Carta *carta, int numero) {
    printf("Digite o codigo da cidade %d: ", numero);
    scanf("%s", carta->codigo);

    printf("Digite o estado da cidade %d: ", numero);
    scanf("%s", carta->estado);

    printf("Digite o nome da cidade %d: ", numero);
    scanf("%s", carta->nome);

    printf("Digite a populacao da cidade %d: ", numero);
    scanf("%d", &carta->populacao);

    printf("Digite a area da cidade %d (km²): ", numero);
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade %d: ", numero);
    scanf("%f", &carta->pib);

    printf("Digite o numero de pontos turisticos da cidade %d: ", numero);
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadeDemografica = (float)carta->populacao / carta->area;
}

// Função para exibir menu de atributos
void exibirMenu(int excluir) {
    printf("\nEscolha um atributo para comparacao:\n");
    if (excluir != 1) printf("1 - Populacao\n");
    if (excluir != 2) printf("2 - Area\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turisticos\n");
    if (excluir != 5) printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
}

// Função que retorna o valor do atributo selecionado
float pegarAtributo(Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return -1; // inválido
    }
}

// Função que retorna o nome do atributo
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Invalido";
    }
}

int main() {
    Carta c1, c2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&c1, 1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&c2, 2);

    int escolha1, escolha2;
    
    // Primeiro atributo
    exibirMenu(0);
    scanf("%d", &escolha1);

    // Segundo atributo (menu dinâmico)
    exibirMenu(escolha1);
    scanf("%d", &escolha2);

    // Pega valores dos atributos
    float valor1_c1 = pegarAtributo(c1, escolha1);
    float valor1_c2 = pegarAtributo(c2, escolha1);

    float valor2_c1 = pegarAtributo(c1, escolha2);
    float valor2_c2 = pegarAtributo(c2, escolha2);

    // Comparação dos dois atributos
    int pontos_c1 = 0, pontos_c2 = 0;

    // Atributo 1
    if (escolha1 == 5) { // densidade -> menor vence
        (valor1_c1 < valor1_c2) ? pontos_c1++ : (valor1_c2 < valor1_c1) ? pontos_c2++ : 0;
    } else {
        (valor1_c1 > valor1_c2) ? pontos_c1++ : (valor1_c2 > valor1_c1) ? pontos_c2++ : 0;
    }

    // Atributo 2
    if (escolha2 == 5) {
        (valor2_c1 < valor2_c2) ? pontos_c1++ : (valor2_c2 < valor2_c1) ? pontos_c2++ : 0;
    } else {
        (valor2_c1 > valor2_c2) ? pontos_c1++ : (valor2_c2 > valor2_c1) ? pontos_c2++ : 0;
    }

    // Soma total dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    printf("\n===== RESULTADO =====\n");
    printf("Cidade 1: %s\n", c1.nome);
    printf("Cidade 2: %s\n", c2.nome);

    printf("\nComparacao de atributos:\n");
    printf("%s -> %s: %.2f | %s: %.2f\n", nomeAtributo(escolha1), c1.nome, valor1_c1, c2.nome, valor1_c2);
    printf("%s -> %s: %.2f | %s: %.2f\n", nomeAtributo(escolha2), c1.nome, valor2_c1, c2.nome, valor2_c2);

    printf("\nSomas finais:\n");
    printf("%s: %.2f\n", c1.nome, soma_c1);
    printf("%s: %.2f\n", c2.nome, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("\nVencedor: %s\n", c1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("\nVencedor: %s\n", c2.nome);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
