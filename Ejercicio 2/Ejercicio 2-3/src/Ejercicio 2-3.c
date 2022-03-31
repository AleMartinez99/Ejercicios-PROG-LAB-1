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
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroCliente;
	char estadoCivil;
	int edad;
	float tempCorporal;
	char sexo;
	int cantViudosMas60 = 0;
	int numClienteSolteraJoven;
	int edadSolteraJoven;
	int flag = 1;
	int seguir = 1;
	int cantPersonas = 0;
	const int PRECIO = 600;
	int precioViaje;
	int precioViajeConDescuento;
	int cantMayores60 = 0;

	do {
		printf("Ingrese num de cliete: ");
		scanf("%d", &numeroCliente);

		printf("Ingrese estado civil: s para soltero, c para casado, v para viudo: ");
		fflush(stdin);
		scanf("%c",&estadoCivil);
		estadoCivil = tolower(estadoCivil);

		while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v') {
			printf("ERROR...Ingrese estado civil: s para soltero, c para casado, v para viudo: ");
			fflush(stdin);
			scanf("%c",&estadoCivil);
			estadoCivil = tolower(estadoCivil);
		}

		printf("Ingrese edad: ");
		fflush(stdin);
		scanf("%d", &edad);

		while(edad < 18) {
			printf("ERORR...Ingrese edad mayor a 17: ");
			fflush(stdin);
			scanf("%d", &edad);
		}

		printf("Ingrese temperatura: ");
		fflush(stdin);
		scanf("%f", &tempCorporal);

		while(tempCorporal < 35 || tempCorporal > 37.5) {
			printf("ERROR... Ingrese temperatura entre 35 y 37.5: ");
			fflush(stdin);
			scanf("%f", &tempCorporal);
		}

		printf("Ingrese sexo: m para masculino, f para femenino, o para no binario: ");
		fflush(stdin);
		scanf("%c",&sexo);
		sexo = tolower(sexo);

		while(sexo != 'm' && sexo != 'f' && sexo != 'o') {
			printf("ERROR...Ingrese sexo: m para masculino, f para femenino, o para no binario: ");
			fflush(stdin);
			scanf("%c",&sexo);
			sexo = tolower(sexo);
		}

		printf("Desea ingresar otro pasajero:\n1 - SI\n0 - NO");
		fflush(stdin);
		scanf("%d", &seguir);

		while(seguir != 1 && seguir != 0) {
			printf("ERROR...Desea ingresar otro pasajero:\n1 - SI\n0 - NO");
			fflush(stdin);
			scanf("%d", &seguir);
		}

		cantPersonas++;

		if(edad > 60) {
			cantMayores60++;
			if(estadoCivil == 'v') {
				cantViudosMas60++;
			}
		}

		if(sexo == 'f' && (edad < edadSolteraJoven || flag)) {
			flag = 0;
			numClienteSolteraJoven = numeroCliente;
			edadSolteraJoven = edad;
		}



	}while(seguir);

	precioViaje = PRECIO * cantPersonas;


	printf("A - Cantidad de personas con estado viudo de m�s de 60 a�os: %d\n", cantViudosMas60);
	printf("B - Numero cliente de soltera mas joven: %d\n", numClienteSolteraJoven);
	printf("Edad de soltera mas joven: %d\n", edadSolteraJoven);
	printf("C - Precio total del viaje: %d\n", precioViaje);
	if(cantMayores60 > (cantPersonas / 2) ) {
			precioViajeConDescuento = precioViaje / 1.25;
			printf("M�s del 50 porciento de los pasajeros que tiene m�s de 60 anios, el precio final con descuento es: %d\n", precioViajeConDescuento);
		}

	return EXIT_SUCCESS;
}
