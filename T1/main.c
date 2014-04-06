#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// prototipos
void menu();
void loadFAT();
void crearBloquesFAT();
void printFAT();
void printBloques();

// globales
typedef struct bloque {
    char nombre[30];
    struct bloque *s;
    struct bloque *ps;
    struct bloque *pa;
} bloque;

char *tablaFAT[80]; // tabla FAT como strings

bloque *bloques[80]; // tabla FAT como structs bloque

struct bloque *crearBloque(char nombre[30], struct bloque *siguiente, struct bloque *pistaAnterior, struct bloque *pistaSiguiente) {
    bloque *bloqueNuevo = (bloque*) malloc(sizeof(bloque));
    bloqueNuevo->s = (bloque*) malloc(sizeof(bloque));
    bloqueNuevo->ps = (bloque*) malloc(sizeof(bloque));
    bloqueNuevo->pa = (bloque*) malloc(sizeof(bloque));
    strcpy(bloqueNuevo->nombre, nombre);
    bloqueNuevo->s = siguiente;
    bloqueNuevo->ps = pistaSiguiente;
    bloqueNuevo->pa = pistaAnterior;
    return bloqueNuevo;
}

int main() {
    loadFAT();
    //printFAT();
    //printBloques();
    menu();
    return 0;
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
                printf("Estás en la Ingresar Datos\n");
                int i;
                int str;
                for(i = 0; i < 80; i++) {
                //printf("%p -> %s\n", bloques[i], bloques[i]->nombre);
                printf("Línea: %d -> %s\n", i, bloques[i]->nombre);
                }
                printf("Dónde desea ingresar su archivo? ");
                scanf("%d",&str);
                printf("Lo que ingreso es: %d\n", str);
                printf("El valor en el arreglo es: %s\n", bloques[str]->nombre);      

                if(strcmp(bloques[str]->nombre, "-\n") == 0){
                    printf("es un espacio vacío %s\n",bloques[str]->nombre);
                }else if(strcmp(bloques[str]->nombre, "+ eof\n") == 0){
                    printf("corresponde a un eof %s\n",bloques[str]->nombre);
                }else if(bloques[str]->nombre[0] == '+' ){

                    printf("Es un + %s\n", bloques[str]->nombre);
                
                }else{//entonces es nombre y se debe borrar todos sus bloques
                    printf("Es un nombre %s\n", bloques[str]->nombre);

                }
/*
                char *aux;
                char *num;
                num = strchr(bloques[i], ' ');
                int is = atoi(num); // indice siguiente
                int p = num - bloques[i];
                aux = (char *)malloc(sizeof(char) * p);
                strncpy(aux,bloques[i],p);
                //printf("is: %d, nombre: %s\n", is, nombre);
                strcpy(bloques[i]->nombre, nombre);
                int j = is;
                bloques[i]->s = bloques[j];
                while(!strcmp(bloques[j], "+ eof\n") == 0) {
                    strcpy(bloques[j]->nombre, nombre);
                    num = strchr(bloques[j], ' ');
                    bloques[j]->s = bloques[atoi(num)];
                    j = atoi(num); // indice siguiente
                }
            }

  */             
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

void loadFAT() {
    FILE *fat = fopen("test.txt", "rw+");

    if(fat == NULL) {
        printf("ERROR: no se puede leer la tabla FAT\n");
        exit(-1);
    }

    ssize_t read; // bytes leidos por getline
    size_t len = 0; // tamaño leido por getline
    char *line = NULL; // string con la linea leida

    int i = 0; // indice de linea
    // leer la tabla FAT linea por linea
    while((read = getline(&line, &len, fat)) != -1) {
        tablaFAT[i] = (char *)malloc(sizeof(read)); // reservar memoria para el string
        strcpy(tablaFAT[i], line); // copiar la linea a la tabla FAT
        i++; // incrementar indice
    }
    free(line); // liberar memoria

    crearBloquesFAT();

    for(i = 0; i < 80; i++) {
        if( !(strcmp(tablaFAT[i], "-\n") == 0 ||
            strcmp(tablaFAT[i], "+ eof\n") == 0 ||
            tablaFAT[i][0] == '+' )) { // si es nombre

            //printf("nombre: %s", tablaFAT[i]);

            char *nombre;
            char *num;
            num = strchr(tablaFAT[i], ' ');
            int is = atoi(num); // indice siguiente
            int p = num - tablaFAT[i];
            nombre = (char *)malloc(sizeof(char) * p);
            strncpy(nombre,tablaFAT[i],p);
            //printf("is: %d, nombre: %s\n", is, nombre);
            strcpy(bloques[i]->nombre, nombre);
            int j = is;
            bloques[i]->s = bloques[j];
            while(!strcmp(tablaFAT[j], "+ eof\n") == 0) {
                strcpy(bloques[j]->nombre, nombre);
                num = strchr(tablaFAT[j], ' ');
                bloques[j]->s = bloques[atoi(num)];
                j = atoi(num); // indice siguiente
            }
        }

    }
}

void printFAT() {
    int i = 0;
    while(tablaFAT[i] != NULL) {
        printf("%s", tablaFAT[i]);
        i++;
    }
}

void printBloques() {
    int i;
    for(i = 0; i < 80; i++) {
        printf("%p -> %s\n", bloques[i], bloques[i]->nombre);
    }

   // bloque *b = bloques[71];
    //printf("\n---\n");
    //printf("%p -> %s -> %p\n", b, b->nombre, b->s);
    //while(b->s != NULL) {
      //  printf("%p -> %s\n", b, b->nombre);
        //b = b->s;
    //}
}

void crearBloquesFAT() {
    int i;
    for(i = 0; i < 80; i++) {
        bloques[i] = (bloque *)crearBloque("-", NULL, NULL, NULL);
    }
}
