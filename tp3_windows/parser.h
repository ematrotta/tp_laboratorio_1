#include "LinkedList.h"
#include "Passenger.h"

#define TAM_BUFFER_PARSER 100

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);


