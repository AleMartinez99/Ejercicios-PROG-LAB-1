/*
Ejercicio 4-2:
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit , validando que las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.

 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "tranformartemperatuas.h"

int main(void) {
	setbuf(stdout, NULL);

	float celsius;
	float fahrenheit;
	float celsiusAFahre;
	float fahreACelsius;


	validarRango(&celsius,"Ingrese temperatura en Celsius: ","ERROR... Rango de 0 a 100\n",0,100);
	validarRango(&fahrenheit,"Ingrese temperatura en Fahrenheit: ","ERROR... Rango de 0 a 100\n",32,212);
	celsiusAFahr(celsius,&celsiusAFahre);
	fahrACelsius(fahrenheit,&fahreACelsius);

	printf("\n%.2f°C son %.2f°F\n",celsius,celsiusAFahre);
	printf("%.2f°F son %.2f°C\n",fahrenheit,fahreACelsius);

	return EXIT_SUCCESS;
}
