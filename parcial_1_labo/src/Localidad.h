/*
 * Localidad.h
 *
 *  Created on: 25 oct. 2021
 *      Author: poux_
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#define MAX_NOMBRE 60
#define CARGADO 1
#define VACIO 0
#include "Input.h"

typedef struct
{
	int idLocalidad;
	char descripcion[MAX_NOMBRE];
	int isEmpty;
}eLocalidad;

void MostrarUnaLocalidad(eLocalidad localidad);
int MostrarLocalidades(eLocalidad lista[], int tam);
eLocalidad ObtenerLocalidadPorID(eLocalidad lista[], int tam, int id);

#endif /* LOCALIDAD_H_ */
