#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
// EJERCICIO 1A
	printf("Bienvenidos a Programación 1-UTN\n");

	system("pause");

// EJERCICIO 1B
	float sueldo;
	float sueldoAumentado;

	printf("Ingrese sueldo: ");
	fflush(stdin);
	scanf("%f", &sueldo);

	sueldoAumentado = sueldo * 1.10;

	printf("Su sueldo con 10 porciento de aumento es: %.2f\n", sueldoAumentado);

	system("pause");

// EJERCICIO 1C
	int edad;
	char estadoCivil;

	printf("Ingrese edad: ");
	//fflush(stdin);
	scanf("%d", &edad);

	printf("Ingrese estado civil s,c,d: ");
	fflush(stdin);
	scanf("%c", &estadoCivil);

	while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'd') {
		printf("ERROR... Ingrese estado civil: ");
		fflush(stdin);
		scanf("%c", &estadoCivil);
	}
	if(edad < 18 && estadoCivil != 's') {
		printf("Es muy pequeño para NO ser soltero\n");
	}

	system("pause");

// Ejercicio 1D

	int num;

	printf("Ingrese numero: ");
	//fflush(stdin);
	scanf("%d", &num);

	if(num % 2 == 0) {
		printf("%d es par", num);
	} else {
		printf("%d no es par", num);
	}

	return EXIT_SUCCESS;
}
