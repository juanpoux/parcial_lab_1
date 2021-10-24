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
		retorno = 0;
		EncabezadoConCantidadPendientes();
		for(i = 0; i < tamCliente; i++)
		{
			if(listaClientes[i].isEmpty == CARGADO)
			{
				retorno = 1;
				ContarPendientes(listaPedidos, tamPedido, listaClientes[i].idCliente, &cantidad);
				MostrarClientePorIdConCantidad(listaClientes, tamCliente, listaClientes[i].idCliente, cantidad);
			}
		}
	}
	return retorno;
}

void EncabezadoConCantidadPendientes()
{
	printf("=======================================================================================================\n");
	printf("|%4s |%-15s |%-15s |%-20s |%-20s |%-15s |\n", "ID", "Empresa", "CUIT", "Direccion", "Localidad", "Cant. Pendientes");
	printf("=======================================================================================================\n");
}

void EncabezadoConCantidadKilos()
{
	printf("============================================================================================================\n");
	printf("|%10s |%-15s |%-15s |%-20s |%-20s |%-15s |\n", "Id pedido", "Empresa", "CUIT", "Direccion", "Localidad", "Cant. kilos");
	printf("============================================================================================================\n");
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
		retorno = 0;
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
				retorno = 1;
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

int ProcesarResiduos(ePedido lista[], int tam, int generadorId, eCliente listaCliente[], int tamCliente)
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
		retorno = 0;
		MostrarPedidosPendientesConKilos(listaCliente, tamCliente, lista, tam);
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

void MostrarPedidosConDatosDeCliente(ePedido pedido, eCliente listaCliente[], int tamCliente)
{
	eCliente auxC;

	auxC = ObtenerClientePorID(listaCliente, tamCliente, pedido.idCliente);
	printf("|%10d |", pedido.idPedido);
	printf("%-15s |", auxC.nombre);
	printf("%-15s |", auxC.cuit);
	printf("%-20s |", auxC.direccion);
	printf("%-20s |", auxC.localidad);
	printf("%-15.2f |\n", pedido.kilos);
	printf("------------------------------------------------------------------------------------------------------------\n");
}

int CantidadPendientesPorLocalidad(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido)
{
	int retorno;
	char localidad[60];
	int cantidad;

	retorno = -1;

	if(listaCliente != NULL && tamCliente > 0 && listaPedido != NULL && tamPedido > 0)
	{
		retorno = 0;
		PedirCadena("Ingrese localidad: ", localidad, 60);
		for(int i = 0; i < tamCliente; i++)
		{
			if(listaCliente[i].isEmpty == CARGADO && stricmp(listaCliente[i].localidad, localidad) == 0)
			{
				retorno = 1;
				ContarPendientes(listaPedido, tamPedido, listaCliente[i].idCliente, &cantidad);
			}
		}
		if(retorno == 1)
		{
			printf("\nEn la localidad de %s hay %d pedidos pedidos pendientes\n", localidad, cantidad);
		}
		else
		{
			if(retorno == 0)
			{
				printf("\nNo hay pedidos pendientes en la localidad de %s\n", localidad);
			}
		}
	}

	return retorno;
}

int MostrarPedidosProcesadosConDescripcion(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido)
{
	int retorno;
	int i;
	//int j;
	//eCliente auxC;

	retorno = -1;

	if(listaCliente != NULL && tamCliente > 0 && listaPedido != NULL && tamPedido > 0)
	{
		printf("===========================================================================================================================================\n");
		printf("|%10s |%-15s |%-15s |%-20s |%-20s |%-10s |%-10s |%-10s |%-10s |\n", "Id pedido", "Empresa", "CUIT", "Direccion", "Localidad", "HDPE", "LDPE", "PP", "Resto");
		printf("===========================================================================================================================================\n");
		retorno = 0;
		for(i = 0; i < tamPedido; i++)
		{
			if(listaPedido[i].isEmpty == CARGADO && listaPedido[i].estado == COMPLETADO)
			{
				MostrarPedidosProcesados(listaPedido[i], listaCliente, tamCliente);
			}
		}
	}

	return retorno;
}


void MostrarPedidosProcesados(ePedido pedido, eCliente listaCliente[], int tamCliente)
{
	eCliente auxC;
	float resto;

	auxC = ObtenerClientePorID(listaCliente, tamCliente, pedido.idCliente);

	resto = pedido.kilos - pedido.HDPE - pedido.LDPE - pedido.PP;

	printf("|%10d |", pedido.idPedido);
	printf("%-15s |", auxC.nombre);
	printf("%-15s |", auxC.cuit);
	printf("%-20s |", auxC.direccion);
	printf("%-20s |", auxC.localidad);
	printf("%-10.2f |", pedido.HDPE);
	printf("%-10.2f |", pedido.LDPE);
	printf("%-10.2f |", pedido.PP);
	printf("%-10.2f |\n", resto);
	printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
}

int CalcularPromedioPP(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente)
{
	int retorno;
	float acumuladorPP;
	int cantClientes;
	float promedio;

	retorno = -1;
	acumuladorPP = 0;

	if(listaPedido != NULL && tamPedido > 0 && listaCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		AcumularKilosPP(listaPedido, tamPedido, &acumuladorPP);
		ContadorClientes(listaCliente, tamCliente, &cantClientes);

		if(acumuladorPP == 0)
		{
			retorno = 2;
			//printf("No hay polipropileno reciclado por el momento...\n");
		}
		else
		{
			retorno = 1;
			promedio = acumuladorPP / cantClientes;
			printf("Kilos totales de polipropileno: %.2f \n", acumuladorPP);
			printf("Cantidad total de clientes: %d \n", cantClientes);
			printf("La cantidad promedio de kilos de polipropileno reciclado por cliente es: %.2f \n", promedio);
		}

	}

	return retorno;
}


