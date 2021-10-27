#include "Localidad.h"

int MostrarLocalidades(eLocalidad lista[], int tam)
{
	int retorno;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO)
			{
				MostrarUnaLocalidad(lista[i]);
			}
		}
		printf("-----------------------------\n");
	}

	return retorno;
}


void MostrarUnaLocalidad(eLocalidad localidad)
{
	printf("-----------------------------\n");
	printf("|%-6d|%-20s|\n", localidad.idLocalidad, localidad.descripcion);
}

eLocalidad ObtenerLocalidadPorID(eLocalidad lista[], int tam, int id)
{
	eLocalidad aux;
	int i;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].idLocalidad == id)
			{
				aux = lista[i];
				break;
			}
		}
	}

	return aux;
}

int VerificarIdActivoLocalidad(eLocalidad lista[], int tam, int id)
{
	int retorno;

	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		retorno = 0;
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].idLocalidad == id)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int PedirYVerificarIdLocalidad(eLocalidad lista[], int tam, int* id, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int retorno;
	int idAux;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		retorno = 1;
		PedirEnteroP(&idAux, mensaje, mensajeError, minimo, maximo);

		while(VerificarIdActivoLocalidad(lista, tam, idAux) != 1)
		{
			printf("El ID ingresado no es valido\n");
			PedirEnteroP(&idAux, mensaje, mensajeError, minimo, maximo);
		}

		*id = idAux;
	}

	return retorno;
}
