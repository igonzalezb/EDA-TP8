
#include "paths.h"
#include "Tile.h"
#include "List.h" //Ver
#include "main.h"
Paths::Paths(List<Tile>* imageList)
{
#if IAM == COMPRESSOR
	oldExtension = ".png";
	newExtension = ".mvi";
#else
	oldExtension = ".mvi";
	newExtension = ".png";
#endif
	this->imageList = imageList;
}

void Paths::saveDirPngs(const char* dir) //recibir tambien la lista
{
	path p(dir); 	//crea path con la dir que se recibe por linea de comandos
	if (exists(p)) //verifica que la ruta este en el sistema de archivos
	{
		if (is_directory(p))     // is p a directory?
		{
			for (directory_iterator itr(p); itr != directory_iterator(); ++itr)
			{
				if (isOldExtension(itr->path().string(), oldExtension))
				{
					Tile t(itr->path().string());
					imageList->addElement(t);
				}
			}
		}
		else
			cout << "Debe ingresar un directorio. \n";
	}
	else
		cout << p << " no existe\n";
}

//REEMPLAZO A ESTA FUNCION Por isOldExtension
/*
bool Paths::isPng(string path)
{
	string str(path);
	string str2(".png");
	unsigned int sizeDifference = (str.length() - str2.length());
	size_t found = str.find(str2, sizeDifference);
	if (found != std::string::npos)
		return true;
	else
		return false;
}
*/

bool Paths::isOldExtension(string filePath, string oldExtension)
{
	string str(filePath);
	string str2(oldExtension);
	unsigned int sizeDifference = (str.length() - str2.length());
	size_t found = str.find(str2, sizeDifference);
	if (found != std::string::npos)
		return true;
	else
		return false;
}

string Paths::replaceExtension(string filePath, string oldExtension, string newExtension)
{
	string str(filePath); 
	string strToFind(oldExtension);
	string strThatReplaces(newExtension);

	unsigned int sizeDifference = (str.length() - strToFind.length());
	size_t found = str.find(strToFind, sizeDifference);

	if (found != std::string::npos)
	{
		str.replace(found, strToFind.length(), strThatReplaces);
	}
	return str;
}
