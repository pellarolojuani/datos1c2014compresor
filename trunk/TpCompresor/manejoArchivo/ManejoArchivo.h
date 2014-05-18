/*
 * ManejoArchivo.h
 *
 */

#ifndef MANEJOARCHIVO_H_
#define MANEJOARCHIVO_H_

#include <string>
#include <fstream>
#include <iostream>
#include "../lz77/Ventana.h"

using namespace std;

class ManejoArchivo {

private:
	FILE* fd_archivo;

public:
	ManejoArchivo();
	ManejoArchivo(string pathEntrada);
	virtual ~ManejoArchivo();
	void leerArchivoByteAByte();
	void leerArchivoBitABit();
	void abrirArchivo(std::string pathEntrada);
	void cerrarArchivo();
	long int contarTerminosDeDocumento();

	/*Este metodo lee el siguiente caracter del archivo y lo guarda en la ventana
	 * devolviendo el caracter que se encuentra ultimo en la ventana y fue desplazado
	 * por el nuevo*/
	char agregarCharEnVentana(Ventana* unaVentana);
};

#endif /* MANEJOARCHIVO_H_ */
