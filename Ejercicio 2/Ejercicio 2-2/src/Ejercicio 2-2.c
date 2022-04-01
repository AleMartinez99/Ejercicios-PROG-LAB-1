/*
 Ingresar 10 números enteros, distintos de cero. Mostrar:Cantidad de pares e impares.
 El menor número ingresado.De los pares el mayor número ingresado.Suma de los positivos.Producto de los negativos.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int num;
	int cantPares = 0;
	int cantImpares = 0;
	int minimo;
	int maxPar;
	int flag = 1;
	int sumaPositivos = 0;
	int productoNegativos = 1;
	int cantNegativos = 0;

	for(int i = 0; i < 10; i++) {
		printf("Ingrese num:");
		scanf("%d", &num);

		while(num == 0) {
			printf("ERROR... Ingrese numero distinto de 0:");
			scanf("%d", &num);
		}

		if(num < minimo || i == 0) {
			minimo = num;
		}

		if(num % 2 == 0) {
			if(num > maxPar || flag) {
				maxPar = num;
				flag = 0;
			}
			cantPares++;
		} else {
			cantImpares++;
		}

		if(num > 0) {
			sumaPositivos += num;
		} else {
			productoNegativos *= num;
			cantNegativos++;
		}
	}
	printf("Cantidad pares: %d\n",cantPares);
	printf("Cantidad impares: %d\n",cantImpares);
	printf("Menor numero: %d\n", minimo);
	if(!cantPares) {
		printf("No se ingresaron pares\n");
	} else {
	printf("Mayor numero par: %d\n", maxPar);
	}
	printf("Suma positivos: %d\n", sumaPositivos);
	if(!cantNegativos) {
		printf("No se ingresaorn numeros negativos para multiplicar\n");
	} else {
		printf("Producto de los negativos: %d\n", productoNegativos);
	}
	return EXIT_SUCCESS;
}
