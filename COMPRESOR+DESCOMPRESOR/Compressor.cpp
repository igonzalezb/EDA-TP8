//
//#include "Compressor.h"
//
//void Compressor::quadTree(unsigned char* image, unsigned int x0, unsigned int y0,
//	unsigned int xf, unsigned int yf, FILE* fp)
//{
//	double Rmed = 0.0, Gmed = 0.0, Bmed = 0.0;
//	unsigned int maxR, maxG, maxB, minR, minG, minB;
//
//	unsigned int i;
//	for (i = 0; i < ....; i++) //COMPLETAR
//	{
//		Rmax = max(Rmax, Img[i]);
//		Rmax = max(Gmax, Img[i+1]);
//		Rmax = max(Bmax, Img[i+2]);
//
//		Rmin = min(Rmin, Img[i]);
//		Rmin = min(Rmin, Img[i+1]);
//		Rmin = min(Rmin, Img[i+2]);
//
//		Rmed += Img[i];
//		Gmed += Img[i+1];
//		Bmed += Img[i+2];
//	}
//	Rmed / i; //ver y seguir
//}