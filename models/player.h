//
// Created by Alex Lopez on 12/06/2020.
//

#ifndef F1_PLAYER_H
#define F1_PLAYER_H

#include "racer.h"
#include "car.h"

typedef struct {
    Racer * racer;
    Car * car;
} Player;

#endif //F1_PLAYER_H
