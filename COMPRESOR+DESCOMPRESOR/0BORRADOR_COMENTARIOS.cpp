/*
	CHECK LIST:
		-Lea archivos dentro de carpetas
		-arreglar lo de remove element
		-Allegro:
			_Enter y Mostrar la cantidad de imagenes comprimidas
		-Quadtree
		
		
*/












/*

PARTES DEL PROGRAMA

1)
SE FIJA EL PATH que entra por linea de comandos y guarda todos los pngs en la lista. (filtro de pngs)

2) parte de allegro de seleccionar (muestra en pantalla todo)
NO MOSTRAR LAS QUE NO SON CUADRADAS (ASI NUNCA SE SELECCIONAN)
cuando se apreta ENTER se pasa a la parte 3

3) borra de la lista todo lo que NO SE SELECCIONO (lo que tiene el bool de selected en false):
for (todos los elementos de la lista) //	VALEN
{
	if (elemento con selected=false)
		delete element; (acomodar los punteros de next y previous node)
}

HECHA ACAAAAA

for (int i = 0; i < (POSICION DEL ULTIMO NODO); i++)
{
	if (Tiles.getElement(i).isSelected == false)
	{
		removeElement(i); //O COMO SEA QUE SE HAGA PARA BORRAR ESE NODO DE LA LISTA Y PONERLE LOS PUNTEROS CORRESPONDIENTES
	}
}


//ahora ya tenemos la lista SOLO con lo que hay que comprimir
for (que recorra todos los pngs que quedaron en la lista) //seria lo que quedo en true
{
	quadTree(......);
}

*/






 /*
 Same as lodepng_decode_file, but always decodes to 32-bit RGBA raw image.
 unsigned lodepng_decode32_file(unsigned char** out, unsigned* w, unsigned* h,
 const char* filename); //devuelve el png para que nosotros lo comprimamos (lo devuelve en pixels)




						   filename: nombre del archivo que quiero abrir.png

						   unsigned char** out: puntero a arreglo de chars donde se guarda como bitmap
						   es un arreglo de pixels. De a un byte. Arreglo de bytes. Arreglo out esta en heap.
						   internamente hizo un malloc. Para devolverte lo que tiene es **. se`pone char* para entrar a la
						   dir. Se pasa por referencia (sino se estaria pasando por valor)

						   w y h: dimensiones de alto y ancho del arreglo. se pasa punteros para simular paso por referencia.
						   vva a haber que modificarlas.

						   rawImg[] arreglo armado por lodepng. Recibe un puntero a este puntero de chars. Hace un malloc, lo mete aca
						   y lo devuelve ya hecho. Al temrinar el programa: free(rawImg);

						   rawImg[0]= componente R del pixel 1
						   rawImg[1]= componente G del pixel 1
						   rawImg[2]= componente B del pixel 1
						   rawImg[3]= componente A del pixel 1

						   i entre 0 y (w-1)*(h-1)      TODAS las imagenes
						   rawImg[4i]=componente R del pixel i
						   rawImg[4i+1]=componente G del pixel i
						   rawImg[4i+2]=componente B del pixel i

						   hay que hacer putPixel en x y en y. cuando llega a w ya hice la primera columna.
						   de cero a w vale i. En w+1 vale 1. Cuando llegue a un w va a ser 1%h va a ser 1.
						   lo voy limitando en x y en y.
						   Se puede hacer con dos fors. i*j
						   Se usa el % para tener la parte entera.

						   -------------------------------------
						   verificar que la imagen sea cuadrada.




						   for (i = 0; i < (w*h); i++)
						   {
						   //la siguiente linea muestra la imagen
						   putPixel(al_map_rgba(rawImg[4i], rawImg[4i + 1], rawImg[4i + 2]), i%w, (i/w)%h);

						   //la siguiente linea transforma la imagen en blanco y negro (haciendo un promedio, hay que ver si es la mejor forma)
						   rawImg[4i] = rawImg[4i + 1] = rawImg[4i + 2] = ((rawImg[4i] + rawImg[4i + 1] + rawImg[4i + 2]) / 3.0);
						   }


						   lodepng_encode32_file("", rawImg, ImgWidth, ImgHeight);

						   free(rawImg);


						   */
