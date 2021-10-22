/*
 ============================================================================

 ============================================================================
 */

#include "Nexo.h"
#define TCLIENTE 100
#define TPEDIDO 1000
#define MAX_NOMBRE 60



int main(void)
{
	setbuf(stdout, NULL);

	eCliente clientes[TCLIENTE] =
	{
	{ "Coca Cola", "22-44556655-2", "San Martin 266", "Abasto", 1, CARGADO },
	{ "Pepsi", "22-88887777-2", "Vieytes 885", "Washington DC", 2, CARGADO },
	{ "Royal Canin", "11-45678489-2", "Comahue 266", "Banfield", 3, CARGADO },
	{ "Eukanuba", "12-55988744-2", "Espora 5990", "Lomas de Zamora", 4, CARGADO },
	{ "Pedigree", "55-15874965-2", "Saavedra 352", "Lanus", 5, CARGADO },
	{ "Purina", "11-49875963-2", "Eva Peron 254", "Temperley", 6, CARGADO } };

	ePedido pedidos[TPEDIDO] =
	{
			{ 1, 1, 100, CARGADO, PENDIENTE, 0, 0, 0},
			{ 2, 1, 500, CARGADO, PENDIENTE, 0, 0, 0},
			{ 3, 2, 625, CARGADO, PENDIENTE, 0, 0, 0},
			{ 4, 1, 1990, CARGADO, PENDIENTE, 0, 0, 0}
	};

	int opcion;
	int bancoIdCliente;
	int bancoIdPedido;

	bancoIdCliente = 7;
	bancoIdPedido = 5;
	//InicializarArray(clientes, TCLIENTE);
	//Hardcodeo(clientes);

	do
	{
		//PedirEnteroP(&opcion, "Ingrese la opcion deseada:1) Altas\n2) Modificaciones\n3) Bajas", "Error, opcion invalida ", 1, 9);
		switch (MenuDeOpciones())
		{
		case 1:
			switch (AltaCliente(clientes, TCLIENTE, &bancoIdCliente))
			{
			case -1:
				printf("Parametros invalidos!\n");
				break;
			case 0:
				printf("No hay posiciones libres!\n");
				break;
			case 1:
				printf("Alta generada con exito\n");
				break;
			case 2:
				printf("Alta cancelada\n");
				break;
			}
			break;
		case 2:
			switch (ModificarCliente(clientes, TCLIENTE))
			{
			case -1:
				printf("Parametros invalidos!\n");
				break;
			case 0:
				printf("No hay posiciones libres!\n");
				break;
			case 1:
				printf("Modificacion generada con exito\n");
				break;
			case 2:
				printf("Modificacion cancelada\n");
				break;
			}
			break;
		case 3:
			switch(BajaCliente(clientes, TCLIENTE))
			{
			case -1:
				printf("Parametros invalidos!\n");
				break;
			case 0:
				printf("No hay posiciones libres!\n");
				break;
			case 1:
				printf("baja generada con exito\n");
				break;
			case 2:
				printf("baja cancelada\n");
				break;
			}
			break;
		case 4:
			printf("\n                ******* Crear pedido de recoleccion *******\n\n");
			switch(CrearPedidoDeRecoleccion(clientes, TCLIENTE, pedidos, TPEDIDO, &bancoIdPedido))
			{
			case -1:
				printf("Parametros invalidos!\n");
				break;
			case 0:
				printf("No hay posiciones libres!\n");
				break;
			case 1:
				printf("Pedido generado con exito!\n");
				break;
			case 2:
				printf("Pedido cancelado\n");
				break;
			}
			break;
		case 5:
			printf("\n                             ******* Procesando residuos *******\n\n");
			MostrarPedidosPendientesConKilos(clientes, TCLIENTE, pedidos, TPEDIDO);
			ProcesarResiduos(pedidos, TPEDIDO, bancoIdPedido);
			break;
		case 6:
			printf("\n                   ******* Clientes con pedidos en estado pendiente *******\n\n");
			MostrarClientesConCantidadPedidosPendientes(clientes, TCLIENTE, pedidos, TPEDIDO);
			break;
		case 7:
			printf("\n                       ******* Pedidos con estado pendiente *******\n\n");
			MostrarPedidosPendientesConKilos(clientes, TCLIENTE, pedidos, TPEDIDO);
			break;
		case 9:
			switch(CantidadPendientesPorLocalidad(clientes, TCLIENTE, pedidos, TPEDIDO))
				{
				case -1:
					printf("Parametros invalidos!\n");
					break;
				case 0:
					printf("No hay clientes cargados!\n");
					break;
				}
			break;
		case 15:
			PedirEnteroP(&opcion, "Desea salir? \n1) SALIR: \n2) NO SALIR: ",
								"Error, opcion invalida ", 1, 2);
			break;
		}
	} while (opcion != 1);

	return EXIT_SUCCESS;
}

