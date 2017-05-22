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

bool allegroStartup(void);
void allegroShutdown(void);
void keyDispacher(ALLEGRO_EVENT ev);

int main(int argc, char *argv[])
{
	//EDAlist<int>li;
	//EDAlis<double>la;
	Paths p;
	Board b;
	
	p.saveDirPngs(argv[1]); //recibir tambien la lista. dir es un const char*

	//B.getTiles().addElement(pos, 0); //en pos, en vez de pos se le pasa un Tile





}



void keyDispacher(ALLEGRO_EVENT ev)
{
	switch (ev.keyboard.keycode) {
	case ALLEGRO_KEY_A:
		for (int j = 1; (j < 6); j++, j++) { for (int i = 1; (i < 6); i++, i++) { selectTale(i, j, true); } }
		break;
	case ALLEGRO_KEY_N:
		for (int j = 1; (j < 6); j++, j++) { for (int i = 1; (i < 6); i++, i++) { selectTale(i, j, false); } }
		break;
	case ALLEGRO_KEY_RIGHT:

		break;
	case ALLEGRO_KEY_LEFT:

		break;
	case ALLEGRO_KEY_1:
		selectTale(1, 1, true);
		break;
	case ALLEGRO_KEY_2:
		selectTale(1, 3, true);
		break;
	case ALLEGRO_KEY_3:
		selectTale(1, 5, true);
		break;
	case ALLEGRO_KEY_4:
		selectTale(3, 1, true);
		break;
	case ALLEGRO_KEY_5:
		selectTale(3, 3, true);
		break;
	case ALLEGRO_KEY_6:
		selectTale(3, 5, true);
		break;
	case ALLEGRO_KEY_7:
		selectTale(5, 1, true);
		break;
	case ALLEGRO_KEY_8:
		selectTale(5, 3, true);
		break;
	case ALLEGRO_KEY_9:
		selectTale(5, 5, true);
		break;
	}


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