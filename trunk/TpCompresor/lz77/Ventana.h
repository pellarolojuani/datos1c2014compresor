/*
 * Ventana.h
 *
 *  Created on: 13/05/2014
 *      Author: juanignacio
 */

#ifndef VENTANA_H_
#define VENTANA_H_
#include <iostream>
#include <string>

using namespace std;

class Ventana {

private:
	char ventana[4096];
	int elementos; //indica la cantidad de elementos que tiene la ventana
	//int fin;
	int match; // indica la posicion del primer match. En caso de que no sirva
			   // busca el siguiente a partir de esta posicion y se modifica.


public:
	Ventana();
	virtual ~Ventana();
	void inicializarMatch();

	/*
	 * devuelve la posicion de la primera aparicion del elemento iniciando desde
	 * la posicion match.
	 * o -1 si no lo encuentra.
	 */
	int buscarElemento(char unValor);

	/*
	 * agrega un elemento en la posicion 0 desplazando al resto una posicion.
	 * Este metodo devuelve el ultimo elemento de la ventana
	 */
	char agregarElemento(char unValor);

	char getElementoEnPosicion(int unaPosicion);
	char getUltimoElemento();
	int getCantidadElementos();
	int getPosicionDeMatch();


};

#endif /* VENTANA_H_ */
