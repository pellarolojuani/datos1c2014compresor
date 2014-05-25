/*
 * lz77.h
 *
 *  Created on: 11/05/2014
 *      Author: lucas
 */

#ifndef LZ77_H_
#define LZ77_H_
#include "Ventana.h"

using namespace std;

class Lz77 {
private:
	Ventana inspeccion;	//aca se va cargando el texto del archivo
	Ventana memoria; 	//aca se van buscando las repeticiones

public:
	Lz77();
	virtual ~Lz77();
	void compresor();
	void descompresor();
};

#endif /* LZ77_H_ */
