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

string parametro = "";
string pathArchivo = "";
string nombreArchivo = "";

bool errorParam = false;

void comprimirArchivo(){
	//FILE* file_out;
//	Lz77 unLz77 = Lz77();
//	unLz77.compresor(pathArchivo, file_out);
}

void descomprimirArchivo(){
	//Lz77 unLz77 = Lz77();
	//unLz77.descompresor(nombreArchivo);
}

void obtenerNombreDeArchivo(){
	int posBarra = pathArchivo.rfind("/");
	if(posBarra != -1){
		nombreArchivo = "LZ_" + pathArchivo.substr(posBarra+1);

	}else{
		nombreArchivo = "LZ_" + pathArchivo;
	}
	cout << nombreArchivo << "\n";
}

/*
int main(int argc, char * argv[]) {


	 // para ejecutarlo, una vez creado el ejecutable
	 // ./<nombre del ejecutable> -<c o d> <directorio archivo>
	 // si quiero descomprimir -d, si quiero comprimir -c

	if (argc > 1) {
		parametro = argv[1];
		pathArchivo = argv[2];
		cout << PARM_INGRESADO + parametro << "\n";
	} else {
		cout << INGRESAR_PARAM << "\n";
		errorParam = true;
	}

	if (parametro.compare("-c") == 0 && !errorParam) {
		cout << COMPRIMIR<< "\n";
	//	comprimirArchivo();
	} else if (parametro.compare("-d") == 0 && !errorParam) {
		cout << DESCOMPRIMIR << "\n";
	//	descomprimirArchivo();
	} else {
		cout << OP_INCORRECTA << "\n";
	};
	obtenerNombreDeArchivo();

	return 0;
}*/


