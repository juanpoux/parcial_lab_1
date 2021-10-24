#include "Pedido.h"

/*void MostrarUnPedidoPendiente(ePedido lista)
{
	char estados[2][10] = { {"PENDIENTE"} , {"COMPLETADO"} };

	printf("%-6d |", lista.idPedido);
	printf("%-4d |", lista.idCliente);
	printf("%-15.2f |", lista.kilos);
	//printf("%-4d |\n", lista.estado);
	printf("%-10s |\n", estados[lista.estado - 1]);
	printf("---------------------------------------------------------------------------\n");
}

int MostrarListaPedidosPendiente(ePedido lista[], int tam)
{
	int i;
	int retorno;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == CARGADO && lista[i].estado == PENDIENTE)
			{
				MostrarUnPedidoPendiente(lista[i]);
				retorno = 1;
			}
		}
	}
	return retorno;
}*/

int BuscarLibrePedido(ePedido lista[], int tam)
{
	int retorno;
	int i;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == VACIO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}



int VerificarIdActivoPedido(ePedido lista[], int tam, int id)
{
	int retorno;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		retorno = 0;
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].idPedido == id)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int PedirYVerificarIdPedido(ePedido lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int retorno;
	int idAux;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		retorno = 1;
		PedirEnteroP(&idAux, mensaje, mensajeError, minimo, maximo);

		while(VerificarIdActivoPedido(lista, tam, idAux) != 1)
		{
			printf("El ID ingresado no es valido\n");
			PedirEnteroP(&idAux, mensaje, mensajeError, minimo, maximo);
		}

		*id = idAux;
	}

	return retorno;
}

ePedido ObtenerPedidoPorID(ePedido lista[], int tam, int id)
{
	ePedido aux;
	int i;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].idPedido == id)
			{
				aux = lista[i];
				break;
			}
		}
	}

	return aux;
}

int BuscarIndicePorIdPedido(ePedido lista[], int tam, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].idPedido == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int ContarPendientes(ePedido lista[], int tam, int idCliente, int* cantidad)
{
	int retorno;
	int contador;
	int i;

	retorno = -1;
	contador = 0;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].estado == PENDIENTE && lista[i].idCliente == idCliente)
			{
				contador++;
			}
		}
		*cantidad = contador;
	}
	return retorno;
}

int InicializarArrayPedidos(ePedido lista[], int tam)
{
	int retorno;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = VACIO;
			lista[i].estado = 0;
		}
	}

	return retorno;
}

int VerificarEstadoActivo(ePedido lista[], int tam, int estado)
{
	int retorno;
	int i;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].estado == estado)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int AcumularKilosPP(ePedido lista[], int tam, float* kilosPP)
{
	int retorno;
	int i;
	//float acumuladorPP;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		retorno = 0;
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].estado == COMPLETADO)
			{
				retorno = 1;
				//acumuladorPP = acumuladorPP + lista[i].PP;
				*kilosPP = *kilosPP + lista[i].PP;
			}
		}
	}

	//*kilosPP = acumuladorPP;

	return retorno;
}

int DarBajaPedidoPorIdCliente(ePedido lista[], int tam, int idCliente)
{
	int retorno;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		retorno = 0;
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].idCliente == idCliente)
			{
				retorno = 1;
				lista[i].isEmpty = VACIO;
			}
		}
	}

	return retorno;
}
