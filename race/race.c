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

}