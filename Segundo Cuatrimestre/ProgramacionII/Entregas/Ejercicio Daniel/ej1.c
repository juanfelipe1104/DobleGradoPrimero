#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 40

int main(int argc,char **argv)
{
  char opcion='5';
  int contadores[10] = {0};
  char texto[TAM_MAX]={'\0'};
  int cont=0;
  int tamanio=0;
  
  char letra;
  
  //Control de errores numero de argumentos
  if((argc<2) || (argc >11))
  {
    printf("Numero de caracteres incorrectos\n");
    return 0;
  }
  else
  {
    
   //Menu para seleccionar opciones
    while (opcion!='0')
    {
        printf("Para introducir un nuevo texto pulse 1\n");
        printf("Para mostrar el resultado pulse 2\n");
        printf("Para salir pulse 0\n");
        scanf("%c",&opcion);
        //Limpiamos buffer
        while(getchar() != '\n');
        switch(opcion)
      {
        case '1':
        {
         //Leeemos el nuevo texto
        do
        {

          letra=getchar();
          if(cont <TAM_MAX)
          {
            texto[cont] = letra;
          }
          
          cont++;
       
         } while (letra!='\n');
         //Controlamos que el tamaño de la cadena no exceda el limite
         if(cont > 40)
         {
           printf("La cadena es muy larga");
           return 0;
         }
         //Recorremos la cadena y si encuentra alguno de los caracteres a contar suma1 a la posicion en el array
         for(int i=1;i<argc;i++)
          {
            for(int j=0;j<TAM_MAX;j++)
            {
              if(texto[j] == argv[i][0])
                {
                  contadores[i] ++;
                }
            
            }
            
          }
          } 
         break;
        case '2':
        {
          
        //Mostramos por pantalla
         for(int i=1;i<argc;i++)
          {
            printf("Numero de %c es %d\n",argv[i][0],contadores[i]);
          }
         }
         break; 
         default:
         {
           printf("Saliendo");
         }
      }
    }
  }
  return 0;
}



  

