//
// Created by Alex Lopez on 12/06/2020.
//

#include "race.h"

int startRace(Championship * championship, Player * player) {

    // check if car its configured
    if ((*(*(*player).car).engine).name == NULL) {
        printf("\nAun no has configurado el coche\n");
        return 1;
    }

    int currentSeason = (*(*championship).season).currentCalendarPosition;

    if (currentSeason < (*(*championship).season).totalGps) {
        printf("\nPreparando carrera #%d: %s\n", currentSeason + 1, (*(*championship).season).gps[currentSeason].name);
    } else {
        printf("\nYa has finalizado la temporada\n");
    }


}