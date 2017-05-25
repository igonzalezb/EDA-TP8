/*
boost crea un objeto que representa lo que esta listado
path //objeto que apunta a un archivo o cosas de filesyst
is_regular_file // devuelve true si es un regular file o directory
//todo lo que sean imagenes van a ser regular files

//al entrar al directorio necesitamos que boost lea todo lo q esta adentro
//agarra un direcotrio y enlista todo lo q esta dentro

//la verificacion para q el usuario no meta cosas q no existen estan en exist
*/

#include "main.h"
#include "Board.h"
#include "Tile.h"
#include "paths.h"
//#include "parseCmdLine.h"
//#include "Callback.h"

#if IAM == COMPRESSOR
#include "Compressor.h"
#else
#include "Decompressor.h"
#endif // IAM

void de_compress(Board* b);// , parametros_t userData);
bool allegroStartup(void);
void allegroShutdown(void);

//typedef int(*pCallback) (char *, char*, void *);


int main(int argc, char *argv[])
{
	//pCallback parser = &Callback;
	//parametros_t userData;
	//if (parseCmdLine(argc, argv, parser, &userData) == 0)
	//{
	//	printf("PARSER ERROR\n");
	//	return EXIT_FAILURE;
	//}
	bool do_exit = false;
	
	if (allegroStartup()) {
		fprintf(stderr, "Error Initilizing Allegro\n");
		return EXIT_FAILURE;
	}
	
	List<Tile> *imageList;
	imageList = new List<Tile>;
	
	Paths *p = new Paths(imageList);
	p->saveDirPngs(argv[1]);//userData.path);

	Board *b = new Board(imageList);

	while (!do_exit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(b->getGraphics()->getEventQueue(), &ev);

		switch (ev.type)
		{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			do_exit = true;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				b->startCompression();
				de_compress(b);// , userData);
				do_exit = true;
			}
				
			else
				do_exit = b->keyDispacher(ev);
			break;
		}
	}

	delete imageList;
	delete p;
	delete b;
	allegroShutdown();
	return EXIT_SUCCESS;
}

void de_compress(Board* b)//, parametros_t userData)
{
#if IAM == COMPRESSOR
	Compressor c;
	
	for (int i = 0; i < b->getTiles()->getListSize(); i++)
	{
		
		c.compressingFunction(b->getTiles()->getElement(i).getFilePath().c_str(), b->getTiles()->getElement(i).getLength(), 1);// , userData.threshold);
	}
#else
	Decompressor d;
	for (int i = 0; i < b->getTiles()->getListSize(); i++)
	{

		d.decompressingFunction(b->getTiles()->getElement(i).getFilePath().c_str());
	}
#endif

}


bool allegroStartup(void)
{
	if (al_init())
	{
		if (al_init_primitives_addon())
		{
			if (al_install_keyboard())
			{
				if (al_install_mouse())
				{
					if (al_init_image_addon())
					{
						al_init_font_addon();   //Void

						if (al_init_ttf_addon())
						{
							return EXIT_SUCCESS;
						}
						else
							fprintf(stderr, "ERROR: Failed to initialize ttf addon\n");
						al_shutdown_font_addon();
						al_shutdown_image_addon();
					}
					else
						fprintf(stderr, "ERROR: Failed to initialize image addon\n");
					al_uninstall_mouse();
				}
				else
					fprintf(stderr, "ERROR: Failed to install mouse\n");
				al_uninstall_keyboard();
			}
			else
				fprintf(stderr, "ERROR: Failed to to install keyboard\n");
			al_shutdown_primitives_addon();
		}
		else
			fprintf(stderr, "ERROR: Failed to load primitives addon \n");
		al_uninstall_system();
	}
	else
		fprintf(stderr, "ERROR: Failed to initialize allegro system\n");

	return EXIT_FAILURE;
}

void allegroShutdown(void)
{
	al_shutdown_font_addon();
	al_shutdown_image_addon();
	al_uninstall_mouse();
	al_uninstall_keyboard();
	al_shutdown_primitives_addon();
	al_uninstall_system();
}