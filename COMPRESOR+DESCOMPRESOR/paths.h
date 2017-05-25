#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "List.h"
#include "Tile.h"

using namespace std;
using namespace boost::filesystem;


class Paths
{
public:
	Paths(List<Tile> *imageList);

	/////////////////////////////////////// saveDirPngs /////////////////////////////////////////	
	//
	// Funcion que guarda en una lista unicamente los paths de los archivos que terminan 
	// en la extension especificada.
	//
	// Recibe: un path
	// Devuelve: nada
	//	
	/////////////////////////////////////////////////////////////////////////////////////////////
	void saveDirPngs(const char* dir); 



	//////////////////////////////////// isOldExtension /////////////////////////////////////////	
	//
	// Funcion que analiza si el archivo cuya direccion se le pasa tiene la extension que
	// se desea. 
	//
	// Recibe:	filePath (el path del archivo cuya extension se quiere verificar).
	//			oldExtension (para verificar si termina en esa extension).
	// Devuelve: true (si esa es la extension que le corresponde al path).
	//			 false (si esa no es su extension).
	//	
	/////////////////////////////////////////////////////////////////////////////////////////////
	bool Paths::isOldExtension(string filePath, string oldExtension); 




	//////////////////////////////////// replaceExtension ///////////////////////////////////////	
	//
	// Funcion que reemplaza la extension vieja por la nueva. Para esto, se asume que se sabe 
	// que el path termina en la extension vieja. PARA LLAMAR A ESTA FUNCION ya se tiene que 
	// haber verificado que el path termina en.png o en.vim (isOldExtension tiene que haber 
	// devuelto true) segun si se trata del caso del compresor o del descompresor respectivamente.
	// Se usa luego de haber comprimido / descomprimido, al guardar las nuevas imagenes con las 
	// extensiones nuevas.
	//
	// Para comprimir llamarla de la siguiente manera:  replaceExtension("todo el path.png", ".png", ".mvi");
	// Para descomprimir : replaceExtension("todo el path.mvi", ".mvi", ".png");
	//	
	/////////////////////////////////////////////////////////////////////////////////////////////
	string replaceExtension(string filePath, string oldExtension, string newExtension);

private:
	string oldExtension; //En Compressor se inicializa en ".png" y en Decompressor se inicializa en ".vim"
	string newExtension; //En Compressor se inicializa en ".vim" y en Decompressor se inicializa en ".png"
	List<Tile> *imageList;

};