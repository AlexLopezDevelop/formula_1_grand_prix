//
// Created by Alex Lopez on 16/05/2020.
//
#include "file.h"

int check_file(char filename[MAX_CHAR], int itsBin) {
    FILE * file;

    // Check can open
    if (itsBin) {
        file = fopen(filename, "rb");
    } else {
        file = fopen(filename, "r");
    }

    if (file == NULL) {
        return 1;
    }

    // Check no void file
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

void read_txt(char filename[MAX_CHAR]) {
    FILE *file = NULL;
    char line[MAX_CHAR];

    if (check_file(filename, false)) {
        printf("\nError al abrir el fichero: %s\n", filename);
    } else {

        file = fopen(filename, "r");

        while (!feof(file)) {
            fscanf(file, "%s", line);
        }

        fclose(file);
    }
}