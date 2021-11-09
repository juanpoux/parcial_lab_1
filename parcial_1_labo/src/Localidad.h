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

/// @fn void EncabezadoLocalidades()
/// @brief encabezado para localidades
///
void EncabezadoLocalidades();

/// @fn void MostrarUnaLocalidad(eLocalidad)
/// @brief muestra una localidad
///
/// @param localidad
void MostrarUnaLocalidad(eLocalidad localidad);

/// @fn int MostrarLocalidades(eLocalidad[], int)
/// @brief muestra la lista de localidades
///
/// @param lista
/// @param tam
/// @return -1 si no pudo, 0 si pudo
int MostrarLocalidades(eLocalidad lista[], int tam);

/// @fn eLocalidad ObtenerLocalidadPorID(eLocalidad[], int, int)
/// @brief recibe un id y devuelve la localidad con ese id
///
/// @param lista
/// @param tam
/// @param id
/// @return estructura de localidad
eLocalidad ObtenerLocalidadPorID(eLocalidad lista[], int tam, int id);

/// @fn int PedirYVerificarIdLocalidad(eLocalidad[], int, int*, char[], char[], int, int)
/// @brief Pide un id de localidad para verificar que sea un id activo
///
/// @param lista
/// @param tam
/// @param id
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @return 0 si no pudo, 1 si pudo pedirlo
int PedirYVerificarIdLocalidad(eLocalidad lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo);

/// @fn int VerificarIdActivoLocalidad(eLocalidad[], int, int)
/// @brief verifica si el id que recibe es un id activo
///
/// @param lista
/// @param tam
/// @param id
/// @return -1 si los paraetros son invalidos, 0 si no encontro el id, 1 si lo encontro
int VerificarIdActivoLocalidad(eLocalidad lista[], int tam, int id);

/// @fn void HardcodearLocalidades(eLocalidad[], int)
/// @brief hardcodea las localidades
///
/// @param lista
/// @param tam
void HardcodearLocalidades(eLocalidad lista[], int tam);

/// @fn int InicializarLocalidades(eLocalidad[], int)
/// @brief inicializa los campos de localidad
///
/// @param lista
/// @param tam
/// @return -1 si no pudo, 0 si pudo
int InicializarLocalidades(eLocalidad lista[], int tam);

#endif /* LOCALIDAD_H_ */
