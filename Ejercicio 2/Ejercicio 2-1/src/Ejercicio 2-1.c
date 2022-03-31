/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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
