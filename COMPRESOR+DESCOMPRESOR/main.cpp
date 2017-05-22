/*
boost crea un objeto que representa lo que esta listado
path //objeto que apunta a un archivo o cosas de filesyst
is_regular_file // devuelve true si es un regular file o directory
//todo lo que sean imagenes van a ser regular files

//al entrar al directorio necesitamos que boost lea todo lo q esta adentro
//agarra un direcotrio y enlista todo lo q esta dentro

//la verificacion para q el usuario no meta cosas q no existen estan en exist
*/


//char a[50] // memoria contigua, se puede acceder a cualquier elementos-> acceso directo


#include "Board.h"
#include "Tile.h"
#include "paths.h"

int main(int argc, char *argv[])
{
	//EDAlist<int>li;
	//EDAlis<double>la;

	Board b;
	Paths p;
	p.saveDirPngs(argv[1]); //recibir tambien la lista. dir es un const char*

	//B.getTiles().addElement(pos, 0); //en pos, en vez de pos se le pasa un Tile
}
