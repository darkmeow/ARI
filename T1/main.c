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
//Estructura lector-escritora
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


//_______________________________


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

        //Pasaré la información de la tabla fat a bloques

        bloque *arreglo_bloque[80];
    
    for(j=0;j<i;j++){
        if(arreglo[j]!=NULL){
            arreglo_bloque[j]=crearbloque(arreglo[j],NULL,NULL,NULL);
           // printf("Indice: %d Nombre del Bloque: %s \n",j, arreglo_bloque[j]->nombreArchivo);//creo arreglo de bloques!
        }
    }
    
    //Reconoceré que hay en cada línea
    int m=0;
    
    for(m=0;m<i;m++){
        if(strcmp(arreglo[m],"-\n")==0){
           // printf("ESPACIO VACÍO Posición: %d, Dato: %s \n",j, arreglo[j]);
        }else if(strcmp(arreglo[m],"+ eof\n")==0){

            //printf("ESTO ES UNA LINEA CON EOF Posición: %d, Dato: %s \n",j, arreglo[j]);
        }else if(arreglo[m][0]=='+'){
            //printf("ESTO ES UNA LINEA CON +++ Posición: %d, Dato: %s \n",j, arreglo[j]);
        }else{
                //bloque *nombres[80];//arreglo que guarda bloques enlazados
                char *p;
                int reversa=0;
                char *substring;
                int e=0;
                p= strchr(arreglo[m],' ');
                e= atoi(p);
                //printf("Posición: %d, Número %s \n",j, arreglo[j][p]);
                //printf("Posicion de j: %d, Valor de p:%s, En el atoi:    %d\n",j,p+1,e);
                reversa= p-arreglo[m];
                substring=(char*)malloc(sizeof(char)*reversa);
                strncpy(substring,arreglo[m],reversa);

                //printf("el arreglo de bloque es este: %s \n")
                //printf("atoi(p): %d, p: %s\n", e, p); 
               //     strcpy(arreglo_bloque[m]->nombreArchivo,substring);
               //     arreglo_bloque[m]->bloqueSiguiente=crearbloque(arreglo_bloque[m]->nombreArchivo, arreglo_bloque[e], NULL, NULL);
                 //   strcpy(arreglo_bloque[e]->nombreArchivo,arreglo_bloque[m]->nombreArchivo);

                    /*
                char *valornum;
                int num=0;
                int prueba=0;
                int k=0;
                prueba=e;
                */
                char *valornum;
                int num=0;
                int prueba=0;
                int k=0;
                prueba=e;

                while(strcmp(arreglo[prueba],"+ eof\n")!=0){
                    
                printf("Posición de m: %d, Siguiente indice en fat:%s\n",m,arreglo[prueba]);
                    
                    valornum= strchr(arreglo[prueba],' ');
                    num= atoi(valornum);
                    prueba=num;
                    
                }
                printf("EOF\n");
                k++;
        
        }
}
}

/*
                int k=0;
                int t=0;
                bloque *inicial = arreglo_bloque[0];
                while(inicial->bloqueSiguiente != NULL) {
                    printf("Bloque Inicial %p, nombre: %s\n",&inicial,inicial->nombreArchivo);
                    inicial = inicial->bloqueSiguiente;
                }

*/
 

/*

                //int l=0;
                //while(nombres[l]!=NULL){
                    
                    //printf("%s\n",nombres[l].nombreArchivo);
                //    l++;
                //}
    //printf("%s\n",test->nombreArchivo);
                
                //while(strcmp(arreglo[j]," ")==0);{
                    //while(strcmp(arreglo[j]," ")!=0){
                    //    printf("Posición: %d, Número %s \n",j, arreglo[j]);
                    //}
           // }
            //
            //strcpy(nombres[k],arreglo[j]);
            //printf("Posición: %d, Dato: %s \n",j, nombres[k]);
            
            //k++;*/
     
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
