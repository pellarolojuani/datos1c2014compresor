/*
 * lz77.cpp
 *
 *  Created on: 11/05/2014
 *      Author: lucas
 */

#include "Lz77.h"
#include "../manejoArchivo/ManejoArchivo.h"
#include "Ventana.h"
#include "../Operaciones/OperacionesConBitsYBytes.h"

using namespace std;

Lz77::Lz77() {
	// TODO Auto-generated constructor stub

}

Lz77::~Lz77() {
	// TODO Auto-generated destructor stub
}

void Lz77::compresor(string pathEntrada, FILE* file_out) {

	ManejoArchivo ma(pathEntrada);
	int tamanioArchivo = 0;
	string salida = ''; // aca guardariamos la salida previo a pasarla al file_out
	OperacionesConBitsYBytes operador_bitbyte;
	bool bandera_EOF = 0; // cuando hayamos leido el EOF debemos ponerla en 1.
	char caracter = '';
	int longitud = 0;
	int posicion = 0;

	while (!bandera_EOF){

		// llenamos la ventana de inspeccion
		for (int i=0; i<4096; i++){
			ma.agregarCharEnVentana(inspeccion); // ERROR: argumento de funcion es puntero
		}

		while ( (caracter = inspeccion.getElementoEnPosicion(0)) != EOF){
			tamanioArchivo++;
			if ( (posicion = memoria.buscarElemento(caracter)) != -1 ){
				// ESTAMOS EN MATCH
				/*
				   1.en un ciclo while vamos chequeando siguientes caracteres
				   hasta que tengamos un char distinto
				   <recordar agregar char leidos en memoria>
				   2.definimos longitud
				   3.concatenamos en salida 'longitud posicion charDistinto'
				   <recordar agregar charDistinto en memoria>
				   <deberiamos chequear si charDistinto es char especial???>
				   <deberiamos dejar match nuevamente en cero>
				*/
				longitud = 0;
				} // fin match
			    else {
			    	// ESTAMOS EN LITERAL
					if ( (caracter=='a') || (caracter=='e') || (caracter=='i') || (caracter=='o') || (caracter=='u') || (caracter=='t') || (caracter=='\n') || (caracter==' ') ){
						// ESTAMOS EN LITERAL ESPECIAL
						salida += '00';
						salida += ( operador_bitbyte.charEspecialAbinario(caracter) );
						} // fin literal especial
						else {
							// ESTAMOS EN LITERAL NO ESPECIAL
							salida += '01';
							salida += ( operador_bitbyte.charAbinario(caracter) );
							} // fin literal no especial

					memoria.agregarElemento(caracter);
					} // fin literales

			posicion = 0; // dejamos nuevamente en cero la variable antes de leer prox char
			}

		// llegamos aca cuando caracter = EOF
		bandera_EOF = 1;
		}

// ACA DEBERIAMOS PASAR EL STRING "SALIDA" DE BINARIOS A FILE_OUT EN BITS


}

void Lz77::descompresor() {

}

