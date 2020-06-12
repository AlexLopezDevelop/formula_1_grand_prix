//
// Created by Alex Lopez on 20/05/2020.
//

#include "configuration.h"

void configureCar(Racer * racer, Championship * championship) {
    racerData(racer);

    //Init Allegro
    LS_allegro_init(1000,600,"Configuracion del coche");

    // Screen actions
    int closeWindow = false;
    int currentPiece = 0;
    int currentCategory = 0;
    while(!closeWindow) {

        // Close window
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            closeWindow = true;
        }

        // Piece category
        if (LS_allegro_key_pressed(ALLEGRO_KEY_UP)) {

            if (currentCategory > 0) {
                currentCategory--;
            } else {
                currentCategory = (*(*championship).warehouse).totalCategories - 1;
            }

        }

        if (LS_allegro_key_pressed(ALLEGRO_KEY_DOWN)) {

            if (currentCategory < (*(*championship).warehouse).totalCategories - 1) {
                currentCategory++;
            } else {
                currentCategory = 0;
            }

        }

        // Model piece
        if (LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)) {

            if (currentPiece > 0) {
                currentPiece--;
            } else {
                currentPiece = (*(*championship).warehouse).categories[currentCategory].totalPieces - 1;
            }

        }

        if (LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)) {
            if (currentPiece < (*(*championship).warehouse).categories[currentCategory].totalPieces - 1) {
                currentPiece++;
            } else {
                currentPiece = 0;
            }
        }


        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,60,0,"%s", (*(*championship).warehouse).categories[currentCategory].pieces[currentPiece].name);

        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,80,0,"%s %d","Velocidad: ", (*(*championship).warehouse).categories[currentCategory].pieces[currentPiece].speed);

        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,100,0,"%s %d","Aceleracion: ", (*(*championship).warehouse).categories[currentCategory].pieces[currentPiece].acceleration);
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,120,0,"%s %d","Consumo: ", (*(*championship).warehouse).categories[currentCategory].pieces[currentPiece].consumption);
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,140,0,"%s %d","Fiabilidad: ", (*(*championship).warehouse).categories[currentCategory].pieces[currentPiece].reliability);

        al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),100,200,0,"%s","Neumaticos");
        al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),100,250,0,"%s","Configuracion Actual");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,280,0,"%s","Neumaticos:");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,300,0,"%s","Aero frontal: ");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,320,0,"%s","Aero zona media: ");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,340,0,"%s","Aero posterior: ");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,360,0,"%s","Gasolina: ");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,380,0,"%s","Motor: ");


        //Draw screen
        LS_allegro_clear_and_paint(BLACK);
    }
}