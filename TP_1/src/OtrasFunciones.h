/*
 * OtrasFunciones.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Emanuel
 */

#ifndef OTRASFUNCIONES_H_
#define OTRASFUNCIONES_H_
#include "OperacionesMatematicas.h"


int RetornoDeNumeroEntero(int numeroEntero);
int SubMenuTp1(float kilometrosIngresados,float precioVuelo,float*precionConTarjetaDebito,float*precionConTarjetaCredito,float*precioBitcoin,float*precioUnitario);
int ImpresionDeResultadosTp1(float kilometrosIngresados,float precioVueloAerolineas,float precioConTarjetaDebitoAerolineas,float precioConTarjetaCreditoAerolineas,float precioBitcoinAerolineas,float precioUnitarioAerolineas,float precioVueloLatam,float precioConTarjetaDebitoLatam,float precioConTarjetaCreditoLatam,float precioBitcoinLatam,float precioUnitarioLatam,float diferenciaPrecios);


#endif /* OTRASFUNCIONES_H_ */
