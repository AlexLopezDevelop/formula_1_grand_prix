//
// Created by Alex Lopez on 21/05/2020.
//

#include "race.h"

int checkRaceStart(Racer * racer) {
    // Check configured car
    if (strlen(racer->name) > 0) {
        printf("\nAun no has configurado el coche\n");
        return 1;
    }
}

int startRace(Racer * racer) {
    int runRace = checkRaceStart(racer);
    if (runRace == 1 || runRace == 2) {
        return 1;
    }
}