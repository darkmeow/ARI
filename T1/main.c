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

void fat();
void menu();

int main() {
    fat();
    //struct bloque *test=crearbloque("test",NULL,NULL,NULL);
    //printf("%s\n",test->nombreArchivo);
    menu();
    return 0;
}

void fat(){
    FILE* archivo;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *arreglo[80];
    char *nombres[80];

    int i,j=0;
    archivo = fopen("test.txt", "r");
    if (archivo == NULL)
        exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, archivo)) != -1) {
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
        arreglo[i]=(char*)malloc(sizeof(read));//asignar el espacio que ocupa read a la posicion del arreglo
        strcpy(arreglo[i],line);//copio el contenido de line en el arreglo
        //printf("%s se llena\n",arreglo[i]);
        i++;
    }
        free(line); //libero el buffer

    for(j=0;j<i;j++){

        if(strcmp(arreglo[j],"-\n")==0){
           // printf("ESPACIO VACÍO Posición: %d, Dato: %s \n",j, arreglo[j]);
        }else if(strcmp(arreglo[j],"+ eof\n")==0){

            //printf("ESTO ES UNA LINEA CON EOF Posición: %d, Dato: %s \n",j, arreglo[j]);
        }else if(arreglo[j][0]=='+'){
            //printf("ESTO ES UNA LINEA CON +++ Posición: %d, Dato: %s \n",j, arreglo[j]);
        }else{
           
            int k=0;
            nombres[k]=(char*)malloc(sizeof(read));
            strcpy(nombres[k],arreglo[j]);
            printf("Posición: %d, Dato: %s \n",j, nombres[k]);
            k++;
        }
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
