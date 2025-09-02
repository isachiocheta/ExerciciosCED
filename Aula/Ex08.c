//Retorna -1 se a data data1 é anterior à data data2, 1 se a data data1 é posterior à data data2 e 0 se as datas data1 e data2 são iguais.
//int comparaDatas(Data data1, Data data2)

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

int comparaDatas(Data data1, Data data2)
{
    if (data1.ano < data2.ano) 
        return -1;
    if (data1.ano > data2.ano) 
        return 1;
    if (data1.mes < data2.mes) 
        return -1;
    if (data1.mes > data2.mes) 
        return 1;
    if (data1.dia < data2.dia) 
        return -1;
    if (data1.dia > data2.dia) 
        return 1;
    return 0;
}

int main()
{
    Data data1 = {2, 9, 2025};
    Data data2 = {11, 10, 2025};

    printf("Dia: %d\n", extraiDia(data1));
    printf("Mes: %d\n", extraiMes(data1));
    printf("Ano: %d\n", extraiAno(data1));

    printf("Dia: %d\n", extraiDia(data2));
    printf("Mes: %d\n", extraiMes(data2));
    printf("Ano: %d\n", extraiAno(data2));

    int resultado = comparaDatas(data1, data2);
    if (resultado == -1) {
        printf("Data 1 é anterior à Data 2\n");
    } else if (resultado == 1) {
        printf("Data 1 é posterior à Data 2\n");
    } else {
        printf("Data 1 é igual à Data 2\n");
    }

    return 0;
}
