/*
 * Parcial 1 laboratorio
 * Juan Poux 1 C
 *
 */

#include "Nexo.h"
#define TCLIENTE 100
#define TPEDIDO 1000
#define TLOCALIDAD 6
#define MAX_NOMBRE 60

int main(void)
{
	setbuf(stdout, NULL);

	eCliente clientes[TCLIENTE];

	ePedido pedidos[TPEDIDO];

	eLocalidad localidades[TLOCALIDAD];

	int opcion;
	int salida;
	int bancoIdCliente;
	int bancoIdPedido;

	bancoIdCliente = 1;
	bancoIdPedido = 1;
	salida = 2;

	InicializarArray(clientes, TCLIENTE);
	InicializarArrayPedidos(pedidos, TPEDIDO);
	InicializarLocalidades(localidades, TLOCALIDAD);
	HardcodearLocalidades(localidades, TLOCALIDAD);
	HardcodearClientes(clientes, 6, &bancoIdCliente);
	HardcodearPedidos(pedidos, 9, &bancoIdPedido);

	do
	{
		switch (MenuDeOpciones())
		{
		case 1:
			printf(
					"\n                ******* Dar de alta un cliente *******\n\n");
			//switch (AltaCliente(clientes, TCLIENTE, &bancoIdCliente))
			switch (AltaCliente2(clientes, TCLIENTE, &bancoIdCliente,
					localidades, TLOCALIDAD))
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
			if (SaberSiHayClientesActivos(clientes,
					TCLIENTE) == 1)
			{
				printf(
						"\n               ******* Modificar datos de un cliente *******\n\n");
				//switch (ModificarCliente(clientes, TCLIENTE))
				switch (ModificarCliente2(clientes, TCLIENTE, localidades,
				TLOCALIDAD))
				{
				case -1:
					printf("Parametros invalidos!\n");
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
			if (SaberSiHayClientesActivos(clientes,
					TCLIENTE) == 1)
			{
				PedirEnteroP(&opcion, "1 BAJA CLIENTE\n2 BAJA PEDIDO: ",
						"Error, opcion invalida ", 1, 2);
				if (opcion == 1)
				{
					printf(
							"\n\t\t\t******* Dar de baja un cliente *******\n\n");

					switch (BajaCliente(clientes, TCLIENTE, pedidos, TPEDIDO,
							localidades, TLOCALIDAD))
					{
					case -1:
						printf("Parametros invalidos!\n");
						break;
					case 1:
						printf("Baja generada con exito!\n");
						break;
					case 2:
						printf("Baja cancelada\n");
						break;
					}
				}
				else
				{
					printf("\n\t\t\t******* Dar de baja un pedido *******\n\n");
					if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
					{
						switch (BajaPedido(pedidos, TPEDIDO, clientes, TCLIENTE,
								localidades, TLOCALIDAD))
						{
						case -1:
							printf("Parametros invalidos!\n");
							break;
						case 1:
							printf("Baja generada con exito!\n");
							break;
						case 2:
							printf("Baja cancelada\n");
							break;
						}
					}
				}
			}
			else
			{
				printf("Primero debe dar de alta al menos un cliente\n");
			}
			break;
		case 4:
			if (SaberSiHayClientesActivos(clientes,
					TCLIENTE) == 1)
			{
				printf(
						"\n                ******* Crear pedido de recoleccion *******\n\n");
				switch (CrearPedidoDeRecoleccion(clientes, TCLIENTE, pedidos,
				TPEDIDO, &bancoIdPedido, localidades, TLOCALIDAD))
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
						TCLIENTE, localidades, TLOCALIDAD))
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
			switch (MenuInformes())
			{
			case 1:
				if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
				{
					printf(
							"\n             ******* Clientes con cantidad de pedidos en estado pendiente *******\n\n");

					switch (MostrarClientesConCantidadPedidosPendientes(
							clientes,
							TCLIENTE, pedidos, TPEDIDO, localidades, TLOCALIDAD))
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
			case 2:
				if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
				{
					printf(
							"\n                       ******* Pedidos con estado pendiente *******\n\n");

					switch (MostrarPedidosPendientesConKilos(clientes, TCLIENTE,
							pedidos, TPEDIDO, localidades, TLOCALIDAD))
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
			case 3:
				if (VerificarEstadoActivo(pedidos, TPEDIDO, COMPLETADO) == 1)
				{
					printf(
							"\n                                                   ******* Pedidos procesados *******\n\n");

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
			case 4:
				if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
				{
					printf(
							"\n                ******* Cantidad de pedidos pendientes por localidad *******\n\n");
					switch (CantidadPendientesPorLocalidad(clientes, TCLIENTE,
							pedidos,
							TPEDIDO, localidades, TLOCALIDAD))
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
			case 5:
				if (VerificarEstadoActivo(pedidos, TPEDIDO, COMPLETADO) == 1)
				{
					printf(
							"\n               ******* Promedio de kilos reciclados de polipropileno *******\n\n");

					switch (CalcularPromedioPP(pedidos, TPEDIDO, clientes,
							TCLIENTE))
					{
					case -1:
						printf("Parametros invalidos!\n");
						break;
					case 2:
						printf(
								"No hay polipropileno reciclado por el momento...\n");
						break;
					}
				}
				else
				{
					printf("Primero debe procesar al menos un pedido!\n");
				}
				break;
			case 6:
				if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
				{
					printf(
							"\n        ******* Clientes con mas cantidad de pedidos pendientes *******\n\n");
					if (MostrarClientesConCantidadDePedidosSegunEstado(clientes,
					TCLIENTE, pedidos, TPEDIDO, PENDIENTE) == -1)
					{
						printf("Parametros invalidos!\n");
					}
				}
				else
				{
					printf("Primero debe procesar al menos un pedido!\n");
				}
				break;

			case 7:
				if (VerificarEstadoActivo(pedidos, TPEDIDO, COMPLETADO) == 1)
				{
					printf(
							"\n        ******* Clientes con mas cantidad de pedidos completados *******\n\n");
					if (MostrarClientesConCantidadDePedidosSegunEstado(clientes,
					TCLIENTE, pedidos, TPEDIDO, COMPLETADO) == -1)
					{
						printf("Parametros invalidos!\n");
					}
				}
				else
				{
					printf("Primero debe procesar al menos un pedido!\n");
				}
				break;
			case 8:
				if (VerificarEstadoActivo(pedidos, TPEDIDO, PENDIENTE) == 1)
				{
					printf(
							"\n         ******* Clientes con mas cantidad de pedidos *******\n\n");
					if (BuscarClienteConMayorCantidadPedidos(clientes, TCLIENTE,
							pedidos,
							TPEDIDO) == -1)
					{
						printf("Parametros invalidos!\n");
					}
				}
				else
				{
					printf("Primero debe crear al menos un pedido!\n");
				}
				break;
			case 9:
				if (SaberSiHayClientesActivos(clientes,
						TCLIENTE) == 1)
				{
					EncabezadoCliente();
					MostrarListaClientes2(clientes, TCLIENTE, localidades,
					TLOCALIDAD);
				}
				else
				{
					printf("Debe hacer la carga de al menos 1 cliente\n");
				}
				break;
			case 10:
				EncabezadoLocalidades();
				MostrarLocalidades(localidades, TLOCALIDAD);
				break;
			}
			break;
		}
	} while (salida != 1);

	return EXIT_SUCCESS;
}
