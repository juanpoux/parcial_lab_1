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
	{ "Coca Cola", "22-44556655-2", "San Martin 266", "Abasto", 1,
	CARGADO },
	{ "Pepsi", "22-88887777-2", "Vieytes 885", "Gerli", 2,
	CARGADO },
	{ "Royal Canin", "11-45678489-2", "Comahue 266", "Banfield", 3,
	CARGADO },
	{ "Eukanuba", "12-55988744-2", "Espora 5990", "Lomas de Zamora", 4,
	CARGADO },
	{ "Pedigree", "55-15874965-2", "Saavedra 352", "Lanus", 5,
	CARGADO },
	{ "Purina", "11-49875963-2", "Eva Peron 254", "Temperley", 6,
	CARGADO } };

	ePedido pedidos[TPEDIDO] =
	{
	{ 1, 1, 100, PENDIENTE, CARGADO, 0, 0, 0 },
	{ 2, 1, 500, PENDIENTE, CARGADO, 0, 0, 0 },
	{ 3, 5, 600, COMPLETADO, CARGADO, 50, 90, 0 },
	{ 4, 6, 625, COMPLETADO, CARGADO, 50, 60, 0 },
	{ 5, 2, 500, PENDIENTE, CARGADO, 0, 0, 0 },
	{ 6, 2, 800, COMPLETADO, CARGADO, 70, 80, 0 },
	{ 7, 2, 625, PENDIENTE, CARGADO, 0, 0, 0 },
	{ 8, 1, 1990, PENDIENTE, CARGADO, 0, 0, 0 } };

	int opcion;
	int bancoIdCliente;
	int bancoIdPedido;
	int banderaCliente;

	bancoIdCliente = 7;
	bancoIdPedido = 9;
	banderaCliente = 1;
	//InicializarArray(clientes, TCLIENTE);
	//Hardcodeo(clientes);

	do
	{
		switch (MenuDeOpciones())
		{
		case 1:
			printf(
					"\n                ******* Dar de alta un cliente *******\n\n");
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
				banderaCliente = 1;
				break;
			case 2:
				printf("Alta cancelada\n");
				break;
			}
			break;
		case 2:
			if (banderaCliente == 1)
			{
				printf(
						"\n               ******* Modificar datos de un cliente *******\n\n");
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
			}
			else
			{
				printf("Primero debe dar de alta al menos un cliente\n");
			}
			break;
		case 3:
			if (banderaCliente == 1)
			{
				printf(
						"\n                  ******* Dar de baja un cliente *******\n\n");
				switch (BajaCliente(clientes, TCLIENTE, pedidos, TPEDIDO))
				{
				case -1:
					printf("Parametros invalidos!\n");
					break;
				case 0:
					printf("No hay posiciones libres!\n");
					break;
				case 1:
					printf("Baja generada con exito\n");
					banderaCliente = SaberSiHayClientesActivos(clientes,
					TCLIENTE);
					break;
				case 2:
					printf("Baja cancelada\n");
					break;
				}
			}
			else
			{
				printf("Primero debe dar de alta al menos un cliente\n");
			}
			break;
		case 4:
			if (banderaCliente == 1)
			{
				printf(
						"\n                ******* Crear pedido de recoleccion *******\n\n");
				switch (CrearPedidoDeRecoleccion(clientes, TCLIENTE, pedidos,
				TPEDIDO, &bancoIdPedido))
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
			}
			else
			{
				printf("Primero debe dar de alta al menos un cliente\n");
			}
			break;
		case 5:
			if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
			{
				printf(
						"\n                             ******* Procesando residuos *******\n\n");

				switch (ProcesarResiduos(pedidos, TPEDIDO, bancoIdPedido,
						clientes,
						TCLIENTE))
				{
				case -1:
					printf("Parametros invalidos!\n");
					break;
				case 0:
					printf("No hay posiciones libres!\n");
					break;
				case 1:
					printf("Proceso de residuos exitoso!\n");
					break;
				case 2:
					printf("Proceso de residuos cancelado\n");
					break;
				}
			}
			else
			{
				printf("Primero debe crear al menos un pedido!\n");
			}
			break;
		case 6:
			if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
			{
				printf(
						"\n             ******* Clientes con cantidad de pedidos en estado pendiente *******\n\n");

				switch (MostrarClientesConCantidadPedidosPendientes(clientes,
				TCLIENTE, pedidos, TPEDIDO))
				{
				case -1:
					printf("Parametros invalidos!\n");
					break;
				}
			}
			else
			{
				printf("Primero debe crear al menos un pedido!\n");
			}
			break;
		case 7:
			if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
			{
				printf(
						"\n                       ******* Pedidos con estado pendiente *******\n\n");

				switch (MostrarPedidosPendientesConKilos(clientes, TCLIENTE,
						pedidos,
						TPEDIDO))
				{
				case -1:
					printf("Parametros invalidos!\n");
					break;
				}
			}
			else
			{
				printf("Primero debe crear al menos un pedido!\n");
			}
			break;
		case 8:
			if (VerificarEstadoActivo(pedidos, TPEDIDO, COMPLETADO) == 1)
			{
				printf(
						"\n                ******* Pedidos procesados *******\n\n");

				switch (MostrarPedidosProcesadosConDescripcion(clientes,
				TCLIENTE, pedidos,
				TPEDIDO))
				{
				case -1:
					printf("Parametros invalidos!\n");
					break;
				}
			}
			else
			{
				printf("Primero debe procesar al menos un pedido!\n");
			}
			break;
		case 9:
			if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
			{
				printf(
						"\n                ******* Cantidad de pedidos pendientes por localidad *******\n\n");
				switch (CantidadPendientesPorLocalidad(clientes, TCLIENTE,
						pedidos,
						TPEDIDO))
				{
				case -1:
					printf("Parametros invalidos!\n");
					break;
				}
			}
			else
			{
				printf("Primero debe crear al menos un pedido!\n");
			}
			break;
		case 10:
			if (VerificarEstadoActivo(pedidos, TPEDIDO, COMPLETADO) == 1)
			{
				printf(
						"\n               ******* Promedio de kilos reciclados de polipropileno *******\n\n");

				switch (CalcularPromedioPP(pedidos, TPEDIDO, clientes, TCLIENTE))
				{
				case -1:
					printf("Parametros invalidos!\n");
					break;
				case 2:
					printf("No hay polipropileno reciclado por el momento...\n");
					break;
				}
			}
			else
			{
				printf("Primero debe procesar al menos un pedido!\n");
			}
			break;
		case 0:
			PedirEnteroP(&opcion, "Desea salir? \n1) SALIR: \n2) NO SALIR: ",
					"Error, opcion invalida ", 1, 2);

			break;
		}
	} while (opcion != 1);

	return EXIT_SUCCESS;
}

