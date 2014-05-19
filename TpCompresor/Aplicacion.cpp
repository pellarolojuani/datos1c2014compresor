//============================================================================
// Name        : Aplicacion.cpp
// Author      : Lucas
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "manejoArchivo/ManejoArchivo.h"
#include "Constantes.h"
#include "lz77/Lz77.h"
#include "lz77/Ventana.h"

using namespace std;

string parametro;
bool errorParam = false;

/*int main(int argc, char * argv[]) {


	 // para ejecutarlo, una vez creado el ejecutable
	 // ./<nombre del ejecutable> -<c o d> <directorio archivo>
	 // si quiero descomprimir -d, si quiero comprimir -c



	if (argc > 1) {
		parametro = argv[1];
		cout << PARM_INGRESADO + parametro << "\n";
	} else {
		cout << INGRESAR_PARAM << "\n";
		errorParam = true;
	}

	if (parametro.compare("-c") == 0 && !errorParam) {
		cout << COMPRIMIR << "\n";
	} else if (parametro.compare("-d") == 0 && !errorParam) {
		cout << DESCOMPRIMIR << "\n";
	} else {
		cout << OP_INCORRECTA << "\n";
	};

	Ventana unaVentana = Ventana();
	Lz77 lz77 = Lz77();
	//esto es un ejemplo que abre un archivo y lo lee byte a byte.
	ManejoArchivo ma = ManejoArchivo(argv[2]);
	ma.leerArchivoByteAByte();
	ma.cerrarArchivo();

	return 0;
}*/
