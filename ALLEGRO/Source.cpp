#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#define SCREEN_W	1000
#define SCREEN_H	600
#define TALES_MAX	9
#define TALES_W		230.0
#define TALES_H		120.0

bool allegroStartup(void);
void allegroShutdown(void);
void keyDispacher(ALLEGRO_EVENT ev);
void drawTales(ALLEGRO_BITMAP **talesArray);
void selectTale(int j, int i, bool isSelected);

ALLEGRO_BITMAP *talesArray[TALES_MAX];		//para probar
ALLEGRO_FONT *font = NULL;

int main()
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *logo = NULL;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	//ALLEGRO_BITMAP *talesArray[TALES_MAX];

//===========================================================================================================
	if (allegroStartup()) {
		fprintf(stderr, "Error Initilizing Allegro\n");
		return EXIT_FAILURE;
	}
	
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

	background = al_load_bitmap("resources/background.png");
	if (!background) {
		fprintf(stderr, "failed to create background!\n");
		al_destroy_display(display);
		al_destroy_bitmap(logo);
		allegroShutdown();
		return EXIT_FAILURE;
	}

	font = al_load_ttf_font("resources/font.ttf", 30, 0);
	if (!font) {
		fprintf(stderr, "failed to create font!\n");
		al_destroy_display(display);
		al_destroy_bitmap(logo);
		al_destroy_bitmap(background);
		allegroShutdown();
		return EXIT_FAILURE;
	}
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event queue!\n");
		al_destroy_display(display);
		al_destroy_bitmap(logo);
		al_destroy_bitmap(background);
		al_destroy_font(font);
		allegroShutdown();
		return EXIT_FAILURE;
	}

	al_set_window_title(display, "Image Compressor & Descompressor");
	al_set_display_icon(display, logo);
//===========================================================================================================
	// CAMBIARLO POR LA LISTA Y PONERLO COMO FUNCION APARTE PARA QUE SE LLAME CADA VEZ QUE SE APRETE <- ->


	char aPath[700];
	for (unsigned int i = 0; i < TALES_MAX; i++)
	{
		sprintf_s(aPath, "resources/image (%d).jpg", i);
		talesArray[i] = al_load_bitmap(aPath);
		if (!talesArray[i])
		{
			fprintf(stderr, "failed to create tale\n");
			al_destroy_display(display);
			al_destroy_bitmap(logo);
			al_destroy_event_queue(event_queue);
			for (i--; i >= 0; i--)
				al_destroy_bitmap(talesArray[i]);

			allegroShutdown();
			return EXIT_FAILURE;
		}
	}

//===========================================================================================================
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_scaled_bitmap(background, 0.0, 0.0,
		al_get_bitmap_width(background), al_get_bitmap_height(background),
		0.0, 0.0, SCREEN_W, SCREEN_H, 0);

	drawTales(talesArray);
	for (int j = 1; (j < 6); j++, j++) { for (int i = 1; (i < 6); i++, i++) { selectTale(i, j, false); } }
	al_flip_display();
	
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
			else
				keyDispacher(ev);
			break;
		}
		/*if (redraw && al_is_event_queue_empty(event_queue)) {

			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			drawTales(talesArray);
			al_flip_display();
		}*/
	}

//================================================================================================================================================

	al_destroy_display(display);
	al_destroy_bitmap(logo);
	al_destroy_bitmap(background);
	al_destroy_font(font);
	al_destroy_event_queue(event_queue);

	for (unsigned int i = 0; i < TALES_MAX; i++){
		al_destroy_bitmap(talesArray[i]);
	}

	allegroShutdown();

	return EXIT_SUCCESS;
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

void drawTales(ALLEGRO_BITMAP **talesArray)
{
	int taleNumber = 0;

	for (int j = 1; (j < 6) && (taleNumber < TALES_MAX); j++, j++, taleNumber++) {
		
		for (int i = 1; (i < 6) && (taleNumber < TALES_MAX); i++ , i++, taleNumber++) {

			al_draw_scaled_bitmap(talesArray[taleNumber], 0.0, 0.0,
				al_get_bitmap_width(talesArray[taleNumber]), al_get_bitmap_height(talesArray[taleNumber]),
				((SCREEN_W / 6) * (i)) - (TALES_W / 2),
				((SCREEN_H / 6) * (j)) - (TALES_H / 2),
				TALES_W, TALES_H, 0);
			al_draw_textf(font, al_map_rgb(0,0,0), ((SCREEN_W / 6) * (i)), ((SCREEN_H / 6) * (j)) + (TALES_H/2), ALLEGRO_ALIGN_CENTRE, "%d", taleNumber+1);
		}

		taleNumber--;
	}
	
	al_flip_display();
	
}

void selectTale(int j, int i, bool isSelected)
{
	if(isSelected)
	al_draw_rectangle(((SCREEN_W / 6) * (i)) - (TALES_W / 2), ((SCREEN_H / 6) * (j)) - (TALES_H / 2),
		((SCREEN_W / 6) * (i)) - (TALES_W / 2) + TALES_W, ((SCREEN_H / 6) * (j)) - (TALES_H / 2) + TALES_H,
		al_map_rgb(0.0,255.0,0.0), 5.0);
	else
	al_draw_rectangle(((SCREEN_W / 6) * (i)) - (TALES_W / 2), ((SCREEN_H / 6) * (j)) - (TALES_H / 2),
		((SCREEN_W / 6) * (i)) - (TALES_W / 2) + TALES_W, ((SCREEN_H / 6) * (j)) - (TALES_H / 2) + TALES_H,
		al_map_rgb(0.0,0.0, 0.0), 5.0);
	al_flip_display();
}