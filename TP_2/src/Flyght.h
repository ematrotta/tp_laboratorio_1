/*
 * Flyght.h
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */

#ifndef FLYGHT_H_
#define FLYGHT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Outputs.h"
#define FLYCODE 10

typedef struct
{
	char flycode[FLYCODE];
	int status;

}sFlyght;

int sFlyght_findFlyghtById(sFlyght * list,int len,char idFlyght[]);


#endif /* FLYGHT_H_ */
