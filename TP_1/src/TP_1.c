/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "get.h"
#include "OtrasFunciones.h"

int main(void) {
	setbuf(stdout,NULL);
    int retorno;
    int numeroIngresado;
    int resultadoOpcionIngresada;
    int resultadoKilometrosIngresados;
    int resultadoPrecioAerolineasIngresado;
    int resultadoPrecioLatamIngresado;
    int resultadoSubMenuAerolineas;
    int resultadoSubMenuLatam;
    float kilometrosIngresados;
    float precioVueloAerolineas;
    float precioVueloLatam;
    float precioConTarjetaDebitoAerolineas;
    float precioConTarjetaCreditoAerolineas;
    float precioBitcoinAerolineas;
    float precioUnitarioAerolineas;
    float precioConTarjetaDebitoLatam;
    float precioConTarjetaCreditoLatam;
    float precioBitcoinLatam;
    float precioUnitarioLatam;
    float diferenciaPrecios;



    retorno = -1;

    printf("\t\t\tCalculador de costos de viajes\n1. Ingresar Kilómetros\n2. Ingresar Precio de Vuelos\n3. Calcular todos los costos\n4. Informar Resultados\n5. Carga forzada de datos\n6. Salir\n\n");

    resultadoOpcionIngresada=GetInt(&numeroIngresado,"Ingrese una opción: ","\nLa opcion debe ser entre 1 y 6\n\n",1,6,3);

    if(resultadoOpcionIngresada == 0)
    {
        while(numeroIngresado!=6)
        {
            switch(numeroIngresado)
            {
                case 1:
                    resultadoKilometrosIngresados = GetFloat(&kilometrosIngresados,"\nIngresar Kilómetros: ","Debe ser mayor a 0 o menor que 12,742\n",1,12742,3);
                    break;
                case 2:
                    if(!resultadoKilometrosIngresados)
                    {
                        resultadoPrecioAerolineasIngresado = GetFloat(&precioVueloAerolineas,"\n- Precio vuelo Aerolíneas: ","Debe ser mayor a 0 o menor a 1000000",1,1000000,3);
                        resultadoPrecioLatamIngresado = GetFloat(&precioVueloLatam,"- Precio vuelo Latam: ","Debe ser mayor a 0 o menor a 1000000",1,1000000,3);
                    }
                    else
                    {
                        printf("\nERROR. Debe ingresar los kilometros primero.\n");
                    }
                    break;
                case 3:
                	if(!resultadoPrecioAerolineasIngresado && !resultadoPrecioLatamIngresado)
                	{
                		resultadoSubMenuAerolineas = SubMenuTp1(kilometrosIngresados, precioVueloAerolineas, &precioConTarjetaDebitoAerolineas, &precioConTarjetaCreditoAerolineas, &precioBitcoinAerolineas, &precioUnitarioAerolineas);
                		resultadoSubMenuLatam = SubMenuTp1(kilometrosIngresados, precioVueloLatam, &precioConTarjetaDebitoLatam, &precioConTarjetaCreditoLatam, &precioBitcoinLatam, &precioUnitarioLatam);
                		RestaFloat(precioVueloAerolineas, precioVueloLatam, &diferenciaPrecios);
						if(diferenciaPrecios<0)
						{
							diferenciaPrecios = diferenciaPrecios*-1;
						}
						printf("\nCarga de resultados Finalizada.");
                	}
                	else
                	{
                		printf("\nERROR. Primero debe ingresar los km. Si Ya lo hizo, debe ingresar los costos de los vuelos.\n");
                	}

                	break;
                case 4:
                	if(!resultadoSubMenuAerolineas && !resultadoSubMenuLatam)
                	{
                		//Informe Resultados Aerolíneas
                		printf("\nKMs Ingresados: %.2f km\n\nPrecio Vuelos Aerolíneas: $%.2f\na) Precio con tarjeta de débito: $ %.2f\nb) Precio con tarjeta de crédito: $ %.2f\nc) Precio pagando con bitcoin: $ %.2f BTC\nd) Precio unitario: $ %.2f\n\n",kilometrosIngresados,precioVueloAerolineas,precioConTarjetaDebitoAerolineas,precioConTarjetaCreditoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas);

                		//Informe Resultados Latam
                		printf("Precio Vuelos Latam: $%.2f\na) Precio con tarjeta de débito: $ %.2f\nb) Precio con tarjeta de crédito: $ %.2f\nc) Precio pagando con bitcoin: $ %.2f BTC\nd) Precio unitario: $ %.2f\n\nLa diferencia de precio es : $ %.2f\n\n",precioVueloLatam,precioConTarjetaDebitoLatam,precioConTarjetaCreditoLatam,precioBitcoinLatam,precioUnitarioLatam,diferenciaPrecios);

                	}
                	else
                	{
                		printf("ERROR. Primero debe ingresar los kilometros, Luego los costos de los vuelos y por último la opción 3\n\n");
                	}
                	break;
                case 5:
                    kilometrosIngresados = 7090;
                    precioVueloAerolineas = 162965;
                    precioVueloLatam = 159339;
               		resultadoSubMenuAerolineas = SubMenuTp1(kilometrosIngresados, precioVueloAerolineas, &precioConTarjetaDebitoAerolineas, &precioConTarjetaCreditoAerolineas, &precioBitcoinAerolineas, &precioUnitarioAerolineas);
                    resultadoSubMenuLatam = SubMenuTp1(kilometrosIngresados, precioVueloLatam, &precioConTarjetaDebitoLatam, &precioConTarjetaCreditoLatam, &precioBitcoinLatam, &precioUnitarioLatam);
                    RestaFloat(precioVueloAerolineas, precioVueloLatam, &diferenciaPrecios);
                    if(diferenciaPrecios<0)
                    {
                    	diferenciaPrecios = diferenciaPrecios*-1;
                    }
            		printf("\nKMs Ingresados: %.2f km\n\nPrecio Aerolíneas: $%.2f\na) Precio con tarjeta de débito: $ %.2f\nb) Precio con tarjeta de crédito: $ %.2f\nc) Precio pagando con bitcoin: $ %.2f BTC\nd) Precio unitario: $ %.2f\n\n",kilometrosIngresados,precioVueloAerolineas,precioConTarjetaDebitoAerolineas,precioConTarjetaCreditoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas);
            		printf("Precio Latam: $%.2f\na) Precio con tarjeta de débito: $ %.2f\nb) Precio con tarjeta de crédito: $ %.2f\nc) Precio pagando con bitcoin: $ %.2f BTC\nd) Precio unitario: $ %.2f\n\nLa diferencia de precio es : $%.2f\n\n",precioVueloLatam,precioConTarjetaDebitoLatam,precioConTarjetaCreditoLatam,precioBitcoinLatam,precioUnitarioLatam,diferenciaPrecios);

                	break;
                case 6:
                	retorno = 0;
                    break;
            }
            GetInt(&numeroIngresado,"\nIngrese una Nueva opción: ","La opcion debe ser entre 1  y 6",1,6,3);
        }
    }
    else
    {
    	printf("ERROR. Sobrepasó los intentos");
    }



    return retorno;
}


