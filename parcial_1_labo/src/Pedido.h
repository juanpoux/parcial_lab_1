
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

/*void MostrarUnPedidoPendiente(ePedido lista);
int MostrarListaPedidosPendiente(ePedido lista[], int tam);*/
int BuscarLibrePedido(ePedido lista[], int tam);
int PedirYVerificarIdPedido(ePedido lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo);
ePedido ObtenerPedidoPorID(ePedido lista[], int tam, int id);
int VerificarIdActivoPedido(ePedido lista[], int tam, int id);
int BuscarIndicePorIdPedido(ePedido lista[], int tam, int id);
int ContarPendientes(ePedido lista[], int tam, int idCliente, int* cantidad);
int InicializarArrayPedidos(ePedido lista[], int tam);
int VerificarEstadoActivo(ePedido lista[], int tam, int estado);
int AcumularKilosPP(ePedido lista[], int tam, float* kilosPP);

#endif /* PEDIDO_H_ */
