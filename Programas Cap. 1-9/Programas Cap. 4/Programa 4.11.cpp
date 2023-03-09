# include <stdio.h>
/* Mayor divisor.
El programa, al recibir como dato un n�mero entero positivo, calcula
? su mayor divisor. */
int mad(int); /* Prototipo de funci�n. */
int main(void)
{
int NUM, RES;
printf("\nIngresa el n�mero: ");
scanf("%d", &NUM);
RES = mad(NUM);
printf("\nEl mayor divisor de %d es: %d", NUM, RES);
}
int mad(int N1)
/* Esta funci�n calcula el mayor divisor del n�mero N1. */
{
	int I = (N1 / 2);
/* I se inicializa con el m�ximo valor posible que puede ser divisor
? de N1. */
while (N1 % I)
I--;
return I;
}
