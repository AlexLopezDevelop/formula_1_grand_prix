//
// Created by Alex Lopez on 16/05/2020.
//

#ifndef F1_FILE_H
#define F1_FILE_H

#define START_CALENDAR_POSITION 0 // Starts in season 1

#include "../game.h"
#include "../models/pieces.h"
#include "../models/gps.h"
#include "../models/racer.h"
#include "../models/base.h"
#include <stdio.h>
#include <stdbool.h>

int checkFile(char *filename, int itsBin);
void loadPieces(char *filename, Championship * championship);
void loadGPs(char *fileName, Season * season);
void loadRacers(char *filename, Championship * championship);
void loadBase(char *fileName, Base * base);
#endif //F1_FILE_H
