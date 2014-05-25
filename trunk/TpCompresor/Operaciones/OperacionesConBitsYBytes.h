/*
 * OperacionesConBitsYBytes.h
 *
 *  Created on: 18/05/2014
 *      Author: lucas
 */

#ifndef OPERACIONESCONBITSYBYTES_H_
#define OPERACIONESCONBITSYBYTES_H_
#endif /* OPERACIONESCONBITSYBYTES_H_ */
#include <string>
#include <cmath>
using namespace std;
#include "../Constantes.h"

using namespace std;

typedef unsigned char byte;

class OperacionesConBitsYBytes{

public:
	byte binarioAchar(string secuencia);
	byte getCharEspecial(string valorEnBinario);
	int getLongitud(string unaLongitudEnBinario);

	string charAbinario(byte caracter);
	string charEspecialAbinario(byte caracter);
	string longitudAbinario(int unaLongitud); // sirve tambien para
											  // las posiciones
	string posicionAbinario(int unaPosicion);


};
