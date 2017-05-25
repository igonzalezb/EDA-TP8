#include "Compressor.h"
#if IAM == COMPRESSOR

#include "lodepng.h"

enum { COMPONENTE_R, COMPONENTE_G, COMPONENTE_B }componentesRGB;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

Compressor::Compressor()
{
}



bool Compressor::compressingFunction(const char* filePath, unsigned int lado)
{
	printf("%u\n", lado);
	imgW = lado;
	
	lodepng_decode32_file(&Img, &lado, &lado, filePath);
	
	string _vim = Path->replaceExtension((string)filePath, ".png", ".mvi");

	std::ofstream vim(_vim.c_str(), ios_base::binary);
	
	if (!vim.good())
		return false;

	quadTree(0, 0,lado,&vim);
	vim.close();
	free(Img);
	return true;
}


void Compressor::quadTree(unsigned int x0, unsigned int y0, double lado, std::ofstream* compressedImg) //se la llama con los limites del cuadrante
{
	printf("%lf\n", lado);
	double Rmed = 0.0, Gmed = 0.0, Bmed = 0.0;
	unsigned int Rmax=0, Gmax=0, Bmax=0, Rmin=255, Gmin=255, Bmin=255;
	unsigned int peso;

	unsigned int i;
	unsigned int j;

	for (i = 0; i < lado; i++)
	{
		for (j = 0; j < lado; j++)
		{
			Rmax = MAX(Rmax, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_R]);
			Gmax = MAX(Gmax, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_G]);
			Bmax = MAX(Bmax, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_B]);

			Rmin = MIN(Rmin, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_R]);
			Gmin = MIN(Gmin, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_G]);
			Bmin = MIN(Bmin, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_B]);

			Rmed += Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_R];
			Gmed += Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_G];
			Bmed += Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_B];
		}
	}

	peso = (Rmax - Rmin) + (Gmax - Gmin) + (Bmax - Bmin); //Suma de las diferencias para cada letra

	if (peso <= THRESHOLD)
	{
		Rmed /= (lado*lado);								//Promedios de las componentes del cuadrante para cada color
		Gmed /= (lado*lado);
		Bmed /= (lado*lado);
		*compressedImg << '0'<<(unsigned char)Rmed<<(unsigned char)Gmed<<(unsigned char)Bmed;
	}
	else
	{
		/*
		Cuadrantes:
		| 1 | 2	|
		| 3 | 4	|
		*/
		*compressedImg << '1';
		lado/=2;
		quadTree(x0, y0, lado, compressedImg);			//primer cuadrante
		quadTree(x0 + lado, y0, lado, compressedImg);		//segundo cuadrante
		quadTree(x0, y0+lado, lado, compressedImg);		//tercer cuadrante
		quadTree(x0+lado, y0+lado, lado, compressedImg);	//cuarto cuadrante
	}
}



#endif
