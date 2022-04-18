/*
Ejercicio 7-3:
Realizar un programa que le pida 5 números enteros al usuario y los almacene en un array.
Crear una función borrarImpares que reciba el array y reemplace los númerosimpares por cero.
Ordenar el array según el criterio seleccionado por el usuario: ascendente o descendente.
El menú debe ser:
1. Ingresar números
2. Borrar impares
3. Mostrar
4. Ordenar
5. Salir

Si se selecciona la opción 4 debe aparecer el siguiente submenú:
1. Ascendentemente
2. Descendentemente
3. Volver atrás
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 5

int borrarImpares(int numeros[], int len);
int ordenarArray(int numeros[], int len, int criterio);
int utn_getNumeroEntero( int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);

int main(void) {

	setbuf(stdout, NULL);

	//int numeros[LEN] = {1,3,8,10,-5};
	int numeros[LEN];

	int opcion;
	int seguir = 1;

	do {
		printf("1. Ingresar numeros\n");
		printf("2. Borrar impares\n");
		printf("3. Mostrar\n");
		printf("4. Ordenar\n");
		printf("5. Salir\n");
		fflush(stdin);
		scanf("%d", &opcion);
		switch(opcion) {
			case 1:
				for(int i = 0;i<LEN;i++) {
					printf("Ingrese numero: ");
					fflush(stdin);
					scanf("%d", &numeros[i]);
				}
				break;
			case 2:
				borrarImpares(numeros,LEN);
				break;
			case 3:
				for(int i = 0;i<LEN;i++) {
					printf("%d ", numeros[i]);
				}
				printf("\n");
				break;
			case 4:
				printf("Desea ordenar de manera:\n");
				printf("1- Ascendente\n");
				printf("2- Descendente\n");
				utn_getNumeroEntero(&opcion,"","Ingrese 1 o 2",1,2);
				ordenarArray(numeros,LEN,opcion);
				break;
			case 5:
				seguir = 0;
				printf("salio");
				break;
			default:
				printf("Opcion invalida\n");
		}
	}while(seguir);

	return EXIT_SUCCESS;
}

int utn_getNumeroEntero( int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo) {

    int retorno = 0;
    int auxInt;  // USO ESTE AUXILIAR PARA RECIEN CUANDO EL NUMERO ESTA VALIDADO LO PASO A LA VARIABLE RESULTADO

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

int ordenarArray(int numeros[], int len, int criterio) {
	int ok = 0;
	int auxInt;

	if(numeros != NULL) {
		ok = 1;
		for(int i = 0; i < len -1;i++) {
			for(int j = i + 1;j < len;j++) {
				if((criterio == 1 && numeros[i] > numeros[j]) || (criterio  == 2 && numeros[i] < numeros[j]) ) {
					auxInt = numeros[i];
					numeros[i] = numeros[j];
					numeros[j] = auxInt;
				}
			}
		}
	}
	return ok;
}

int borrarImpares(int numeros[], int len) {
	int ok = 0;

	if(numeros != NULL) {
		ok = 1;
		for(int i = 0;i<len;i++) {
			if(numeros[i] % 2 != 0) {
				numeros[i] = 0;
			}
		}
	}
	return ok;
}
