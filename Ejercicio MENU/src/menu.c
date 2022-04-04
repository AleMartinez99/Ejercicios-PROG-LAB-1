/*
 * menu.c
 *
 *  Created on: 3 abr 2022
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu() {

	int opcion;

	printf("MENU COMPRAS:\n");
	printf("1- Loguearse\n");
	printf("2- Comprar\n");
	printf("3- Ver mis compras\n");
	printf("4- Vender\n");
	printf("5- Salir\n");
	printf("Ingrese opcion:");
	scanf("%d", &opcion);

	return opcion;
}

int subMenu() {

	int opcion;

	printf("Que desea hacer\n");
	printf("1- Vender\n");
	printf("2- Hacer Factura\n");
	printf("3- Volver atras\n");
	scanf("%d", &opcion);

	return opcion;
}

