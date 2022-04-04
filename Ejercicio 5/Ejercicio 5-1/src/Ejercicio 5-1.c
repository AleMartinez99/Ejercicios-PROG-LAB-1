/*
Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int n;
	int acumulador = 0;

	for(int i = 0; i< 5;i++) {
		printf("Ingrese numero:");
		scanf("%d", &n);

		acumulador += n;
	}
	printf("La suma es: %d", acumulador);
	return EXIT_SUCCESS;
}
