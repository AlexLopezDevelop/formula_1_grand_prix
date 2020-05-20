//
// Created by Alex Lopez on 16/05/2020.
//

#ifndef F1_FILE_H
#define F1_FILE_H

#include "../game.h"
#include <stdio.h>
#include <stdbool.h>

void read_txt(char filename[MAX_CHAR]);
int checkFile(char *filename[], int itsBin);
void loadRacers(char *filename[]);
#endif //F1_FILE_H
