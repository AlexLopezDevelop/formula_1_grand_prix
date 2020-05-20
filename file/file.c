//
// Created by Alex Lopez on 16/05/2020.
//
#include "file.h"

int checkFile(char *filename[], int itsBin) {
    FILE * file;

    // Check can open
    if (itsBin) {
        file = fopen(*filename, "rb");
    } else {
        file = fopen(*filename, "r");
    }

    if (file == NULL) {
        return 1;
    }

    // Check empty file
    int size = 0;
    if(file!=NULL) {
        fseek (file, 0, SEEK_END);

        size = ftell (file);
        rewind(file);
    }

    if (size==0) {
        return 2;
    }

    // Valid file
    fclose(file);
    return 0;
}

void loadRacers(char *fileName[]) {
    FILE *file = NULL;
    char line[MAX_CHAR];

    printf("\n%s\n", (char *) fileName);

    if (checkFile(fileName, false)) {
        printf("\nError al abrir el fichero: %s\n", (char *) fileName);
    } else {

        file = fopen(*fileName, "rb");

        while (!feof(file)) {
            fscanf(file, "%s", line);
            printf("\n%s\n", line);
        }

        fclose(file);
    }
}