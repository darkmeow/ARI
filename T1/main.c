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
        fp=fopen("fat.txt","rw");
        int i;
        for(i=0; i<80;i++){
            fprintf(fp,"%s\n",tablaFAT[i]);
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
                    int is = atoi(num); // indice siguiente
                    int p = num - name;
                    nom = (char *)malloc(sizeof(char) * p);
                    strncpy(nom,name,p);
                    printf("is: %d, nombre: %s\n", is, nom);
                    
                    int m=0;
                    for(m=0;m<is;m++){
                        i=encontrarVacio();
                        strcpy(bloques[i]->nombre,nom);
                    }

                    int r;
                    for(r=0;r<79;r++){ 
                        printf("%p -> %s\n", bloques[r], bloques[r]->nombre);
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
                printf("Se ha encontrado el archivo %s en el bloque %d\n",nom,i);
                int count=0;
                bloque *bloquetemp;
                bloquetemp=bloques[i];
                while((bloquetemp->s)!= NULL){
                    count++;
                    bloquetemp=bloquetemp->s;
                }
                printf("El archivo tiene %d bloques\n", count);
                printBloques();
                
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

                int count2=0;
                bloque *bloquetemp2;
                bloquetemp2=bloques[i];
                while((bloquetemp2->s)!= NULL){
                     count2++;
                    strcpy(bloquetemp2->nombre,"-");
                    bloque *temp;
                    temp=bloquetemp2;
                    bloquetemp2=bloquetemp2->s;
                    temp->s=NULL;
                    temp->ps=NULL;
                    temp->pa=NULL;
                }

                printf("Se ha borrado el archivo %s junto con %d bloques \n",nom,count2);
                printBloques();

                break;
            case 4:
                printf("¿Seguro desea guardar los cambios?(s=sí | n=no) ");
                char *resp;
                int x;
                resp=ingresarnom();
                if(strcmp(resp,"s\n")==0){
                    for(x=0;x<80;x++){
                        strcpy(tablaFAT[x],bloques[x]->nombre);
                    }
                }else{
                    printf("no quiere salir :D\n");
                }

                guardarFAT();
                printFAT();
                break;
            default:
                printf("\n*** Entrada inválida ***\n\n");
                break;
            
        }
    } while(cmd != 0);
}

void loadFAT() {
    FILE *fat = fopen("fat.txt", "rw+");

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
         printf("%s\n", tablaFAT[i]);
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
