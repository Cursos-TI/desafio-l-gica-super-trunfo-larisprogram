#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// ... Código base é o mesmo, mas agora:
Comparar múltiplas
Infelizmente a resposta foi cortada. Vou retomar com o código completo do **nível mestre**, evoluindo o nível anterior para incluir as funcionalidades descritas:

---

### **Evolução do Código: Nível Mestre**
No nível mestre, um menu dinâmico permite selecionar múltiplos atributos para a comparação, e a lógica trata empates integrando critérios adicionais.

```c
#include <stdio.h>

typedef struct {
    char estado[30];
    char nome[30];
    int populacao;
    float area;
    float pib;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

void calcularAtributos(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

void compararMultiplo(Carta c1, Carta c2, int atributo1, int atributo2) {
    float somaCarta1 = 0.0, somaCarta2 = 0.0;

    switch (atributo1) {
        case 1: // População
            somaCarta1 += c1.populacao;
            somaCarta2 += c2.populacao;
            break;
        case 2: // Área
            somaCarta1 += c1.area;
            somaCarta2 += c2.area;
            break;
        case 3: // Densidade Populacional
            somaCarta1 += c1.densidadePopulacional;
            somaCarta2 += c2.densidadePopulacional;
            break;
    }

    switch (atributo2) {
        case 1:
            somaCarta1 += c1.populacao;
            somaCarta2 += c2.populacao;
            break;
        case 2:
            somaCarta1 += c1.area;
            somaCarta2 += c2.area;
            break;
        case 3:
            somaCarta1 += c1.densidadePopulacional;
            somaCarta2 += c2.densidadePopulacional;
            break;
    }

    printf("\nComparação com múltiplos atributos\n");
    printf("Soma total de %s: %.2f\n", c1.nome, somaCarta1);
    printf("Soma total de %s: %.2f\n", c2.nome, somaCarta2);
    if (somaCarta1 > somaCarta2) {
        printf("Resultado: Carta 1 venceu!\n");
    } else if (somaCarta1 < somaCarta2) {
        printf("Resultado: Carta 2 venceu!\n");
    } else {
        printf("Empate! Não foi possível determinar um vencedor.\n");
    }
}

int main() {
    Carta carta1 = {"SP", "São Paulo", 12300000, 1521.11, 700.00, 0, 0};
    Carta carta2 = {"RJ", "Rio de Janeiro", 6000000, 1182.30, 412.00, 0, 0};

    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    int opcao1, opcao2;
    printf("\n==== MENU SUPER TRUNFO NÍVEL MESTRE ====\n");
    printf("Escolha dois atributos para a comparação:\n");
    printf("1. População\n2. Área\n3. Densidade Populacional\n");

    // Escolha do primeiro atributo
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &opcao1);

    // Menu dinâmico para o segundo atributo
    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &opcao2);
        if (opcao2 == opcao1) {
            printf("Por favor, escolha um atributo diferente do primeiro.\n");
        }
    } while (opcao2 == opcao1);

    compararMultiplo(carta1, carta2, opcao1, opcao2);

    printf("Encerrando o programa... Até logo!\n");
    return 0;
}
