#include <stdio.h>
#include <stdlib.h>

int var;
int *ptr;
    int *ptr = &var;

printf("Endereco de var: %p\n", (void*)&var);
printf("Endereco de ptr: %p\n", (void*)&ptr);
printf("Valor de ptr: %p\n", (void*)ptr);
printf("Valor apontado por ptr: %d\n", *ptr);