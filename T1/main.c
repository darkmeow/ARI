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

FILE* fichero; 
char *arreglo[33];
char *lee; 
int i; 

if( (fichero = fopen("test.txt", "r")) == NULL ){ 
puts("No se pudo abrir el fichero"); 
return 1; 
} 

i = 0; 
while( fscanf(fichero, "%s", lee) != EOF ){ 
    //arreglo[i] = (char*)malloc(sizeof(lee));
    arreglo[i] = lee; 
    ++i; 

} 

fclose( fichero ); 

    puts("Contenido del fichero:"); 
    for(i = 0; i < 5; ++i) 
    printf("%s ", arreglo[i]); 

    return 0; 
    
    /*
    FILE *archivo;
 
 	char caracteres[80];
    char array[80];
    int i=0;
 
 	archivo = fopen("test.txt","r");
 
 	if (archivo == NULL)
 		exit(1);
 
 	//printf("\nEl contenido del archivo de prueba es \n\n");
 	while (feof(archivo) == 0)
 	{
 		fgets(caracteres,80,archivo);
 		printf("Esto es lo que contiene caracteres %s", caracteres);
        	
    }
        fclose(archivo);
        //while((caracteres[i])!="\0"){
          //  array[i]=caracteres[i];
            //array[i]=malloc(sizeof(caracteres[i]);
            //strcpy(array[i],caracteres[i]);
         //   i++;
        //}
    FILE *archivo;
    char caracter[33];
    char cadena[33];
    char *array[80];
    char var[100];
    int i=0;
    archivo = fopen("test.txt","r");
    if(archivo == NULL){
        printf("\nError de Apertura del archivo\n\n");
    }else{
        //printf("\nEl contenido de prueba del archivo es: \n\n");
     
        //while(feof(archivo)==0){    
        while(fscanf(archivo,"%s",var)!=EOF){
        
            //caracter = fgetc(archivo)!= var;
                fgets(var,100,archivo);
                
                if(var[i]!="\n"){

                    cadena[i]=var[i];
                }else{
        
                //(var=(strtok(cadena,"o "));
                
                //fgets(var,33,archivo);

                array[i]=malloc(sizeof(var));
                strcpy(array[i],var);
                printf("\n Este es el valor %d que contiene %s\n",i, array[i]);
                i++;
                }
               
            //}
        
        }
    }
    
    fclose(archivo);
   
   */ 
   

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
