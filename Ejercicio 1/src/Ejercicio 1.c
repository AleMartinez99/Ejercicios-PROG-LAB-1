/*
a-Salida/Eclispe/Compilar
Crear un proyecto desde cero en Eclipse y modificar en el mensaje
de "Hello world" por el de "Bienvenidos a Programación 1-UTN".

b-Entrada/salida
Pedir el sueldo al usuario. Sumarle un 10% e informarle cuál será su sueldo con aumento.

c-Control de Flujo
Pedirle al usuario su edad y su estado civil ('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado)
Si ingresa una edad menor a 18 años y un estado civil distinto a "Soltero",
mostrar el siguiente mensaje: 'Es muy pequeño para NO ser soltero.'

d-Operadores Logicos
Aplicando el concepto de Operadores Lógicos con valores booleanos en el condicional:
Solicitar un número al usuario
Informar si el mismo es par o impar.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
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
