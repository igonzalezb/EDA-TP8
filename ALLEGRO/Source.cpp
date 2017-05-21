#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#define SCREEN_W	1000
#define SCREEN_H	600
#define TALES_MAX	9
#define TALES_W		200.0
#define TALES_H		90.0

bool allegroStartup(void);
void allegroShutdown(void);
void drawTales(ALLEGRO_BITMAP **talesArray);

int main()
{
	if (allegroStartup()) {
		fprintf(stderr, "Error Initilizing Allegro\n");
		return EXIT_FAILURE;
	}
	
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *logo = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *imageArray[TALES_MAX];

	
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display){
		fprintf(stderr, "failed to create display!\n");
		allegroShutdown();
		return EXIT_FAILURE;
	}

	logo = al_load_bitmap("resources/logo.png");
	if (!logo) {
		fprintf(stderr, "failed to create logo!\n");
		al_destroy_display(display);
		allegroShutdown();
		return EXIT_FAILURE;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event queue!\n");
		al_destroy_display(display);
		al_destroy_bitmap(logo);
		allegroShutdown();
		return EXIT_FAILURE;
	}


	char aPath[700];
	for (unsigned int i = 0; i < TALES_MAX; i++)
	{

		sprintf_s(aPath, "resources/image (%d).jpg", i);		//voy cambiando de frame (i), copiando el string con el valor de frame en que estoy en aPath

		imageArray[i] = al_load_bitmap(aPath);	//Voy cargando los bitmaps al arreglo variable
		if (!imageArray[i])
		{
			fprintf(stderr, "failed to create tale\n");
		}
	}

	al_set_window_title(display, "Image Compressor & Descompressor");
	al_set_display_icon(display, logo);


	drawTales(imageArray);
	al_flip_display();
	al_rest(5.0);



	/*al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	bool do_exit = false, redraw = true;

	while (!do_exit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (key_pressed[KEY_UP] && cuadradito_y >= MOVE_RATE)
				cuadradito_y -= MOVE_RATE;

			if (key_pressed[KEY_DOWN] && cuadradito_y <= SCREEN_H - CUADRADITO_SIZE - MOVE_RATE)
				cuadradito_y += MOVE_RATE;

			if (key_pressed[KEY_LEFT] && cuadradito_x >= MOVE_RATE)
				cuadradito_x -= MOVE_RATE;

			if (key_pressed[KEY_RIGHT] && cuadradito_x <= SCREEN_W - CUADRADITO_SIZE - MOVE_RATE)
				cuadradito_x += MOVE_RATE;

			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			do_exit = true;

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key_pressed[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key_pressed[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key_pressed[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key_pressed[KEY_RIGHT] = true;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key_pressed[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key_pressed[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key_pressed[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key_pressed[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				do_exit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {

			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(cuadradito, cuadradito_x, cuadradito_y, 0);
			al_flip_display();
		}
	}
*/

	al_destroy_display(display);
	al_destroy_bitmap(logo);
	al_destroy_event_queue(event_queue);

	for (unsigned int i = 0; i < TALES_MAX; i++){
		al_destroy_bitmap(imageArray[i]);
	}

	allegroShutdown();

	return EXIT_SUCCESS;
}



void keyDispacher(ALLEGRO_EVENT ev)
{
	

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



void drawTales(ALLEGRO_BITMAP **talesArray)
{
	int taleNumber = 0;

	for (int j = 1; (j < 4) && (taleNumber < TALES_MAX); j++, taleNumber++) {
		
		for (int i = 1; (i < 4) && (taleNumber < TALES_MAX); i++ , taleNumber++) {

			al_draw_scaled_bitmap(talesArray[taleNumber], 0.0, 0.0,
				al_get_bitmap_width(talesArray[taleNumber]), al_get_bitmap_height(talesArray[taleNumber]),
				((SCREEN_W / 4) * (i)) - (TALES_W / 2),
				((SCREEN_H / 4) * (j)) - (TALES_H / 2),
				TALES_W, TALES_H, 0);

			al_flip_display();

			
		}

		taleNumber--;
	}
		
	
}