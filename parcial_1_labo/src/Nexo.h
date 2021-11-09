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

/// @fn int MenuDeOpciones()
/// @brief menu principal del programa
///
/// @return no tiene retorno por el momento
int MenuDeOpciones();

/// @fn int MenuInformes()
/// @brief menu de informes
///
/// @return
int MenuInformes();

/// @fn eCliente CargarCliente2(int, eLocalidad[], int)
/// @brief nuevo cargar cliente con parametro de localidades
///
/// @param idGenerico
/// @param listaLoc
/// @param tamLoc
/// @return un eCliente completo
eCliente CargarCliente2(int idGenerico, eLocalidad listaLoc[], int tamLoc);

/// @fn int AltaCliente2(eCliente[], int, int*, eLocalidad[], int)
/// @brief nuevo alta cliente con parametros de localidades
///
/// @param lista
/// @param tam
/// @param generadorId
/// @param listaLoc
/// @param tamLoc
/// @return retorna -1 si algun dato no esta bien, 0 si no hay espacio libre en el array, 1 si pudo hacer la carga con exito, 2 si cancelo la carga
int AltaCliente2(eCliente lista[], int tam, int* generadorId, eLocalidad listaLoc[], int tamLoc);

/// @fn void MostrarUnCliente2(eCliente, eLocalidad[], int)
/// @brief muestra los datos de un cliente
///
/// @param lista
/// @param localidad
/// @param tamLoc
void MostrarUnCliente2(eCliente lista, eLocalidad localidad[], int tamLoc);

/// @fn int MostrarListaClientes2(eCliente[], int, eLocalidad[], int)
/// @brief muestra la lista de los clientes
///
/// @param lista
/// @param tam
/// @param localidades
/// @param tamLoc
/// @return -1 si no pudo, 0 si pudo
int MostrarListaClientes2(eCliente lista[], int tam, eLocalidad localidades[], int tamLoc);

/// @fn int ModificarCliente2(eCliente[], int, eLocalidad[], int)
/// @brief nuevo modificar cliente con parametros de localidades
///
/// @param lista
/// @param tam
/// @param listaLoc
/// @param tamLoc
/// @return retorna -1 si algun dato no esta bien, 1 si pudo hacer la modificacion con exito, 2 si cancelo
int ModificarCliente2(eCliente lista[], int tam, eLocalidad listaLoc[], int tamLoc);

//int BuscarClienteConMasPedidosPendientes(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);

/// @fn int CalcularMayor(eAuxiliar[], int, int*)
/// @brief recorre los contadores de la lista auxiliar y devuelve el mayor
///
/// @param listaAux
/// @param tamAux
/// @param cantidad
/// @return -1 si no pudo, 0 si pudo
int CalcularMayor(eAuxiliar listaAux[], int tamAux, int* cantidad);

/// @fn int ContarClientesPorEstadoDePedido(ePedido[], int, int, int, int*)
/// @brief cuenta la cantidad de pedidos tiene cada cliente segun el estado que se pasa por parametro
///
/// @param listaPedido
/// @param tamPedido
/// @param estado
/// @param idCliente
/// @param cantidad
/// @return -1 si no pudo, 0 si pudo
int ContarClientesPorEstadoDePedido(ePedido listaPedido[], int tamPedido, int estado, int idCliente, int* cantidad);

/// @fn int MostrarClientesConCantidadDePedidosSegunEstado(eCliente[], int, ePedido[], int, int)
/// @brief muestra el o los clientes que tengan la mayor cantidad de pedidos segun el estado que se pasa por parametro
///
/// @param listaCliente
/// @param tamCliente
/// @param listaPedido
/// @param tamPedido
/// @param estado
/// @return -1 si no pudo, 0 si pudo
int MostrarClientesConCantidadDePedidosSegunEstado(eCliente listaCliente[], int tamCliente, ePedido listaPedido[],	int tamPedido, int estado);

/// @fn int BuscarClienteConMayorCantidadPedidos(eCliente[], int, ePedido[], int)
/// @brief Busca en la lista el cliente o clientes con mayor cantidad de pedidos y los muestra
///
/// @param listaCliente
/// @param tamCliente
/// @param listaPedido
/// @param tamPedido
/// @return -1 si no pudo, 0 si pudo
int BuscarClienteConMayorCantidadPedidos(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);

/// @fn int MostrarClientePorIdConCantidad(eCliente[], int, int, int, eLocalidad[], int)
/// @brief muestra lista de clientes con cantidad de kilos que coincida con el id que se pasa por parametro
///
/// @param lista
/// @param tam
/// @param id
/// @param cantidad
/// @param localidades
/// @param tamLoc
/// @return -1 si no pudo, 0 si pudo
int MostrarClientePorIdConCantidad(eCliente lista[], int tam, int id, int cantidad, eLocalidad localidades[], int tamLoc);

/// @fn void MostrarUnClienteConCantidad(eCliente, int, eLocalidad[], int)
/// @brief muestra un cliente con la cantidad de kilos que tiene a procesar
///
/// @param lista
/// @param cantidad
/// @param localidades
/// @param tamLoc
void MostrarUnClienteConCantidad(eCliente lista, int cantidad, eLocalidad localidades[], int tamLoc);

/// @fn int CargarAuxConClientePorEstado(ePedido[], int, eCliente[], eAuxiliar[], int, int)
/// @brief
///
/// @param listaPedido
/// @param tamPedido
/// @param listaCliente
/// @param aux
/// @param tamCliente
/// @param estado
/// @return
int CargarAuxConClientePorEstado(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], eAuxiliar aux[], int tamCliente, int estado);

#endif /* NEXO_H_ */
