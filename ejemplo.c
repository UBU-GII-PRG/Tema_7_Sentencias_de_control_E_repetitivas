#include <stdio.h>

long int factorial(int n);

int main()
{


int lado = 5;
char car = 'R';
int i, j;


    /* Itera sobre cada fila */
    for(i=1; i<=lado; i++)
    {
        /* Itera sobre cada columna */
        for(j=1; j<=lado; j++)
        {
            if(i==1 || i==lado || j==1 || j==lado) 
            {
                /* Imprime caracteres */
                printf("%c", car);
            }
            else
            {
                printf(" ");
            }
        }

        /* Intro */
        printf("\n");
    }
    printf("%ld\n", factorial(5));
    return 0;
}

long int factorial(int n){
                long int nfactor=1L;
                if (n>0){
                nfactor = n*factorial(n-1);
                }
            return nfactor;
        }
