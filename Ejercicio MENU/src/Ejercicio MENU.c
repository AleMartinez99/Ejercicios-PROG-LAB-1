/*
Nota:
Se deben hacer los ejercicios en orden. Al ingresar a cada punto de menú se debe indicar dónde estoy y al apretar una tecla salir del mismo. es decir que cada opción no tiene funcionalidad extra. En cualquier caso informar que está sucediendo: Ejemplo: "Primero se debe loguear".

A- Hacer el menú de un programa con las siguientes opciones: 1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir
B- Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó
C- Al menú anterior chequear que no pueda ver sus compras, si no ingresó primero a comprar al menos una vez
D- Cuando se ingresa a la opción vender del menú, debe abrirse otro menú que contenga: 1. Vender 2. Hacer factura 3. Volver atrás
E- A lo anterior sumarle que haya compras para poder vender. (Si compré una vez y vendí una vez no puedo ingresar a vender).
F- Pasar las acciones de menú a funciones y llevarlas a una biblioteca
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);

	int flagLoguin = 0;
	int flagCompra = 0;
	int salir = 0;
	int compras = 0;

	do {
		switch(menu()) {
			case 1:
				printf("Usted se ingreso con exito\n");
				flagLoguin = 1;
				break;
			case 2:
				if(flagLoguin == 0) {
					printf("Primedo debe loguearse\n");
				} else {
					printf("Compra realizada con exito\n");
					flagCompra = 1;
					compras++;
				}
				break;
			case 3:
				if(flagLoguin == 0) {
					printf("Primedo debe loguearse\n");
				}
				else if(flagCompra == 0) {
					printf("Primedo debe comprar\n");
				} else {
					printf("Visualizando compras\n");
				}
				break;
			case 4:
				if(flagLoguin == 0) {
					printf("Primedo debe loguearse\n");
				} else if(compras == 0){
					printf("Debe comprar para poder vender\n");
				}else {
					switch(subMenu()) {
						case 1:
							printf("Vendio con exito\n");
							compras--;
							break;
						case 2:
							printf("Factura realizada\n");
							break;
						case 3:
							break;
						default:
							printf("Opcion invalida, vuelve al menu\n");
					}
				}
				break;
			case 5:
				printf("SALIO CON EXITO");
				salir = 1;
				break;
			default:
				printf("OPCION INVALIDA\n");
		}
	}while(salir == 0);
	return EXIT_SUCCESS;
}
