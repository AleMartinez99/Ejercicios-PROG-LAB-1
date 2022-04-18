/*
Ejercicio 7-2:

Crear un programa que permita registrar el valor de temperatura máxima de cada día de un mes.
Definir un array de float de 31 posiciones.
Cada posición corresponderá a un día.
Hacer un programa con un menú de dos opciones:
1- imprimir el array
2- cargar array
La opcion 1 imprimirá el índice, el número de día y el valor de cada posición del array
La opción 2 pedirá al usuario el día (1 a 31) y a temperatura. Guardará en la posición que corresponda.
Ambas opciones deben volver al menú principal.
 */

#include <stdio.h>
#include <stdlib.h>

#define DIAS 31

int inicializarArray(float array[], int len);
int utn_getNumeroEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo);

int main(void) {

	setbuf(stdout, NULL);

	float temperaturas[DIAS];
	int opcion;
	int diaElegido = 3;

	if(!inicializarArray(temperaturas,DIAS)){
		printf("No se pudo cargar el array\n");
	}

	do {
		printf("1- Mostrar Array\n");
		printf("2- Cargar ARRAY\n");
		printf("3- Salir\n");
		fflush(stdin);
		scanf("%d", &opcion);

		switch(opcion) {
			case 1:
				for(int i = 0;i<DIAS;i++) {
                	printf("Indice: %d, Num de dia: %d, Temperatura: %.2f\n", i,i+1,temperaturas[i]);
				}
				break;
			case 2:
				utn_getNumeroEntero(&diaElegido,"Seleccione un dia (1-31): ","Ingrese de 1 a 31: ",1,31);
				utn_getNumeroFlotante(&temperaturas[diaElegido],"Ingrese temperatura","De 0 a 100", 0,100);

				break;
			default:
			printf("OPCION INVALIDA\n");
		}
	}while(opcion != 3);

	printf("ha salido\n");
	system("pause");


	return EXIT_SUCCESS;
}


int inicializarArray(float array[], int len) {
	int ok = 0;
	if(array != NULL) {
		ok = 1;
		for(int i = 0; i< len;i++) {
			array[i] = 0;
		}
	}
	return ok;
}

int utn_getNumeroEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo) {

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
    float auxFloat;   // USO ESTE AUXILIAR PARA RECIEN CUANDO EL NUMERO ESTA VALIDADO LO PASO A LA VARIABLE RESULTADO

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

