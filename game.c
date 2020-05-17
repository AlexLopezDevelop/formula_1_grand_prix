//
// Created by Alex Lopez on 17/05/2020.
//

#include "game.h"

void startGame() {
    printf("\nCreated by cristianalex.lopez\n");
    printf("\nBienvenidos a LS Racing!\n");

    int * option = 0;
    int endGame = false;

    while(!endGame){

        int correctInput = 0;

        while (!correctInput) {
            show_main_menu();
            correctInput = read_option((int *) &option);
        }

        endGame = switch_option((int *) &option);
    }
}

int checkArgs(int argc, char *argv[]) {

    if((int) argc != TOTAL_ARGS) {
        printf("Error. El programa tiene que recibir 4 argumentos.");
        return 1;
    }

    // txt file 1
    int fileStatus = checkFile(argv[1], false);
    if (fileStatus == 1) {
        printf("\nError. Ha ocurrido un error durante el procesamiento de los ficheros.\n");
        return 1;
    } else if (fileStatus == 2) {
        printf("\nError. Hay un fichero vacio.\n");
        return 1;
    }

    // txt file 2
    fileStatus = checkFile(argv[2], false);
    if (fileStatus == 1) {
        printf("\nError. Ha ocurrido un error durante el procesamiento de los ficheros.\n");
        return 1;
    } else if (fileStatus == 2) {
        printf("\nError. Hay un fichero vacio.\n");
        return 1;
    }

    // txt file 3
    fileStatus = checkFile(argv[3], true);
    if (fileStatus == 1) {
        printf("\nError. Ha ocurrido un error durante el procesamiento de los ficheros.\n");
        return 1;
    } else if (fileStatus == 2) {
        printf("\nError. Hay un fichero vacio.\n");
        return 1;
    }

    // txt file 4
    fileStatus = checkFile(argv[4], true);
    if (fileStatus == 1) {
        printf("\nError. Ha ocurrido un error durante el procesamiento de los ficheros.\n");
        return 1;
    } else if (fileStatus == 2) {
        printf("\nError. Hay un fichero vacio.\n");
        return 1;
    }

    return 0;
}