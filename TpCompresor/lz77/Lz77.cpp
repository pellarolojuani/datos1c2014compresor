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
#include "string.h"

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

	long int i = 0;		//contador de posiciones para el string de 1s y 0s
	char unChar;

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

		//if (salida.size() > 8){ //si hay mas de 8 bits se van guardando en disco
			//string ochoBits = "";
			//for (int k = 0; k < 8; k++){
				//ochoBits += salida[i];
				//i++;
			//}
			//unChar = operador_bitbyte.binarioAchar(ochoBits);
			//fputc(unChar, file_out);
			//ochoBits = "";
		//}
	}
	cout<<"se agregan los bits de relleno al archivo comprimido"<<endl;
	/*----------Relleno-----------*/
	int resto = strlen(salida.c_str()) % 8;
	salida += "1";
	for (int j = 0; j < (8-resto-1); j++){
		salida += "0";
	}
	/*----------------------------*/



	cout<<"..se comienza a grabar el archivo comprimido en disco.."<<endl;

	while (i < strlen(salida.c_str())){
		string ochoBits = "";
		for (int k = 0; k < 8; k++){
			ochoBits += salida[i];
			i++;
		}
		unChar = operador_bitbyte.binarioAchar(ochoBits);
		fputc(unChar, file_out);
		ochoBits = "";
	}

	fclose(file_out);
	//cierro el archivo de entrada y lo elimino.
	ma.cerrarArchivo();
	ma.eliminarArchivo();
	delete tamanioMatch;

}


void Lz77::descompresor(string pathEntrada) {

	string entrada = "";	//aca se va a guardar el contenido del archivo comprimido
	char unChar; 			//aca guardamos cada caracter del archivo comprimido para procesar
	string aux = "";
	char unBit;				//aca guardamos cada 1 o 0 que leemos

	long int posicion = 0; 		//indica la posicion a leer del archivo comprimido en binario

	FILE* fd_archivoComrimido = fopen(pathEntrada.c_str(), "r");

	/*Creamos el archivo descomprimido*/
	string nombre = "";
	for (int a = 3; a < pathEntrada.size(); a++) nombre += pathEntrada.at(a);
	FILE* fd_archivoDescomprimido = fopen(nombre.c_str(), "w");
	cout<<"Se crea el archivo original en blanco para ser completado"<<endl;

	Ventana unaVentana = Ventana();
	OperacionesConBitsYBytes operador_bitbyte;
	OperacionesEntreVentanas operador_ventanas;
	ManejoArchivo ma = ManejoArchivo(pathEntrada);
	long int cantidadElementos = ma.contarTerminosDeDocumento();
	ma.cerrarArchivo();
	//elimina el archivo de entrada.
	ma.eliminarArchivo();

	/*chequeamos que el tipo de archivo se recibe para descomprimir sea el correcto*/
	string inicio = "";
	for (int i = 0; i < 3; i++ ){
		inicio += pathEntrada.at(i);
	}
	if (inicio != "LZ_"){
		cout<<"Archivo invalido. No se puede descomprimir."<<endl;
		return;
	}
	/*--------------------Fin de chequeo de archivo correcto----------------------*/
	cout<<"Se chequeo el formato del archivo a descomprimir. OK"<<endl;

	for(long int i = 0; i < cantidadElementos; i++){
		//pasamos todo el archivo a binario para procesarlo
		unChar = fgetc(fd_archivoComrimido);
		aux	 += operador_bitbyte.charAbinario(unChar);
	}
	fclose(fd_archivoComrimido);
	cout<<"Se levanto todo el archivo en binario a memoria. OK"<<endl;

	/*Descartamos el relleno del archivo en binario*/
	int relleno = 0;
	int pos = aux.size()-1;
	while (aux.at(pos) == '0'){
		relleno ++;
		pos--;
	}
	relleno ++; //para descartar el 1 que le sigue a la cadena de 0s
	for ( int j = 0; j < aux.size() - relleno; j++ ){
		entrada += aux.at(j);
	}
	/*------Completado el descarte de bits de relleno---------*/
	cout<<"Se sacan los bits de relleno del archivo en binario. OK"<<endl;

	/*Comenzamos a leer el archivo binario*/
	cout<<"SIZE: "<<entrada.size()<<endl;
	while (posicion <= entrada.size()-1){ //procesamos mientras no lleguemos al fin de archivo
		unBit = entrada.at(posicion);
		posicion ++;
		if (unBit == '1'){
			//Caso en que no hay match. Paso siguiente es chequear si es vocal o char normal
			unBit = entrada.at(posicion);
			posicion ++;
			if (unBit == '0'){
				//caso de caracter comun
				string unCharComun = "";
				for (int i = 0; i < 8; i++){
					unCharComun += entrada.at(posicion);
					posicion++;
				}
				unChar = operador_bitbyte.binarioAchar(unCharComun);
				unaVentana.agregarElemento(unChar);
				fputc(unChar, fd_archivoDescomprimido);

			}
			else{
				//caso de caracter especial
				string unCharEspecial = "";
				for (int i = 0; i < 3; i++){
					unCharEspecial += entrada.at(posicion);
					posicion ++;
				}
				unChar = operador_bitbyte.getCharEspecial(unCharEspecial);
				unaVentana.agregarElemento(unChar);
				fputc(unChar, fd_archivoDescomprimido);
			}
		}
		else{
			//caso MATCH
		}
	}
	fclose(fd_archivoDescomprimido);
}

