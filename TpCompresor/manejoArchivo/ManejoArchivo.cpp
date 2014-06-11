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
	nombreArchivo = "";
	nombreDeArchivoSinBarra = "";
	this->cantidadBytes = 0;
	eof = false;

}

ManejoArchivo::ManejoArchivo(string pathEntrada) {
	this->nombreArchivo = pathEntrada;
	fd_archivo = fopen(pathEntrada.c_str(), READ);
	if (fd_archivo == 0)
		cout << "No se puede abrir el archivo" << "\n";
	this->cantidadBytes = this->contarTerminosDeDocumento();
	eof = false;
}

ManejoArchivo::~ManejoArchivo() {
	// TODO Auto-generated destructor stub

}


void ManejoArchivo::abrirArchivo(std::string pathEntrada) {
	fd_archivo = fopen(pathEntrada.c_str(), READ);
	if (fd_archivo == 0)
		cout << "No se puede abrir el archivo" << "\n";
	this->cantidadBytes = this->contarTerminosDeDocumento();

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

	long int cantidad;
	fseek(this->fd_archivo, 0, ios::end);
	cantidad = ftell(this->fd_archivo);
	this->cantidadBytes = cantidad;
	rewind(fd_archivo);
	return cantidad;
	/*int cantidad;
	cantidad = 0;
	while (fgetc(fd_archivo) != ios::end) cantidad ++;

	rewind(fd_archivo);
	return cantidad;*/
}

bool ManejoArchivo::agregarCharEnVentana(Ventana* unaVentana){
	/*PRE: El archivo ya tiene que estar abierto*/

	char caracter;
	caracter = fgetc(fd_archivo);

	if (eof) return false;
	if (ftell(fd_archivo) == this->cantidadBytes) eof = true;

	unaVentana->agregarElemento(caracter);

	return true;
}

bool ManejoArchivo::cargaInicialEnVentana(Ventana* unaVentana){
	/*PRE: El archivo ya tiene que estar abierto
	 *PRE: La ventana tiene que estar vacia*/

	char caracter;

	//caso de archivo menor al tamaño de la ventana
	if (this->cantidadBytes < 2048){
		for (int j = 0; j < this->cantidadBytes; j++){
			caracter = fgetc(fd_archivo);
			unaVentana->agregarElemento(caracter);
		}
		eof = true;
	}
	//caso de archivo mayor al tamaño de la ventana
	else{
		for (int i = 0; i < 2048 ; i++){
			caracter = fgetc(fd_archivo);
			unaVentana->agregarElemento(caracter);
		}
		if (ftell(fd_archivo) == this->cantidadBytes) eof = true;
	}

	return true;
}

void ManejoArchivo::leerArchivoYGuardarEnMemoria(){

	byte caracter;
	//char buffer[1];

	while ((caracter = fgetc(fd_archivo)) != EOF) {
	   // caracter = static_cast<byte>(buffer[0]);
	    vbuffer.push_back(caracter); //agrego un elemento al final del vector.
	  }

}

void ManejoArchivo::obtenerNombreDeArchivoSinBarras(){

	int posBarra = nombreArchivo.rfind("/");
	if(posBarra != -1){
		nombreDeArchivoSinBarra = nombreArchivo.substr(posBarra+1);
	}else{
		nombreDeArchivoSinBarra = nombreArchivo;
	}
	cout << nombreArchivo << "\n";

}

void ManejoArchivo::eliminarArchivo(){
	if(remove(nombreArchivo.c_str()) == -1){
		cout << "No se puedo eliminar el archivo de entrada." << "\n";
	}else{
		cout << "El archivo de entrada ha sido eliminado." << "\n";
	}
}

