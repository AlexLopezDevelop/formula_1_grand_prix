#define TOTAL_ARGS 5

#include <stdio.h>
#include "./interface/interface.h"
#include "LS_allegro.h"
#include "file/file.h"

int main(int argc, char *argv[]){

    int nSortir = 0;

    //Inicialitzem Allegro
    LS_allegro_init(1000,600,"Projecte 2");


    //Bucle infinit del joc
    while(!nSortir){

        //Escoltem el teclat esperant la tecla ESC
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }

        //Draw screen
        LS_allegro_clear_and_paint(BLACK);

        if((int) argc != TOTAL_ARGS) { // Check arguments

            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,80,0,"%s","Error. El programa tiene que recibir 4 argumentos.");
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,100,0,"%s","Pulsa ESC para salir.");

        } else { // Check files

            int checkFile1 = check_file("fitxerGPs.txt", false);
            int checkFile2 = check_file("fitxerPeces.txt", false);

            if (checkFile1 == 1 || checkFile2 == 1) {
                al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,80,0,"%s","Error. Ha ocurrido un error durante el procesamiento de los ficheros.");
                al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,100,0,"%s","Pulsa ESC para salir.");
            } else if (checkFile1 == 2 || checkFile2 == 2) {
                al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,80,0,"%s","Error. Hay un fichero vacio.");
                al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),100,100,0,"%s","Pulsa ESC para salir.");
            } else {
                menu_interface();
            }
        }
    }

    //Tanquem la finestra gràfica
    LS_allegro_exit();



    return 0;
}
