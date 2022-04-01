/*
Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la aplicación con distintos valores.
Ejemplo 1:  3 - 5 - 7 - 9 - 1
Ejemplo 2:  2 - 1 - 8 -1 - 2
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int num;
	int acumulador = 0;
	float prom;

	for(int i = 0;i< 5;i++) {
		printf("Ingrese num: ");
		scanf("%d", &num);

		acumulador += num;

	}

	prom =(float) acumulador / 5;

	printf("El prom es: %.2f", prom);

	return EXIT_SUCCESS;
}
