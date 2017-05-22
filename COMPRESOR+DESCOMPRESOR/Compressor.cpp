
#include "Compressor.h"


void Compressor::decode(char* path)
{
	lodepng_encode32_file(&rawImg, &imgWidth, &imgHeight, path);
}



void Compressor::quadTree(unsigned char* image, unsigned int x0, unsigned int y0,
	unsigned int xf, unsigned int yf, FILE* fp)
{
	double Rmed = 0.0, Gmed = 0.0, Bmed = 0.0;
	unsigned int Rmax, GmaxG, Bmax, Rmin, Gmin, Bmin;

	unsigned int i;
	for (i = 0; i < ....; i++) //COMPLETAR para determinar i
	{
		Rmax = max(Rmax, Img[i+COMPONENTE_R]);
		Rmax = max(Gmax, Img[i+COMPONENTE_G]);
		Rmax = max(Bmax, Img[i+COMPONENTE_B]);

		Rmin = min(Rmin, Img[i+COMPONENTE_R]);
		Rmin = min(Rmin, Img[i+COMPONENTE_G]);
		Rmin = min(Rmin, Img[i+COMPONENTE_B]);

		Rmed += Img[i+COMPONENTE_R];
		Gmed += Img[i+COMPONENTE_G];
		Bmed += Img[i+COMPONENTE_B];
	}
	Rmed /= i; //ver y seguir
	Gmed /= (i + 1);
	Bmed
}

unsigned int Compressor::max (unsigned int, unsigned int)
{
	return 
}