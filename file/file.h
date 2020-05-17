//
// Created by Alex Lopez on 16/05/2020.
//

#ifndef F1_FILE_H
#define F1_FILE_H

#define MAX_CHAR 50
#include <stdio.h>
#include <stdbool.h>

void read_txt(char filename[MAX_CHAR]);
int checkFile(char *filename[], int itsBin);

#endif //F1_FILE_H
