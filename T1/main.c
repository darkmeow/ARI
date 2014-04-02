#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Estructura Bloque
typedef struct bloque{
    char nombreArchivo[30];
    struct bloque* bloqueSiguiente;
    struct bloque* pistaAnterior;
    struct bloque* pistaSiguiente;
}bloque;
//Prototipo lector-escritora
struct lector{
    int pistaActual;
    int sectorActual;
    struct bloque* cabeza;
};

//Fucion para crear bloque
bloque *crearbloque(char nombre[30], struct bloque *next, struct bloque *pa, struct bloque *ps){
    bloque *pb=malloc(sizeof(bloque));
    strcpy(pb->nombreArchivo, nombre);
    pb->bloqueSiguiente=(bloque*) malloc(sizeof(bloque));
    pb->pistaAnterior=(bloque*) malloc(sizeof(bloque));
    pb->pistaSiguiente=(bloque*) malloc(sizeof(bloque));
    pb->bloqueSiguiente=next;
    pb->pistaAnterior=pa;
    pb->pistaSiguiente=ps;
    return pb;
}
//_______________________________---

int fat();
void menu();

int main() {
    fat();
    //struct bloque *test=crearbloque("test",NULL,NULL,NULL);
    //printf("%s\n",test->nombreArchivo);
    menu();
    return 0;
}

int fat(){
    //char *var[80];
    FILE* archivo;
    archivo=fopen("test.txt","r+b");
    int bytes_read;
  int nbytes = 100;
  char *my_string;

  puts ("Please enter a line of text.");

  /* These 2 lines are the heart of the program. */
  my_string = (char *) malloc (nbytes + 1);
  bytes_read = getline (&my_string, &nbytes, archivo);

  if (bytes_read == -1)
    {
      puts ("ERROR!");
    }
  else
    {
      puts ("You typed:");
      puts (my_string);
    } 

}

void menu() {
    int cmd;

    do {
        printf("+-----------------------+\n");
        printf("|1. Ingresar Datos\t|\n");
        printf("|2. Buscar Archivos\t|\n");
        printf("|3. Eliminar Datos\t|\n");
        printf("|4. Calcular Tiempo\t|\n");
        printf("|0. Salir\t\t|\n");
        printf("+-----------------------+\n");
        printf("> ");
        scanf("%d", &cmd);

        switch(cmd) {
            case 0:
                printf("Chao :)\n");
                exit(0);
                break;
            case 1:
                printf("Estás en la opción 1\n");
                break;
            case 2:
                printf("Estás en la opción 2\n");
                break;
            case 3:
                printf("Estás en la opción 3\n");
                break;
            case 4:
                printf("Estás en la opción 4\n");
                break;
            default:
                printf("\n*** Entrada inválida ***\n\n");
                break;
        }
    } while(cmd != 0);
}
