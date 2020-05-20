//
// Created by Alex Lopez on 17/05/2020.
//

#ifndef F1_GAME_H
#define F1_GAME_H

#define MAX_CHAR 25
#define TOTAL_ARGS 5

#include <stdio.h>
#include <stdbool.h>
#include "LS_allegro.h"
#include "./interface/interface.h"
#include "./file/file.h"

void startGame(int argc, char *argv[]);
int checkArgs(int argc, char *argv[]);

#endif //F1_GAME_H
