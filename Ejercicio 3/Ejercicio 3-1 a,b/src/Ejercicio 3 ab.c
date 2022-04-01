/*
 A-Funciones
- Limpie la pantalla
- Asigne a la variable numero1 un valor solicitado al usuario
- Valide el mismo entre 10 y 100
- Realice un descuento del 5% a dicho valor a través de una función llamada realizarDescuento()
- Muestre el resultado por pantalla

B-Funciones
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores solicitados al usuario
- Valide los mismos entre 10 y 100
- Asigne a la variable operacion el valor solicitado al usuario
- Valide el mismo 's'-sumar, 'r'-restar
- Realice la operación de dichos valores a través de una función
- Muestre el resultado por pantalla
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void realizarDescuento(float* pNum);
float sumar(float n1, float n2);
float restar(float n1,float n2);

int main(void) {
	setbuf(stdout, NULL);

	float numero1;

	printf("Ingrese num1: ");
	scanf("%f", &numero1);

	while(numero1 < 10 || numero1 > 100) {
		printf("ERROR...Ingrese num1 emtre 10 y 100: ");
		scanf("%f", &numero1);
	}

	realizarDescuento(&numero1);

	printf("Con descuento: %.2f\n", numero1);
	system("pause");

	float numero2;
	float numero3;
	char operacion;

	printf("Ingrese num2: ");
	scanf("%f", &numero2);

	while(numero2 < 10 || numero2 > 100) {
		printf("ERROR...Ingrese num2 emtre 10 y 100: ");
		scanf("%f", &numero2);
	}

	printf("Ingrese num3: ");
	scanf("%f", &numero3);

	while(numero3 < 10 || numero3 > 100) {
		printf("ERROR...Ingrese num3 emtre 10 y 100: ");
		scanf("%f", &numero3);
	}

	printf("Que desea hacer:\ns - Suma\nr - Resta");
	fflush(stdin);
	scanf("%c", &operacion);
	operacion = tolower(operacion);

	while(operacion != 's' && operacion != 'r') {
		printf("ERROR...\nQue desea hacer:\ns - Suma\nr - Resta");
		fflush(stdin);
		scanf("%c", &operacion);
		operacion = tolower(operacion);
	}

	if(operacion == 's') {
		printf("La suma es: %.2f", sumar(numero2,numero3));
	} else {
		printf("La resta es: %.2f", restar(numero2,numero3));
	}
	return EXIT_SUCCESS;
}

void realizarDescuento(float* pNum) {
	*pNum = *pNum / 1.05;
}

float sumar(float n1, float n2) {
	return n1 + n2;
}

float restar(float n1, float n2) {
	return n1 - n2;
}




