// Crie um aplicativo de conversão entre as temperaturas Celsius e Fahrenheit.
//Primeiro o usuário deve escolher se vai entrar com a temperatura em Celsius ou Fahrenheit, depois a conversão escolhida é realizada.
//Se C é a temperatura em Celsius e F em Fahrenheit, as fórmulas de conversão são:
//C = 5*(F-32)/9
//F = (9*C/5) + 32

#include <stdio.h>

float celsius_para_fahrenheit(float *c) {
    return (9 * (*c) / 5) + 32;
}

float fahrenheit_para_celsius(float *f) {
    return 5 * (*f - 32) / 9;
}

int main() {
    int opcao;
    float temp;

    printf("Conversor de Temperaturas\n");
    printf("1 - Celsius para Fahrenheit\n");
    printf("2 - Fahrenheit para Celsius\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Digite a temperatura em Celsius: ");
        scanf("%f", &temp);
        printf("%.2f C = %.2f F\n", temp, celsius_para_fahrenheit(&temp));
    } else if (opcao == 2) {
        printf("Digite a temperatura em Fahrenheit: ");
        scanf("%f", &temp);
        printf("%.2f F = %.2f C\n", temp, fahrenheit_para_celsius(&temp));
    } else {
        printf("Opcao invalida!\n");
    }

    return 0;
}