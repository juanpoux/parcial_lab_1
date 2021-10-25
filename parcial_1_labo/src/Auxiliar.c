#include "Auxiliar.h"

void InicializarAux(eAuxiliar lista[], int tam)
{
	int i;

	for(i = 0; i<tam; i++)
	{
		lista[i].contador = 0;
		lista[i].flotantes = 0;
		lista[i].isEmpty = VACIO;
		lista[i].id = 0;
		lista[i].idCliente = 0;
	}
}
