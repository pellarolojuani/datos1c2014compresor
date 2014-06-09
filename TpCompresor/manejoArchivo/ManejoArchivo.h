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
	string nombreArchivo;
	string nombreDeArchivoSinBarra;

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
	void obtenerNombreDeArchivoSinBarras();
	void eliminarArchivo();

	/*Este metodo lee el siguiente caracter del archivo y lo guarda en la ventana
	 * devolviendo el caracter que se encuentra ultimo en la ventana y fue desplazado
	 * por el nuevo*/
	bool agregarCharEnVentana(Ventana* unaVentana);
	bool cargaInicialEnVentana(Ventana* unaVentana);

	const vector<byte>& getVbuffer() const {
		return vbuffer;
	}

	void setVbuffer(const vector<byte>& vbuffer) {
		this->vbuffer = vbuffer;
	}

	const string& getNombreDeArchivoSinBarra() const {
		return nombreDeArchivoSinBarra;
	}

	void setNombreDeArchivoSinBarra(const string& nombreDeArchivoSinBarra) {
		this->nombreDeArchivoSinBarra = nombreDeArchivoSinBarra;
	}
};

#endif /* MANEJOARCHIVO_H_ */
