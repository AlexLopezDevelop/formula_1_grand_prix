//
// Created by Alex Lopez on 11/06/2020.
//

#ifndef F1_CHAMPIONSHIP_H
#define F1_CHAMPIONSHIP_H

#include "../models/gps.h"
#include "../models/pieces.h"
#include "../models/base.h"
#include "../models/racer.h"

typedef struct {
    Season * season;
    Warehouse * warehouse;
    Base * base;
    Racers * racers;
} Championship;

#endif //F1_CHAMPIONSHIP_H
