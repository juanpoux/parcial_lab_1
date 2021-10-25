#include "Nexo.h"

int CrearPedidoDeRecoleccion(eCliente listaClientes[], int tamCliente,
		ePedido listaPedidos[], int tamPedidos, int *idPedido)
{
	int retorno;
	int opcion;
	int indice = -1;
	ePedido pedidoAux;

	retorno = -1;

	if (listaClientes != NULL && tamCliente > 0 && listaPedidos != NULL
			&& tamPedidos > 0)
	{
		retorno = 0;
		indice = BuscarLibrePedido(listaPedidos, tamPedidos);

		if (indice != -1)
		{
			pedidoAux = CrearPedido(listaClientes, tamCliente, listaPedidos,
					tamPedidos, idPedido);

			EncabezadoConCantidadKilos();
			MostrarPedidosConDatosDeCliente(pedidoAux, listaClientes,
					tamCliente);
			PedirEnteroP(&opcion,
					"Desea guardar el pedido asi? \n1) SI\n2) NO \n",
					"Error, ingreso invalido ", 1, 2);
			if (opcion == 1)
			{
				listaPedidos[indice] = pedidoAux;
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

ePedido CrearPedido(eCliente listaClientes[], int tamCliente,
		ePedido listaPedidos[], int tamPedidos, int *idPedido)
{
	ePedido pedidoAux;

	EncabezadoCliente();
	MostrarListaClientes(listaClientes, tamCliente);
	PedirYVerificarIdCliente(listaClientes, tamCliente, &pedidoAux.idCliente,
			"Ingrese el ID del cliente: ", "Error, ingreso invalido ", 1, 9999);
	pedidoAux.idPedido = *idPedido;
	pedidoAux.estado = PENDIENTE;
	pedidoAux.isEmpty = CARGADO;
	PedirFlotanteP(&pedidoAux.kilos,
			"Ingrese la cantidad de kilos de plastico: ",
			"Error, ingreso invalido ", 0, 99999999);

	return pedidoAux;
}

int MostrarClientesConCantidadPedidosPendientes(eCliente listaClientes[],
		int tamCliente, ePedido listaPedidos[], int tamPedido)
{
	int retorno;
	int i;
	int cantidad;

	retorno = -1;

	if (listaClientes != NULL && tamCliente > 0 && listaPedidos != NULL
			&& tamPedido > 0)
	{
		retorno = 0;
		EncabezadoConCantidadPendientes();
		for (i = 0; i < tamCliente; i++)
		{
			if (listaClientes[i].isEmpty == CARGADO)
			{
				retorno = 1;
				ContarPendientes(listaPedidos, tamPedido,
						listaClientes[i].idCliente, &cantidad);
				MostrarClientePorIdConCantidad(listaClientes, tamCliente,
						listaClientes[i].idCliente, cantidad);
			}
		}
	}
	return retorno;
}

void EncabezadoConCantidadPendientes()
{
	printf(
			"=======================================================================================================\n");
	printf("|%4s |%-15s |%-15s |%-20s |%-20s |%-15s |\n", "ID", "Empresa",
			"CUIT", "Direccion", "Localidad", "Cant. Pendientes");
	printf(
			"=======================================================================================================\n");
}

void EncabezadoConCantidadKilos()
{
	printf(
			"============================================================================================================\n");
	printf("|%10s |%-15s |%-15s |%-20s |%-20s |%-15s |\n", "Id pedido",
			"Empresa", "CUIT", "Direccion", "Localidad", "Cant. kilos");
	printf(
			"============================================================================================================\n");
}

int MostrarPedidosPendientesConKilos(eCliente listaCliente[], int tamCliente,
		ePedido listaPedido[], int tamPedido)
{
	int retorno;
	int i;

	retorno = -1;

	if (listaCliente != NULL && tamCliente > 0 && listaPedido != NULL
			&& tamPedido > 0)
	{
		retorno = 0;
		EncabezadoConCantidadKilos();

		for (i = 0; i < tamPedido; i++)
		{
			if (listaPedido[i].isEmpty == CARGADO
					&& listaPedido[i].estado == PENDIENTE)
			{
				retorno = 1;
				MostrarPedidosConDatosDeCliente(listaPedido[i], listaCliente,
						tamCliente);
			}
		}
	}

	return retorno;
}

int ProcesarResiduos(ePedido lista[], int tam, int generadorId,
		eCliente listaCliente[], int tamCliente)
{
	int retorno;
	int id;
	float kilos;
	int opcion;
	ePedido aux;
	int indice;

	retorno = -1;

	if (lista != NULL && tam > 0)
	{
		retorno = 0;
		MostrarPedidosPendientesConKilos(listaCliente, tamCliente, lista, tam);
		PedirYVerificarIdPedido(lista, tam, &id, "ingrese el id: ", "error ", 1,
				generadorId);
		aux = ObtenerPedidoPorID(lista, tam, id);
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

		printf("%.2f de HDPE\n%.2f de LDPE\n%.2f de PP\n%.2f de resto\n",
				aux.HDPE, aux.LDPE, aux.PP, kilos);

		PedirEnteroP(&opcion, "Desea guardar el pedido asi? \n1) SI\n2) NO \n",
				"Error, ingreso invalido ", 1, 2);
		if (opcion == 1)
		{
			lista[indice] = aux;
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

void MostrarPedidosConDatosDeCliente(ePedido pedido, eCliente listaCliente[],
		int tamCliente)
{
	eCliente auxC;

	auxC = ObtenerClientePorID(listaCliente, tamCliente, pedido.idCliente);
	printf("|%10d |", pedido.idPedido);
	printf("%-15s |", auxC.nombre);
	printf("%-15s |", auxC.cuit);
	printf("%-20s |", auxC.direccion);
	//printf("%-20s |", auxC.localidad);
	printf("%-15.2f |\n", pedido.kilos);
	printf(
			"------------------------------------------------------------------------------------------------------------\n");
}

int CantidadPendientesPorLocalidad(eCliente listaCliente[], int tamCliente,
		ePedido listaPedido[], int tamPedido, eLocalidad listaLoc[], int tamLoc)
{
	int retorno;
	//char localidad[60];
	int localidad;
	int cantidad;

	retorno = -1;

	if (listaCliente != NULL && tamCliente > 0 && listaPedido != NULL
			&& tamPedido > 0)
	{
		retorno = 0;
		//PedirCadena("Ingrese localidad: ", localidad, 60);
		MostrarLocalidades(listaLoc, tamLoc);
		PedirEnteroP(&localidad, "Ingrese ID de localidad: ", "ERROR", 1, 99);
		for (int i = 0; i < tamCliente; i++)
		{
			if (listaCliente[i].isEmpty == CARGADO/* && stricmp(listaCliente[i].localidad, localidad) == 0*/)
			{
				for (int j = 0; j < tamLoc; j++)
				{
					if (listaLoc[j].isEmpty == CARGADO
							&& listaCliente[i].idLocalidad
									== listaLoc[j].idLocalidad)
					{
						retorno = 1;
						ContarPendientes(listaPedido, tamPedido,
								listaCliente[i].idCliente, &cantidad);
						printf(
								"\nEn la localidad de %s hay %d pedidos pedidos pendientes\n",
								listaLoc[j].descripcion, cantidad);
					}
				}
			}
		}
		if (retorno == 1)
		{
			//printf("\nEn la localidad de %s hay %d pedidos pedidos pendientes\n", listaLoc[j].descripcion, cantidad);
		}
		else
		{
			if (retorno == 0)
			{
				printf("\nNo hay pedidos pendientes en la localidad de %d\n",
						localidad);
			}
		}
	}

	return retorno;
}

int MostrarPedidosProcesadosConDescripcion(eCliente listaCliente[],
		int tamCliente, ePedido listaPedido[], int tamPedido)
{
	int retorno;
	int i;

	retorno = -1;

	if (listaCliente != NULL && tamCliente > 0 && listaPedido != NULL
			&& tamPedido > 0)
	{
		printf(
				"===========================================================================================================================================\n");
		printf(
				"|%10s |%-15s |%-15s |%-20s |%-20s |%-10s |%-10s |%-10s |%-10s |\n",
				"Id pedido", "Empresa", "CUIT", "Direccion", "Localidad",
				"HDPE", "LDPE", "PP", "Resto");
		printf(
				"===========================================================================================================================================\n");
		retorno = 0;
		for (i = 0; i < tamPedido; i++)
		{
			if (listaPedido[i].isEmpty == CARGADO
					&& listaPedido[i].estado == COMPLETADO)
			{
				retorno = 1;
				MostrarPedidosProcesados(listaPedido[i], listaCliente,
						tamCliente);
			}
		}
	}

	return retorno;
}

void MostrarPedidosProcesados(ePedido pedido, eCliente listaCliente[],
		int tamCliente)
{
	eCliente auxC;
	float resto;

	auxC = ObtenerClientePorID(listaCliente, tamCliente, pedido.idCliente);

	resto = pedido.kilos - pedido.HDPE - pedido.LDPE - pedido.PP;

	printf("|%10d |", pedido.idPedido);
	printf("%-15s |", auxC.nombre);
	printf("%-15s |", auxC.cuit);
	printf("%-20s |", auxC.direccion);
	//printf("%-20s |", auxC.localidad);
	printf("%-10.2f |", pedido.HDPE);
	printf("%-10.2f |", pedido.LDPE);
	printf("%-10.2f |", pedido.PP);
	printf("%-10.2f |\n", resto);
	printf(
			"-------------------------------------------------------------------------------------------------------------------------------------------\n");
}

int CalcularPromedioPP(ePedido listaPedido[], int tamPedido,
		eCliente listaCliente[], int tamCliente)
{
	int retorno;
	float acumuladorPP;
	int cantClientes;
	float promedio;

	retorno = -1;
	acumuladorPP = 0;

	if (listaPedido != NULL && tamPedido > 0 && listaCliente != NULL
			&& tamCliente > 0)
	{
		retorno = 0;
		AcumularKilosPP(listaPedido, tamPedido, &acumuladorPP);
		ContadorClientes(listaCliente, tamCliente, &cantClientes);

		if (acumuladorPP == 0)
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
			printf(
					"La cantidad promedio de kilos de polipropileno reciclado por cliente es: %.2f \n",
					promedio);
		}

	}

	return retorno;
}

int BajaCliente(eCliente lista[], int tam, ePedido listaPedido[], int tamPedido)
{
	int retorno;
	int idCliente;
	int indice;
	int opcion;
	eCliente aux;

	retorno = -1;

	if (lista != NULL && tam > 0)
	{
		retorno = 0;
		EncabezadoCliente();
		MostrarListaClientes(lista, tam);
		PedirYVerificarIdCliente(lista, tam, &idCliente,
				"Seleccione el ID del cliente que desea dar de baja: ",
				"Error, opcion invalida! ", 1, 9999);
		indice = BuscarClientePorID(lista, tam, idCliente);
		EncabezadoCliente();
		MostrarUnCliente(lista[indice]);
		aux = lista[indice];
		aux.isEmpty = VACIO;

		if (VerificarIdActivoPedido(listaPedido, tamPedido, idCliente) == 1)
		{
			printf("\n\n**** Este cliente tiene pedidos asociados ****\n\n");
		}
		PedirEnteroP(&opcion, "Desea confirmar operacion? \n1) SI\n2) NO \n",
				"Error, opcion invalida ", 1, 2);
		if (opcion == 1)
		{
			DarBajaPedidoPorIdCliente(listaPedido, tamPedido, idCliente);
			lista[indice] = aux;
			retorno = 1;
		}
		else
		{
			retorno = 2;
		}
	}
	return retorno;
}

int BajaPedido(ePedido lista[], int tam, eCliente listaCliente[],
		int tamCliente)
{
	int retorno;
	int idPedido;
	int indice;
	int opcion;
	ePedido aux;

	retorno = -1;

	if (lista != NULL && tam > 0)
	{
		retorno = 0;
		//EncabezadoConCantidadKilos();
		MostrarPedidosPendientesConKilos(listaCliente, tamCliente, lista, tam);
		PedirYVerificarIdPedido(lista, tam, &idPedido,
				"Seleccione el ID del pedido que desea dar de baja: ",
				"Error, opcion invalida! ", 1, 9999);
		indice = BuscarIndicePorIdPedido(lista, tam, idPedido);
		aux = lista[indice];
		aux.isEmpty = VACIO;
		EncabezadoConCantidadKilos();
		MostrarPedidosConDatosDeCliente(aux, listaCliente, tamCliente);

		PedirEnteroP(&opcion, "Desea confirmar operacion? \n1) SI\n2) NO \n",
				"Error, opcion invalida ", 1, 2);
		if (opcion == 1)
		{
			lista[indice] = aux;
			retorno = 1;
		}
		else
		{
			retorno = 2;
		}
	}
	return retorno;
}
eCliente CargarCliente2(int idGenerico, eLocalidad listaLoc[], int tamLoc)
{
	eCliente cliente;

	PedirCadena("Ingrese el nombre de la empresa: ", cliente.nombre,
	MAX_NOMBRE);
	PedirCuit(cliente.cuit);
	PedirCadena("Ingrese la direccion de la empresa: ", cliente.direccion,
	MAX_NOMBRE);
	MostrarLocalidades(listaLoc, tamLoc);
	PedirEnteroP(&cliente.idLocalidad, "Ingrese id de la localidad: ",
			"Error, ingreso invalido ", 1, 9999);
	//PedirCadena("Ingrese la localidad de la empresa: ", cliente.localidad, MAX_NOMBRE);
	cliente.idCliente = idGenerico;
	cliente.isEmpty = CARGADO;

	return cliente;
}

int AltaCliente2(eCliente lista[], int tam, int *generadorId,
		eLocalidad listaLoc[], int tamLoc)
{
	int retorno;
	int indice;
	int opcion;
	eCliente aux;

	retorno = -1;

	if (lista != NULL && tam > 0)
	{
		retorno = 0;
		indice = BuscarLibreCliente(lista, tam);
		if (indice != -1)
		{
			aux = CargarCliente2(*generadorId, listaLoc, tamLoc);
		}

		EncabezadoCliente();
		MostrarUnCliente(aux);
		PedirEnteroP(&opcion, "Desea guardar cliente asi? \n1) SI\n2) NO\n",
				"Error, opcion invalida ", 1, 2);

		if (opcion == 1)
		{
			lista[indice] = aux;
			retorno = 1;
			*generadorId = *generadorId + 1;
		}
		else
		{
			retorno = 2;
		}
	}

	return retorno;
}

int ModificarCliente2(eCliente lista[], int tam, eLocalidad listaLoc[],
		int tamLoc)
{
	int retorno;
	int idCliente;
	int indice;
	int opcion;
	eCliente aux;
	retorno = -1;
	if (lista != NULL && tam > 0)
	{
		retorno = 0;
		EncabezadoCliente();
		MostrarListaClientes(lista, tam);
		PedirYVerificarIdCliente(lista, tam, &idCliente,
				"Seleccione el ID del cliente que desea modificar: ",
				"Error, opcion invalida! ", 1, 9999);
		indice = BuscarClientePorID(lista, tam, idCliente);
		aux = lista[indice];
		EncabezadoCliente();
		MostrarUnCliente(aux);
		PedirEnteroP(&opcion,
				"1) Modificar direccion \n2) Modificar localidad \n3) Volver al menu principal: ",
				"Error, opcion invalida! ", 1, 3);
		switch (opcion)
		{
		case 1:
			PedirCadena("Ingrese modificacion de la direccion : ",
					aux.direccion, MAX_NOMBRE);
			break;
		case 2:
			MostrarLocalidades(listaLoc, tamLoc);
			PedirEnteroP(&aux.idLocalidad, "Ingrese id de la localidad: ",
					"Error, ingreso invalido ", 1, 9999);
			//PedirCadena("Ingrese modificacion de la localidad : ", aux.localidad, MAX_NOMBRE);
			break;
		case 3:
			break;
		}
		EncabezadoCliente();
		MostrarUnCliente(aux);
		PedirEnteroP(&opcion, "Desea guardar cliente asi? \n1) SI\n2) NO \n",
				"Error, opcion invalida ", 1, 2);
		if (opcion == 1)
		{
			lista[indice] = aux;
			retorno = 1;
		}
		else
		{
			retorno = 2;
		}
	}
	return retorno;
}

/*int BuscarClienteConMasPedidosPendientes(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido)
{
	int retorno;
	int cantidad;
	int maximo = -1;
	int bandera = 1;
	eCliente aux;

	retorno = -1;

	if (listaCliente != NULL && tamCliente > 0 && listaPedido != NULL && tamPedido > 0)
	{
		for (int i = 0; i < tamCliente; i++)
		{
			if (listaCliente[i].isEmpty == 1)
			{

				ContarPendientes(listaPedido, tamPedido,
						listaCliente[i].idCliente, &cantidad);
				aux = listaCliente[i];
				printf("\nasdmmmm%dmmmmmasd\n", cantidad);

				if (bandera == 1 || maximo < cantidad)
				{
					aux = listaCliente[i];
					maximo = cantidad;
					bandera = 0;
					printf("\n11mmmm%dmmmmm11\n", cantidad);
				}
				printf("mmmm%dmmmmm", cantidad);
			}
		}

		//MostrarUnCliente(aux);
		printf("\nf***%d***f\n", cantidad);
	}

	return retorno;
}*/

int BuscarClienteConMasPedidosPendientes(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente)
{
	int retorno;
	eAuxiliar aux[tamCliente];
	eCliente auxCliente;
	int mayor;

	InicializarAux(aux, tamCliente);

	retorno = -1;

	if (listaPedido != NULL && tamPedido > 0)
	{
		retorno = 0;
		for(int i = 0; i < tamCliente; i++)
		{
			if(listaCliente[i].isEmpty == CARGADO)
			{
				for(int j = 0; j < tamPedido; j++)
				{
					if(listaPedido[j].isEmpty == CARGADO && listaPedido[j].estado == PENDIENTE &&
							listaPedido[j].idCliente == listaCliente[i].idCliente)
					{
						aux[i].idCliente = listaCliente[i].idCliente;
						aux[i].contador++;
						aux[i].isEmpty = CARGADO;
					}
				}
			}
		}

		CalcularMayor(aux, tamCliente, &mayor);


	}

	return retorno;
}

/*void MostrarClientesConCantidadDePedidosSegunEstado(eCliente listaCliente[], int tamCliente, eAuxiliar aux[], int)
{
	for(int i = 0; i < tamCliente; i++)
	{
		if(aux[i].isEmpty == CARGADO && aux[i].contador == mayor)
		{
			auxCliente = ObtenerClientePorID(listaCliente, tamCliente, aux[i].idCliente);

			printf("Nombre: %s cantidad: %d\n", auxCliente.nombre, aux[i].contador);
		}
	}
}*/

int CalcularMayor(eAuxiliar listaAux[], int tamAux, int* cantidad)
{
	int retorno;
	int bandera;
	int mayor;

	retorno = -1;
	bandera = 0;

	if(listaAux != NULL && tamAux > 0)
	{
		retorno = 0;
		for(int i = 0; i < tamAux; i++)
		{
			if(listaAux[i].isEmpty == CARGADO && (bandera == 0 || mayor < listaAux[i].contador))
			{
				mayor = listaAux[i].contador;
				bandera = 1;
			}
		}

		*cantidad = mayor;
	}

	return retorno;

}

void ING_renglones(int posicion, int cantidad, char simbolo)
{
	switch (posicion)
	{
	case -1:
		for (int i = 0; i < cantidad; i++)
		{
			printf("%c", simbolo);
		}
		printf("\n");
		break;
	case 0:
		for (int i = 0; i < cantidad; i++)
		{
			printf("%c", simbolo);
		}
		break;
	case 1:
		printf("\n");
		for (int i = 0; i < cantidad; i++)
		{
			printf("%c", simbolo);
		}
		break;
	}

}
