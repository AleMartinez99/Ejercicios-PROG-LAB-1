/*
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
Por ejemplo:
5! = 5*4*3*2*1 = 120
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int num;
	int fact = 1;

	printf("Ingrese num: ");
	scanf("%d", &num);

	if(num == 0 || num == 1)
	{
		printf("Fact de %d: %d", num,fact);
	}else {
		for(int i = num;i > 0;i--) {
		fact *= i;
		}
		printf("Fact de %d: %d", num,fact);
	}

	return EXIT_SUCCESS;
}

