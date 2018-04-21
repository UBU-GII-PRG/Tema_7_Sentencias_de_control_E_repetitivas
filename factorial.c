/*
Programa: 	factorial.c
Sinopsis:	Calcula el factorial de un número N
		Versión iterativa

@autor:	 	Paco González Moya
@version: 	1.0
@date:		mar 2018	
*/
#include<stdio.h>
unsigned long Factorial(int n);
 
int main() {
	int n=0;	//n-ésimo valor cuyo factorial se desea
	int x=0;	//variable auxiliar para scnaf
	unsigned long f=0;	//valor del factorial

	//Solicitamos el valor de k
	printf("\nTeclea un número natural[0..50]: ");
	x=scanf("%i", &n);
	x++; //evitamos el warning
	
	//Cáĺculos
	f=Factorial(n);

	//Resultados
	printf("\nEl factorial de %d es : %lu\n", n, f);
	return 0;
}

/**
unsigned long Factorial (int n)
@param int n E/ ordinal de término cuyo factorial se desea calcular
@return el valor del factorial
Función recursiva
*/

unsigned long Factorial(int n) {
	unsigned long fact=1;	//variable auxiliar para el cálculo
	unsigned long i;	//variable de control de bucle

	//Bucle FOR de cálculo
	for (i=n; i>0;i--) {
		fact*=i;
	}
	//Valor del factorial
	return fact;	
}
