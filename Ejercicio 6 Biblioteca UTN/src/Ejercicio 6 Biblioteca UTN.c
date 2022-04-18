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
#include <string.h>
#include <ctype.h>

int utn_getNumeroEntero( int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);
int utn_getNumeroFlotante( float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo);
int utn_getNumeroFlotanteSoloMinimo(float* pResultado,char* mensaje,char* mensajeError,float minimo);
int utn_getCaracter( char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo);
int mi_validarEntre2Caracteres(char* pResultado,char* mensaje,char* mensajeError,char a,char b);
int mi_validarLargoCadena(char cadena[]);
int mi_corregirUnaCadena(char cadena[]);

int main(void) {

	setbuf(stdout, NULL);

	char nombre[20] = "aleJAndRO";


	mi_corregirUnaCadena(nombre);
	printf("%s", nombre);



	/*
	printf("Mi cadena tiene: %d caracteres",mi_validarLargoCadena(nombre));
	*/

	return EXIT_SUCCESS;
}

int mi_corregirUnaCadena (char cadena[]) {

    int ok= 0;

    if(cadena != NULL) {
        ok = 1;
        strlwr(cadena);
        cadena[0] = toupper(cadena[0]);
    }
    return ok;
}

int mi_validarLargoCadena(char cadena[]) {

    int cantidad = 0;

    if(cadena != NULL) {

        while(cadena[cantidad] != '\0') {
            cantidad++;
        }
    }
  return cantidad;

}

int mi_validarEntre2Caracteres(char* pResultado,char* mensaje,char* mensajeError,char a,char b) {

    int retorno = 0;
    char auxChar;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL ) {

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &auxChar);

            if(auxChar == a || auxChar == b) {
                *pResultado = auxChar;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);
            }
        } while(retorno != 1);
    }
    return retorno;
}

int utn_getNumeroEntero( int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo) {

    int retorno = 0;
    int auxInt;   // USO ESTE AUXILIAR PARA RECIEN CUANDO EL NUMERO ESTA VALIDADO LO PASO A LA VARIABLE RESULTADO

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo) {

       do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &auxInt);

            if(auxInt >= minimo && auxInt <= maximo) {
                *pResultado = auxInt;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);

            }

       }while(retorno != 1);
    }

    return retorno;
}



int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo) {

    int retorno = 0;
    float auxFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo) {

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%f", &auxFloat);

            if(auxFloat >= minimo && auxFloat <= maximo) {
                *pResultado = auxFloat;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);

            }
        }while(retorno != 1);
    }
    return retorno;
}

int utn_getCaracter( char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo) {

    int retorno = 0;
    char auxChar;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo) {

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &auxChar);

            if(auxChar >= minimo && auxChar <= maximo) {
                *pResultado = auxChar;
                retorno = 1;
                break;
            } else {
                printf("%s", mensajeError);
            }
        } while(retorno != 1);
    }
    return retorno;
}

int utn_getNumeroFlotanteSoloMinimo(float* pResultado,char* mensaje,char* mensajeError,float minimo) {

    int retorno = 0;
    float auxFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL) {

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%f", &auxFloat);

            if(auxFloat >= minimo ) {
                *pResultado = auxFloat;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);

            }
        }while(retorno != 1);
    }
    return retorno;
}
