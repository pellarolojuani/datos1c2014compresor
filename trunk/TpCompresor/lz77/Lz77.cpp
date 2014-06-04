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
	this->inspeccion = new Ventana();
	this->memoria = new Ventana();

}

Lz77::~Lz77() {
	// TODO Auto-generated destructor stub
}

void Lz77::compresor(string pathEntrada, FILE* file_out) {

	ManejoArchivo ma(pathEntrada);
	int tamanioArchivo = 0;
	string salida = ""; // aca guardariamos la salida previo a pasarla al file_out
	OperacionesConBitsYBytes operador_bitbyte;
	bool bandera_EOF = 0; // cuando hayamos leido el EOF debemos ponerla en 1.
	char caracter, caracterSiguiente;
	int longitud = 0;
	int posicion = 0;

	//---------------------------------------------------------------
	//Creamos el archivo comprimido con el mismo nombre anteponiendo LZ_
	string nombreArchivoComprimido = "LZ_";
	nombreArchivoComprimido += pathEntrada;
	file_out = fopen(nombreArchivoComprimido.c_str(), "w");
	//---------------------------------------------------------------

	while (!bandera_EOF){

		// llenamos la ventana de inspeccion
		ma.cargaInicialEnVentana(inspeccion);

		while ( (caracter = inspeccion->getElementoEnPosicion(0)) != EOF){
			tamanioArchivo++;
			caracterSiguiente = inspeccion->getElementoEnPosicion(1);
			if ( ((posicion = memoria->buscarElemento(caracter)) != -1) && (caracterSiguiente == memoria->getElementoEnPosicion(posicion+1)) ){
				// ESTAMOS EN MATCH
				longitud = 2;
				caracterSiguiente = inspeccion->getElementoEnPosicion(longitud);

				// vamos chequeando siguientes caracteres hasta que tengamos un char distinto
				while ( caracterSiguiente == memoria->getElementoEnPosicion(posicion+longitud) ){
					longitud++;
					caracterSiguiente = inspeccion->getElementoEnPosicion(longitud);
					}

				// concatenamos en salida 'longitud posicion charDistinto'
				salida += ( operador_bitbyte.longitudAbinario(longitud) );
				salida += ( operador_bitbyte.longitudAbinario(posicion) );
				salida += ( operador_bitbyte.charAbinario(caracterSiguiente) );
				/*
				   <recordar agregar char leidos en memoria>
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
						salida += "00";
						salida += ( operador_bitbyte.charEspecialAbinario(caracter) );
						} // fin literal especial
						else {
							// ESTAMOS EN LITERAL NO ESPECIAL
							salida += "01";
							salida += ( operador_bitbyte.charAbinario(caracter) );
							} // fin literal no especial

					memoria->agregarElemento(caracter);
					} // fin literales

			posicion = 0; // dejamos nuevamente en cero la variable antes de leer prox char
			}

		// llegamos aca cuando caracter = EOF
		bandera_EOF = 1;
		}

// ACA DEBERIAMOS PASAR EL STRING "SALIDA" DE BINARIOS A FILE_OUT EN BITS
// <recordar incluir tamanioArchivo al comienzo>

}

void Lz77::descompresor() {

}

