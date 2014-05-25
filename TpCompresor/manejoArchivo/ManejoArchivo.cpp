/*
 * manejoArchivo.cpp
 *
 */

#include "ManejoArchivo.h"
#include <iostream>
#include <string>
#include <fstream>
#include "stdio.h"
#include "../Constantes.h"
using namespace std;


ManejoArchivo::ManejoArchivo() {
	fd_archivo = 0;

}

ManejoArchivo::ManejoArchivo(string pathEntrada) {
	fd_archivo = fopen(pathEntrada.c_str(), READ);
	if (fd_archivo == 0)
		cout << "No se puede abrir el archivo" << "\n";
}

ManejoArchivo::~ManejoArchivo() {
	// TODO Auto-generated destructor stub

}


void ManejoArchivo::abrirArchivo(std::string pathEntrada) {
	fd_archivo = fopen(pathEntrada.c_str(), READ);
	if (fd_archivo == 0)
		cout << "No se puede abrir el archivo" << "\n";

}

void ManejoArchivo::cerrarArchivo() {
	fclose(fd_archivo);
}

void ManejoArchivo::leerArchivoByteAByte() {

	char caracter;

	while ((caracter = fgetc(fd_archivo)) != EOF) {

		//imprimo byte a byte para mostrar que funciona.
		cout << caracter << "\n";
	}
}

void ManejoArchivo::leerArchivoBitABit() {

}

long int ManejoArchivo::contarTerminosDeDocumento(){
	//poco eficiente
	int cantidad;
	cantidad = 0;
	while (fgetc(fd_archivo) != EOF) cantidad ++;

	rewind(fd_archivo);
	return cantidad;
}

char ManejoArchivo::agregarCharEnVentana(Ventana* unaVentana){
	/*PRE: El archivo ya tiene que estar abierto*/

	char caracter;
	char ultimoCaracter; //para recuperar el caracter que se desplaza de la ventana
	caracter = fgetc(fd_archivo);

	ultimoCaracter = unaVentana->agregarElemento(caracter);

	return ultimoCaracter;
}

void ManejoArchivo::cargaInicialEnVentana(Ventana* unaVentana){
	/*PRE: El archivo ya tiene que estar abierto
	 *PRE: La ventana tiene que estar vacia*/

	char caracter;

	for (int i = 0; i < 4096; i++){
		caracter = fgetc(fd_archivo);
		unaVentana->agregarElemento(caracter);
	}

	return;
}

void ManejoArchivo::leerArchivoYGuardarEnMemoria(){

	byte caracter;
	//char buffer[1];

	while ((caracter = fgetc(fd_archivo)) != EOF) {
	   // caracter = static_cast<byte>(buffer[0]);
	    vbuffer.push_back(caracter); //agrego un elemento al final del vector.
	  }

}

