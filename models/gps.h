//
// Created by Alex Lopez on 17/05/2020.
//

#ifndef F1_GPS_H
#define F1_GPS_H

#include "../game.h"

typedef struct {
    int calendarPosition;
    char name[MAX_CHAR];
    int properSpeed;
    int properAcceleration;
    int properConsumption;
    int properFlexibility;
    float baseTime;
    int pitStopTime;
    int pitStopNum;
} Gps;

typedef struct {
    int totalGps;
    int currentCalendarPosition;
    Gps * gps;
} Season;

#endif //F1_GPS_H
