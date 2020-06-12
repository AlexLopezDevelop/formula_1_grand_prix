//
// Created by Alex Lopez on 12/06/2020.
//

#include "race.h"

void initView(Championship * championship) {
    int currentSeason = (*(*championship).season).currentCalendarPosition;

    if (currentSeason < (*(*championship).season).totalGps) {
        printf("\nPreparando carrera #%d: %s\n", currentSeason + 1, (*(*championship).season).gps[currentSeason].name);

        int closeWindow = false;

        // user onclick keys
        while(!closeWindow) {

            // Close window
            if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
                closeWindow = true;
            }


            al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),100,40,0,"%s %s","Bienvenido a ", (*(*championship).season).gps[currentSeason].name);
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,70,0,"%s %d","Velocidad:", (*(*championship).season).gps[currentSeason].properSpeed);
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,90,0,"%s %d","Aceleracion: ", (*(*championship).season).gps[currentSeason].properAcceleration);
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,110,0,"%s %d","Consumo: ", (*(*championship).season).gps[currentSeason].properConsumption);
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,130,0,"%s %d","Fiabilidad: ", (*(*championship).season).gps[currentSeason].properFlexibility);
            al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),100,160,0,"%s","Pulsa R para comenzar la carrera");


            //Draw screen
            LS_allegro_clear_and_paint(BLACK);
        }


    } else {
        printf("\nYa has finalizado la temporada\n");
    }

}

void trafficLight() {
    int closeWindow = false;

    clock_t begin;
    double time_spent;
    /* Mark beginning time */
    begin = clock();

    // user onclick keys
    while(!closeWindow) {



        // Close window
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            closeWindow = true;
        }


        time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;

        // on
        if (time_spent>=0.1) {
            al_draw_filled_circle (150, 150, 50, LS_allegro_get_color(RED));
            al_draw_filled_circle (150, 300, 50, LS_allegro_get_color(RED));
        }

        if (time_spent>=0.2) {
            al_draw_filled_circle (300, 150, 50, LS_allegro_get_color(RED));
            al_draw_filled_circle (300, 300, 50, LS_allegro_get_color(RED));
        }

        if (time_spent>=0.3) {
            al_draw_filled_circle (450, 150, 50, LS_allegro_get_color(RED));
            al_draw_filled_circle (450, 300, 50, LS_allegro_get_color(RED));
        }

        if (time_spent>=0.4) {
            al_draw_filled_circle (600, 150, 50, LS_allegro_get_color(RED));
            al_draw_filled_circle (600, 300, 50, LS_allegro_get_color(RED));
        }

        if (time_spent>=0.5) {
            al_draw_filled_circle (750, 150, 50, LS_allegro_get_color(RED));
            al_draw_filled_circle (750, 300, 50, LS_allegro_get_color(RED));
        }

        // off

        if (time_spent>=0.7) {
            al_draw_filled_circle (150, 150, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (150, 300, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (300, 150, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (300, 300, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (450, 150, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (450, 300, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (600, 150, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (600, 300, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (750, 150, 50, LS_allegro_get_color(BLACK));
            al_draw_filled_circle (750, 300, 50, LS_allegro_get_color(BLACK));
        }

        if (time_spent>=0.75) {
            closeWindow = true;
        }

        //Draw screen
        LS_allegro_clear_and_paint(BLACK);
    }
}

int startRace(Championship * championship, Player * player) {

    // check if car its configured
    if ((*(*(*player).car).engine).name == NULL) {
        printf("\nAun no has configurado el coche\n");
        return 1;
    }

    initView(championship);
    trafficLight();

    int currentSeason = (*(*championship).season).currentCalendarPosition;
    int seasonSpeed = (*(*championship).season[currentSeason].gps).properSpeed;
    int seasonAcceleration = (*(*championship).season[currentSeason].gps).properAcceleration;
    int seasonConsumption = (*(*championship).season[currentSeason].gps).properConsumption;
    int seasonFlexibility = (*(*championship).season[currentSeason].gps).properFlexibility;
    int totalRacers = (*(*championship).racers).totalRacers;

    Racers * racersSeason;
    Racer * racerSeason;

    // create racers with season data
    for (int i = 0; i < totalRacers; ++i) {

        if (i == 0) {
            racerSeason = malloc(sizeof(Racer));
        } else {
            racerSeason = (Racer *) realloc(racerSeason, sizeof(Racer));
        }

        racerSeason[i].speed = seasonSpeed - (*(*championship).racers).racer[i].speed;
        racerSeason[i].acceleration = seasonAcceleration - (*(*championship).racers).racer[i].speed;
        racerSeason[i].consumption = seasonConsumption - (*(*championship).racers).racer[i].consumption;
        (*racerSeason).flexibility = seasonFlexibility - (*(*championship).racers).racer[i].flexibility;
        strcpy(racerSeason[i].name, (*(*championship).racers).racer[i].name);
        strcpy(racerSeason[i].team, (*(*championship).racers).racer[i].team);
        racerSeason[i].dorsal = (*(*championship).racers).racer[i].dorsal;
        racerSeason[i].physicalCondition = (*(*championship).racers).racer[i].physicalCondition;
        racerSeason[i].reflexes = (*(*championship).racers).racer[i].reflexes;
        racerSeason[i].temperament = (*(*championship).racers).racer[i].temperament;
        racerSeason[i].tireManagement = (*(*championship).racers).racer[i].tireManagement;

    }

    // add player
    racerSeason = realloc(racerSeason, sizeof(Racer));

    racerSeason[totalRacers + 1].speed = seasonSpeed - (*(*player).racer).speed;
    racerSeason[totalRacers + 1].acceleration = seasonAcceleration - (*(*player).racer).speed;
    racerSeason[totalRacers + 1].consumption = seasonConsumption - (*(*player).racer).consumption;
    racerSeason[totalRacers + 1].flexibility = seasonFlexibility - (*(*player).racer).flexibility;
    strcpy(racerSeason[totalRacers + 1].name, (*(*player).racer).name);
    strcpy(racerSeason[totalRacers + 1].team, (*(*player).racer).team);
    racerSeason[totalRacers + 1].dorsal = (*(*player).racer).dorsal;
    racerSeason[totalRacers + 1].physicalCondition = (*(*player).racer).physicalCondition;
    racerSeason[totalRacers + 1].reflexes = (*(*player).racer).reflexes;
    racerSeason[totalRacers + 1].temperament = (*(*player).racer).temperament;
    racerSeason[totalRacers + 1].tireManagement = (*(*player).racer).tireManagement;

    // add all players
    racersSeason = malloc(sizeof(Racers));
    (*racersSeason).racer = racerSeason;
    (*racersSeason).totalRacers = (*(*championship).racers).totalRacers + 1;

}