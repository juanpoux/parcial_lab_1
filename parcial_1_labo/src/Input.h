/*
 * CargarVectorEntero.h
 *
 *  Created on: 12 sep. 2021
 *      Author: poux_
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @fn void CargarVectorEntero(char[], int[], int, int, int)
/// @brief pide el ingreso de numeros en un array
///
/// @param mensaje
/// @param array de enteros
/// @param tam
/// @param numero minimo
/// @param numero maximo
void CargarVectorEntero(char mensaje[], int [], int tam, int, int);

/// @fn int PedirCadena(char[], char[], int)
/// @brief pide el ingreso de una cadena de texto
///
/// @param mensaje
/// @param cadena
/// @param tam
/// @return retorna 1 si fue exitoso, 0 si hubo algun error
int PedirCadena(char mensaje[], char cadena[], int tam);

/// @fn int VerificarLetras(char[])
/// @brief Verifica que el ingreso sea solo de letras
///
/// @param cadena
/// @return retorna 1 si solo se ingresaron letras, 0 si ingreso algun caracter invalido
int VerificarLetras(char cadena[]);

/// @fn int PedirNombre(char[], char[], int)
/// @brief Pide el ingreso de un nombre
///
/// @param mensaje
/// @param cadena
/// @param tam
/// @return retorna 1 si fue exitoso, 0 si hubo algun error
int PedirNombre(char mensaje[], char cadena[], int tam);

/// @fn int MyGets(char*, int)
/// @brief guarda el ingreso de un numero entero en formato string
///
/// @param cadena
/// @param tam
/// @return por ahora no retorna nada
///
int MyGets(char* cadena, int tam);

/// @fn int EsEntero(char*)
/// @brief Verifica que el ingreso tenga solo numeros.
///
/// @param cadena
/// @return 1 si es un entero, 0 si no lo pudo validar
int EsEntero(char* cadena);

/// @fn int GetInt(int*)
/// @brief convierte el string validado en un numero entero
///
/// @param pResultado
/// @return retorna 1 si pudo hacerlo correctamente, 0 si no pudo
int GetInt(int* pResultado);

/// @fn void PedirEnteroP(int*, char*, char*, int, int)
/// @brief funcion que pide el ingreso del numero entero
///
/// @param pResultado variable donde se guarda el entero recibido
/// @param mensaje mensaje para el usuario
/// @param mensajeError mensaje de error para el usuario
/// @param minimo numero maximo posible
/// @param maximo numero minimo posible
void PedirEnteroP(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/// @fn int EsFloat(char*)
/// @brief
///
/// @param cadena
/// @return
int EsFloat(char* cadena);

/// @fn int GetFloat(float*)
/// @brief convierte el string validado en un numero flotante
///
/// @param pResultado
/// @return retorna 1 si pudo hacerlo correctamente, 0 si no pudo
int GetFloat(float* pResultado);

/// @fn void PedirFlotanteP(float*, char*, char*, int, int)
/// @brief pide el ingreso de un numero flotante
///
/// @param pResultado variable donde se guarda el entero recibido
/// @param mensaje mensaje para el usuario
/// @param mensajeError mensaje de error para el usuario
/// @param minimo numero maximo posible
/// @param maximo numero minimo posible
void PedirFlotanteP(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/// @fn int PedirCuit(char[])
/// @brief pide y valida el ingreso de un cuit
///
/// @param cadena
/// @return retorna 1 si pudo validar el ingreso y 0 si tiene que pedirlo de nuevo
int PedirCuit(char cadena[]);

/// @fn void Renglones(int, int, char)
/// @brief crea una linea con el simbolo que elija
///
/// @param posicion
/// @param cantidad
/// @param simbolo
void Renglones(int posicion, int cantidad, char simbolo);

#endif /* BIBLIOTECA_H_ */
