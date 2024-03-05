#include <stdio.h>
#include <stdlib.h>
#define MAX_MESAS 5
#define TAM_MAX_INDICE 9

typedef enum materiales_e
{
  plastico,madera,cristal,metal
} materiales_e;

char * tipoMaterial[]={"plastico","madera","cristal","metal"};

typedef struct mesas_t
{
    float ancho;
    float alto;
    float fondo;
    
    float precio;
    int opcion;
  
} mesas_t;

//Funcion que pide los datos de una mesa 
mesas_t introducirMesa(mesas_t mesa);
//Funcion que muestra las mesas
void mostrarMesas(mesas_t arrayMesas[], int numMesas);
//Funcion que calcula el precio
void calcularPrecio (mesas_t arrayMesas[], int numMesas);

int main(int argc,char **argv)
{
    mesas_t mesa;
    mesas_t arrayMesas[MAX_MESAS];
    int opcion, numMesas = 0;
    

    do {
       
        printf("Menu ---\n");
        printf("1- Introducir una nueva mesa\n");
        printf("2- Mostrar las mesas disponibles\n");
        printf("3- Calcular precio pedido\n");
        printf("4- Salir\n");
        printf("Seleccione una opcion: \n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mesa = introducirMesa(mesa);
                arrayMesas[numMesas] = mesa;
                numMesas++;
                break;
            case 2:
                mostrarMesas(arrayMesas, numMesas);
                break;
            case 3:
                calcularPrecio(arrayMesas, numMesas);
                break;
            case 4:
                printf("Saliendo");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while (opcion != 4);

    return 0;
}



mesas_t introducirMesa(mesas_t mesa)
{
    mesas_t mesa1;
    printf("Introduce las características de la mesa:\n");
    printf("Ancho/Alto/Fondo: ");
    while(scanf("%f %f %f", &mesa1.ancho, &mesa1.alto, &mesa1.fondo)!=3)
    {
      getchar();
    }
    printf("Material:\n1-plastico\n2-madera\n3-crsital\n4-metal ");
    while(scanf("%d", &mesa1.opcion)!=1)
    {
      getchar();
    }
    printf("Precio: ");
    while(scanf("%f", &mesa1.precio)!=1)
    {
      getchar();
    }
    return mesa1;    
}

void mostrarMesas(mesas_t arrayMesas[], int numMesas)
{
  for(int i=0;i<numMesas;i++)
  {
    printf("Ancho/Alto/Fondo: \n");
    printf("%.2f %.2f %.2f\n", arrayMesas[i].ancho, arrayMesas[i].alto, arrayMesas[i].fondo);
    printf("%s\n", tipoMaterial[arrayMesas[i].opcion-1]);
    printf("Precio: \n");
    printf("%.2f\n", arrayMesas[i].precio);
  }
}


void calcularPrecio (mesas_t arrayMesas[], int numMesas)
{
  float precio;
  char cadena[TAM_MAX_INDICE];
  int indices[MAX_MESAS];
  int aux;
  printf("Introduce los indices de las mesas juntos sin espacios separados por comas");
  scanf("%s",cadena);
  for(int i=0;i<TAM_MAX_INDICE;i++)
  {
    if(cadena[i]!=',')
    {
      indices[i]=cadena[i]-'0';
    }
    else
    {
      indices[i]=-1;
    }
  }
  for(int i=0;i<MAX_MESAS;i++)
  {
    if(indices[i]==-1)
    {
      aux=0;
    }
    else
    {
      precio = precio + arrayMesas[indices[i]].precio;
    }
  }
  printf("Precio :%.2f\n",precio);
}