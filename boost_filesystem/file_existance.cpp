#include "filesystem_header.h"

int check_existance(const char* file)
{
	path p(file); //Constructor de path. lleva un const char.
	if (exists(p))  //Verifica que exista la ruta especificada
	{
		if (is_regular_file(p)) //chequeo si es archivo o carpeta y no otra cosa, como un CD
			cout << p << " existe y su tamaño es " << file_size(p) << '\n';
		else if (is_directory(p))//Me fijo si es un directorio
			cout << p << " Es un directorio!\n";
		else
			cout << p << "Es un dispositivo Pipe o un Socket. En windows, capaz la lectora de CDs\n";
	}
	else
		cout << p << " No existe\n";
	getchar();
	return 0;
}