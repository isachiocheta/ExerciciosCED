//Crie uma função que receba 3 números e retorne o maior valor, utilizando uma chamada para a função anterior.

#include <stdio.h>

int maior2(int n1, int n2) // q2
{
    if (n1>n2) {return n1;}
    else       {return n2;}
}
//
int maior3(int n1, int n2, int n3)
{  
    int m=maior2(n1,n2);
    return maior2(n3,m);
}
//q3
int main()
{
    int a=5,b=10,c=3,d=7,e=9,f=17;
    printf("Maior entre %d e %d é %d\n",a,b,maior2(a,b));
    printf("Maior entre %d, %d e %d é %d\n",a,b,c,maior3(a,b,c));
    printf("%d\n",maior2(maior2(a,f),maior2(maior2(c,d),e)));
    return 0;
}