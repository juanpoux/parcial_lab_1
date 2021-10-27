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
	//char localidad[MAX_NOMBRE];
	int idLocalidad;
	int idCliente;
	int isEmpty;

}eCliente;

/// @fn eCliente CargarCliente()
/// @brief pide datos de los campos de eCliente
///
/// @return retorna un cliente con los campos completados
eCliente CargarCliente();

/// @fn int AltaCliente(eCliente[], int, int*)
/// @brief carga un cliente nuevo en el sistema
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @param generadorId id automatico
/// @return retorna -1 si algun dato no esta bien, 0 si no hay espacio libre en el array, 1 si pudo hacer la carga con exito, 2 si cancelo la carga
int AltaCliente(eCliente lista[], int tam, int* generadorId);

/// @fn int BuscarLibreCliente(eCliente[], int)
/// @brief busca un espacio libre en el array
///
/// @param lista de clientes
/// @param tam tamaño del array
/// @return retorna la posicion del array si encontro espacio o -1 si no encontro
int BuscarLibreCliente(eCliente lista[], int tam);

/// @fn int MenuDeOpciones()
/// @brief menu principal del programa
///
/// @return no tiene retorno por el momento
int MenuDeOpciones();

/// @fn void EncabezadoCliente()
/// @brief encabezado con datos del cliente
///
void EncabezadoCliente();

/// @fn void MostrarUnCliente(eCliente)
/// @brief muestra los datos de un solo cliente
///
/// @param recibe un cliente
void MostrarUnCliente(eCliente lista);

/// @fn int MostrarListaClientes(eCliente[], int)
/// @brief muestra los clientes activos
///
/// @param lista array de empleados
/// @param tam tamaño del array
/// @return 0 si no encotro clientes cargados, 1 si encontro
int MostrarListaClientes(eCliente lista[], int tam);

/// @fn int InicializarArray(eCliente[], int)
/// @brief inicializa el campo isEmpty en "vacio" o 0 del array de clientes
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @return 0 si no encotro clientes cargados, 1 si encontro
int InicializarArray(eCliente lista[], int tam);

/// @fn int BuscarClientePorID(eCliente[], int, int)
/// @brief recibe un id como parametro y devuelve la posicion del array
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @param id id para buscar la posicion
/// @return -1 si no lo encontro, la posicion del array si encontro
int BuscarClientePorID(eCliente lista[], int tam, int id);

/// @fn int VerificarIdActivoCliente(eCliente[], int, int)
/// @brief verifica si el campo isEmpty de un cliente esta "CARGADO"
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @param id id a buscar
/// @return retorna -1 si hay algun dato mal cargado, 0 si no encontro el id, 1 si lo encontro y esta activo
int VerificarIdActivoCliente(eCliente lista[], int tam, int id);

/// @fn int PedirYVerificarIdCliente(eCliente[], int, int*, char[], char[], int, int)
/// @brief pide un id y verifica que este activo con la funcion VerificarIdActivoCliente
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @param id id a buscar
/// @param mensaje mensaje para el usuario
/// @param mensajeError mensaje si ingreso un id erroneo
/// @param minimo valor minimo que puede ingresar el usuario
/// @param maximo valor maximo que puede ingresar el usuario
/// @return retorna -1 si algun dato no es valido, 1 si encuentra el id
int PedirYVerificarIdCliente(eCliente lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo);

/// @fn int ModificarCliente(eCliente[], int)
/// @brief permite al usuario hacer modificaciones en 2 campos del cliente
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @return -1 si algun dato no es valido, 1 si pudo hacer el cambio, 2 si cancelo los cambios
int ModificarCliente(eCliente lista[], int tam);

/// @fn int MostrarClientePorIdConCantidad(eCliente[], int, int, int)
/// @brief muestra los clientes activos con cantidad de pedidos pendientes
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @param id id del cliente
/// @param cantidad cantidad de pedidos pendientes
/// @return -1 si algun dato no es valido, 1 si pudo hacerlo
//int MostrarClientePorIdConCantidad(eCliente lista[], int tam, int id, int cantidad);

/// @fn void MostrarUnClienteConCantidad(eCliente, int)
/// @brief muestra un cliente con cantidad de pedidos pendientes
///
/// @param lista un cliente
/// @param cantidad cantidad de pedidos pendientes
//void MostrarUnClienteConCantidad(eCliente lista, int cantidad);

/// @fn eCliente ObtenerClientePorID(eCliente[], int, int)
/// @brief obtiene los datos de un cliente por id
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @param id id del cliente a buscar
/// @return retorna un auxiliar con los datos completos del cliente que encontro
eCliente ObtenerClientePorID(eCliente lista[], int tam, int id);

/// @fn int SaberSiHayClientesActivos(eCliente[], int)
/// @brief busca si hay al menos un cliente con el campo isEmpty en "CARGADO"
///
/// @param lista array de empleados
/// @param tam tamaño del array
/// @return retorna -1 si no encontro, 1 si encontro
int SaberSiHayClientesActivos(eCliente lista[], int tam);

/// @fn int ContadorClientes(eCliente[], int, int*)
/// @brief cuenta la cantidad de clientes activos en el array
///
/// @param lista array de clientes
/// @param tam tamaño del array
/// @param contClientes puntero de la cantidad de clientes
/// @return retorna -1 si algun dato es invalido, 0 si no encontro clientes cargados, 1 si encontro clientes
int ContadorClientes(eCliente lista[], int tam, int* contClientes);

int BuscarClientePorIdLocalidad(eCliente lista[], int tam, int idLocalidad);

#endif /* CLIENTE_H_ */
