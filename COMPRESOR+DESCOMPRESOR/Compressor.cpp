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
	
	double Rmed = 0.0, Gmed = 0.0, Bmed = 0.0;
	unsigned int Rmax=0, Gmax=0, Bmax=0, Rmin=255, Gmin=255, Bmin=255;
	unsigned int peso;

	unsigned int i;
	unsigned int j;
	//for (i = 0; i < lado*lado; i++)				//COMPLETAR para determinar i (width * height)
	//{
	//	j = i*PIXEL;
	//	Rmax = MAX(Rmax, Img[j+COMPONENTE_R]);	//maximas componentes del cuadrante
	//	Gmax = MAX(Gmax, Img[j+COMPONENTE_G]);
	//	Bmax = MAX(Bmax, Img[j+COMPONENTE_B]);

	//	Rmin = MIN(Rmin, Img[j+COMPONENTE_R]);	//minimas componentes del cuadrante
	//	Gmin = MIN(Rmin, Img[j+COMPONENTE_G]);
	//	Bmin = MIN(Rmin, Img[j+COMPONENTE_B]);

	//	Rmed += Img[j+COMPONENTE_R];			//Suma de todas las componentes del color en el cuadrante
	//	Gmed += Img[j+COMPONENTE_G];
	//	Bmed += Img[j+COMPONENTE_B];
	//}

	/*for (i = 0; i < lado; i++)
	{
		for (j = 0; j < lado; j++)
		{
			Rmax = MAX(Rmax, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_R]);
			Gmax = MAX(Rmax, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_G]);
			Bmax = MAX(Rmax, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_B]);
			Rmin = MAX(Rmin, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_R]);
			Gmin = MAX(Rmin, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_G]);
			Bmin = MAX(Rmin, Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_B]);
			Rmed += Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_R];
			Gmed += Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_G];
			Bmed += Img[(y0 + j)*imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_B];
		}
	}*/


	unsigned char* pElement = Img;


	for (unsigned int j = 0; j < lado; j++)
	{

		pElement = Img + PIXEL*(j  * imgW + x0);

		for (i = 0; i < lado; i++)    //COMPLETAR para determinar i (width * height)
		{
			Rmax = MAX(Rmax, pElement[COMPONENTE_R]); //maximas componentes del cuadrante
			Gmax = MAX(Gmax, pElement[COMPONENTE_G]);
			Bmax = MAX(Bmax, pElement[COMPONENTE_B]);

			Rmin = MIN(Rmin, pElement[COMPONENTE_R]); //minimas componentes del cuadrante
			Gmin = MIN(Rmin, pElement[COMPONENTE_G]);
			Bmin = MIN(Rmin, pElement[COMPONENTE_B]);

			Rmed += pElement[COMPONENTE_R];   //Suma de todas las componentes del color en el cuadrante
			Gmed += pElement[COMPONENTE_G];
			Bmed += pElement[COMPONENTE_B];

			pElement += PIXEL;
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
		| 3	| 4	|
		*/
		*compressedImg << '1';
		lado/=2;
		quadTree(x0, y0, lado, compressedImg);			//primer cuadrante
		quadTree(x0 + lado, y0, lado, compressedImg);	//segundo cuadrante
		quadTree(x0, y0+lado, lado, compressedImg);		//tercer cuadrante
		quadTree(x0+lado, y0+lado, lado, compressedImg);//cuarto cuadrante
	}
}



#endif
