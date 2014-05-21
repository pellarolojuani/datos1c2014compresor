/*
 * OperacionesConBitsYBytes.cpp
 *
 *  Created on: 18/05/2014
 *      Author: juanignacio
 */

#include "OperacionesConBitsYBytes.h"
#include <iostream>

//
//	CARACTERES ESPECIALES: A E I O U T (espacio) \n
//


byte OperacionesConBitsYBytes::binarioAchar(string secuencia) {
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

string OperacionesConBitsYBytes::charAbinario(byte caracter){

	string unBinario;
	string sBuffer;

	if( caracter == 0){
	  for (int i = 0; i < 8; i++ )
	    unBinario.push_back('0');
	  return unBinario;
	}
	else{
	  for (byte i = caracter; i > 1; i/=2) {
	    byte nResto = i%2;
	    if (nResto == 0) {
	    	sBuffer.push_back('0');
	    } else {
	    	sBuffer.push_back('1');
	    }
	}
	sBuffer.push_back('1');

	int longitud = static_cast<int>(sBuffer.size());
	for (int i = 0; i < (8 - longitud); i++ ) unBinario.push_back('0');
	for(int i = longitud - 1; i >= 0; i-- ) unBinario.push_back(sBuffer[i]);

	return unBinario;
	}
}

string OperacionesConBitsYBytes::longitudAbinario(int unaLongitud){

	string unBinario;
	string sBuffer;

	if( unaLongitud == 0){
	  for (int i = 0; i < 12; i++ )
			unBinario.push_back('0');
	  return unBinario;
	}
	else{
	  for (int i = unaLongitud; i > 1; i/=2) {
	    byte nResto = i%2;
	    if (nResto == 0) {
	    	sBuffer.push_back('0');
	    } else {
	    	sBuffer.push_back('1');
	    }
	}
	sBuffer.push_back('1');

	int longitud = static_cast<int>(sBuffer.size());
	for (int i = 0; i < (12 - longitud); i++ ) unBinario.push_back('0');
	for(int i = longitud - 1; i >= 0; i-- ) unBinario.push_back(sBuffer[i]);


	return unBinario;
	}
}

string OperacionesConBitsYBytes::charEspecialAbinario(byte caracter){

	string valorEnBinario;

	switch (caracter){
		//1
		case 'a': valorEnBinario = "000";
		break;
		//2
		case 'e': valorEnBinario = "001";
		break;
		//3
		case 'i': valorEnBinario = "010";
		break;
		//4
		case 'o': valorEnBinario = "011";
		break;
		//5
		case 'u': valorEnBinario = "100";
		break;
		//6
		case 't': valorEnBinario = "101";
		break;
		//7
		case '\n': valorEnBinario = "110";	//fin de linea
		break;
		//8
		case ' ': valorEnBinario = "111";
		break;
	}

	return valorEnBinario;
}

byte OperacionesConBitsYBytes::getCharEspecial(string valorEnBinario){
	/*Recibe un valor binario y lo transforma en el char especial correspondiente*/

	/*MUY MEDIOCRE*/

	byte unChar;

	if (valorEnBinario == "000") unChar = 'a';
	if (valorEnBinario == "001") unChar = 'e';
	if (valorEnBinario == "010") unChar = 'i';
	if (valorEnBinario == "011") unChar = 'o';
	if (valorEnBinario == "100") unChar = 'u';
	if (valorEnBinario == "101") unChar = 't';
	if (valorEnBinario == "110") unChar = '\n';
	if (valorEnBinario == "111") unChar = ' ';

	return unChar;
}

int OperacionesConBitsYBytes::getLongitud(string unaLongitudEnBinario){

	 int longitud = static_cast<int>(unaLongitudEnBinario.size());
	 int suma = 0;
	 for (int i = 0; i < longitud; i++) {
	   unsigned char c = unaLongitudEnBinario[i];
	   int n = 0;
	   if (c == '0') {
	     n = 0;
	   } else if (c == '1'){
	     n = 1;
	   }
	   suma += n*pow(2.0, (longitud - 1) - i);
	 }


	return suma;
}

