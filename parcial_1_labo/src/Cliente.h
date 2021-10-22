/*
 * Cliente.h
 *
 *  Created on: 20 oct. 2021
 *      Author: poux_
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define MAX_NOMBRE 60
#define CARGADO 1
#define VACIO 0
#include "Input.h"

typedef struct
{
	char nombre[MAX_NOMBRE];
	char cuit[MAX_NOMBRE];
	char direccion[MAX_NOMBRE];
	char localidad[MAX_NOMBRE];
	int idCliente;
	int isEmpty;

}eCliente;

eCliente CargarCliente();
void Hardcodeo(eCliente lista[]);
int AltaCliente(eCliente lista[], int tam, int* generadorId);
int BuscarLibreCliente(eCliente lista[], int tam);
int MenuDeOpciones();
void EncabezadoCliente();
void MostrarUnCliente(eCliente lista);
int MostrarListaClientes(eCliente lista[], int tam);
int InicializarArray(eCliente lista[], int tam);
int BuscarClientePorID(eCliente lista[], int tam, int id);
int VerificarIdActivoCliente(eCliente lista[], int tam, int id);
int PedirYVerificarIdCliente(eCliente lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo);
int ModificarCliente(eCliente lista[], int tam);
int BajaCliente(eCliente lista[], int tam);
int MostrarClientePorIdConCantidad(eCliente lista[], int tam, int id, int cantidad);
void MostrarUnClienteConCantidad(eCliente lista, int cantidad);
eCliente ObtenerClientePorID(eCliente lista[], int tam, int id);

#endif /* CLIENTE_H_ */
