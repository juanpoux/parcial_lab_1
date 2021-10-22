#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int PedirCadena(char mensaje[], char cadena[], int tam);
int PedirCuit(char cadena[]);

int main(void)
{
	setbuf(stdout, NULL);

    char cuit[14];

    if(PedirCuit(cuit) == 0)
    {
        printf("**********");
    }
    else
    {
        printf("\n%s", cuit);
    }

	return 0;
}

int PedirCuit(char cadena[])
{
    int retorno = 0;
    int contador = 0;

    PedirCadena("Ingrese CUIT:\nEjemplo 12-12345678-1*: ", cadena, 14);
    while(retorno != 1)
    {
    	retorno = 1;
		PedirCadena("ERROR Ingrese CUIT:\nEjemplo 12-12345678-1*: ", cadena, 14);
		if(strlen(cadena) == 13)
		{
			for(int i = 0; i < 14 && cadena[i] != '\0'; i++)
			{
				if(i == 2 && cadena[i] == '-')
				{   printf("asd\n");
					continue;
				}
				if(i == 11 && cadena[i] == '-')
				{   printf("dsa\n");
					continue;
				}
				if(isdigit(cadena[i]) == 0)
				{   contador++;
					retorno = 0;
					printf("%d\n", contador);
					break;
				}
			}
		}
		else
		{
			retorno = 0;
		}
    }
    return retorno;
}

int PedirCadena(char mensaje[], char cadena[], int tam)
{
	int retorno = 0;

	if (mensaje != NULL && cadena != NULL)
	{
		fflush(stdin);
		printf("%s\n", mensaje);
		scanf("%[^\n]", cadena);
		retorno = 1;
	}

	return retorno;
}
