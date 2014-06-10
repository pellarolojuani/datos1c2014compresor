/*
 * Prueba.cpp
 *
 *  Created on: 17/05/2014
 *      Author: juanignacio
 */

#include "manejoArchivo/ManejoArchivo.h"
#include "Constantes.h"
#include "lz77/Ventana.h"
#include "lz77/Lz77.h"
#include "Operaciones/OperacionesConBitsYBytes.h"
#include "Operaciones/OperacionesEntreVentanas.h"
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
	delete unaVentana;
	return;
}

void testCargarArchivoEnVentana(){

	Ventana* unaVentana = new Ventana();
	ManejoArchivo unArchivo = ManejoArchivo("1984GeorgeOrwell");

	unArchivo.cargaInicialEnVentana(unaVentana);

	for (int i = 0; i < 2048; i++){
		cout<<i<<": "<<unaVentana->getElementoEnPosicion(i)<<endl;
	}
	cout<<"-----------------------------------------------------"<<endl;

	unArchivo.cerrarArchivo();
	delete unaVentana;

	unaVentana = new Ventana();

	unArchivo = ManejoArchivo("unArchivoDePrueba.txt");
	if (!unArchivo.cargaInicialEnVentana(unaVentana))
		cout<<"ERROR EN LA PRUEBA."<<endl;
	unArchivo.cerrarArchivo();


	for (int i=0; i < unaVentana->getCantidadElementos(); i++){
		cout<<i<<": "<<unaVentana->getElementoEnPosicion(i)<<endl;
	}

	delete unaVentana;

	return;
}

void testTransformarBinarioAChar(){

	string unaCadenaBinaria = "01000000"; //64
	byte valor;
	OperacionesConBitsYBytes operaciones = OperacionesConBitsYBytes();
	valor = operaciones.binarioAchar(unaCadenaBinaria);
	cout<<endl;
	cout<<"BINARIO(64) = "<<valor<<endl;
	cout<<"en Binario: "<<operaciones.charAbinario(valor)<<endl;
	unaCadenaBinaria = "01000001"; //65
	valor = operaciones.binarioAchar(unaCadenaBinaria);
	cout<<endl;
	cout<<"BINARIO(65) = "<<valor<<endl;
	cout<<"en Binario: "<<operaciones.charAbinario(valor)<<endl;
	unaCadenaBinaria = "01000010"; //66
	valor = operaciones.binarioAchar(unaCadenaBinaria);
	cout<<endl;
	cout<<"BINARIO(66) = "<<valor<<endl;
	cout<<"en Binario: "<<operaciones.charAbinario(valor)<<endl;
	unaCadenaBinaria = "01000011"; //67
	valor = operaciones.binarioAchar(unaCadenaBinaria);
	cout<<endl;
	cout<<"BINARIO(67) = "<<valor<<endl;
	cout<<"en Binario: "<<operaciones.charAbinario(valor)<<endl;
	cout<<endl;

	return;
}

void testProbarCaracteresEspeciales(){

	string binario;
	OperacionesConBitsYBytes operaciones = OperacionesConBitsYBytes();

	byte caracter = 'a';
	binario = operaciones.charEspecialAbinario(caracter);
	cout<<endl;
	cout<<"a: "<<binario<<endl;
	cout<<"recupero el caracter: "<<operaciones.getCharEspecial(binario)<<endl;
	cout<<endl;

	caracter = 'e';
	binario = operaciones.charEspecialAbinario(caracter);
	cout<<"e: "<<binario<<endl;
	cout<<"recupero el caracter: "<<operaciones.getCharEspecial(binario)<<endl;
	cout<<endl;

	caracter = 'i';
	binario = operaciones.charEspecialAbinario(caracter);
	cout<<"i: "<<binario<<endl;
	cout<<"recupero el caracter: "<<operaciones.getCharEspecial(binario)<<endl;
	cout<<endl;

	caracter = 'o';
	binario = operaciones.charEspecialAbinario(caracter);
	cout<<"o: "<<binario<<endl;
	cout<<"recupero el caracter: "<<operaciones.getCharEspecial(binario)<<endl;
	cout<<endl;

	caracter = 'u';
	binario = operaciones.charEspecialAbinario(caracter);
	cout<<"u: "<<binario<<endl;
	cout<<"recupero el caracter: "<<operaciones.getCharEspecial(binario)<<endl;
	cout<<endl;

	caracter = 't';
	binario = operaciones.charEspecialAbinario(caracter);
	cout<<"t: "<<binario<<endl;
	cout<<"recupero el caracter: "<<operaciones.getCharEspecial(binario)<<endl;
	cout<<endl;

	caracter = '\n';
	binario = operaciones.charEspecialAbinario(caracter);
	cout<<"<finDeLinea>: "<<binario<<endl;
	cout<<"recupero el caracter: "<<operaciones.getCharEspecial(binario)<<endl;
	cout<<endl;

	caracter = ' ';
	binario = operaciones.charEspecialAbinario(caracter);
	cout<<"<espacio>: "<<binario<<endl;
	cout<<"recupero el caracter: "<<operaciones.getCharEspecial(binario)<<endl;
	cout<<endl;


	return;
}

void testProbarLongitudes(){

	string longEnBinario;
	OperacionesConBitsYBytes operaciones = OperacionesConBitsYBytes();

	cout<<"LONGITUDES EN BINARIO: "<<endl;
	longEnBinario = operaciones.longitudAbinario(0);
	cout<<"0: "<<longEnBinario<<endl;
	cout<<"Valor Recuperado: "<<operaciones.getLongitud(longEnBinario)<<endl;

	longEnBinario = operaciones.longitudAbinario(10);
	cout<<"10: "<<longEnBinario<<endl;
	cout<<"Valor Recuperado: "<<operaciones.getLongitud(longEnBinario)<<endl;

	longEnBinario = operaciones.longitudAbinario(55);
	cout<<"55: "<<longEnBinario<<endl;
	cout<<"Valor Recuperado: "<<operaciones.getLongitud(longEnBinario)<<endl;

	longEnBinario = operaciones.longitudAbinario(1000);
	cout<<"1000: "<<longEnBinario<<endl;
	cout<<"Valor Recuperado: "<<operaciones.getLongitud(longEnBinario)<<endl;

	longEnBinario = operaciones.longitudAbinario(4095);
	cout<<"2048: "<<longEnBinario<<endl;
	cout<<"Valor Recuperado: "<<operaciones.getLongitud(longEnBinario)<<endl;

	return;
}


void testAlmanenarArchivoEnBuffer(string pathEntrada){
	ManejoArchivo unArchivo = ManejoArchivo(pathEntrada);
	unArchivo.leerArchivoYGuardarEnMemoria();

	 int n = static_cast<int>(unArchivo.getVbuffer().size());
	    for (int i = 0; i < n; i++)
	    {
	        	cout<<"aca llega" <<unArchivo.getVbuffer()[i]<<endl;
	    }
	unArchivo.cerrarArchivo();
}

void testBuscarMatchEnVentana(){

	Ventana* inspeccion = new Ventana();
	Ventana* memoria = new Ventana();
	ManejoArchivo ma = ManejoArchivo("1984GeorgeOrwell");
	int* tamanioMatch = new int();
	*tamanioMatch = 0;
	int posicionMatch = 4099; //valor random para inicializar. No puede ser un valor posible
							  //dentro de la ventana para poder comparar si da error
	OperacionesEntreVentanas operaciones = OperacionesEntreVentanas();

	ma.cargaInicialEnVentana(inspeccion);
	ma.cerrarArchivo();
	ma = ManejoArchivo("1984GeorgeOrwell");
	ma.cargaInicialEnVentana(memoria);
	ma.cerrarArchivo();
		//en este punto las dos ventanas tienen exactamente el mismo contenido.
		//esta prueba tiene que encontrar el match mas largo posible en la posicion 0
	bool ok = true;
	for (int i = 0; i < 4096; i++){
		if (inspeccion->getElementoEnPosicion(i) != memoria->getElementoEnPosicion(i))
			ok = false;
	}
	cout<<endl;
	if (ok) cout<<"Primera etapa OK: Ventanas cargadas correctamente."<<endl;
	cout<<endl;

	posicionMatch = operaciones.buscarMaximoMatch(inspeccion, memoria, tamanioMatch);

	cout<<"Posicion Match: "<<posicionMatch<<endl;
	cout<<"Tamanio Match: "<<*tamanioMatch<<endl;

	if (posicionMatch == 4095 && *tamanioMatch == 4096)
		cout<<"Prueba OK."<<endl;

	delete memoria;
	delete inspeccion;
	delete tamanioMatch;

	return;
}

void testbuscarMatchEnVentana2(){
	Ventana* inspeccion = new Ventana();
	Ventana* memoria = new Ventana();
	ManejoArchivo ma = ManejoArchivo("1984GeorgeOrwell");
	ManejoArchivo ma2 = ManejoArchivo("1984");
	int* tamanioMatch = new int();
	*tamanioMatch = 0;
	int posicionMatch = 4099; //valor random para inicializar. No puede ser un valor posible
							  //dentro de la ventana para poder comparar si da error
	OperacionesEntreVentanas operaciones = OperacionesEntreVentanas();
	ma.cargaInicialEnVentana(inspeccion);
	ma.cerrarArchivo();
	ma2.cargaInicialEnVentana(memoria);
	ma2.cerrarArchivo();

	posicionMatch = operaciones.buscarMaximoMatch(inspeccion, memoria, tamanioMatch);

	cout<<"Posicion Match: "<<posicionMatch<<endl;
	cout<<"Tamanio Match: "<<*tamanioMatch<<endl;

	delete tamanioMatch;

	return;
}

void testCompresor(){

	FILE* file_out;
	Lz77 unLz77 = Lz77();
	unLz77.compresor("Harry Potter and the Order of the Phoenix", file_out);


	return;
}

void testDescompresor(){

	Lz77 unLz77 = Lz77();
	unLz77.descompresor("LZ_Harry Potter and the Order of the Phoenix");
}

void testCrearArchivo(){

	//Creamos el archivo comprimido con el mismo nombre anteponiendo LZ_
	string nombreArchivoComprimido = "LZ_";
	nombreArchivoComprimido += "prueba";


	FILE* file_out = fopen(nombreArchivoComprimido.c_str(), "w");

	string unTexto = "";
	unTexto += "texto de prueba";
	unTexto.push_back('!');

	fputs(unTexto.c_str(), file_out);
	fputc('A', file_out);
	fputc('A', file_out);
	fputc('A', file_out);

	fclose(file_out);

	return;
}
/*
int main(int argc, char *argv[]){
	//Aca voy habilitando las pruebas que quiera correr
	int i=0;
	cout<<"ELEGIR NUMERO DE PRUEBA: "<<endl;
	cout<<"1- testProbarVentana"<<endl;
	cout<<"2- testCargarArchivoEnVentana"<<endl;
	cout<<"3- testTransformarBinarioAChar"<<endl;
	cout<<"4- testProbarCaracteresEspeciales"<<endl;
	cout<<"5- testProbarLongitudes"<<endl;
	cout<<"6- testAlmanenarArchivoEnBuffer"<<endl;
	cout<<"7- testBuscarMatchEnVentana (MOMENTANEAMENTE SUSPENDIDO)"<<endl;
	cout<<"8- testCompresor"<<endl;
	cout<<"9- testbuscarMatchEnVentana2 (MOMENTANEAMENTE SUSPENDIDO)"<<endl;
	cout<<"10- testCrearArchivo"<<endl;
	cout<<"11- testDescompresor"<<endl;
	cin>>i;
	switch (i){
		case 1: testProbarVentana();
				break;
		case 2: testCargarArchivoEnVentana();
				break;
		case 3: testTransformarBinarioAChar();
				break;
		case 4: testProbarCaracteresEspeciales();
				break;
		case 5: testProbarLongitudes();
				break;
		case 6: testAlmanenarArchivoEnBuffer(argv[2]);
				break;
		case 7: testBuscarMatchEnVentana();
				break;
		case 8: testCompresor();
				break;
		case 9: testbuscarMatchEnVentana2();
				break;
		case 10: testCrearArchivo();
				break;
		case 11: testDescompresor();
				break;

	}
	cout<<endl;

	cout<<"FIN DE PRUEBAS."<<endl;
	cout<<endl;
	return 0;
}
*/
