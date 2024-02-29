#include <stdio.h>
#include <stdlib.h>

#define LEEDATO(formato,dato) scanf(formato,dato); while(getchar()!='\n');

typedef enum gruposUtad_e
{
  IPR1A,IPR1B,IPR1C,MAIS,FIIS
} gruposUtad_e;
const char* gruposUtadNombre[] = {"IPR1A", "IPR1B", "IPR1C", "MAIS", "FIIS"}; 
typedef struct listaEnteros_t
{
  int *numeros;
  int tamMax;
  int numUsados;
} listaEnteros_t;

typedef struct listaEdades_t
{
  gruposUtad_e grupo;
  listaEnteros_t* edades;
} listaEdades_t;

typedef struct listaGrupos_t
{
  listaEdades_t** edadesPorGrupo;
  int tamMax;
  int numUsados;
} listaGrupos_t;


void introduceEnListaNumeros(listaEnteros_t* lista,int pos,int num)
{
  if(lista->tamMax<=pos) 
  {
    lista->numeros=realloc(lista->numeros,sizeof(int)*(pos+1));
    lista->tamMax=pos+1;
  }
  lista->numeros[pos]=num;
  if(lista->numUsados<=pos)
  {
    lista->numUsados=pos+1;
  }
  
}


void pedirListaEdadesDeGrupo(listaEdades_t* edadesGrupo)
{
 
  int edad=0;
  int pos=0;
  edadesGrupo->edades=(listaEnteros_t*)malloc(sizeof(listaEnteros_t));
  edadesGrupo->edades->numeros=NULL;
  edadesGrupo->edades->tamMax=0;
  edadesGrupo->edades->numUsados=0;
  printf("Introduzca edades del grupo %s, acabar con -1\n",gruposUtadNombre[edadesGrupo->grupo]);
  do
  {
    LEEDATO("%d",&edad);
    if(edad>=0)
    {
       introduceEnListaNumeros(edadesGrupo->edades,pos,edad);
       pos++;
    }
    else
    {
      printf("Edad no valida");
    }
    
  } while(edad != -1);
  

}



listaEdades_t* pedirNuevoGrupo()
{
  listaEdades_t* nuevaLista=(listaEdades_t*)malloc(sizeof(listaEdades_t));
  printf("Introduzca nombre del grupo\n");
  printf("Grupos disponibkes\n");
  for(gruposUtad_e grupo=IPR1A;grupo<=FIIS;grupo++)
  {
    printf("%d %s\n",grupo,gruposUtadNombre[grupo]);
  }
  LEEDATO("%d",&nuevaLista->grupo);
  pedirListaEdadesDeGrupo(nuevaLista);
  return nuevaLista;
}


int calculaMaxima(listaEdades_t* grupo)
{
  int max=-1;
  for(int i=0;i<grupo->edades->numUsados;i++)
  {
    if(max<grupo->edades->numeros[i])
    {
      max = i;
    }
  }
  return max;
}

int calculaMin(listaEdades_t* grupo)
{
  unsigned int min=0xFFFFFFFF;
  for(int i=0;i<grupo->edades->numUsados;i++)
  {
    if(min >grupo->edades->numeros[i])
    {
      min = i;
    }
  }
  return min;
}

float calculaMedia(listaEdades_t* grupo)
{
  float suma=0;
  float media=0;
  for(int i=0;i<grupo->edades->numUsados;i++)
  {
    suma= suma + grupo->edades->numeros[i];
  }
  media = suma /grupo->edades->numUsados;
  return media;
}


int main(int argc,char **argv)
{
  listaGrupos_t grupos={.edadesPorGrupo=NULL, .tamMax=0, .numUsados=0};
  int salir = 0;
  grupos.tamMax=1;
 
  
  do
  {
     printf("1-Pedir Grupo");
     printf("2-Salir");
     LEEDATO("%d",&salir)
     if(salir==1)
     {
        if(grupos.numUsados==grupos.tamMax)
        {
          grupos.tamMax++;
          grupos.edadesPorGrupo=(listaEdades_t**)realloc(grupos.edadesPorGrupo, sizeof(listaEdades_t**)*grupos.tamMax);
        }
        grupos.edadesPorGrupo[grupos.numUsados]=pedirNuevoGrupo();
        grupos.numUsados++;
       
      
     }
    
  } while(salir!=2);
   for(int i=0;i<grupos.numUsados;i++)
   {
     printf("Datos del grupo %s\n",gruposUtadNombre[grupos.edadesPorGrupo[i]->grupo]);
     float media = calculaMedia(grupos.edadesPorGrupo[i]);
     int max = calculaMaxima(grupos.edadesPorGrupo[i]);
     int min = calculaMin(grupos.edadesPorGrupo[i]);
     printf("media %f\n max %d\n min %d\n",media,max,min);
   }
   return 0;
}