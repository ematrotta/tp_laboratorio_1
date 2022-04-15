/*
 * OperacionesMatematicas.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Emanuel
 */

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

#include <stdio.h>
#include <stdlib.h>

/// @fn float Promedio2NumerosInt(int, int)
/// @brief PROMEDIO DE 2 NUMEROS ENTEROS
///
/// @pre
/// @post
/// @param num1 Numero 1 Entero Ingresado
/// @param num2 Numero 2 Entero Ingresado
/// @return Promedio float de 2 numeros enteros
float Promedio2NumerosInt(int num1,int num2);
int PorcentajeInt(int numero,int porcentajeAplicado,char operacion,float*resultado);
int DivisionInt(int dividendo,int divisor,char mensajeError[],float *resultado);
int RestaInt(int numero1,int numero2,int*resultado);



int PorcentajeFloat(float numero,float porcentajeAplicado,char operacion,float*resultado);
int DivisionFloat(float dividendo,float divisor,char mensajeError[],float *resultado);
int RestaFloat(float numero1,float numero2,float*resultado);






#endif /* OPERACIONESMATEMATICAS_H_ */
