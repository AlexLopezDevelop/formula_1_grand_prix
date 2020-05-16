//
// Created by Alex Lopez on 16/05/2020.
//

#include "interface.h"

int menu_interface() {

    int exit = 0;

    while (!exit) {

        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            exit = 1;
        }

        //Draw screen
        LS_allegro_clear_and_paint(BLACK);

        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,100,0,"%s","Bienvenidos a LS Racing!");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,150,0,"%s","1. Configurar coche");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,170,0,"%s","2. Carrera");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,190,0,"%s","3. Ver clasificacion");
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,210,0,"%s","4. Guardar temporada");
    }
}