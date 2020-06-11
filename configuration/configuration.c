//
// Created by Alex Lopez on 20/05/2020.
//

#include "configuration.h"

void configureCar(Racer * racer, Warehouse * warehouse) {
    racerData(racer);

    //Init Allegro
    LS_allegro_init(1000,600,"Configuracion del coche");

    // Screen actions
    int closeWindow = false;
    while(!closeWindow) {

        // Close window
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            closeWindow = true;
        }

        // Piece category
        if (LS_allegro_key_pressed(ALLEGRO_KEY_UP)) {
            printf("\narriba\n");
        } else if (LS_allegro_key_pressed(ALLEGRO_KEY_DOWN)) {
            printf("\nabajo\n");
        }

        // Model piece
        if (LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)) {
            printf("\nizquierda\n");
        } else if (LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)) {
            printf("\nderecha\n");
        }


        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,60,0,"%s", (*warehouse).categories[0].pieces[0].name);
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,100,0,"%s","Velocidad: ");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,150,0,"%s","Aceleracion: ");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,170,0,"%s","Consumo: ");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,190,0,"%s","Fiabilidad: ");

        al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),100,250,0,"%s","Neumaticos");
        al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),100,270,0,"%s","Configuracion Actual");
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