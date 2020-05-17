//
// Created by Alex Lopez on 16/05/2020.
//

#ifndef F1_INTERFACE_H
#define F1_INTERFACE_H

#define MENU_OPTION_EXIT -1
#define MENU_OPTION_1 1
#define MENU_OPTION_2 2
#define MENU_OPTION_3 3
#define MENU_OPTION_4 4
#define MAX_CHAR 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../configuration/configuration.h"

void show_main_menu();
int read_option(int * option);
int switch_option(int * option);

#endif //F1_INTERFACE_H
