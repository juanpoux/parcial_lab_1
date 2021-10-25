/*
 * Auxiliar.h
 *
 *  Created on: 25 oct. 2021
 *      Author: Negocio
 */

#ifndef AUXILIAR_H_
#define AUXILIAR_H_
#include "Input.h"
#define CARGADO 1
#define VACIO 0

typedef struct
{
	int contador;
	int idCliente;
	int isEmpty;
	int id;
	float flotantes;
}eAuxiliar;

void InicializarAux(eAuxiliar lista[], int tam);


#endif /* AUXILIAR_H_ */
