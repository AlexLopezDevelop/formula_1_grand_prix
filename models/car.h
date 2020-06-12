//
// Created by Alex Lopez on 12/06/2020.
//

#ifndef F1_CAR_H
#define F1_CAR_H

#include "pieces.h"

typedef struct {
    Piece * tires;
    Piece * aeroFront;
    Piece * aeroMiddleZone;
    Piece * aeroBack;
    Piece * petrol;
    Piece * engine;
} Car;

#endif //F1_CAR_H
