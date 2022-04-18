/*
Ejercicio 7-1: Hacer una función que se llame calcularMayor().
Debe recibir dos números enteros y devolver por referencia el mayor.
Debe retornar 1 si hay mayor o 0 si ambos son iguales.
 */

#include <stdio.h>
#include <stdlib.h>

int calcularMayor(int n1, int n2, int* mayor);

int main(void) {
	 setbuf(stdout, NULL);

	int mayor;

	if(calcularMayor(5,10,&mayor)) {
		printf("El mayor es: %d", mayor);
	} else {
		printf("Los numeros son iguales");
	}

	return EXIT_SUCCESS;
}

int calcularMayor(int n1, int n2, int* mayor) {
	int comparacion;

	if(mayor != NULL) {
		if(n1 > n2) {
			*mayor = n1;
			comparacion = 1;
		} else if (n1 < n2){
			*mayor = n2;
			comparacion = 1;
		} else {
			comparacion = 0;
		}
	}

	return comparacion;
}
