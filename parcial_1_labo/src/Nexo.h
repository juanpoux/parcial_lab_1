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
int ProcesarResiduos(ePedido lista[], int tam, int generadorId, eCliente listaCliente[], int tamCliente);
void MostrarPedidosConDatosDeCliente(ePedido pedido, eCliente listaCliente[], int tamCliente);
int CantidadPendientesPorLocalidad(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);
void MostrarPedidosProcesados(ePedido pedido, eCliente listaCliente[], int tamCliente);
int MostrarPedidosProcesadosConDescripcion(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);
int CalcularPromedioPP(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);

#endif /* NEXO_H_ */
