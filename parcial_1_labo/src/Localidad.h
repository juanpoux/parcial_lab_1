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

void EncabezadoLocalidades();
void MostrarUnaLocalidad(eLocalidad localidad);
int MostrarLocalidades(eLocalidad lista[], int tam);
eLocalidad ObtenerLocalidadPorID(eLocalidad lista[], int tam, int id);
int PedirYVerificarIdLocalidad(eLocalidad lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo);
int VerificarIdActivoLocalidad(eLocalidad lista[], int tam, int id);
void HardcodearLocalidades(eLocalidad lista[], int tam);
int InicializarLocalidades(eLocalidad lista[], int tam);

#endif /* LOCALIDAD_H_ */
