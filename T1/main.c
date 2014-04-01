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
        printf("+---------------+\n");
        printf("|0. Salir\t|\n");
        printf("+---------------+\n");
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
