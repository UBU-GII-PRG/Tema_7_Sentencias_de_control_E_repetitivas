/*
Programa:	abinario.c
Sinopsis:	Calcula el binario correspondiente al número N
		Versión iterativa
@autor: 	Paco González Moya
@version: 	1.0
@date:	 	feb 2018	
*/
#include<stdio.h>
void abinario (unsigned int n);

int main() {
	unsigned int n=0;	//valor natural que vamos a pasar a binario
	int x=0;		//variable auxiliar para scnaf
	

	//Solicitamos el valor de n
	printf("\nTeclea un número natural[0..100]: ");
	x=scanf("%u", &n);
	x++; //evitamos el warning

	//Llamamos de forma recursiva
	abinario(n);
	printf("\n");
	return 0;
}

/**
void abinario (unsigned int n)
@param unsigned int n E/ número a traducir a binario
@return void
*/
void abinario (unsigned int n) {
	//Si n>1, resolvemos el problema con n/2 y ponemos al final 1 o cero
	//según sea par o impar el actual N
	//Al final, se obtiene la descomposición binaria	
	unsigned int i;		//variable de control de bucle	
	

	
	for (i=n; i>=1;i/=2) {
		//..luego escribimos 1 o cero
		if (i%2==0) {
			printf("%u", 0);
		} else {	
			printf("%u", 1);
		}
	}


	return;	
}

