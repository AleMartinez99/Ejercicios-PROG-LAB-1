/*
Hacer un programa para ingresar hasta 100 nombres.
Debe contar con el siguiente menú:
1- Ingresar nuevo nombre (no se aceptan nombres repetidos, informar si ocurre)
2- listar todos
3- Ordenar alfabeticamente
4- Borrar nombre. Se ingresa el nombre y si se encuentra, se elimina.
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

#define FILAS 5 // PASAR A 100 DESPUES DE LAS PRUEBAS
#define COLUMNAS 20

int inicializarNombres(char nombres[][COLUMNAS],int filas);
int buscarLibre(char nombres[][COLUMNAS],int filas);
int listarNombres(char nombres[][COLUMNAS],int filas);
int ingresarNombre(char nombres[][COLUMNAS],int filas);
int ordenarAlfabeticamente(char nombres[][COLUMNAS], int filas); // -1 sino pudo, 0 sino necesito hacer cambios, 1 si hizo cambios.
int borrarNombre(char nombres[][COLUMNAS],int filas);

int main(void) {

	setbuf(stdout, NULL);

	char nombres[FILAS][COLUMNAS];
	int opcion;
	int seguir = 1;

	inicializarNombres(nombres,FILAS);

	do {
		printf(" **** MENU ****");
		printf("\n1- Ingresar nuevo nombre\n");
		printf("2- Listar nombres\n");
		printf("3- Ordenar Alfabeticamente\n");
		printf("4- Borrar name\n");
		printf("Ingrese opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
		switch(opcion) {
			case 1:
				if(ingresarNombre(nombres,FILAS) == -1){
					printf("\nEl ARRAY esta lleno\n\n");
				}
				break;
			case 2:
				if(!listarNombres(nombres,FILAS)) {
					printf("\nNo hay personas para mostrar\n\n");
				}
				break;
			case 3:
				if(!ordenarAlfabeticamente(nombres,FILAS)) {
					printf("No es necesario hacer cambios o no hay personas para ordenar\n\n");
				} else {
					printf("Se ordeno correctamente\n\n");
				}
				break;
			case 4:
				if(!borrarNombre(nombres,FILAS)) {
					printf("No se encontro un nombre identico para borrar\n\n");
				} else {
					printf("Se borro correctamente\n\n");
				}
				break;
			case 5:
				printf("salio\n");
				seguir = 0;
				break;
			default:
				printf("Opcion invalida\n");
		}
	}while(seguir);

	return EXIT_SUCCESS;
}

int ingresarNombre(char nombres[][COLUMNAS],int filas) {

	int ok = -1;
	int indice = buscarLibre(nombres,filas);
	char auxChar[20];

	if(nombres != NULL && filas > 0 && indice > -1) {
		if(indice != -1) {
            ok = 0;
			printf("Ingrese nombre: ");
			scanf("%s",auxChar);
			for(int i = 0; i < filas;i++) {
				if(strcmp(nombres[i],auxChar) == 0) {
					printf("\nEl nombre ya existe\n");
					break;
				} else {
				ok = 1;
				}
			}
			if(ok == 1) {
				strcpy(nombres[indice],auxChar);
			}
		}

	}
	return ok;
}

int inicializarNombres(char nombres[][COLUMNAS],int filas) {

	int ok = 0;

	if(nombres != NULL && filas > 0) {
		ok = 1;
		for(int i = 0 ; i < filas;i++) {
			strcpy(nombres[i],"NO_NAME");
		}
	}
	return ok;
}

int buscarLibre(char nombres[][COLUMNAS],int filas) {
	int indice = -1;

	if(nombres != NULL && filas > 0) {
		for(int i = 0 ; i < filas ; i++) {
			if(strcmp(nombres[i],"NO_NAME") == 0) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int listarNombres(char nombres[][COLUMNAS],int filas) {
	int ok = 0;

	if(nombres != NULL && filas > 0) {
		printf("**** Listado de personas ****\n");
		for(int i = 0 ; i < filas ; i++) {
			if(strcmp(nombres[i],"NO_NAME") != 0) {
				printf("%s\n", nombres[i]);
				ok = 1;
			}
		}
	}
	return ok;
}



int ordenarAlfabeticamente(char nombres[][COLUMNAS], int filas) {
	int ok = -1;
	char auxChar[20];

	if(nombres != NULL && filas > 0) {
		ok = 0;
		for(int i = 0; i< filas - 1;i++) {
			for(int j = i + 1;j < filas; j++) {
				if(strcmp(nombres[i],nombres[j]) == 1) {
					ok = 1;
					strcpy(auxChar,nombres[i]);
					strcpy(nombres[i],nombres[j]);
					strcpy(nombres[j],auxChar);
				}
			}
		}

	}

	return ok;
}

int borrarNombre(char nombres[][COLUMNAS],int filas) {

	int ok = -1;
	char nombreParaBorrar[20];

	if(nombres != NULL && filas > 0) {
		ok = 0;
		listarNombres(nombres,filas);
		printf("Que nombre desea borrar: \n");
		fflush(stdin);
		gets(nombreParaBorrar);
		for(int i = 0;i<filas;i++) {
			if(strcmp(nombres[i],nombreParaBorrar) == 0) {
				strcpy(nombres[i],"NO_NAME");
				ok = 1;
			}
		}
	}
	return ok;
}
