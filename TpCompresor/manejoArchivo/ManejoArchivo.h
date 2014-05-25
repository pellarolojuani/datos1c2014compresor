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
#include <list>
#include <vector>


typedef unsigned char byte;

using namespace std;

class ManejoArchivo {

private:
	FILE* fd_archivo;
	vector <byte> vbuffer;

public:
	ManejoArchivo();
	ManejoArchivo(string pathEntrada);
	virtual ~ManejoArchivo();
	void leerArchivoByteAByte();
	void leerArchivoYGuardarEnMemoria();
	void leerArchivoBitABit();
	void abrirArchivo(std::string pathEntrada);
	void cerrarArchivo();
	long int contarTerminosDeDocumento();

	/*Este metodo lee el siguiente caracter del archivo y lo guarda en la ventana
	 * devolviendo el caracter que se encuentra ultimo en la ventana y fue desplazado
	 * por el nuevo*/
	char agregarCharEnVentana(Ventana* unaVentana);
	void cargaInicialEnVentana(Ventana* unaVentana);

	const vector<byte>& getVbuffer() const {
		return vbuffer;
	}

	void setVbuffer(const vector<byte>& vbuffer) {
		this->vbuffer = vbuffer;
	}
};

#endif /* MANEJOARCHIVO_H_ */
