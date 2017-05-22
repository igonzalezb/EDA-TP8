
#include "Compressor.h"
#include "lodepng.h"


void Compressor::decode(char* filePath)
{
	lodepng_decode32_file(&Img, &imgWidth, &imgHeight, filePath);
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
		Gmax = max(Gmax, Img[i+COMPONENTE_G]);
		Bmax = max(Bmax, Img[i+COMPONENTE_B]);

		Rmin = min(Rmin, Img[i+COMPONENTE_R]);
		Gmin = min(Rmin, Img[i+COMPONENTE_G]);
		Bmin = min(Rmin, Img[i+COMPONENTE_B]);

		Rmed += Img[i+COMPONENTE_R];
		Gmed += Img[i+COMPONENTE_G];
		Bmed += Img[i+COMPONENTE_B];
	}
	Rmed /= (i+COMPONENTE_R); //ver y seguir
	Gmed /= (i+COMPONENTE_G);
	Bmed /= (i+COMPONENTE_B);
}

unsigned int Compressor::max (unsigned int, unsigned int)
{
	return 
}


unsigned int Compressor::min(unsigned int, unsigned int)
{
	return
}


int max(int* array, int arraySize)
{
	int mayor = array[0];

	for (int i = 0; i < arraySize; i++) {
		if (array[i] > mayor)
		{
			mayor = array[i];
		}
	}
	return mayor;
}

int min(int* array, int arraySize)
{
	int menor = array[0];

	for (int i = 0; i < arraySize; i++) {
		if (array[i] < menor)
		{
			menor = array[i];
		}
	}
	return menor;
}