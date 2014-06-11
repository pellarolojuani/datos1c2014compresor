/*
 * Ventana.cpp
 *
 *  Created on: 13/05/2014
 *      Author: juanignacio
 */

#include "Ventana.h"

using namespace std;

Ventana::Ventana() {

	elementos = 0;
	//fin = 0;
	match = -1;
	this->ventana = deque<char>();

}

Ventana::~Ventana() {/*NADA*/}


/*
 * MIENTRAS QUEDEN ELEMENTOS EN EL ARCHIVO DE TEXTO USO ESTE METODO
 */
char Ventana::agregarElemento(char unValor){

	char ultimoElemento;
	if (elementos == 2048){
		ventana.push_front(unValor);
		ultimoElemento = ventana.back();
		ventana.pop_back();
		return ultimoElemento;
	}
	ventana.push_front(unValor);
	elementos ++;
	return '\0';
}

/*
 * CUANDO SE LLEGO AL EOF VOY SACANDO LOS ELEMENTOS DE LA VENTANA CON ESTE METODO
 */
char Ventana::getUltimoElemento(){
	/*Saca el ultimo elemento de la ventana y desplaza el resto de los elementos
	 * Se le asigna valor nulo al primer elemento de la ventana*/

	if (elementos == 0) return '\0';

	char ultimoElemento = ventana.back();
	ventana.pop_back();
	elementos--;
	return ultimoElemento;
}

int Ventana::buscarElemento(char unValor){

	int posicion = -1;
	for (int i = match+1; i < elementos-1; i++ ){
		if (ventana.at(i) == unValor){
			match = i;
			posicion = match;
		}
	}

	return posicion;
}

char Ventana::getElementoEnPosicion(int unaPosicion){
	/*no borra el elemento de la ventana*/

	if (unaPosicion < 0) return '\0';

	return (this->ventana.at(unaPosicion));
}

int Ventana::getCantidadElementos(){
	return this->elementos;
}

int Ventana::getPosicionDeMatch(){
	return this->match;
}

void Ventana::inicializarMatch(){
	this->match = -1;

	return;
}





