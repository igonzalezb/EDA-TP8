#include "filesystem_header.h"


int sort_directories(const char* dir)
{
	path p(dir);   // p se crea a partir de un const char con la ruta al directorio
		if (exists(p))
		{
			if (is_regular_file(p)) //Me fijo si es un archivo o un directorio
				cout << p << " size is " << file_size(p) << '\n';
			else if (is_directory(p))   //me fijo si es directorio
			{
				cout << p << " is a directory containing:\n";
				for (directory_iterator itr(p); itr != directory_iterator(); ++itr)
				{
					cout << itr->path().string() << ' '; // display filename only
					cout << '\n';
				}
			}
		}
		else
			cout << p << "No existe\n";
		getchar();
	return 0;
}