/*Same as lodepng_decode_file, but always decodes to 32-bit RGBA raw image.*/
unsigned lodepng_decode32_file(unsigned char** out, unsigned* w, unsigned* h,
	const char* filename); //devuelve el png para que nosotros lo comprimamos (lo devuelve en pixels)

/*
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

*/

for (i = 0; i < (w*h); i++)
{
	putPixel(al_map_rgba(rawImg[4i], rawImg[4i + 1], rawImg[4i + 2]), i%w, (i/w)%h);
	rawImg[4i]=rawImg[4i+1]=rawImg[4i+2]=
}