#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

/// VARIABLES DES BOUCLES PRINCIPALES !


/// VARIABLES TEMPS !

int augmenter_temps, temps_initial;
int temps_actuel = 0;
int temps_precedent = 0;

/// VARIABLES GENERATION !

#define LARG_BLOX 30
#define LONG_BLOX 30


    int a=0;
    int ab =0;

    int limite_gen=0;
    int limite_gen2=0;
    int limite_gen3=0;
    int limite_sky=0;

    int gen_x = 0;
    int gen_y = 700;

    int gen_x2 = 0;
    int gen_y2 = 760;

    int gen_x3 = 0;
    int gen_y3 = 790;

    int gen_x4=0;
    int gen_y4=0;

    int gen_x_sky=0;
    int gen_y_sky=0;

    int ciel =1;
    int terre =1;
    int dirt =1;
    int pierre =1;

    int MAX= 7, MIN = 1;



int gravite = 1;
float v_y =0.0;
float lerect = 470.0;

int move_huski = 960;


/// POINTEUR POUR TABLEAUX DE GENERATION !

int *tabentier_x_herbe;
int *tabentier_y_herbe;

int *tabentier_x_under_herbe;
int *tabentier_y_under_herbe;

int *tabentier_x_terre;
int *tabentier_y_terre;

int *tabentier_x_pierre;
int *tabentier_y_pierre;

int *tabentier_x_sky;
int *tabentier_y_sky;


int plus_herbe = 1;
int plus2_herbe = 1;

int plus_under_herbe = 1;
int plus2_under_herbe = 1;

int plus_terre = 1;
int plus2_terre = 1;

int plus_pierre = 1;
int plus2_pierre = 1;

int plus_sky = 1;
int plus2_sky = 1;










