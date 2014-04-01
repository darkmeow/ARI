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
                exit(0);
                break;
            default:
                printf("\n*** Entrada inválida ***\n\n");
                break;
        }
    } while(cmd != 0);
}
