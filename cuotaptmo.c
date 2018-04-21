/*
Programa: 	cuotaptmo.c
Sinopsis:	Cálculo de la cuota periódica en un préstamo a interés 
		constante calculado por el método francés.
		
		Incorpora además una tabla bidimensional de sensibilidad 
		de la evolución de la cuota, es decir, un recálculo 
		de la misma ante pequeños cambios en el tipo de interés 
		o el número de períodos.

		Puede resultar interesante, no sólo por aspectos docentes.


@autor:	 	Paco González Moya
@version: 	1.0
@date:		mar 2018	
*/
#include<stdio.h>
#include<math.h>

//Constantes que delimitan el tamaño de la tabla bidimensional
#define FILAS 4
#define COLUMNAS 5
//Constante para expresar porcentajes de interés en tantos por cien
#define CIEN 100	

//Períodos (meses) en un año
#define PERIODOS_ANIO 12



//Cálculo de la cuota por método frances
float cuotaFrances (unsigned int capital, float tipo_int, unsigned int nperiodos);

//Cuadro bidimensional de análisis de sensibilidad de la cuota respecto
//de pequeños cambios diferenciales en períodos o tipo de interés
void analisisSensibilidad (unsigned int capital, 
			float tipo_int, 
			unsigned int nperiodos, 
			unsigned int num_intereses, float diferencial_int, 
			unsigned int num_periodos, float diferencial_periodos);

 
int main() {
	int x=0;	//variable auxiliar para scanf

	unsigned int capital;		//capital de la inversión 
	unsigned int nperiodos;		//número de períodos de tiempo (meses)
	float tipo;			//tipo de interés del período
	float tipo_anual;		//tipo de interes anualizado
	float cuota;			//cuota de pago resultante

	unsigned int anios;		//número de años del préstamo
	unsigned int num_periodos;	//número de períodos (cols) en la tabla
	unsigned int num_intereses;	//número de ints (filas) en la tabla
	unsigned int diferencial_periodos;	//incremento en columnas
	float diferencial_interes;	//incremento en filas


	//Solicitamos el valor de capital, n periodos y tipo
	printf("\nTeclea el capital: ");
	x=scanf("%u", &capital);
	x++; //evitamos el warning
	
	printf("Teclea número de años: ");
	x=scanf("%u", &anios);
	x++; //evitamos el warning

	printf("Teclea el tipo de interes anual: ");
	x=scanf("%f", &tipo_anual);
	x++; //evitamos el warning

	//Establecemos tipos mensual y períodos
	tipo = tipo_anual / PERIODOS_ANIO / CIEN;
	nperiodos = anios * PERIODOS_ANIO;

	//Cálculo de la cuota
	cuota=cuotaFrances (capital, tipo, nperiodos);

	//Resultado de los cálculos, en formato sencillo
	printf("\nCapital: %6u", capital);
	printf("\nTipo anual: %1.2f (%1.2f período)", tipo_anual, tipo*CIEN);
	printf("\nAños: %u (%u períodos)", anios, nperiodos);
	printf("\nCuota: %6.2f\n", cuota);

	
	//tabla de análisis de sensibilidad
	
	//Establecemos el valor de los parámetros que gobiernan la tabla
	num_periodos=COLUMNAS;
	num_intereses=FILAS;
	diferencial_periodos=PERIODOS_ANIO;
	diferencial_interes = tipo / (num_intereses-1); //una forma sencilla de establecerlo

	//llamada a la tabla
	analisisSensibilidad (capital, tipo, nperiodos,
		num_intereses, diferencial_interes,
		num_periodos, diferencial_periodos); 

	return 0;
}

/**
float cuotaFrances (unsigned int capital, float tipo_int, unsigned int nperiodos)  
@param unsigned int capital  	E/ capital del préstamo
@param float tipo		E/ tipo de interes del período
@param unsigned int nperiodos	E/ número de períodos
@return el valor de la cuota
*/

float cuotaFrances (unsigned int capital, float tipo_int, unsigned int nperiodos)  {
	float factor=0.0;	//factor potencial que se repite en el cálculo
	float cuota=0.0;	//cuota calculada
/*
***************************************************************************
	NOTA IMPORTANTE

	El cálculo de la cuota periódica para un préstamo calculado por el 
	método francés sigue la sigiente expresición
	
	 	tipo_int * (1+tipo_int)^nperiodos 
		---------------------------------- * capital
		(1+tipo_int)^nperiodos -1

	vemos que hay un factor (1+_tipo_int)^nperiodos que se repite
	y que podemos calcular aisladamente en una variable "factor"

	Hay que tener en cuenta que tipo_int debe referirse al tipo relativo
	al tipo de período (int mensual si períodos de pago son mensuales)

	Ejm: 	capital -> 50.000
		tipo -> 6.0 (0.5% mensual, equivale a 6% anual)
		periodos -> 300 (meses, equivale a  25 años)
		cuota -> 322.15 eur / periodo

***************************************************************************
*/
	
	//cálculo del factor
	factor = pow((1.0 + tipo_int), nperiodos);
	//cálculo de la cuota
	cuota = capital*(tipo_int * factor) / (factor -1);

	//Valor del factorial
	return cuota;
}
/**
void analisisSensibilidad (unsigned int capital, float tipo_int, unsigned int nperiodos, unsigned int num_intereses, float diferencial_interes, unsigned int num_periodos, float diferencial_periodo) 

Permite realizar una tabla bidimensional en filas y columnas para mostrar la evolución de la cuota del préstamo ante variaciones en tipos de interes (filas) o en fracciones de tiempo (columnas).

@param unsigned int capital	E/ Capital comprometido en el préstamo
@param float tipo_int		E/ Tipo de interés constante en el préstamos
@param unsignd int nperiodos	E/ Número de períodos (meses) de tiempo
@param unsigned int num_intereses	E/ Número de fracciones de interes para la tabla  (filas)
@param float diferencial_interes	E/ incremento de interés en cada fracción
@param unsigned int num_periodos	E/ Número de fracciones de períodos (meses) de la tabla (columnas)
@param float diferencial_periodo	E/ incremento de período en cada fracción
	
@return	void


*/


void analisisSensibilidad (unsigned int capital, 
		float tipo_int, 
		unsigned int nperiodos, 
		unsigned int num_intereses, float diferencial_interes, 
		unsigned int num_periodos, float diferencial_periodo) {

	float fila;		//variables de control de los bucle (filas)
	unsigned int col;	//variable de control de bucle (columnas)
	float cuota;		//valor calculado de la cuota en cada escenario 
				//tipo de interés vs número de períodos establecido. Un "escenario" por cada intersección fila - columna

	//Rótulo
	printf("\n\tSENSIBILIDAD de la CUOTA\n\ttipo interés vs períodos\n");
	printf("\t--------------------------------------\n\n");

	//Cabeceras de columna
	printf("\t--------------------------------------\n");
	for (col=nperiodos; col <nperiodos + num_periodos*diferencial_periodo; col+=diferencial_periodo) {
		printf("\t%6.0f", (float)col);
	}
	printf("\n");
	printf("\t--------------------------------------\n");


	//Tabla
	for (fila=tipo_int; fila < tipo_int +num_intereses*diferencial_interes; fila+=diferencial_interes){
	
		//En cabecera de columna mostramos el tipo en tanto por cien 
		//y anualizado
		printf("%5.2f", fila*CIEN*PERIODOS_ANIO);

		//Cálculo de la cuota en cada período, tipo interés constante
		for (col=nperiodos; col< nperiodos + num_periodos*diferencial_periodo; col+=diferencial_periodo) {
	
			//Cálculo de la cuota en cada tipo de interés
			cuota = cuotaFrances (capital, fila, col);
			printf("\t%6.2f", cuota);
		}	
		printf("\n");
		
	}
	printf("\t--------------------------------------\n");
	return;

}


