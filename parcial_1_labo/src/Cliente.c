#include "Cliente.h"

void Hardcodeo(eCliente* lista)
{
	eCliente clientes[3] =
	{
	{ "Coca Cola", "22-44556655-2", "San Martin 266", "Abasto", 1, CARGADO },
	{ "Pepsi", "22-88887777-2", "Vieytes 885", "Washington DC", 2, CARGADO },
	{ "Google", "11-77777777-2", "Comahue 266", "Banfield", 3, CARGADO } };

	//if(lista != NULL)
	//{
		lista = clientes;
	//}
}

eCliente CargarCliente(int idGenerico)
{
	eCliente cliente;

	PedirCadena("Ingrese el nombre de la empresa: ", cliente.nombre, MAX_NOMBRE);
	//PedirCadena("Ingrese el ciut de la empresa: ", cliente.cuit, MAX_NOMBRE);
	PedirCuit(cliente.cuit);
	PedirCadena("Ingrese la direccion de la empresa: ", cliente.direccion, MAX_NOMBRE);
	PedirCadena("Ingrese la localidad de la empresa: ", cliente.localidad, MAX_NOMBRE);
	cliente.idCliente = idGenerico;
	cliente.isEmpty = CARGADO;

	return cliente;
}

int AltaCliente(eCliente lista[], int tam, int* generadorId)
{
	int retorno;
	int indice;
	int opcion;
	eCliente aux;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		retorno = 0;
		indice = BuscarLibreCliente(lista, tam);
		if(indice != -1)
		{
			aux = CargarCliente(*generadorId);
		}

		EncabezadoCliente();
		MostrarUnCliente(aux);
		PedirEnteroP(&opcion, "Desea guardar cliente asi? \n1) SI\n2) NO\n", "Error, opcion invalida ", 1, 2);

		if(opcion == 1)
		{
			lista[indice] =  aux;
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

int BuscarLibreCliente(eCliente lista[], int tam)
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
int MenuDeOpciones()
{
	int retorno;

	printf("====================\n\tMENU\n====================\n\n1) ALTAS \n2) MODIFICACIONES \n3) BAJAS \n4) CREAR PEDIDO DE RECOLECCION"
			"\n5) PROCESAR RESIDUOS \n6) MOSTRAR CLIENTES CON PEDIDOS PENDIENTES \n7) MOSTRAR PEDIDOS PENDIENTES"
			"\n8) MOSTRAR PEDIDOS PROCESADOS \n9) MOSTRAR PEDIDOS PENDIENTES POR LOCALIDAD "
			"\n10) MOSTRAR CANTIDAD DE KILOS RECICLADOS DE POLIPROPILENO RECICLADO POR CLIENTE \n0) SALIR\n\n");
	PedirEnteroP(&retorno, "Ingrese una opcion: ", "Error, opcion invalida! ", 0, 10);

	return retorno;
}

void EncabezadoCliente()
{
printf("=====================================================================================\n");
printf("|%4s |%-15s |%-15s |%-20s |%-20s |\n", "ID", "Empresa", "CUIT", "Direccion", "Localidad");
printf("=====================================================================================\n");
}
void MostrarUnCliente(eCliente lista)
{
	printf("|%4d |", lista.idCliente);
	printf("%-15s |", lista.nombre);
	printf("%-15s |", lista.cuit);
	printf("%-20s |", lista.direccion);
	printf("%-20s |\n", lista.localidad);

	//printf("%-4d |\n", lista.isEmpty);
	printf(
			"-------------------------------------------------------------------------------------\n");
}

int MostrarListaClientes(eCliente lista[], int tam)
{
	int i;
	int retorno;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == CARGADO)
			{
				MostrarUnCliente(lista[i]);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int InicializarArray(eCliente lista[], int tam)
{
	int retorno;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = VACIO;
		}
	}

	return retorno;
}

int BuscarClientePorID(eCliente lista[], int tam, int id)
{
	int i;
	int retorno;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].idCliente == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int ModificarCliente(eCliente lista[], int tam)
{
	int retorno;
	int idCliente;
	int indice;
	int opcion;
	eCliente aux;
	retorno = -1;
	if(lista != NULL && tam > 0)
	{
		retorno = 0;
		EncabezadoCliente();
		MostrarListaClientes(lista, tam);
		PedirYVerificarIdCliente(lista, tam, &idCliente, "Seleccione el ID del cliente que desea modificar: ", "Error, opcion invalida! ", 1, 9999);
		indice = BuscarClientePorID(lista, tam, idCliente);
		aux = lista[indice];
		EncabezadoCliente();
		MostrarUnCliente(aux);
		PedirEnteroP(&opcion, "1) Modificar direccion \n2) Modificar localidad \n3) Volver al menu principal: ", "Error, opcion invalida! ", 1, 3);
		switch(opcion)
		{
		case 1:
			PedirCadena("Ingrese modificacion de la direccion : ", aux.direccion, MAX_NOMBRE);
			break;
		case 2:
			PedirCadena("Ingrese modificacion de la localidad : ", aux.localidad, MAX_NOMBRE);
			break;
		case 3:
			break;
		}
		EncabezadoCliente();
		MostrarUnCliente(aux);
		PedirEnteroP(&opcion, "Desea guardar cliente asi? \n1) SI\n2) NO \n", "Error, opcion invalida ", 1, 2);
		if(opcion == 1)
		{
			lista[indice] =  aux;
			retorno = 1;
		}
		else
		{
			retorno = 2;
		}
	}
	return retorno;
}

int VerificarIdActivoCliente(eCliente lista[], int tam, int id)
{
	int retorno;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		retorno = 0;
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].idCliente == id)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int PedirYVerificarIdCliente(eCliente lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int retorno;
	int idAux;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		retorno = 1;
		PedirEnteroP(&idAux, mensaje, mensajeError, minimo, maximo);

		while(VerificarIdActivoCliente(lista, tam, idAux) != 1)
		{
			printf("El ID ingresado no es valido\n");
			PedirEnteroP(&idAux, mensaje, mensajeError, minimo, maximo);
		}

		*id = idAux;
	}

	return retorno;
}

int MostrarClientePorIdConCantidad(eCliente lista[], int tam, int id, int cantidad)
{
	int i;
	int retorno;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty == CARGADO && lista[i].idCliente == id)
			{
				MostrarUnClienteConCantidad(lista[i], cantidad);
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

void MostrarUnClienteConCantidad(eCliente lista, int cantidad)
{
	printf("|%4d |", lista.idCliente);
	printf("%-15s |", lista.nombre);
	printf("%-15s |", lista.cuit);
	printf("%-20s |", lista.direccion);
	printf("%-20s |", lista.localidad);
	printf("%-16d |\n", cantidad);
	//printf("%-4d |", lista.isEmpty);

	printf(
			"-------------------------------------------------------------------------------------------------------\n");
}

eCliente ObtenerClientePorID(eCliente lista[], int tam, int id)
{
	eCliente aux;
	int i;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].idCliente == id)
			{
				aux = lista[i];
				break;
			}
		}
	}

	return aux;
}

int SaberSiHayClientesActivos(eCliente lista[], int tam)
{
	int retorno;
	int i;

	retorno = 0;
	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int ContadorClientes(eCliente lista[], int tam, int* contClientes)
{
	int retorno;
	int i;
	int contador;

	retorno = -1;
	contador = 0;

	if(lista != NULL && tam > 0)
	{
		retorno = 0;
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO)
			{
				retorno = 1;
				contador++;
				//*contClientes = *contClientes + 1;
			}
		}
	}
	*contClientes = contador;

	return retorno;
}

