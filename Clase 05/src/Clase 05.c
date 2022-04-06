/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

int main(void) {
	setbuf(stdout, NULL);

	float numero;
	int resultadoFuncion;

	resultadoFuncion = getFloatUtn("Ingrese un número: ","Error, vuelva a intentarlo",10,1,3,&numero);

	if(resultadoFuncion == 0)
	{
		printf("Salio Todo bien");
	}


	return EXIT_SUCCESS;
}
