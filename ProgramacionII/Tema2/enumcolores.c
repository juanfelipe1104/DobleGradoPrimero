#include <stdio.h>
#include <stdlib.h>

typedef enum colores_e
{
  rojo =0,
  verde =1,
  azul=2,
  amarillo =3
} colores_e;

typedef struct libro_t
{
  colores_e color;
}libro_t;

char* coloresNombre[]={"rojo","verde","azul","amarillo"};
int main(int argc,char ** argv)
{
  libro_t libro;
  printf("Introduzca un color:\n"
         "0-Rojo\n"
         "1-Verde\n"
         "2-Azul\n"
         "3-Amarillo\n");
  scanf("%d",&libro.color);
  while(getchar()!='\n');
  
  printf("%s",coloresNombre[libro.color]);
  
  
  return 0;
}