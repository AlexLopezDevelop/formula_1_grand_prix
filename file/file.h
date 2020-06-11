//
// Created by Alex Lopez on 16/05/2020.
//

#ifndef F1_FILE_H
#define F1_FILE_H

#include "../game.h"
#include "../models/pieces.h"
#include "../models/gps.h"
#include "../models/racer.h"
#include <stdio.h>
#include <stdbool.h>

void read_txt(char filename[MAX_CHAR]);
int checkFile(char *filename[], int itsBin);
void loadPieces(char *filename[], Warehouse * warehouse);
void loadGPs(char *fileName[], Season * season);
void loadRacers(char *filename[], Racer * racers);
void loadBase(char *fileName[]);
#endif //F1_FILE_H
