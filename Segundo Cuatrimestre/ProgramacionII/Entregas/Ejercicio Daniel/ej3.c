#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20
#define MAX_JORNADAS 3
#define NUM_PAREJAS 4 //porque el array en el que lo uso acaba en 0


typedef struct parejas_t
{
  char integrante1[TAM_MAX];
  char integrante2[TAM_MAX];
} parejas_t;

typedef struct partidos_t
{
  int parejaA;
  int parejaB;
  int puntuacionA;
  int puntuacionB;
} partidos_t;

typedef struct jornadas_t
{
  partidos_t partidosJornada[2];
}  jornadas_t;
  
//Funcion  que pasa los parameteros a las parejas
parejas_t asignarParejas(int n,char **listaParejas);
//Funcion que las imprime
void imprimirParejas (parejas_t arrayParejas[]);
//Funcion que te pide los datos de la jornada y que va registrando quien gana y por cuantos sets
jornadas_t introducirJornada(int numJornada, parejas_t arrayParejas[], int ganadores[],int sets[]);
//Funcion que imprime las jornadas
void mostrarJornadas(parejas_t arrayParejas[],jornadas_t arrayJornadas[],int numJornada);
//Funcion que muestra los ganadores
void mostrarGanadores(int ganadores[],parejas_t arrayParejas[],int sets[]);
//Funcion para hacer control de errores
int controlarResultados(int a,int b);
 
  
int main(int argc,char **argv)
{
   if(argc-1!=8)
   {
     printf("Numero de parametros incorrectos");
     return 0;
   }
    parejas_t arrayParejas[NUM_PAREJAS];
    jornadas_t arrayJornadas[MAX_JORNADAS];
    
    int ganadores[NUM_PAREJAS]={0};
    int sets [NUM_PAREJAS];
    for (int i=0;i<NUM_PAREJAS;i++) 
    {
      arrayParejas[i]=asignarParejas(i*2+1, argv);
    }
    imprimirParejas(arrayParejas);
    
    int opcion=-1;
    int numJornada=0;

  while(opcion)
  {
    printf("Elige una opcion:\n1 - Introducir un resultado de una jornada, 2 - Mostrar los resultados de todos los partidos, 3 -Obtener la pareja ganadora... 0 - Salir\n");
    
    while(scanf("%d", &opcion)!=1)
    {
      getchar();
    }
    switch(opcion)
    {
      case 1:
        arrayJornadas [numJornada] = introducirJornada(numJornada, arrayParejas, ganadores,sets);
        numJornada++;
      break;
      case 2:
        mostrarJornadas(arrayParejas,arrayJornadas,numJornada);
      break;
      case 3:
      if(numJornada!=3)
      {
        printf("El torneo no ha terminado");
      }
      else
      {
        mostrarGanadores(ganadores,arrayParejas,sets);
      }
      break;
      default:
      printf("Saliendo");
      break;
    }
  }
  
   return 0;
}  

parejas_t asignarParejas(int n,char **listaParejas)
{
 parejas_t parejas;
  int i=0;
  
  while(listaParejas[n][i]!='\0')
  {
    parejas.integrante1[i]=listaParejas[n][i];
    i++;
  }
  parejas.integrante1[i]='\0';
  i=0;
   while(listaParejas[n+1][i]!='\0')
  {
    parejas.integrante2[i]=listaParejas[n+1][i];
    i++;
  }
  parejas.integrante2[i]='\0';
  
  return parejas;
}



void imprimirParejas (parejas_t arrayParejas[]) 
{
  printf("Participantes en el torneo de padel\n");
  printf("-----------------------------------\n");
  for (int i=0;i<NUM_PAREJAS;i++) 
  {
    printf("Pareja %d: %s - %s  \n",i+1, arrayParejas[i].integrante1, arrayParejas[i].integrante2);
  }
  
  
}



jornadas_t introducirJornada(int numJornada, parejas_t arrayParejas[], int ganadores[],int sets[])
{
  jornadas_t jornada;
  //Matriz para asociar cada jornada con las parejas que juegan
  int emparejamientos [MAX_JORNADAS][NUM_PAREJAS] = {{1,2,3,4},{1,3,2,4},{1,4,2,3}};
  //La pareja 1 es de la jornada que sea la psocion de la pareja y menos 1 por que array de 0 a 3
  int pareja1=emparejamientos[numJornada][0]-1;
  int pareja2=emparejamientos[numJornada][1]-1;
  int pareja3=emparejamientos[numJornada][2]-1;
  int pareja4=emparejamientos[numJornada][3]-1;
  
  printf("Cuando se le indique introduzca los resultados separados por un espacio\n");
  printf("Resultados de la jornada %d\n",numJornada+1);
  printf("Primer Emparejamiento: \n");

  printf("%s - %s --- %s - %s  \n",
      arrayParejas[pareja1].integrante1,
      arrayParejas[pareja1].integrante2,
      arrayParejas[pareja2].integrante1,
      arrayParejas[pareja2].integrante2);
      //Partido 1 de la jornada numJornada
   
      do
    {
     while(scanf("%d %d",&jornada.partidosJornada[0].puntuacionA, &jornada.partidosJornada[0].puntuacionB)!=2)
     {
       getchar();
     }
   }while(controlarResultados(jornada.partidosJornada[0].puntuacionA,jornada.partidosJornada[0].puntuacionB)==0);
   
   
   
   jornada.partidosJornada[0].parejaA = emparejamientos[numJornada][0];
   jornada.partidosJornada[0].parejaB = emparejamientos[numJornada][1];
   sets[pareja1] += jornada.partidosJornada[0].puntuacionA;
   sets[pareja2] += jornada.partidosJornada[0].puntuacionB;
   if (jornada.partidosJornada[0].puntuacionA>jornada.partidosJornada[0].puntuacionB) {
     ganadores[pareja1]+=1;
   } else {
     ganadores[pareja2]+=1;
   }
   
   

  printf("Segundo Emparejamiento: \n");
  printf("%s - %s --- %s - %s\n",
      arrayParejas[pareja3].integrante1,
      arrayParejas[pareja3].integrante2,
      arrayParejas[pareja4].integrante1,
      arrayParejas[pareja4].integrante2);
      
   do
   {
     while(scanf("%d %d",&jornada.partidosJornada[1].puntuacionA, &jornada.partidosJornada[1].puntuacionB)!=2)
     {
       getchar();
     }
   }while(controlarResultados(jornada.partidosJornada[1].puntuacionA,jornada.partidosJornada[1].puntuacionB)==0);
   jornada.partidosJornada[1].parejaA = emparejamientos[numJornada][2];
   jornada.partidosJornada[1].parejaB = emparejamientos[numJornada][3];   
   
   sets[pareja3] += jornada.partidosJornada[1].puntuacionA;
   sets[pareja4] += jornada.partidosJornada[1].puntuacionB;
   
   if (jornada.partidosJornada[1].puntuacionA>jornada.partidosJornada[1].puntuacionB) {
     ganadores[pareja3]+=1;
   } else {
     ganadores[pareja4]+=1;
   }   
   
  return jornada;
}

void mostrarJornadas(parejas_t arrayParejas[],jornadas_t arrayJornadas[],int numJornada)
{
  
  for(int i=0;i<numJornada;i++)
  {
    int pareja1=arrayJornadas[i].partidosJornada[0].parejaA-1;
    int pareja2=arrayJornadas[i].partidosJornada[0].parejaB-1;
    
    printf("%s - %s --- %s - %s  ",arrayParejas[pareja1].integrante1,arrayParejas[pareja1].integrante2,
    arrayParejas[pareja2].integrante1,arrayParejas[pareja2].integrante2);
    printf("%d - %d\n",arrayJornadas[i].partidosJornada[0].puntuacionA,arrayJornadas[i].partidosJornada[0].puntuacionB);
    
    int pareja3=arrayJornadas[i].partidosJornada[1].parejaA-1;
    int pareja4=arrayJornadas[i].partidosJornada[1].parejaB-1;
    
    printf("%s - %s --- %s - %s  ",arrayParejas[pareja3].integrante1,arrayParejas[pareja3].integrante2,
    arrayParejas[pareja4].integrante1,arrayParejas[pareja4].integrante2);
    printf("%d - %d\n",arrayJornadas[i].partidosJornada[1].puntuacionA,arrayJornadas[i].partidosJornada[1].puntuacionB);
    
  }
}

void mostrarGanadores(int ganadores[],parejas_t arrayParejas[],int sets[])
{
  sets[0]=0;
  sets[1]=4;
  sets[2]=4; // La paraje ganaddora debería ser la 2
  sets[3]=1;
  
  ganadores[0]=0;
  ganadores[1]=4;
  ganadores[2]=4;
  ganadores[3]=1;
  
  for(int i=0;i<NUM_PAREJAS;i++)
  {
    printf("Puntuacion de pareja (%s - %s) --",arrayParejas[i].integrante1,arrayParejas[i].integrante2);
    printf("%d\n",sets[i]);
  }
  
  int max;
  int parejasGanadoras[NUM_PAREJAS]={0};
  int numGanadores=0;
  max = -1;
  
  for(int i=0;i<NUM_PAREJAS;i++)
  {
      printf("Ganadores i :%d\n",ganadores[i]);
      if(ganadores[i]>max)
      {
         printf("Ganadores i %d :%d > max %d\n",i, ganadores[i], max);
        max = ganadores[i];
        parejasGanadoras[0]=i; // La pareja ganadora hasta ahora es la "i"
        numGanadores=1;
        
      }  
      else if (ganadores[i]==max)
      {
        printf("Tenemos segunda pareja ganadora %d \n", i);
        parejasGanadoras[numGanadores]=i;
        numGanadores++;
        
      }
      printf("max: %d\n",max);
      printf("numGanadores :%d\n",numGanadores);
      
      
      
  }
  printf("Los ganadores son:\n");
  printf("********************\n");
  for(int i=0;i<numGanadores;i++)
      {
        // Si parejasGanadoras[i] tiene valor > 0, habrá que mostrarla.
        if(parejasGanadoras[i]>0)
          printf("Pareja %d: %s - %s\n",parejasGanadoras[i]+1, arrayParejas[parejasGanadoras[i]].integrante1,arrayParejas[parejasGanadoras[i]].integrante2);
      }
      printf("********************\n");
}


int controlarResultados(int a, int b)
{
  if(a != 1 && a != 2 && a != 0
     && b != 1 && b != 2 && b!= 0)
     {
       printf("Error\n");
       return 0;
     }
  if(a +b != 2 && a+b != 3)
  {
    printf("Error\n");
    return 0;
  }
  if(a != 2 && b!=2)
  {
    printf("Error\n");
    return 0;
  }
  return 1;
}