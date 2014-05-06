/*
    Tarea N°1 ILI-135
    Almacenamiento y recuperación de la información
    "El diso blando"

    Barbarita Andrea Lara Martínez
    201021048-0
    Grupo 12
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// prototipos
void menu();
void loadFAT();
void crearBloquesFAT();
void printFAT();
void printBloques();
char* ingresarnom();
int encontrarVacio();
int encontrarIgual();
void guardarFAT();

// globales
typedef struct bloque {
    char nombre[30];
    struct bloque *s;
    struct bloque *ps;
    struct bloque *pa;
} bloque;

typedef struct lector { //  :(
    int pistaActual;
    int sectorActual;
    struct bloque *cabeza;
} lector;

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

char* ingresarnom(){
    int t;
    char *nombre[33];
    char B[33];
    for(t=0; t <2;t++){
        fflush(stdout);
        fgets(B,33,stdin);
        *(nombre + t ) = malloc(strlen(B)+1);
        strcpy(nombre[t],B);
    }
    return(nombre[1]);
}

int encontrarVacio(){ //Retorna indice espacio vacio o -1 si no hay espacio vacio
    int i=0;
    for(i = 0; i < 80; i++) {
        //printf("%p -> %s\n", bloques[i], bloques[i]->nombre);
        if(strcmp(bloques[i]->nombre, "-") == 0) {
            return(i);  

        }

    }
    return(-1);
}
int encontrarIgual(char *name){ //Retorna indice espacio vacio o -1 si no hay espacio vacio
    int i=0;
    for(i = 0; i < 80; i++) {
        //printf("%p -> %s\n", bloques[i], bloques[i]->nombre);
        if(strcmp(bloques[i]->nombre, name) == 0) {
            return(i);  

        }

    }
    return(-1);
}
void guardarFAT(){
    FILE * fp;
    fp=fopen("fat","w");
    int i;
    for(i=0; i<80;i++){
        fprintf(fp,"%s",tablaFAT[i]);
    }
    fclose(fp);
}

void menu() {
    int cmd;
    char *name;

    do {
        printf("+-----------------------+\n");
        printf("|1. Ingresar Datos\t|\n");
        printf("|2. Buscar Archivos\t|\n");
        printf("|3. Eliminar Datos\t|\n");
        printf("|4. Guardar y Salir\t|\n");
        printf("|0. Salir sin guardar\t|\n");
        printf("+-----------------------+\n");
        printf("> ");
        scanf("%d", &cmd);
        if(cmd >= 0 && cmd < 10) {
        switch(cmd) {
            case 0:
                printf("Chao :)\n");
                exit(0);
                break;
            case 1:
                    printf("Estás en Ingresar Datos\n");
                    int i=0;
                    printf("Ingrese nombre del archivo: ");
                    name=ingresarnom();
                    char *nom;
                    char *num;
                    num = strchr(name, ' ');
                    if(num == NULL) {
                        printf("Debe ingresar nombre y cantidad de bloques\n");
                        break;
                    }
                    int is = atoi(num); // indice siguiente
                    if(!(is > 0 && is <= 80)) {
                        printf("Favor indicar un número de bloques entre 1 y 80\n");
                        break;
                    }
                    int p = num - name;
                    nom = (char *)malloc(sizeof(char) * p);
                    strncpy(nom,name,p);
                    //printf("is: %d, nombre: %s\n", is, nom);
                    int m=0;
                    bloque *anterior;
                    char siguiente[33];
                    for(m=0;m<is;m++){
                        i=encontrarVacio();
                       // printf("siguiente vacio: %d\n", i);
                        strcpy(bloques[i]->nombre,nom);
                        if(m == 0) {
                            anterior = bloques[i];
                            strcpy(tablaFAT[i], nom);
                            if(is == 1) {
                                sprintf(siguiente, " eof\n");
                            } else {
                                sprintf(siguiente, " %d\n", encontrarVacio());
                            }
                            strcat(tablaFAT[i], siguiente);
                        } else if(m < is - 1) {
                            anterior->s = bloques[i];
                            anterior = bloques[i];
                            strcpy(tablaFAT[i], "+");
                            sprintf(siguiente, " %d\n", encontrarVacio());
                            strcat(tablaFAT[i], siguiente);
                        } else {
                            anterior->s = bloques[i];
                            bloques[i]->s = NULL;
                            strcpy(tablaFAT[i], "+ eof\n");
                        }
                    }

                    break;
            case 2:
                printf("Estás en Buscar Archivos\n");
                printf("Ingrese el nombre de archivo a buscar: ");
                name=ingresarnom();
                num = strchr(name, '\n');
                int q = num - name;
                nom = (char *)malloc(sizeof(char) * q);
                strncpy(nom,name,q);
                i=encontrarIgual(nom);
                //printf("Se ha encontrado el archivo %s en el bloque %d\n",nom,i);
                if(i >= 0) { // posición encontrada
                    int count=0;
                    bloque *bloquetemp;
                    bloquetemp=bloques[i];
                    while((bloquetemp->s)!= NULL){
                        count++;
                        bloquetemp=bloquetemp->s;
                    }
                    printf("El archivo tiene %d bloques\n", count+1);
                } else { // No se encontró archivo
                    printf("No se encontró el archivo\n");
                }
                break;
            case 3:
                printf("Estás en Eliminar Datos\n");
                printf("Ingrese el nombre de archivo a eliminar: ");
                name=ingresarnom();
                num = strchr(name, '\n');
                int w = num - name;
                nom = (char *)malloc(sizeof(char) * w);
                strncpy(nom,name,w);
                i=encontrarIgual(nom);
                if(i >= 0) { // posición encontrada
                    int count2=0;
                    bloque *bloquetemp2;
                    bloque *temp;
                    bloquetemp2=bloques[i];
                    while((bloquetemp2->s)!= NULL){
                        count2++;
                        strcpy(bloquetemp2->nombre,"-");
                        temp=bloquetemp2;
                        bloquetemp2=bloquetemp2->s;
                        temp->s=NULL;
                        temp->ps=NULL;
                        temp->pa=NULL;
                    }
                    strcpy(bloquetemp2->nombre, "-");
                    bloquetemp2->s=NULL;
                    bloquetemp2->ps=NULL;
                    bloquetemp2->pa=NULL;
                    count2++;

                    // actualizar tabla FAT
                    for(i = 0; i < 80; i++) {
                        if(strcmp(bloques[i]->nombre, "-") == 0) {
                            strcpy(tablaFAT[i], "-\n");
                        }
                    }

                    printf("Se ha borrado el archivo %s junto con %d bloques \n",nom,count2);
                } else {
                    printf("No se encontró el archivo\n");
                }
                break;
            case 4:
                printf("¿Seguro desea guardar los cambios?(s=sí | n=no) ");
                char *resp;
                resp=ingresarnom();
                if(strcmp(resp,"s\n")==0){
                    guardarFAT();
                    exit(0);
                }else{
                    printf("no quiere salir :D\n");
                }

                break;
            case 5:
                printFAT();
                break;
            case 6:
                printBloques();
                break;
            default:
                printf("\n*** Entrada inválida ***\n\n");
                break;
        }
        } else {

                printf("\n*** Entrada inválida ***\n\n");
                break;
        }
    } while(cmd != 0);
}

void loadFAT() {
    FILE *fat = fopen("fat", "rw+");

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
            strcpy(bloques[j]->nombre, nombre);
            bloques[j]->s = NULL;
        }
    }
}

void printFAT() {
    int i;
    for(i = 0; i < 80; i++) {
         printf("%d: %s", i, tablaFAT[i]);
    }
}

void printBloques() {
    int i;
    for(i = 0; i < 80; i++) {
        printf("%d: %s\n", i, bloques[i]->nombre);
    }
}

void crearBloquesFAT() {
    int i;
    for(i = 0; i < 80; i++) {
        bloques[i] = (bloque *)crearBloque("-", NULL, NULL, NULL);
    }
}

int main() {
    loadFAT();
    menu();
    return 0;
}
