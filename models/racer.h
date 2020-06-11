//
// Created by Alex Lopez on 17/05/2020.
//

#ifndef F1_RACER_H
#define F1_RACER_H

#define MAX_CHAR 25

typedef struct {
    char name[MAX_CHAR];
    int dorsal;
    char team[MAX_CHAR];
    int speed;
    int acceleration;
    int consumption;
    int flexibility;
    int reflexes;
    int physicalCondition;
    int temperament;
    int tireManagement;
}Racer;

#endif //F1_RACER_H