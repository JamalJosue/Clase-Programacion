#include <stdio.h>
/* Cuenta-n�meros.
El programa, al recibir como datos un arreglo unidimensional de tipo
?entero y un n�mero entero, determina cu�ntas veces se encuentra el
?n�mero en el arreglo. */
int main(void)
{
int I, NUM, CUE = 0;
int ARRE[100];
for (I=0; I<100; I++)
{
printf("Ingrese el elemento %d del arreglo: ", I+1);
scanf("%d", &ARRE[I]); 
}
printf("\n\nIngrese el n�mero que se va a buscar en el arreglo:");
scanf("�%d", &NUM);
for (I=0; I<100; I++)
if (ARRE[I] == NUM) 
CUE++;
printf("\n\nEl %d se encuentra %d veces en el arreglo", NUM, CUE);
}
