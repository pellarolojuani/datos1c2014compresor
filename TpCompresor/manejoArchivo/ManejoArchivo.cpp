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

}

ManejoArchivo::ManejoArchivo(string pathEntrada) {
	this->nombreArchivo = pathEntrada;
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

bool ManejoArchivo::agregarCharEnVentana(Ventana* unaVentana){
	/*PRE: El archivo ya tiene que estar abierto*/

	char caracter;
	caracter = fgetc(fd_archivo);
	if (caracter == EOF) return false;

	unaVentana->agregarElemento(caracter);

	return true;
}

bool ManejoArchivo::cargaInicialEnVentana(Ventana* unaVentana){
	/*PRE: El archivo ya tiene que estar abierto
	 *PRE: La ventana tiene que estar vacia*/

	char caracter;

	//caso de archivo menor al tamaño de la ventana
	int cant = this->contarTerminosDeDocumento();
	if (cant < 2048){
		for (int j = 0; j < cant; j++){
			caracter = fgetc(fd_archivo);
			unaVentana->agregarElemento(caracter);
		}
		for (int j = cant; j < 2048; j++){
			unaVentana->agregarElemento('');
		}
	}
	//caso de archivo mayor al tamaño de la ventana
	else{
		for (int i = 0; i < 2048 ; i++){
			caracter = fgetc(fd_archivo);
			unaVentana->agregarElemento(caracter);
		}
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

