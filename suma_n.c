/*
Programa: 	suma_n.c
Sinopsis:	Realiza la suma de los N primeros números naturales, excluido 0
		Versión iterativa, varias opciones

@autor:	 	Paco González Moya
@version: 	1.0
@date:		mar 2018	
*/
#include<stdio.h>
//Distintas versiones de la función, según el tipo de bucle
unsigned int Suma_N_v1(unsigned int n);
unsigned int Suma_N_v2(unsigned int n);
unsigned int Suma_N_v3(unsigned int n);


 
int main() {
	unsigned int n=0;	//n-ésimo valor cuya serie natural se desea
	int x=0;		//variable auxiliar para scnaf
	unsigned int suma_n;	//valor de la suma

	//Solicitamos el valor de k
	printf("\nTeclea un número natural[1..50]: ");
	x=scanf("%u", &n);
	x++; //evitamos el warning
	
	//Cáĺculos: version v1 -> bucle for
	suma_n=Suma_N_v1(n);

	//Resultados
	printf("\nV1 La suma de los %u primeros naturales es : %u\n", n, suma_n);
	//Cáĺculos: version v2 -> bucle do..while
	suma_n=Suma_N_v2(n);

	//Resultados
	printf("\nV2 La suma de los %u primeros naturales es : %u\n", n, suma_n);

	//Cáĺculos: version v3 -> bucle while
	suma_n=Suma_N_v3(n);

	//Resultados
	printf("\nV3 La suma de los %u primeros naturales es : %u\n", n, suma_n);


	return 0;
}

/**
unsigned int Suma_N_v1 (int n)
@param int n E/ ordinal de término cuya suma en serie se desea calcular
@return el valor de la suma
Función iterativa, FOR
*/

unsigned int Suma_N_v1 (unsigned int n) {
	unsigned int suma=0;	//variable auxiliar para el cálculo
	unsigned int i;		//variable de control de bucle

	//Bucle FOR de cálculo
	for (i=1; i<=n;i++) {
		suma+=i;
	}
	//Valor de la suma
	return suma;	
}


/**
unsigned int Suma_N_v2 (int n)
@param int n E/ ordinal de término cuya suma en serie se desea calcular
@return el valor de la suma
Función iterativa, bucle do..while
*/

unsigned int Suma_N_v2 (unsigned int n) {
	unsigned int suma=0;	//variable auxiliar para el cálculo
	unsigned int i=1;	//variable de control de bucle

	//Bucle do..while de cálculo
	do {
		suma+=i;
		i++;
	} while (i<=n);

	//Valor de la suma
	return suma;	
}


/**
unsigned int Suma_N_v3 (int n)
@param int n E/ ordinal de término cuya suma en serie se desea calcular
@return el valor de la suma
Función iterativa, bucle while
*/

unsigned int Suma_N_v3 (unsigned int n) {
	unsigned int suma=0;	//variable auxiliar para el cálculo
	unsigned int i=1;	//variable de control de bucle

	//Bucle while de cálculo
	while (i<=n) {
		suma+=i;
		i++;
	} 

	//Valor de la suma
	return suma;	
}

