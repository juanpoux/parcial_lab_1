
#include "Input.h"
#ifndef PEDIDO_H_
#define PEDIDO_H_
#define PENDIENTE 1
#define COMPLETADO 2
#define CARGADO 1
#define VACIO 0

typedef struct
{
	int idPedido;
	int idCliente;
	float kilos;
	int estado;
	int isEmpty;
	float HDPE;
	float LDPE;
	float PP;
}ePedido;

/// @fn int BuscarLibrePedido(ePedido[], int)
/// @brief busca una posicion en el array que tenga el campo isEmpty "VACIO"
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @return retorna -1 si no encontro espacio libre, o la posicion del array si encontro
int BuscarLibrePedido(ePedido lista[], int tam);

/// @fn int PedirYVerificarIdPedido(ePedido[], int, int*, char[], char[], int, int)
/// @brief pide un id y verifica que este activo con la funcion VerificarIdActivoPedido
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @param id id a buscar
/// @param mensaje mensaje para el usuario
/// @param mensajeError mensaje si ingreso un id erroneo
/// @param minimo valor minimo que puede ingresar el usuario
/// @param maximo valor maximo que puede ingresar el usuario
/// @return retorna -1 si algun dato no es valido, 1 si encuentra el id
int PedirYVerificarIdPedido(ePedido lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo);

/// @fn ePedido ObtenerPedidoPorID(ePedido[], int, int)
/// @brief obtiene los datos de un pedido por id
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @param id id del pedido a buscar
/// @return retorna un auxiliar con los datos completos del pedido que encontro
ePedido ObtenerPedidoPorID(ePedido lista[], int tam, int id);

/// @fn int VerificarIdActivoPedido(ePedido[], int, int)
/// @brief verifica si el campo isEmpty de un pedido esta "CARGADO"
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @param id id a buscar
/// @return retorna -1 si hay algun dato mal cargado, 0 si no encontro el id, 1 si lo encontro y esta activo
int VerificarIdActivoPedido(ePedido lista[], int tam, int id);

/// @fn int BuscarIndicePorIdPedido(ePedido[], int, int)
/// @brief recibe un id como parametro y devuelve la posicion del array
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @param id id para buscar la posicion
/// @return -1 si no lo encontro, la posicion del array si encontro
int BuscarIndicePorIdPedido(ePedido lista[], int tam, int id);

/// @fn int ContarPendientes(ePedido[], int, int, int*)
/// @brief cuenta la cantidad de pedidos pendientes tiene un id de cliente
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @param idCliente id a buscar
/// @param cantidad puntero para pasar la cantidad de pendientes
/// @return retorna -1 si algun dato no es valido, 1 si logro contar
int ContarPendientes(ePedido lista[], int tam, int idCliente, int* cantidad);

/// @fn int InicializarArrayPedidos(ePedido[], int)
/// @brief inicializa el campo isEmpty y el campo estado en 0
///
/// @param lista array de empleados
/// @param tam tamaño del array
/// @return -1 si algun dato no es valido, 1 si pudo hacerlo
int InicializarArrayPedidos(ePedido lista[], int tam);

/// @fn int VerificarEstadoActivo(ePedido[], int, int)
/// @brief verifica que haya pedidos activos segun el estado que se pase por parametro
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @param estado estado a buscar
/// @return -1 si algun dato es invalido, 0 si no encontro pedidos activos, 1 si encotro pedidos activos
int VerificarEstadoActivo(ePedido lista[], int tam, int estado);

/// @fn int AcumularKilosPP(ePedido[], int, float*)
/// @brief acumula la cantidad de kilos de polipropileno hay procesados entre los pedidos activos
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @param kilosPP puntero para devolver la cantidad de kilos
/// @return -1 si algun dato no es valido, 0 si no encontro polipropileno, 1 si encontro y acumulo
int AcumularKilosPP(ePedido lista[], int tam, float* kilosPP);

/// @fn int DarBajaPedidoPorIdCliente(ePedido[], int, int)
/// @brief da de baja los pedidos que estan ligados a un cliente que fue dado de baja
///
/// @param lista array de pedidos
/// @param tam tamaño del array
/// @param idCliente id del cliente dado de baja
/// @return -1 si algun dato no es valido, 0 si no tenia pedidos activos, 1 si logro hacerlo
int DarBajaPedidoPorIdCliente(ePedido lista[], int tam, int idCliente);

#endif /* PEDIDO_H_ */
