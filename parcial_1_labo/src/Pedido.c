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

int ProcesarResiduos(ePedido lista[], int tam, int generadorId)
{
	int retorno;
	int id;
	float kilos;
	int opcion;
	ePedido aux;
	int indice;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		//MostrarListaPedidosPendiente(lista, tam);
		PedirYVerificarIdPedido(lista, tam, &id, "ingrese el id: ", "error ", 1, generadorId);
		aux  = ObtenerPedidoPorID(lista, tam, id);
		indice = BuscarIndicePorIdPedido(lista, tam, id);

		kilos = aux.kilos;

		printf("Kilos a procesar %.2f. ", kilos);
		PedirFlotanteP(&aux.HDPE, "Cuanto de HDPE? ", "ERROR ", 0, kilos);
		kilos = kilos - aux.HDPE;
		printf("Quedan %.2f kilos. ", kilos);
		PedirFlotanteP(&aux.LDPE, "Cuanto de LDPE: ", "ERROR ", 0, kilos);
		kilos = kilos - aux.LDPE;
		printf("Quedan %.2f kilos. ", kilos);
		PedirFlotanteP(&aux.PP, "Cuanto de PP: ", "ERROR ", 0, kilos);
		kilos = kilos - aux.PP;

		printf("%.2f de HDPE\n%.2f de LDPE\n%.2f de PP\n%.2f de resto\n", aux.HDPE, aux.LDPE, aux.PP, kilos);

		PedirEnteroP(&opcion, "Desea guardar el pedido asi? \n1) SI\n2) NO \n", "Error, ingreso invalido ", 1, 2);
		if(opcion == 1)
		{
			lista[indice] =  aux;
			lista[indice].estado = COMPLETADO;
			retorno = 1;
		}
		else
		{
			retorno = 2;
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
