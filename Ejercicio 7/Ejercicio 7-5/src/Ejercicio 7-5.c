/*
Ejercicio 7-5: Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo: Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:Gomez, Juan Ignacio
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

int main() {

	setbuf(stdout, NULL);

    char nombre[20];
    char apellido[20];
    char nombreCompleto[39];
    int i = 0;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);

    strcpy(nombreCompleto,apellido);

    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto,nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0] = toupper(nombreCompleto[0]);
    while(nombreCompleto[i] != '\0') {
    	if(nombreCompleto [i] == ' ') {
    		nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
    	}
    	i++;
    }
    printf("%s", nombreCompleto);

    return 0;
}
