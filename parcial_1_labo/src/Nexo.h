/*
 * Nexo.h
 *
 *  Created on: 20 oct. 2021
 *      Author: poux_
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "Pedido.h"
#include "Cliente.h"
#include "Input.h"
#include "Localidad.h"
#include "Auxiliar.h"

/// @fn int CrearPedidoDeRecoleccion(eCliente[], int, ePedido[], int, int*)
/// @brief crea un pedido de recoleccion completando algunos campos de un ePedido
///
/// @param listaClientes array de clientes
/// @param tamCliente tamaño del array de clientes
/// @param listaPedidos array de pedidos
/// @param tamPedidos tamaño del array de pedidos
/// @param idPedido genera un id automatico sumando de a 1
/// @return -1 si hubo algun dato no valido, 0 si no encontro posiciones libre, 1 si logro crear el pedido, 2 si cancelo la creacion del pedido
int CrearPedidoDeRecoleccion(eCliente listaClientes[], int tamCliente,ePedido listaPedidos[], int tamPedidos, int *idPedido, eLocalidad localidades[], int tamLoc);

/// @fn ePedido CrearPedido(eCliente[], int, ePedido[], int, int*)
/// @brief pide los datos de los campos de un ePedido
///
/// @param listaClientes array de clientes
/// @param tamCliente tamaño del array de clientes
/// @param listaPedidos array de pedidos
/// @param tamPedidos tamaño del array de pedidos
/// @param idPedido id generado en la funcion anterior
/// @return retorna el ePedido con los campos llenos
ePedido CrearPedido(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, int* idPedido, eLocalidad listaLocalidad[], int tamLoc);

/// @fn int MostrarClientesConCantidadPedidosPendientes(eCliente[], int, ePedido[], int)
/// @brief imprime en pantalla datos de los clientes y la cantidad de pedidos pendientes
///
/// @param listaClientes array de clientes
/// @param tamCliente tamaño del array de clientes
/// @param listaPedidos array de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @return -1 si hubo algun dato no valido, 0 si no encontro clientes cargados, 1 si logro hacerlo
//int MostrarClientesConCantidadPedidosPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedido);
int MostrarClientesConCantidadPedidosPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedido, eLocalidad listaLoc[], int tamLoc);

/// @fn void EncabezadoConCantidadPendientes()
/// @brief encabezado con cantidad de pedidos pendientes
///
void EncabezadoConCantidadPendientes();

/// @fn void EncabezadoConCantidadKilos()
/// @brief encabezado con cantidad de kilos a procesar
///
void EncabezadoConCantidadKilos();

/// @fn int MostrarPedidosPendientesConKilos(eCliente[], int, ePedido[], int)
/// @brief imprime en pantalla datos de los pedidos y la cantidad de kilos
///
/// @param listaCliente array de clientes
/// @param tamCliente tamaño del array de clientes
/// @param listaPedido array de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @return -1 si hubo algun dato no valido, 0 si no encontro clientes cargados, 1 si logro hacerlo
int MostrarPedidosPendientesConKilos(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido, eLocalidad localidades[], int tamLoc);

/// @fn int ProcesarResiduos(ePedido[], int, int, eCliente[], int)
/// @brief muestra en pantalla los pedidos pendientes, pide el ingreso de un id para realizar el procesamiento
/// completando los campos que faltan en ePedido
///
/// @param lista array de pedidos
/// @param tam tamañod el array de pedidos
/// @param generadorId id del pedido
/// @param listaCliente array de clientes
/// @param tamCliente tamaño del array
/// @return -1 si hubo algun dato no valido, 1 si logro hacerlo, 2 si fue cancelado
int ProcesarResiduos(ePedido lista[], int tam, int generadorId, eCliente listaCliente[], int tamCliente, eLocalidad localidades[], int tamLoc);

/// @fn void MostrarPedidosConDatosDeCliente(ePedido, eCliente[], int)
/// @brief imprime los datos de un pedido con datos del cliente
///
/// @param pedido ePedido
/// @param listaCliente array de clientes
/// @param tamCliente tamaño del array de clientes
void MostrarPedidosConDatosDeCliente(ePedido pedido, eCliente listaCliente[],int tamCliente, eLocalidad localidades[], int tamLoc);

/// @fn int CantidadPendientesPorLocalidad(eCliente[], int, ePedido[], int)
/// @brief pide el ingreso de una localidad y muestra en pantalla la cantidad de pedidos pendientes que tiene esa localidad
///
/// @param listaCliente array de clientes
/// @param tamCliente tamaño del array de clientes
/// @param listaPedido array de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @return -1 si hubo algun dato no valido, 0 si no hay pedidos pendientes, 1 si encontro pedidos pendientes en dicha localidad
int CantidadPendientesPorLocalidad(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido, eLocalidad listaLoc[], int tamLoc);

/// @fn void MostrarPedidosProcesados(ePedido, eCliente[], int)
/// @brief imprime en pantalla los datos de un ePedido ya procesado
///
/// @param pedido ePedido
/// @param listaCliente array de clientes
/// @param tamCliente tamaño del array de clientes
void MostrarPedidosProcesados(ePedido pedido, eCliente listaCliente[], int tamCliente);

/// @fn int MostrarPedidosProcesadosConDescripcion(eCliente[], int, ePedido[], int)
/// @brief muestra los pedidos activos que ya fueron procesados
///
/// @param listaCliente array de clientes
/// @param tamCliente tamaño del array de clientes
/// @param listaPedido array de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @return -1 si hubo algun dato no valido, 1 si encontro al menos un pedido procesado
int MostrarPedidosProcesadosConDescripcion(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);

/// @fn int CalcularPromedioPP(ePedido[], int, eCliente[], int)
/// @brief calcula el promedio de kilos de polipropileno por la cantidad de clientes activos
///
/// @param listaPedido array de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @param listaCliente array de clientes
/// @param tamCliente tamaño del array de clientes
/// @return -1 si hubo algun dato no valido, 1 si hizo el calculo con exito, 2 si no hay polipropileno procesado
int CalcularPromedioPP(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);

/// @fn int BajaCliente(eCliente[], int, ePedido[], int)
/// @brief cambia el campo isEmpty de un cliente por "VACIO" y si este tiene pedidos asociados tambien los da de baja
///
/// @param lista array de clientes
/// @param tam tamaño del array de clientes
/// @param listaPedido array de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @return	-1 si hubo algun dato no valido, 1 si fue dado de baja con exito, 2 si fue cancelado
int BajaCliente(eCliente lista[], int tam, ePedido listaPedido[], int tamPedido, eLocalidad localidades[], int tamLoc);

/// @fn int BajaPedido(ePedido[], int, eCliente[], int)
/// @brief
///
/// @param lista
/// @param tam
/// @param listaCliente
/// @param tamCliente
/// @return
int BajaPedido(ePedido lista[], int tam, eCliente listaCliente[], int tamCliente, eLocalidad localidades[], int tamLoc);

eCliente CargarCliente2(int idGenerico, eLocalidad listaLoc[], int tamLoc);
int AltaCliente2(eCliente lista[], int tam, int* generadorId, eLocalidad listaLoc[], int tamLoc);
void MostrarUnCliente2(eCliente lista, eLocalidad localidad[], int tamLoc);
int MostrarListaClientes2(eCliente lista[], int tam, eLocalidad localidades[], int tamLoc);
int ModificarCliente2(eCliente lista[], int tam, eLocalidad listaLoc[], int tamLoc);
int BuscarClienteConMasPedidosPendientes(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);
int CalcularMayor(eAuxiliar listaAux[], int tamAux, int* cantidad);
void Renglones(int posicion, int cantidad, char simbolo);
int ContarClientesPorEstadoDePedido(ePedido listaPedido[], int tamPedido, int estado, int idCliente, int* cantidad);
int MostrarClientesConCantidadDePedidosSegunEstado(eCliente listaCliente[], int tamCliente, ePedido listaPedido[],	int tamPedido, int estado);
int BuscarClienteConMayorCantidadPedidos(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);//, eAuxiliar aux[])
int MostrarClientePorIdConCantidad(eCliente lista[], int tam, int id, int cantidad, eLocalidad localidades[], int tamLoc);
void MostrarUnClienteConCantidad(eCliente lista, int cantidad, eLocalidad localidades[], int tamLoc);
int CargarAuxConClientePorEstado(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], eAuxiliar aux[], int tamCliente, int estado);

#endif /* NEXO_H_ */
