//Escreva uma função usando structs considerando o tipo e defina o tipo data e a data nesta apresentação e retorna um inteiro

#include <stdio.h>

struct tdata {
  int dia;
  int mes;
  int ano;
};
typedef struct tdata Data;

int extraiDia(Data data)
{
    return data.dia;
}

int extraiMes(Data data)
{
    return data.mes;
}

int extraiAno(Data data)
{
    return data.ano;
}

int main()
{
    Data data1 = {15, 8, 2021};
    Data data2 = {20, 8, 2021};

    printf("Dia: %d\n", extraiDia(data1));
    printf("Mes: %d\n", extraiMes(data1));
    printf("Ano: %d\n", extraiAno(data1));

    return 0;
}