#include "Localidad.h"
void EncabezadoLocalidades()
{
	Renglones(1, 29, '=');
	printf("\n|%-5s |%-19s |\n", "ID", "Localidad");
	Renglones(-1, 29, '=');
}

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
	}

	return retorno;
}

void MostrarUnaLocalidad(eLocalidad localidad)
{
	printf("|%-6d|%-20s|\n", localidad.idLocalidad, localidad.descripcion);
	Renglones(-1, 29, '-');
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

void HardcodearLocalidades(eLocalidad lista[], int tam)
{
	int idLoc[] = { 1,2,3,4,5,6 };
	char descripcion[][MAX_NOMBRE] = { "Lomas de Zamora", "Banfield", "Lanus", "Temperley", "Adrogue", "Avellaneda" };
	int isEmpty[] = { CARGADO,CARGADO,CARGADO,CARGADO,CARGADO,CARGADO };
	int contador;

	contador = 1;

	for(int i = 0; i < tam; i++)
	{
		lista[i].idLocalidad= idLoc[i];
		strcpy(lista[i].descripcion, descripcion[i]);
		lista[i].isEmpty = isEmpty[i];
		contador++;
	}
}

int InicializarLocalidades(eLocalidad lista[], int tam)
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

