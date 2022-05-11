/*
 * ArrayPassenger_Flight.h
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */

#ifndef ARRAYPASSENGER_FLIGHT_H_
#define ARRAYPASSENGER_FLIGHT_H_
#include "ArrayPassenger.h"
#include "Flyght.h"

int sFlyght_findFlyghtById(sFlyght * list,int len,char idFlyght[]);
int sPassenger_InputsDataPassenger(sPassenger * passenger, sFlyght listFlyghts[],int lenflyghts, char mensajeError[]);
int sPassenger_addPassengerFlyghtStatus(sPassenger passenger[],int lenPassenger, sFlyght listFlyghts[],int lenflyghts);
int sPassenger_Modification(sPassenger * list,int len,int id,sFlyght listFlyght[],int lenFlyghts);




#endif /* ARRAYPASSENGER_FLIGHT_H_ */
