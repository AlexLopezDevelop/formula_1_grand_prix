//
// Created by Alex Lopez on 16/05/2020.
//

#include "interface.h"

void showMainMenu() {
    printf("\n");
    printf("     1. Configurar coche\n");
    printf("     2. Carrera\n");
    printf("     3. Ver clasificatoria\n");
    printf("     4. Guardar temporada\n");
    printf("\nQue opcion quieres ejecutar? ");
}

int readOption(int * option) {

    fflush(stdin);

    // Get user option
    char userInput[MAX_CHAR];
    scanf("%s", (char *) &userInput);

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

int switchOption(int * option) {

    switch (*option) {

        case MENU_OPTION_EXIT:
            printf("\nHasta pronto!\n");
            return 1;

        case MENU_OPTION_1:
            configureCar();
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

void pilotData() {

    Racer racer;
    char userInput[MAX_CHAR];
    bool correctInput = false;

    while (!correctInput) {
        fflush(stdin);
        printf("\nNombre del piloto? ");
        scanf("%s", (char *) &userInput);
        if (strlen(userInput) <= MAX_CHAR) {
            strcpy(racer.name, userInput);
            correctInput = true;
        } else {
            printf("\nError, el tamaño maximo es de 25 caracteres\n");
        }
    }


}
