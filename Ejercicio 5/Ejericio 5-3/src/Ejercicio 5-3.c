/*
Ejercicio 5-3:
Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
La carga deberá ser aleatoria (todos los elementos se inicializarán en cero por default.
Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores.
Utilizar funciones y arrays.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void mi_tomarEnteroSinLimit(int num[], char mensaje[], char mensajeError[], int distinto);
int initNumeros(int num[], int tam);

int main(void) {
	setbuf(stdout, NULL);

	int numeros[TAM];
	int contPositivos = 0;
	int acumuladorPositivos = 0;
	float promPositivos;
	int flagMin = 1;
	int minNegativo;
	int acumuladorAntecesores = 0;

	if(!initNumeros(numeros,TAM)) {
		printf("No se pudo inicializar en 0 el array\n");
	}

	for(int i = 0; i < TAM;i++) {
		mi_tomarEnteroSinLimit(&numeros[i], "Ingrese num distinto de 0:", "ERROR...\n", 0);

		if(numeros[i] > 0) {
			contPositivos++;
			acumuladorPositivos += numeros[i];
		} else {
			if(numeros[i] < minNegativo || flagMin) {
				flagMin = 0;
				minNegativo = numeros[i];
			}
		}

	}
	promPositivos = (float)acumuladorPositivos / contPositivos;

	printf("Promedio de los positivos: %.2f\n", promPositivos);
	for(int i = minNegativo + 1; i < 0; i++) {
		acumuladorAntecesores += i;
	}
	printf("Suma de los antecesores del menor negativo: %d\n", acumuladorAntecesores);

	return EXIT_SUCCESS;
}

int initNumeros(int num[], int tam) {
	int ok = 0;

	if(num != NULL && tam > 0) {
		ok = 1;
		for(int i = 0;i < tam;i++) {
			num[i] = 0;
		}
	}
	return ok;
}

void mi_tomarEnteroSinLimit(int *num, char mensaje[], char mensajeError[], int distinto) {

	int auxNum;
	int ok = 0;

	do {
		printf("%s", mensaje);
		scanf("%d", &auxNum);
	if(auxNum == distinto) {
		printf("%s", mensajeError);
	} else {
		*num = auxNum;
		ok = 1;
	}
	}while(ok == 0);
}
