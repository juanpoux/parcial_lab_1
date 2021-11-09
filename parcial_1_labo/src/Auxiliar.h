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

/// @fn void InicializarAux(eAuxiliar[], int)
/// @brief iniciliaza los campos de la estructura en 0
///
/// @param lista
/// @param tam
void InicializarAux(eAuxiliar lista[], int tam);


#endif /* AUXILIAR_H_ */
