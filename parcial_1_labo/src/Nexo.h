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

int CrearPedidoDeRecoleccion(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, int* idPedido);
ePedido CrearPedido(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, int* idPedido);
int MostrarClientesConCantidadPedidosPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedido);
void EncabezadoConCantidadPendientes();
void EncabezadoConCantidadKilos();
int MostrarPedidosPendientesConKilos(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);
void MostrarPedidosConDatosDeCliente(ePedido pedido, eCliente listaCliente[], int tamCliente);
int CantidadPendientesPorLocalidad(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);
void MostrarPedidosProcesados(ePedido pedido, eCliente listaCliente[], int tamCliente);
int MostrarPedidosProcesadosConDescripcion(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);

#endif /* NEXO_H_ */
