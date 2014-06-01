/*
 * OperacionesEntreVentanas.h
 *
 *  Created on: 01/06/2014
 *      Author: juanignacio
 */

#ifndef OPERACIONESENTREVENTANAS_H_
#define OPERACIONESENTREVENTANAS_H_
#include "stdio.h"
#include "string.h"
#include "../manejoArchivo/ManejoArchivo.h"
#include "../lz77/Ventana.h"

class OperacionesEntreVentanas {

public:
	virtual ~OperacionesEntreVentanas();
	OperacionesEntreVentanas();

	//devuelve la posicion donde este el maximo match en la ventana de memoria
	//tamanioMatch para recuperar la cantidad de match en repeticion
	int buscarMaximoMatch(Ventana* inspeccion, Ventana* memoria, int* tamanioMatch);
};

#endif /* OPERACIONESENTREVENTANAS_H_ */
