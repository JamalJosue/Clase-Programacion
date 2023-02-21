#include <stdio.h>
#include <math.h>
/* Suma cuadrados.
El programa, al recibir como datos un grupo de enteros positivos, obtiene el
?cuadrado de los mismos y la suma correspondiente a dichos cuadrados. */
int main(void)
{
int NUM;
long CUA, SUC = 0;
printf("\nIngrese un número entero -0 para terminar-:\t");
scanf("%d", &NUM);
while (NUM)

{
CUA = pow (NUM, 2);
printf("%d al cuadrado es %ld", NUM, CUA);
SUC = SUC + CUA;
printf("\nIngrese un número entero -0 para terminar-:\t");
scanf("%d", &NUM);
}
printf("\nLa suma de los cuadrados es %ld", SUC);
}
