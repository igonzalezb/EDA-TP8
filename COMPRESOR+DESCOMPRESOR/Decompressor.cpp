
#include "Decompressor.h"
#if IAM == DECOMPRESSOR
#include "lodepng.h"

enum { COMPONENTE_R, COMPONENTE_G, COMPONENTE_B, COMPONENTE_A }componentesRGB;


bool Decompressor::decompressingFunction(const char* filePath)
{
	printf("DECOMPRESSING: %s\n", filePath);
	int lado = NEW_SIZE;
	imgW = lado;

	string _png = Path->replaceExtension((string)filePath, ".mvi", "(new).png");

	std::ifstream vim (filePath, ios_base::binary);				//Se utiliza el archivo en modo lectura
	if (!vim.good())
		return false;
	
	Img = new unsigned char[lado*lado*PIXEL];

	bool _noError = true;
	
	if (!quadTree(0, 0, lado, &vim))
	{
		_noError = false;
	}
	

	if(lodepng_encode32_file(_png.c_str(), Img, lado, lado)!=0) 
	{
		_noError = false;
	}

	vim.close();
	printf("FINISHED\n");
	return _noError;
}


bool Decompressor::quadTree(unsigned int x0, unsigned int y0, double lado, std::ifstream* vim) 
{
	unsigned char c = vim->get();
	bool noError = false;
	switch (c)
	{
	case '1':													//Se dividi� el cuadrante en 4.
	{
		lado /= 2;	
		quadTree(x0, y0, lado, vim);
		quadTree(x0 + lado, y0, lado, vim);		
		quadTree(x0, y0 + lado, lado, vim);
		quadTree(x0 + lado, y0 + lado, lado, vim);
	}
	break;

	case'0':													//El cuadrante no se dividi�. 
	{
		unsigned char rgba[PIXEL] = { vim->get(),vim->get(),vim->get(),255 };	//Valores de RGBA para todos los pixels del cuadrante.

		for (unsigned int j = 0; j < lado; j++)											//Se guardan los valores RGB y alfa 
		{																				//de todos los pixels del cuadrante,
			for (unsigned int i = 0; i < lado; i++)										//cuyo tama�o es lado*lado
			{
				Img[(y0 + j)*(int)imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_R] = rgba[COMPONENTE_R];
				Img[(y0 + j)*(int)imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_G] = rgba[COMPONENTE_G];
				Img[(y0 + j)*(int)imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_B] = rgba[COMPONENTE_B];
				Img[(y0 + j)*(int)imgW*PIXEL + (x0 + i)*PIXEL + COMPONENTE_A] = rgba[COMPONENTE_A];
			}
		}

	}
	break;

	default: noError = false;				//Si no se ley� ni 1 ni 0, 
		break;								//se indica error por como estan guardados los datos.
	}
	return noError;
}

Decompressor::Decompressor()
{
}

#endif