#include <stdlib.h>
#include <stdio.h>

void fat();
void menu();

int main() {
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
                printf("estás en la opción 1\n");
                break;
            case 2:
                printf("estás en la opción 2\n");
                break;
            case 3:
                printf("estás en la opción 3\n");
                break;
            case 4:
                printf("estás en la opción 4\n");
                break;
            default:
                printf("\n*** Entrada inválida ***\n\n");
                break;
        }
    } while(cmd != 0);
}
