



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TAM_MAX 40


//Tipo de arma
typedef enum arma_e
{
  lanza =1,
  espadas=0
} arma_e;

char * arma[]={"espada","lanza"};


//Personajes
typedef struct luchador_t
{
  char nombre[10];
  int ataque;
  int salud;
  int def;
  int eleccion;
  arma_e tipoArma;
} luchador_t;

//Funncion que rellena los paramteros de un personja een funcion de los parameteros
luchador_t crearLuchadores(char **argv,int desde);
//Funcion para comparar cadenas para seleccionar el tipo de armas
int compararCadenas(char cadena1[], char cadena2[]);



int main(int argc,char **argv)
{
  if(argc-1!=2)
  {
    printf("Numero de parametros incorrectos");
    return 0;
  }
  srand(getpid());
  int accionUser;
  int salir=-1;
  int accionMaquina=0;
  printf("Bienvenido a lucha de gladiadores\n");
  
  luchador_t gladiador;
  luchador_t maquina;
  gladiador = crearLuchadores(argv,1);
  maquina = crearLuchadores(argv,2);
  do
  {
    
  
  
    printf("Turno de %s \n",gladiador.nombre);
    printf("Elige tu accion\n");
    printf("1-Atacar,0-Defender\n");
    scanf("%d",&accionUser);
    
    switch(accionUser)
    {
      
      case 1:
      
      printf("Atacas a %s y le haces %d danio\n",maquina.nombre,gladiador.ataque);
      maquina.salud-=gladiador.ataque;///maquina.def;
      
      
      if(maquina.salud<=0)
      {
        
        salir=1;
        
      }
      break;
      
      case 2:
      printf("Te defiendes\n");
      maquina.def*=2;
      break;
    }
    
    printf("Turno de la maquina\n");
    accionMaquina=rand()%2+1;
    switch(accionMaquina)
    {
      
      case 1:
      printf("Atacas a %s y le haces %d danio\n",gladiador.nombre,maquina.ataque);
      gladiador.salud-=maquina.ataque;///gladiador.def;
      
      if(gladiador.salud<=0)
      {
        salir=3;
      }
      break;
      case 2:
      printf("Te defiendes");
      maquina.def*=2;
      break;
    }
  }while(salir==-1);
    printf("\n\n");
    //En funcion de por donde salga se quien ha ganado
    if(salir==1)
    {
      printf("Ganaste %s\n",gladiador.nombre);
      printf("Tipo de Arma :%s\n",arma[gladiador.eleccion]);
      printf("Fuerza: %d\n",gladiador.ataque);
      printf("Salud: %d\n",gladiador.salud);
    }
    else if(salir==3)
    {
      printf("Perdiste, ha ganado %s\n",maquina.nombre);
      printf("Tipo de Arma: %s\n ",arma[maquina.eleccion]);
      printf("Fuerza: %d\n",maquina.ataque);
      printf("Salud: %d\n",maquina.salud);
    } 
  
}

luchador_t crearLuchadores(char **argv,int desde)
{
 
  luchador_t personaje;
  int primerComa=0;
  int segundoComa=0;
  int tercerComa=0;
  char fuerza[TAM_MAX]={'\0'};
  char arma[TAM_MAX];
  int cont=0;
  char cadena[TAM_MAX];
  char espadas[]="espada";
  
 
    do
    {
      cadena[cont] = argv[desde][cont];
      if (cadena[cont]=='\0') {
        
      }
      
      if(cadena[cont]== ',')
      {
        
        if(primerComa==0)
        {
          primerComa = cont;
         
        }
        else if (segundoComa ==0)
        {
          segundoComa= cont;
          
        }
      }
      cont++;
    } while (cadena[cont-1] != '\0');
      int final = cont;
       
      cadena[cont]='\0';      
 
  cont=0;
  for(int i=0;i<primerComa;i++)
  {
    personaje.nombre[cont]=cadena[i];
    cont++;
  }
  
  personaje.nombre[cont]='\0';
  
  
  cont=0;
  for(int i=primerComa+1;i<segundoComa;i++)
  {
    fuerza[cont]= cadena[i];
    cont++;
  }
  fuerza[cont]='\0';
 
  personaje.ataque= atoi(fuerza);
  
  cont=0;
  for(int i=segundoComa+1;i<final;i++)
  {
    
    arma[cont]=cadena[i];
    cont++;
  }
  
  arma[cont]='\0';
  

  
  
  if(compararCadenas(arma,espadas))
  {
    personaje.eleccion=0;
    
  }
  else
  {
    personaje.eleccion=1;
    personaje.ataque*=2;
  }
  
  personaje.salud =100;
  
  return personaje;
  
 
}

int compararCadenas(char cadena1[], char cadena2[]) 
{
    int i=0;
     while (cadena1[i] != '\0' && cadena2[i] != '\0') {
       if (cadena1[i] != cadena2[i]) {
         return 0;
       }
       i++;
     }
      
      
      return 1;
 

}

