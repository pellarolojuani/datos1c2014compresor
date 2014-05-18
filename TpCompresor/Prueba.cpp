/*
 * Prueba.cpp
 *
 *  Created on: 17/05/2014
 *      Author: juanignacio
 */

#include "manejoArchivo/ManejoArchivo.cpp"
#include "Constantes.h"
#include "lz77/Ventana.cpp"
#include "Operaciones/OperacionesConBitsYBytes.cpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 *
 *
 * ACA VOY A IR HACIENDO VARIAS PRUEBAS DE LAS CLASES Y SUS METODOS
 * PARA CHEQUEAR QUE FUNCIONEN BIEN!
 *
 *
 * */

void testProbarVentana(){

	Ventana* unaVentana = new Ventana();
	ManejoArchivo unArchivo = ManejoArchivo("unArchivoDePrueba.txt");
	int cantidad = unArchivo.contarTerminosDeDocumento();

	for (int i = 0; i < cantidad; i++){
		unArchivo.agregarCharEnVentana(unaVentana);
	}
	cout<<"Cantidad de Elementos: "<<unaVentana->getCantidadElementos()<<endl;
	for (int j = 0; j < unaVentana->getCantidadElementos(); j++)
		if (unaVentana->getElementoEnPosicion(j) == FIN_DE_LINEA)
			cout<<"Elemento: <fin de linea>"<<endl;
		else
			cout<<"Elemento: "<<unaVentana->getElementoEnPosicion(j)<<endl;

	unArchivo.cerrarArchivo();
	return;
}

void testTransformarBinarioAChar(){
	string unaCadenaBinaria = "01000000";
	byte valor;
	valor = binarioAchar(unaCadenaBinaria);
	cout<<"BINARIO(64) = "<<valor<<endl;

	return;
}



int main(int argc, char *argv[]){
	/*Aca voy habilitando las pruebas que quiera correr*/

	testProbarVentana();
	testTransformarBinarioAChar();

	return 0;
}
