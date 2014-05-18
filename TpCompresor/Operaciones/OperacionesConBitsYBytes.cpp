/*
 * OperacionesConBitsYBytes.cpp
 *
 *  Created on: 18/05/2014
 *      Author: juanignacio
 */

using namespace std;
#include "../Constantes.h"
#include <cmath>

typedef unsigned char byte;


byte binarioAchar(string secuencia) {
/*Recibe una secuencia de 1s y 0s y devuelve su correspondiente caracter ASCII*/

  if (secuencia.size() != 8) return '\0';

  int longitud = static_cast<int>(secuencia.size());
  byte suma = 0;
  for (int i = 0; i < longitud; i++) {
    unsigned char c = secuencia[i];
    int n = 0;
    if (c == '0') {
      n = 0;
    } else if (c == '1'){
      n = 1;
    }
    suma += static_cast<unsigned int>(n*pow(2.0, (longitud - 1) - i));
  }
  byte cOcteto;
  cOcteto = static_cast<byte>(suma);
  return cOcteto;
}
