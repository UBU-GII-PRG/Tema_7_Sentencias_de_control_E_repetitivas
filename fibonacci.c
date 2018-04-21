/*
Programa:	fibonacci.c
Sinopsis:	Calcula el k-ésimo término de la conocida sucesión de Fibonacci
		Versión iterativa
@autor: 	Paco González Moya
@version:	1.0
@date:		feb 2018	
*/
#include<stdio.h>
long Fibonacci(int k);
 
int main() {
	int k=0;	//k-ésimo término a solicitar
	int x=0;	//variable auxiliar para scnaf
	long f=0;	//valor del término

	//Solicitamos el valor de k
	printf("\nTeclea un número natural[0..50]: ");
	x=scanf("%i", &k);
	x++; //evitamos el warning
	
	//Cáĺculos
	f=Fibonacci(k);

	//Resultados
	printf("\nEl término %i-ésimo de Fibonacci es: %ld\n", k, f);
	return 0;
}

/**
long Fibonacci (int k)
@param int k E/ ordinal de término k-ésimo de la serie Fibonnaci a calcular
@return k-ésimo término de la serie
Función recursiva
*/

long Fibonacci(int k) {
	long fibo=1L;	//variable auxiliar para el cálculo
	long i;		//variable de control de bucle
	long f_1=1L; 
	long f_2=1L;	//valor de los dos términos anteriores de la sucesión

	if (k==0 || k==1)	//Caso particular para los dos primeros términos
		fibo=1;
	else {
		//Caso general: bucle FOR de cálculo
		for (i=2; i<=k;i++) {
			f_2 = f_1;	//pasamos f_1 a la variable f_2
			f_1 =fibo;	//dejamos en f_1 el valor calculado en anterior iteracion
			fibo = f_1 + f_2; //nuevo término de la sucesión
		}
	}
	return fibo;	
}
