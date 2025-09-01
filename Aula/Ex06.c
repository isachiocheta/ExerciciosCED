// 2 inteiros para multiplicacao e devolve o resultado, sem *, recebe a base e o expoente e devolve o resultado, informa o resto da divisao sem usar %
//1 - multiplicacao - sem *
//2 - potenciacao - sem *
//3 - resto da divisao - sem %
//0 - sair
#include <stdio.h>

int multiplicacao(int a, int b) {
    int resultado = 0;
    for (int i = 0; i < b; i++) {
        resultado += a;
    }
    return resultado;
}

int potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado = multiplicacao(resultado, base);
    }
    return resultado;
}

int resto_divisao(int a, int b) {
    while (a >= b) {
        a = a - b;
    }
    return a;
}

int main() {
    int opcao;
    do {
        printf("Digite a opcao desejada (1: multiplicacao, 2: potenciacao, 3: resto de divisao, 0: sair): ");
        scanf("%d", &opcao);
        if (opcao == 1 || opcao == 2 || opcao == 3) {
            int a, b;
            printf("Digite o primeiro numero: ");
            scanf("%d", &a);
            printf("Digite o segundo numero: ");
            scanf("%d", &b);
            if (opcao == 1) {
                int resultado = multiplicacao(a, b);
                printf("Resultado da multiplicacao: %d\n", resultado);
            } else if (opcao == 2) {
                int resultado = potencia(a, b);
                printf("Resultado da potenciacao: %d\n", resultado);
            } else if (opcao == 3) {
                int resultado = resto_divisao(a, b);
                printf("Resultado do resto da divisao: %d\n", resultado);
            }
        }
    } while (opcao != 0);
    printf("Programa encerrado!!\n");
    return 0;
}