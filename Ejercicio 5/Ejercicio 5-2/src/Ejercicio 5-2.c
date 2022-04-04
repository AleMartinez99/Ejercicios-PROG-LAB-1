/*
Pedir el ingreso de 10 números enteros entre -1000 y 1000.
Determinar:Cantidad de positivos y negativos.
Sumatoria de los pares.
El mayor de los impares.
Listado de los números ingresados.
Listado de los números pares.
Listado de los números de las posiciones impares.
Se deberán utilizar funciones y arrays.
 */

// NO USO BIBLIOTECAS PORQ NO LAS PIDE EL EJERCICIO.

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mi_tomarEntero(int *num, char mensaje[], char mensajeError[], int min, int max);

int main(void) {
	setbuf(stdout, NULL);

	int numeros[TAM];
	int listNumPares[TAM];
	int cantPares = 0;
	int posicionesImpar[TAM];
	int cantImpar = 0;
	int cantPositivos = 0;
	int cantNegativos = 0;
	int sumPares = 0;
	int flagImpar = 1;
	int maxImpar;

	for(int i =0; i< TAM;i++) {
		mi_tomarEntero(&numeros[i],"Ingrese numero de -1000 a 1000:","ERROR...\n", -1000,1000);

		if(numeros[i] > 0) {
			cantPositivos++;
		} else {
			cantNegativos++;
		}
		if(numeros[i] % 2 == 0) {
			listNumPares[cantPares] = numeros[i];
			cantPares++;
			sumPares += numeros[i];
		} else {
			posicionesImpar[cantImpar] = i;
			cantImpar++;
			if(numeros[i] > maxImpar || flagImpar) {
				flagImpar = 0;
				maxImpar = numeros[i];
			}
		}
	}
	printf("Positivos: %d\n", cantPositivos);
	printf("Negativos: %d\n", cantNegativos);
	printf("Suma de los pares: %d\n", sumPares);
	printf("El impar mas grande: %d\n", maxImpar);
	printf("Listado numeros ingresados:");
	for(int i = 0; i < TAM;i++) {
		printf("%d ", numeros[i]);
	}
	printf("\nListado numeros pares:");
	for(int i = 0; i < cantPares;i++) {
		printf("%d ", listNumPares[i]);
	}
	printf("\nListado posiciones impares:");
		for(int i = 0; i < cantImpar;i++) {
			printf("%d ", posicionesImpar[i]);
		}
	return EXIT_SUCCESS;
}

void mi_tomarEntero(int *num, char mensaje[], char mensajeError[], int min, int max) {

	int auxNum;
	int ok = 0;

	do {
		printf("%s", mensaje);
		scanf("%d", &auxNum);
	if(auxNum < min || auxNum > max) {
		printf("%s", mensajeError);
	} else {
		*num = auxNum;
		ok = 1;
	}
	}while(ok == 0);
}
