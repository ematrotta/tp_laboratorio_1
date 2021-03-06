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

    //Imprecion del men? principal
    printf("\t\t\tCalculador de costos de viajes\n1. Ingresar Kil?metros\n2. Ingresar Precio de Vuelos\n3. Calcular todos los costos\n4. Informar Resultados\n5. Carga forzada de datos\n6. Salir\n\n");

    //Ingreso del n?mero seleccionado
    resultadoOpcionIngresada=GetInt(&numeroIngresado,"Ingrese una opci?n: ","\nLa opcion debe ser entre 1 y 6\n\n",1,6,3);


    if(resultadoOpcionIngresada == 0)
    {
        while(numeroIngresado!=6)
        {
            switch(numeroIngresado)
            {
                case 1:
                	//Ingreso de los km por el usuario
                    resultadoKilometrosIngresados = GetFloat(&kilometrosIngresados,"\nIngresar Kil?metros: ","Debe ser mayor a 0 o menor que 12,742\n",1,12742,3);
                    break;
                case 2:
                	//Ingreso del precio de vuelos de aerolineas y Latam
                    if(!resultadoKilometrosIngresados)
                    {
                        resultadoPrecioAerolineasIngresado = GetFloat(&precioVueloAerolineas,"\n- Precio vuelo Aerol?neas: ","Debe ser mayor a 0 o menor a 1000000",1,1000000,3);
                        resultadoPrecioLatamIngresado = GetFloat(&precioVueloLatam,"- Precio vuelo Latam: ","Debe ser mayor a 0 o menor a 1000000",1,1000000,3);
                    }
                    else
                    {
                        printf("\nERROR. Debe ingresar los kilometros primero.\n");
                    }
                    break;
                case 3:
                	//Calculo de resultados segun precio y kilometros ingresados
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
                	//Impresion de resultados por los km y los costos ingresados
                	if(!resultadoSubMenuAerolineas && !resultadoSubMenuLatam)
                	{
                		ImpresionDeResultadosTp1(kilometrosIngresados,precioVueloAerolineas,precioConTarjetaDebitoAerolineas,precioConTarjetaCreditoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas,precioVueloLatam,precioConTarjetaDebitoLatam,precioConTarjetaCreditoLatam,precioBitcoinLatam,precioUnitarioLatam,diferenciaPrecios);
                	}
                	else
                	{
                		printf("ERROR. Primero debe ingresar los kilometros, Luego los costos de los vuelos y por ?ltimo la opci?n 3\n\n");
                	}
                	break;
                case 5:
                	//Calculo e imprecion de resultados contantes dodos en el TP
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
            		ImpresionDeResultadosTp1(kilometrosIngresados,precioVueloAerolineas,precioConTarjetaDebitoAerolineas,precioConTarjetaCreditoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas,precioVueloLatam,precioConTarjetaDebitoLatam,precioConTarjetaCreditoLatam,precioBitcoinLatam,precioUnitarioLatam,diferenciaPrecios);
                	break;
                case 6:
                    break;
            }
            //Solicitd de nueva opcion de ingreso
            GetInt(&numeroIngresado,"\nIngrese una Nueva opci?n: ","La opcion debe ser entre 1  y 6",1,6,3);
        }
        retorno = 0;
    }
    else
    {
    	printf("ERROR. Sobrepas? los intentos");
    }



    return retorno;
}


