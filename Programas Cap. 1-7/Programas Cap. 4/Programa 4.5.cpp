#include <stdio.h>
/* Cubo-3.
El programa calcula el cubo de los 10 primeros n�meros naturales con la
? ayuda de una funci�n y utilizando par�metros por valor.*/

int cubo(int); /* Prototipo de funci�n. El par�metro es de
? tipo entero. */
int main(void)
{
int I;
for (I = 1; I <= 10; I++)
printf("\nEl cubo de I es:%d",cubo(I));

}
int cubo(int K) 
{
return (K*K*K);
}
