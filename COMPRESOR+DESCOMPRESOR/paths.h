#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "Board.h"
#include "List.h"


using namespace std;
using namespace boost::filesystem;


class Paths
{
public:
	Paths(List<Tile> *imageList);
	void saveDirPngs(const char* dir); //Recibir lista
	//bool isPng(string path);
	bool Paths::isOldExtension(string filePath, string oldExtension); //EN REMPLAZO DE IS PNG. ASI SIRVE PARA COMPRESOR Y DESCOMPRESOR, SEGUN LA EXTENSION QUE PASAMOS

	/*
	replaceExtension reemplaza la extension vieja por la nueva. Para esto, se asume que se sabe que el path termina en la extension vieja.
	PARA LLAMAR A ESTA FUNCION ya se tiene que haber verificado que el path termina en .png o en .vim (isOldExtension tiene que haber devuelto true)
	segun si se trata del caso del compresor o del descompresor respectivamente. Se usa luego de haber comprimido/descomprimido, al guardar 
	las nuevas imagenes con las extensiones nuevas.
	Para comprimir llamarla de la siguiente manera:  replaceExtension("todo el path.png", ".png", ".vim");
	Para descomprimir:								 replaceExtension("todo el path.vim", ".vim", ".png");
	*/
	void replaceExtension(string filePath, string oldExtension, string newExtension);

private:
	string oldExtension; //En Compressor se inicializa en ".png" y en Decompressor se inicializa en ".vim"
	string newExtension; //En Compressor se inicializa en ".vim" y en Decompressor se inicializa en ".png"
	List<Tile> *imageList;
	//Tile* tilePtr;
};