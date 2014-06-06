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
#include "../Operaciones/OperacionesEntreVentanas.h"

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
	long int cantidadTerminos = ma.contarTerminosDeDocumento();
	int tamanioArchivo = 0;
	string salida = ""; // aca guardariamos la salida previo a pasarla al file_out
	OperacionesConBitsYBytes operador_bitbyte;
	OperacionesEntreVentanas operador_ventanas;
	bool bandera_EOF = 0; // cuando hayamos leido el EOF debemos ponerla en 1.
	char caracter, caracterSiguiente;
	int longitud = 0;
	int posicion = 0;
	int *tamanioMatch = new int(); //este va a ser el parametro para meterle al
	*tamanioMatch = 0; 			 // operador_ventanas

	//---------------------------------------------------------------
	//Creamos el archivo comprimido con el mismo nombre anteponiendo LZ_
	string nombreArchivoComprimido = "LZ_";
	nombreArchivoComprimido += pathEntrada;

	file_out = fopen(nombreArchivoComprimido.c_str(), "w");
	//---------------------------------------------------------------
	cout<<"COMIENZA A CORRER EL COMPRESOR"<<endl;
	cout<<"Se carga la ventana"<<endl;
	ma.cargaInicialEnVentana(inspeccion);
	int cant;
	cout<<"    ...Se procesa cada uno de los caracteres del texto..."<<endl;
	while ((cant = inspeccion->getCantidadElementos()) != 0){
		posicion = operador_ventanas.buscarMaximoMatch(this->inspeccion, this->memoria, tamanioMatch);
		if (posicion != -1) { //Hay Match!!
			cout<<"SI ENTRA ACA EN ALGUN MOMENTO ESTA MAL!!!"<<endl;
					for (int i = 0; i < *tamanioMatch; i++){
						//agrego todos los elementos que hacen match en memoria
						int nada; cin>>nada;
						ma.agregarCharEnVentana(this->inspeccion);
						this->memoria->agregarElemento(caracter);
					}
					salida += "0";	//indica que hubo match
					salida += operador_bitbyte.longitudAbinario(*tamanioMatch);
					salida += operador_bitbyte.longitudAbinario(posicion);

					caracter = this->inspeccion->getUltimoElemento(); //charSiguiente
					ma.agregarCharEnVentana(this->inspeccion);
					this->memoria->agregarElemento(caracter);
					salida += operador_bitbyte.charAbinario(caracter);
				}

		else{
			/*No hay match*/
			caracter = this->inspeccion->getUltimoElemento();
			ma.agregarCharEnVentana(this->inspeccion);
			this->memoria->agregarElemento(caracter);

			if ( (caracter=='a') || (caracter=='e') || (caracter=='i') || (caracter=='o') || (caracter=='u') || (caracter=='t') || (caracter=='\n') || (caracter==' ') ){
				/*Caracter especial*/
				string agregar =  "11";	//el primer 1 indica que emite un caracter
										//el segundo indica caracter especial
				salida += agregar;
				salida += operador_bitbyte.charEspecialAbinario(caracter);
			}
			else{
				/*Caracter comun*/
				string agregar =  "10";	//el primer 1 indica que emite caracter
										//el 0 indica caracter comun
				salida += agregar;
				salida += operador_bitbyte.charAbinario(caracter);
			}

		}//FIN DEL CASO EN QUE NO HAY MATCH
	}
	cout<<"se agregan los bits de relleno al archivo comprimido"<<endl;
	/*----------Relleno-----------*/
	int resto = strlen(salida.c_str()) % 8;
	salida += "1";
	for (int j = 0; j < (8-resto-1); j++){
		salida += "0";
	}
	/*----------------------------*/
	string ochoBits = "";
	char unChar;
	int i = 0;
	cout<<"..se comienza a grabar el archivo comprimido en disco.."<<endl;
	while (i < strlen(salida.c_str())){
		for (int k = 0; k < 8; k++){
			ochoBits += salida[i];
			i++;
		}
		unChar = operador_bitbyte.binarioAchar(ochoBits);
		fputc(unChar, file_out);
		ochoBits = "";
	}

	fclose(file_out);
	delete tamanioMatch;

}


void Lz77::descompresor() {

}

