/*
Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
 */

#include <stdio.h>
#include <stdlib.h>

int sumar1(int n1, int n2);
int sumar2();
void sumar3(int n1, int n2);
void sumar4();

int main(void) {
	setbuf(stdout, NULL);

	int n1;
	int n2;

	printf("Ingrese num: ");
	scanf("%d", &n1);
	printf("Ingrese num: ");
	scanf("%d", &n2);

	printf("Con funcion SUMAR1: %d\n", sumar1(n1,n2));
	system("pause");
	printf("Con funcion SUMAR2: %d\n", sumar2());
	system("pause");
	sumar3(n1,n2);
	system("pause");
	sumar4();

	return EXIT_SUCCESS;
}

int sumar1(int n1, int n2) {
	return n1 + n2;
}

int sumar2() {
	int n1;
	int n2;

	printf("Ingrese num: ");
	scanf("%d", &n1);
	printf("Ingrese num: ");
	scanf("%d", &n2);

	return n1 + n2;
}

void sumar3(int n1, int n2) {
	printf("Con funcion SUMAR3: %d\n", n1+n2);
}

void sumar4() {
	int n1;
	int n2;

	printf("Ingrese num: ");
	scanf("%d", &n1);
	printf("Ingrese num: ");
	scanf("%d", &n2);

	printf("Con funcion SUMAR4: %d\n", n1+n2);
}
