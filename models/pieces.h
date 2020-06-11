//
// Created by Alex Lopez on 20/05/2020.
//

#ifndef F1_PIECES_H
#define F1_PIECES_H

#include "../game.h"

typedef struct {
    char name[MAX_CHAR];
    int speed;
    int acceleration;
    int consumption;
    int reliability;
} Piece;

typedef struct {
    char name[MAX_CHAR];
    int totalPieces;
    Piece *pieces;
} Category;

typedef struct {
    int totalCategories;
    Category *categories;
} Warehouse;

#endif //F1_PIECES_H
