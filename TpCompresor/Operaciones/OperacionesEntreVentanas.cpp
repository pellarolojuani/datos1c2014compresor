/*
 * OperacionesEntreVentanas.cpp
 *
 *  Created on: 01/06/2014
 *      Author: juanignacio
 */

#include "OperacionesEntreVentanas.h"

OperacionesEntreVentanas::~OperacionesEntreVentanas() {
	// TODO Auto-generated destructor stub
}

OperacionesEntreVentanas::OperacionesEntreVentanas() {
	// TODO Auto-generated constructor stub

}

int OperacionesEntreVentanas::buscarMaximoMatch(Ventana* inspeccion, Ventana* memoria, int* tamanioMatch){
	/*busca el maximo match dentro de la ventana de memoria y devuelve la posicion.
	PRE: La ventana de inspeccion ya tiene que estar cargada*/
	*tamanioMatch = 0;
	int posInspeccion = 4095; //primera elemento de la ventana de inspeccion a comparar
	int posMaximoMatch = -1;
	int unMatch; //para ir sumando y comparando con el maximo match

	memoria->inicializarMatch(); //para comenzar buscando desde el principio de la ventana

	int posicionAux = 4099; //aca vamos almacenando la posicion de cada match que va encontrando.
							//se inicializa con un valor que no existe en la ventana
	while (posicionAux != -1){
		char caracter = inspeccion->getElementoEnPosicion(posInspeccion);
		posicionAux = memoria->buscarElemento(caracter);
		unMatch = 0;

		if (posicionAux != -1){
			unMatch ++;
			posInspeccion --;
			int aux = posicionAux -1;
			//a partir de ahora cuenta cuantos caracteres hay de match
			while ((inspeccion->getElementoEnPosicion(posInspeccion) == memoria->getElementoEnPosicion(aux))
					&& (posInspeccion >= 0 && aux >= 0)){
				unMatch ++;
				posInspeccion --;
				aux --;
			}
			if (unMatch > *tamanioMatch && unMatch > 2){
				*tamanioMatch = unMatch;
				posMaximoMatch = posicionAux;
			}

		}

	}

	return posMaximoMatch;
}

