/*
Programa:	euclides.c
Sinopsis:	Cálculo del MCD por el algoritmo de Euclides 
		Se trata de encontrar el CMD entre dos valores dados
		Se divide sucesivamente entre el resto encontrado mientras
		el resto no sea cero
		El último resto hallado es el MCD, es decir, el mayor  
		de los divisores con resto cero.

		version estructurada, iterativa
@version:	1.0
@date:		Enero 2018 
@author:	Paco González Moya
*/
#include<stdio.h>
int main () {
  int x, y;			//Operandos para el MCD
  int x_inicial, y_inicial;	//valores iniciales de x e y
  int resto;			//resto de la division entera
  int mcd;			//valor del mcd;  
      

  printf ("\nCálculo del MCD por el método exhaustivo\n");
  printf ("\tTeclear el primer valor (mayor): ");
  scanf ("%i", &x);
  printf ("\tTeclear el segundo valor (menor): ");
  scanf ("%i", &y);

  //salvamos los valores originales
  x_inicial=x;
  y_inicial=y;

  //Calculamos el primer resto	
  resto = x % y;
  if (resto == 0) {
    //En este caso, y es el MCD	
    mcd = y;
  } else {
    //En caso contrario, iteramos (al menos una vez)
    //para encontrar el MCD		
      do {
	  x = y;		//Desplazamos factores y->x
	  y = resto;		//El divisor es ahora resto
	  resto = x % y;	//Calculamos el nuevo resto
      } while (resto != 0);	//Seguimos hasta hallar un divisor entero

      //Llegados a este punto, el mcd es y	
      mcd = y;
    }
  printf ("\n\tMCD(%i, %i) es %i\n", x_inicial, y_inicial, mcd);
  return 0;
}
