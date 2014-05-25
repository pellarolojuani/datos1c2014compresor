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
	fin = 0;
	match = 0;
	for (int i = 0; i < 4096; i++) ventana[i] = '\0';

}

Ventana::~Ventana() {/*NADA*/}

char Ventana::agregarElemento(char unValor){

	char ultimoChar;
	if (elementos != 0){
		/*Desplazo todos los elementos de la ventana*/
		for (int i = 4095; i > 0; i--){
			ultimoChar = ventana[i];
			ventana[i] = ventana[i-1];
		}
	}
	this->ventana[0] = unValor;
	this->elementos ++;
	return ultimoChar;
}

int Ventana::buscarElemento(char unValor){

	int posicion = -1;
	for (int i = match; i < 4096; i++ ){
		if (ventana[i] == unValor){
			match = i;
			posicion = match;
		}
	}

	return posicion;
}

char Ventana::getElementoEnPosicion(int unaPosicion){
	return (this->ventana[unaPosicion]);
}

int Ventana::getCantidadElementos(){
	return this->elementos;
}

int Ventana::getPosicionDeMatch(){
	return this->match;
}

void Ventana::inicialzarMatch(){
	this->match = 0;

	return;
}





