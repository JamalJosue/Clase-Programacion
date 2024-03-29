#include <stdio.h>
/* Frecuencia de calificaciones.
El programa, al recibir como datos las calificaciones de un grupo de 50
?alumnos, obtiene la frecuencia de cada una de las calificaciones y adem�s
?escribe cu�l es la frecuencia m�s alta. */
const int MAX = 10; 
void Lectura(int VEC[], int T);
void Imprime(int VEC[], int T); 
void Producto(int *X, int *Y, int *Z, int T); 

int main(void)
{
  int VE1[MAX], VE2[MAX], VE3[MAX];
  
  Lectura(VE1, MAX);
 
  Lectura(VE2, MAX);
  Producto(VE1, VE2, VE3, MAX);
  printf("\nProduct of Vectors\n");
  Imprime(VE3, MAX);
  return 0;
}

void Lectura(int VEC[], int T)
{
  int I;
  printf("\n");
  for (I = 0; I < T; I++)
  {
    printf("Enter element %d: ", I + 1);
    scanf("%d", &VEC[I]);
  }
}

void Imprime(int VEC[], int T) 
{
  int I;
  for (I = 0; I < T; I++)
    printf("\nVEC[%d]: %d", I + 1, VEC[I]);
}

void Producto(int *X, int *Y, int *Z, int T)
{
  int I;
  for (I = 0; I < T; I++)
    Z[I] = X[I] * Y[I];
}
