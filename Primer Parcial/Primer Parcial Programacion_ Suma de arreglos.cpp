//Jamal Josué Cuello Epinoza 2022-0061//
#include <stdio.h>
#include <conio.h>

int main()
{

    int ar1[8], ar2[8], SumInv[8], i;

    printf("\nDigite los numeros del primer arreglo: ");

    for (i = 0; i < 8; i++)
    {
        scanf("%i", &ar1[i]);
    }

    printf("\nDigite los numeros del segundo arreglo: ");

    for (i = 0; i < 8; i++)
    {
        scanf("%i", &ar2[i]);
    }

    printf("\n\nLa sumatoria inversa de los dos arrays es: { ");

    for (i = 0; i < 8; i++)
    {
        SumInv[i] = ar1[i] + ar2[8 - (i+1)];
        printf("%i, ", SumInv[i]);
    }
    printf("}");

    getch();
    return 0;
}
