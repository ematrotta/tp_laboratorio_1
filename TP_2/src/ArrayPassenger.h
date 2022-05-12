/*
 * Passenger.h
 *
 *  Created on: 6 may. 2022
 *      Author: Emanuel
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Flyght.h"
#include "Inputs.h"
#include "Outputs.h"
#define NAME 51
#define FLYCODE 10
#define TRUE 0
#define FALSE 1
#define LOW 2
#define TAM_TYPEPASSENGER 30
#define TAM_STATUSFLYGHT 13
#define ACTIVO 1
#define REPROGRAMADO 2
#define CANCELADO 3


typedef struct
{
	int id;
	char name[NAME];
	char lastName[NAME];
	float price;
	char flycode[FLYCODE];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}sPassenger;

int sPassenger_initPassenger(sPassenger * list, int len);
int sPassenger_findFreeSpace(sPassenger * list, int len);
int sPassenger_findPassengerById(sPassenger * list,int len,int id);
int sPassenger_addPassenger(sPassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int sPassenger_removePassenger(sPassenger* list, int len, int id);
int sPassenger_sortPassengers(sPassenger* list, int len, int order);
int sPassenger_sortPassengersByTypePassenger(sPassenger* list, int len, int order);
int sPassenger_printAllIdByInit(sPassenger* list,int len,int init);
int sPassenger_sortPassengersByCode(sPassenger* list, int len, int order);
void sPassenger_printOne(sPassenger passenger);
int sPassenger_printPassengers(sPassenger* list,int len);
int sPassenger_printPassengerByStatus(sPassenger* list,int len,int status);





#endif /* ARRAYPASSENGER_H_ */
