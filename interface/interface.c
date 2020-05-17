//
// Created by Alex Lopez on 16/05/2020.
//

#include "interface.h"

void show_main_menu() {
    printf("\n");
    printf("     1. Configurar coche\n");
    printf("     2. Carrera\n");
    printf("     3. Ver clasificatoria\n");
    printf("     4. Guardar temporada\n");
    printf("\nQue opcion quieres ejecutar? ");
}

int read_option(int * option) {

    fflush(stdin);

    // Get user option
    char userInput[MAX_CHAR];
    scanf("%s", &userInput);

    // check exit case
    if (strcmp(userInput, "exit") == 0) {
        *option = -1;
        return 1;

    } else { // check if its number
        // TODO: Loop for more digits, HARDCODED for just one
        if (strlen(userInput) == 1) {
            if (isdigit(userInput[0])) {
                *option = atoi(userInput);
                return 1;
            }
        }
    }

    printf("\nError. Opcion no valida.\n");
    return 0;
}

int switch_option(int * option) {

    switch (*option) {

        case MENU_OPTION_EXIT:
            printf("\nHasta pronto!\n");
            return 1;

        case MENU_OPTION_1:
            //configure_car();
            return 0;

        case MENU_OPTION_2:

            return 0;

        case MENU_OPTION_3:

            return 0;

        case MENU_OPTION_4:

            return 0;

        default:
            printf("\nError. Opcion no valida.\n");
            return 0;
    }

}