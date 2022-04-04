/*
 * tranformartemperatuas.c
 *
 *  Created on: 3 abr 2022
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include "tranformartemperatuas.h"


void celsiusAFahr(float celsius, float* celsiusAFahre) {
	*celsiusAFahre = (celsius * 9/5) + 32;
}


void fahrACelsius(float fahrenheit , float* fahreACelsius) {
	*fahreACelsius = (fahrenheit - 32) * 5/9;
}

