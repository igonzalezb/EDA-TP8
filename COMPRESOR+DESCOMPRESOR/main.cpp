
/////////////////////////////////////////////////////////////////////////////////////////////	
//
// Instituto Tecnologico de Buenos Aires		25/05/2017
//
// Algoritmos y Estructuras de Datos - Trabajo Práctico 8 (Listas y arboles)
//
//
// Gonzalez Bigliardi Iñaki		 /////////////////////////////////////////
// Lago Valentina			// Compresor y Descompresor de imagenes.
// Muller Malena		       //////////////////////////////////////////
//
// El siguiente programa contiene un switch de compilacion para que funcione como compresor
// o como descompresor. Esto debe ser modificado en main.h en #define IAM COMPRESSOR o 
// DECOMPRESSOR segun el caso.
//
// COMPRESSOR: Recibe por linea de comandos: "-path" seguido por el directorio del cual se 
//						     quieren buscar los .png.
//					     "-threshold" seguido por el valor deseado.
//						     (entre 0 y 3*255).
//
// DECOMPRESSOR: Recibe por linea de comandos: "-path" seguido por el directorio del cual se 
// quieren buscar los .mvi.
//
// El COMPRESSOR comprime unicamente imagenes de tamaño cuadrado y que a su vez sea una 
// potencia de dos. Esas imagenes .png seran las que el usuario podra ver en pantalla.
// El resto no seran mostradas. Las imagenes comprimidas se guardan en la misma carpeta
// de los .png correspondientes
//
// El DECOMPRESSOR descomprime unicamente los archivos .mvi.
//
// Para seleccionar las imagenes que se desean comprimir/descomprimir (con teclado):
// Numeros del 1 al 9: para la imagen correspondiente dentro de las que se ven en la pagina.
// A: Selecciona todas las imagenes.
// N: Deselecciona todas las imagenes que se encuentran seleccionadas.
// Flecha derecha: para ir a la siguiente pagina y ver mas imagenes.
// Flecha izquierda: para ir a la pagina anterior y ver mas imagenes.
//	
/////////////////////////////////////////////////////////////////////////////////////////////

#include "main.h"
#include "Board.h"
#include "Tile.h"
#include "paths.h"

extern "C"
{
	#include "parseCmdLine.h"
}

#include "Callback.h"

#if IAM == COMPRESSOR
#include "Compressor.h"
#else
#include "Decompressor.h"
#endif // IAM

void de_compress(Board* b, parametros_t userData);
bool allegroStartup(void);
void allegroShutdown(void);

typedef int(*pCallback) (char *, char*, void *);


int main(int argc, char *argv[])
{
	pCallback parser = &Callback;
	parametros_t userData;

	userData.path = NULL;
#if IAM == COMPRESSOR
	userData.threshold = 1;
#endif


	if (parseCmdLine(argc, argv, parser, &userData) == 0)
	{
		printf("PARSER ERROR\n");
		return EXIT_FAILURE;
	}
	bool do_exit = false;
	
	if (allegroStartup()) {
		fprintf(stderr, "Error Initilizing Allegro\n");
		return EXIT_FAILURE;
	}
	
	List<Tile> *imageList;
	imageList = new List<Tile>;
	
	Paths *p = new Paths(imageList);
	p->saveDirPngs(userData.path);

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
				de_compress(b, userData);
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


/////////////////////////////////////////////////////////////////////////////////////////////
//		DE_COMPRESS
//	Llama al compresor o descompresor con todas los archivos que fueron seleccionados
////////////////////////////////////////////////////////////////////////////////////////////
void de_compress(Board* b, parametros_t userData)
{
#if IAM == COMPRESSOR
	Compressor c;
	
	for (int i = 0; i < b->getTiles()->getListSize(); i++)
	{
		
		c.compressingFunction(b->getTiles()->getElement(i).getFilePath().c_str(), b->getTiles()->getElement(i).getLength(), userData.threshold);
	}
#else
	Decompressor d;
	for (int i = 0; i < b->getTiles()->getListSize(); i++)
	{

		d.decompressingFunction(b->getTiles()->getElement(i).getFilePath().c_str());
	}
#endif

}

/////////////////////////////////////////////////////////////////////////////////////
//		ALLEGRO STARTUP
//	Inicializa allegro y los addons. Devuelve true si hubo error
////////////////////////////////////////////////////////////////////////////////////
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


/////////////////////////////////////////////////////////////////////////////////////
//		ALLEGRO SHUTDOWN
//	Apaga allegro y los addons
////////////////////////////////////////////////////////////////////////////////////
void allegroShutdown(void)
{
	al_shutdown_font_addon();
	al_shutdown_image_addon();
	al_uninstall_mouse();
	al_uninstall_keyboard();
	al_shutdown_primitives_addon();
	al_uninstall_system();
}