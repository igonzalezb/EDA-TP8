/*
boost crea un objeto que representa lo que esta listado
path //objeto que apunta a un archivo o cosas de filesyst
is_regular_file // devuelve true si es un regular file o directory
//todo lo que sean imagenes van a ser regular files

//al entrar al directorio necesitamos que boost lea todo lo q esta adentro
//agarra un direcotrio y enlista todo lo q esta dentro

//la verificacion para q el usuario no meta cosas q no existen estan en exist
*/

#include "Board.h"
#include "Tile.h"
#include "paths.h"

bool allegroStartup(void);
void allegroShutdown(void);

int main(int argc, char *argv[])
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *logo = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	
	if (allegroStartup()) {
		fprintf(stderr, "Error Initilizing Allegro\n");
		return EXIT_FAILURE;
	}
	
	List<Tile> *imageList;
	imageList = new List<Tile>;
	
	Paths *p = new Paths(imageList);
	p->saveDirPngs(argv[1]);

//===========================================================================================================
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		delete imageList;
		delete p;
		allegroShutdown();
		return EXIT_FAILURE;
	}

	logo = al_load_bitmap("resources\\logo.png");
	if (!logo) {
		fprintf(stderr, "failed to create logo!\n");
		delete imageList;
		delete p;
		al_destroy_display(display);
		allegroShutdown();
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event queue!\n");
		delete imageList;
		delete p;
		al_destroy_display(display);
		al_destroy_bitmap(logo);
		allegroShutdown();
		return EXIT_FAILURE;
	}

	al_set_window_title(display, "Image Compressor & Descompressor");
	al_set_display_icon(display, logo);
//===========================================================================================================
	Board *b = new Board(imageList);

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	bool do_exit = false, redraw = true;

	while (!do_exit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		switch (ev.type)
		{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			do_exit = true;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			break;
		case ALLEGRO_EVENT_KEY_UP:
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				do_exit = true;
			else if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				//LLAMAR AL QUADTREE Y MOSTRAR CARTELITO
				do_exit = true;
			}
				
			else
				b->keyDispacher(ev);
			break;
		}
	}

	//================================================================================================================================================
	
	delete imageList;
	delete p;
	delete b;
	al_destroy_display(display);
	al_destroy_bitmap(logo);
	al_destroy_event_queue(event_queue);
	allegroShutdown();
	
	return EXIT_SUCCESS;
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