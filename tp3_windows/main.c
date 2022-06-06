#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Flyght.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

sFlyght vuelos[VUELOS]={{"BA2491A",Aterrizado},{"BR3456J",Demorado},{"FR5678G",EnHorario},{"GU2345F",EnVuelo},{"HY4567D",Demorado},{"IB0800A",Aterrizado},{"MM0987B",EnHorario},{"TU6789B",Aterrizado}};


int main()
{
	setbuf(stdout,NULL);
	int retorno;
	int option;
	char UltimoId[TAM_BUFFER_PARSER];

	Passenger* pPasajero;
	Passenger* pUltimoPasajero;
	LinkedList* listaPasajeros = ll_newLinkedList();




	retorno = -1;
	do
	{
		puts("Menú\n");
		puts("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).");
		puts("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).");
		puts("3. Alta de pasajero.");
		puts("4. Modificar datos de pasajero");
		puts("5. Baja de pasajero");
		puts("6. Listar pasajeros");
		puts("7. Ordenar pasajeros");
		puts("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).");
		puts("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).");
		puts("10. Salir");
		if(Utn_GetNumeroInt(&option, "OPCION", "La opción debe ser entre 1 y 10", 10, 1, 3)!= 0)
		{
			option = 10;
		}

		switch(option)
		{
		case 1:
			controller_loadFromText("data.csv", listaPasajeros);
			break;
		case 2:
			break;
		case 3:;
			FILE* pArchivoUltimoId = fopen("UltimoId.txt","r");
			if(pArchivoUltimoId != NULL)
			{
				fscanf(pArchivoUltimoId,"%s",UltimoId);
			}
			fclose(pArchivoUltimoId);


			printf("El ultimo id es: %s",UltimoId);





			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			controller_ListPassenger(listaPasajeros);
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}



	}while(option != 10);


    return retorno;
}
