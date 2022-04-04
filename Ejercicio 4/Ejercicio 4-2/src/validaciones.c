/*
 * validaciones.c
 *
 *  Created on: 3 abr 2022
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int validarRango(float* pTemperatura, char mensaje[],char mensajeError[], int minimo, int maximo) {

	int estaEnElRango = 0;
	float auxResultado;

	do {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &auxResultado);

		if(auxResultado >= minimo && auxResultado <= maximo) {
			*pTemperatura = auxResultado;
			estaEnElRango = 1;
		} else {
			printf("%s", mensajeError);
		}

	}while(estaEnElRango == 0);

	return estaEnElRango;
}
