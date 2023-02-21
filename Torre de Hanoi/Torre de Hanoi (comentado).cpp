//Comentarios modificados by Jamal Espinoza 2022-0061
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 

void imprime( int *tab, int fil, int col, int ultNum )
// Se declaran las variables o condiciones de tipo entero que definen el funcionamiento del programa//
{
    int f, c;
    int i, esp;//se declaran variables de tipo entero para definir los espacios entre los discos
    
    
    
    for( c=col-1; c >= 0; c-- )
    {
        for( f=0; f < fil; f++ )
        {
            esp = ( ultNum - tab[col*f+c] )/2;
        //Se usan dos for, uno para definir el numero de columnas
		//y otro para la cantidad de filas. Luego la variable
		//esp es usada para definir el epacio entre las columnas.

 

// Espacios a la izquierda. Este for define los espacios que se mueven los discos; en esta caso a la izquierda.
            for( i=0; i < esp; i++ )
                printf( " " );

 

// Imprime los comodines. Esta for en combinación con el printf, imprimen el "*" como representacion de los discos
            for( i=0; i < tab[col*f+c]; i++ )
                printf( "*" );

 

// Espacios a la derecha. Este for define los espacios que se mueven los discos; en esta caso a la izquierda.
            for( i=0; i < esp; i++ )
                printf( " " );

 

            printf( "\t" );// hay un espacio
        };

 

        printf( "\n" );//Termina una línea y comienza otra
    };

};

 


void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )
{
    /*
   Se dclaran las variables de tipo entero que definen los numeros de la matríz, tango como 
   los movimientos de los discos y los numeros que ocupa para disco dentro de la matríz.
    */
    
    int cO=col-1, cD=col-1;

// Se busca el disco que se encuentre mas arriba y por lo tanto el mas pequeño de la fila de origen.
    while( cO >= 0  &&  tab[col*filOrig+cO] == 0 )
    {
        cO--;
    };
    if( cO < 0 )
        cO = 0;

// Se calcula cuál es la posición libre mas arriba de la fila de destino
    while( cD >= 0  &&  tab[col*filDest+cD] == 0 )
    {
        cD--;
    };

// Se mueve el disco de la fila de origen a la de destino:
    tab[col*filDest+cD+1] = tab[col*filOrig+cO];
    tab[col*filOrig+cO] = 0;


// Se imprime el tablero:
    imprime( tab, fil, col, ultNum );
};


void delay(int tiempo)
{
  //sleep(tiempo):se define un pequeño retardo para que se pueda notar los movimentos de los discos.

    int c, d;
    while(tiempo >= 0)
    {
        for (c = 1; c <= 10000; c++)
            for (d = 1; d <= 10000; d++)
            {}
        tiempo--;
    }

}


void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )
{
    /*
    Aquí se declara un puntero que apunta a la matríz de tipo entero y se declaran los numeros dentro
    de la matríz, los cuales corresponden tanto a los discos como a los numeros de filas y columnas.
    */

    if( disc==1 )// condiciones
    {
// Se borra la pantalla, se imprime la tabla y se hace una pausa que varia dependiendo del numero de discos:
        system("cls");
      //system("clear");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
    }
    else// acciones
    {
        hanoi( tab, fil, col, disc-1, ultNum, O, D, A );

        system("cls");
        //system("clear");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);

        hanoi( tab, fil, col, disc-1, ultNum, A, O, D );
    };

};

int main()
{
    int fil=3, col, *tablero = NULL;
    int f, c, disc=1, ultNum;

    printf( "Indique el numero de discos: " );
    scanf( "%i", &col );

 
    tablero = (int *)malloc( sizeof(int)*fil*col );


// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
    for( f=0; f < fil; f++ )
        for( c=col-1; c >= 0; c-- )
            if( f==0 )
            {
                tablero[col*f+c] = disc;
                disc+=2;
            }
            else
                tablero[col*f+c] = 0;


    ultNum = disc;
 

// Se imprime el tablero antes de iniciar ningún movimiento:
    //system("cls");
    system("clear");
    imprime( tablero, fil, col, ultNum );
    delay(6);


// Se llama a hanoi para comenzar "la partida":
    hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 );
};
