#include "Nexo.h"

int CrearPedidoDeRecoleccion(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, int* idPedido)
{
	int retorno;
	//int idCliente;
	int opcion;
	int indice = -1;
	ePedido pedidoAux;

	retorno = -1;

	if(listaClientes != NULL && tamCliente > 0 && listaPedidos != NULL && tamPedidos > 0)
	{
		retorno = 0;
		indice = BuscarLibrePedido(listaPedidos, tamPedidos);

		if(indice != -1)
		{
			pedidoAux = CrearPedido(listaClientes, tamCliente, listaPedidos, tamPedidos, idPedido);

			EncabezadoConCantidadKilos();
			MostrarPedidosConDatosDeCliente(pedidoAux, listaClientes, tamCliente);
			PedirEnteroP(&opcion, "Desea guardar el pedido asi? \n1) SI\n2) NO \n", "Error, ingreso invalido ", 1, 2);
			if(opcion == 1)
			{
				listaPedidos[indice] =  pedidoAux;
				retorno = 1;
				*idPedido = *idPedido + 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}
	return retorno;
}

ePedido CrearPedido(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, int* idPedido)
{
	ePedido pedidoAux;

	EncabezadoCliente();
	MostrarListaClientes(listaClientes, tamCliente);
	PedirYVerificarIdCliente(listaClientes, tamCliente, &pedidoAux.idCliente, "Ingrese el ID del cliente: ", "Error, ingreso invalido ", 1, 9999);
	pedidoAux.idPedido = *idPedido;
	pedidoAux.estado = PENDIENTE;
	pedidoAux.isEmpty = CARGADO;
	PedirFlotanteP(&pedidoAux.kilos, "Ingrese la cantidad de kilos de plastico: ", "Error, ingreso invalido ", 0, 99999999);

	return pedidoAux;
}

int MostrarClientesConCantidadPedidosPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedido)
{
	int retorno;
	int i;
	int cantidad;

	retorno = -1;

	if(listaClientes != NULL && tamCliente > 0 && listaPedidos != NULL && tamPedido > 0)
	{
		EncabezadoConCantidadPendientes();
		for(i = 0; i < tamCliente; i++)
		{
			if(listaClientes[i].isEmpty == CARGADO)
			{
				ContarPendientes(listaPedidos, tamPedido, listaClientes[i].idCliente, &cantidad);
				MostrarClientePorIdConCantidad(listaClientes, tamCliente, listaClientes[i].idCliente, cantidad);
			}
		}
	}
	return retorno;
}

void EncabezadoConCantidadPendientes()
{
	printf("=============================================================================================\n");
	printf("|%4s |%-15s |%-15s |%-15s |%-15s |%-15s |\n", "ID", "Empresa", "CUIT", "Direccion", "Localidad", "Cant. Pendientes");
	printf("=============================================================================================\n");
}

void EncabezadoConCantidadKilos()
{
	printf("==============================================================================================\n");
	printf("|%6s |%-15s |%-15s |%-15s |%-15s |%-15s |\n", "Id", "Empresa", "CUIT", "Direccion", "Localidad", "Cant. kilos");
	printf("==============================================================================================\n");
}


int MostrarPedidosPendientesConKilos(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido)
{
	int retorno;
	int i;
	//int j;
	//eCliente auxC;

	retorno = -1;

	if(listaCliente != NULL && tamCliente > 0 && listaPedido != NULL && tamPedido > 0)
	{
		EncabezadoConCantidadKilos();

		/*for(i = 0; i < tamPedido; i++)
		{
			if(listaPedido[i].isEmpty == CARGADO && listaPedido[i].estado == PENDIENTE)
  			{
				for(j = 0; j < tamCliente; j++)
				{
					if(listaCliente[j].isEmpty == CARGADO && listaCliente[j].idCliente == listaPedido[i].idCliente)
					{
						printf("|%6d |", listaPedido[i].idPedido);
						printf("%-15.2f |\n", listaPedido[i].kilos);

						printf("%-15s |", listaCliente[j].nombre);
						printf("%-15s |", listaCliente[j].cuit);
						printf("%-15s |", listaCliente[j].direccion);
						printf("%-15s |", listaCliente[j].localidad);
						printf("----------------------------------------------------------------------------------------------\n");
					}
				}
			}
		}*/

		for(i = 0; i < tamPedido; i++)
		{
			if(listaPedido[i].isEmpty == CARGADO && listaPedido[i].estado == PENDIENTE)
			{
				/*auxC = ObtenerClientePorID(listaCliente, tamCliente, listaPedido[i].idCliente);
				printf("|%6d |", listaPedido[i].idPedido);
				printf("%-15s |", auxC.nombre);
				printf("%-15s |", auxC.cuit);
				printf("%-15s |", auxC.direccion);
				printf("%-15s |", auxC.localidad);
				printf("%-15.2f |\n", listaPedido[i].kilos);
				printf("----------------------------------------------------------------------------------------------\n");*/
				MostrarPedidosConDatosDeCliente(listaPedido[i], listaCliente, tamCliente);
			}
		}
	}

	return retorno;
}

void MostrarPedidosConDatosDeCliente(ePedido pedido, eCliente listaCliente[], int tamCliente)
{
	eCliente auxC;

	auxC = ObtenerClientePorID(listaCliente, tamCliente, pedido.idCliente);
	printf("|%6d |", pedido.idPedido);
	printf("%-15s |", auxC.nombre);
	printf("%-15s |", auxC.cuit);
	printf("%-15s |", auxC.direccion);
	printf("%-15s |", auxC.localidad);
	printf("%-15.2f |\n", pedido.kilos);
	printf("----------------------------------------------------------------------------------------------\n");
}

void CantidadPendientesPorLocalidad(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido)
{
	char localidad[60];
	int cantidad;

	PedirCadena("Ingrese localidad: ", localidad, 60);
	for(int i = 0; i < tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == CARGADO && stricmp(listaCliente[i].localidad, localidad) == 0)
		{
			ContarPendientes(listaPedido, tamPedido, listaCliente[i].idCliente, &cantidad);
		}
	}
}

/*int ContarPendientesPorLocalidad(eCliente cliente, ePedido listaPedido[], int tamPedido)
{
	int retorno;

	retorno = -1;



	return retorno;

}*/
