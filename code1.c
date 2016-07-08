#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include <stdlib.h>
#include "variables.h"


int main(int argc, char** argv)
{


    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(IMG_INIT_PNG);
    SDL_Init(IMG_INIT_JPG);
    TTF_Init();


   /// int continuer=1;
    SDL_Event event;
    SDL_Event quitter;
    SDL_TimerID timer;
    SDL_Window *fenetre1 = NULL;
    SDL_Surface * iconne = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/ICON.PNG");


    /* VARIABLE UTILISEE POUR MC2PE : */
     /// texture 1 | 2 | 3 | 4 | 5 | 6 |
     /// surfaces 1 |

    int continuer;



Mix_Music *musique;
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) ///Initialisation de l'API Mixer
    {

    }


    fenetre1 = SDL_CreateWindow("Minecraft 2D edition 0.0.4 dev_version",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1200,700,SDL_WINDOW_SHOWN);



    SDL_SetWindowIcon(fenetre1, iconne);


SDL_Renderer *RENDU = SDL_CreateRenderer(fenetre1,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ); /// Création d'un rendu graphique utilisant l'accélération matérielle

    SDL_Surface* accueil5 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/NOMNOM.JPG");
    SDL_Texture* loading = SDL_CreateTextureFromSurface(RENDU,accueil5); /// Préparation du sprite
    SDL_Rect rectangle_accueil1 = {0,0,1200,700};
    SDL_RenderCopy(RENDU,loading,NULL,&rectangle_accueil1); /// Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);
    SDL_Delay(2000);

    SDL_FreeSurface(accueil5);
    SDL_DestroyTexture(loading);



    SDL_Surface* accueil = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/fond2.JPG");
    SDL_Texture* Texture_accueil = SDL_CreateTextureFromSurface(RENDU,accueil); /// Préparation du sprite
    SDL_Rect rectangle_accueil = {0,0,1200,700};
    SDL_RenderCopy(RENDU,Texture_accueil,NULL,&rectangle_accueil); /// Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);

    SDL_FreeSurface(accueil);
    SDL_DestroyTexture(Texture_accueil);

    SDL_Surface* jouerAAA = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/logo.PNG");
    SDL_Texture* TextureAAA = SDL_CreateTextureFromSurface(RENDU,jouerAAA); // Préparation du sprite
    SDL_Rect rectangleAAA = {200,40,825,190};
    SDL_RenderCopy(RENDU,TextureAAA,NULL,&rectangleAAA);

    SDL_RenderPresent(RENDU);
    SDL_UpdateWindowSurface(fenetre1);

    SDL_FreeSurface(jouerAAA);
    SDL_DestroyTexture(TextureAAA);






    SDL_Surface* jouer = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/PLAY_1.JPG");
    SDL_Texture* Texture = SDL_CreateTextureFromSurface(RENDU,jouer); // Préparation du sprite
    SDL_Rect rectangle = {350,250,500,100};
    SDL_RenderCopy(RENDU,Texture,NULL,&rectangle); // Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);
    SDL_UpdateWindowSurface(fenetre1);

    SDL_FreeSurface(jouer);
    SDL_DestroyTexture(Texture);


    SDL_Surface* bouton_quitter1 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/latest.JPG");
    SDL_Texture* Texture_quit1 = SDL_CreateTextureFromSurface(RENDU,bouton_quitter1); // Préparation du sprite
    SDL_Rect quitter1 = {420,550,360,90};
    SDL_RenderCopy(RENDU,Texture_quit1,NULL,&quitter1); // Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);
    SDL_UpdateWindowSurface(fenetre1);

    SDL_FreeSurface(bouton_quitter1);
    SDL_DestroyTexture(Texture_quit1);



    SDL_Surface* bouton_setty = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sety.JPG");
    SDL_Texture* Texture_setty = SDL_CreateTextureFromSurface(RENDU,bouton_setty); // Préparation du sprite
    SDL_Rect setty1 = {380,370,440,95};
    SDL_RenderCopy(RENDU,Texture_setty,NULL,&setty1); // Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);
    SDL_UpdateWindowSurface(fenetre1);

    SDL_FreeSurface(bouton_setty);
    SDL_DestroyTexture(Texture_setty);




musique = Mix_LoadMUS("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESC_MUSIC/mc2d_them1.mp3");  /// CHARGEMENT MUSIQUE
Mix_PlayMusic(musique, -1);
Mix_VolumeMusic(MIX_MAX_VOLUME / 21);







TTF_Font *police = NULL;
police = TTF_OpenFont("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESC TXT/lapolice.ttf", 100);      /// CHARGEMENT VERSION   /// ATTENTION /// NE PAS TROP AUGMENTER LA QUALITE DE LA PÖLICE ! ! ! /// LAG DE OUF
SDL_Color couleurNoire = {255, 255, 255};

SDL_Surface *texte1 = TTF_RenderText_Blended(police, "v 0.0.4  beta", couleurNoire);
SDL_Texture *rect_text1 = SDL_CreateTextureFromSurface(RENDU, texte1);
SDL_Rect position_txt = {1040,660,150,35};
SDL_RenderCopy(RENDU, rect_text1, NULL, &position_txt);

SDL_FreeSurface(texte1);
SDL_DestroyTexture(rect_text1);






TTF_Font *police2 = NULL;
police2 = TTF_OpenFont("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESC TXT/lapolice.ttf", 20);      /// CHARGEMENT COPYRIGHT
/// SDL_Color couleurNoire = {255, 255, 255};

SDL_Surface *texte2 = TTF_RenderText_Blended(police, "   Trap-Ware Studio", couleurNoire);
SDL_Texture *rect_text2 = SDL_CreateTextureFromSurface(RENDU, texte2);
SDL_Rect position_txt2 = {25,660,200,35};
SDL_RenderCopy(RENDU, rect_text2, NULL, &position_txt2);

SDL_FreeSurface(texte2);
SDL_DestroyTexture(rect_text2);

    SDL_Surface* copyright = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/copyright.PNG");
    SDL_Texture* Texture_copyright = SDL_CreateTextureFromSurface(RENDU,copyright); // Préparation du sprite
    SDL_Rect copyright1 = {7,665,25,25};
    SDL_RenderCopy(RENDU,Texture_copyright,NULL,&copyright1); // Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);

SDL_FreeSurface(copyright);
SDL_DestroyTexture(Texture_copyright);



while (continuer)
{


SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_MOUSEMOTION:
        if (event.motion.x >= rectangle.x && event.motion.x <= rectangle.x + rectangle.w && event.motion.y >= rectangle.y && event.motion.y <= rectangle.y + rectangle.h)
        {

        SDL_Surface* jouer1 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/PLAY_2.JPG");
        SDL_Texture* Texture4 = SDL_CreateTextureFromSurface(RENDU,jouer1); // Préparation du sprite
        SDL_Rect rectangle2 = {350,250,500,100};
        SDL_RenderCopy(RENDU,Texture4,NULL,&rectangle2);

        SDL_Surface* bouton_quitter10 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/latest.JPG");
        SDL_Texture* Texture_quit10 = SDL_CreateTextureFromSurface(RENDU,bouton_quitter10); // Préparation du sprite
        SDL_Rect quitter10 = {420,550,360,90};
        SDL_RenderCopy(RENDU,Texture_quit10,NULL,&quitter10);

        SDL_RenderPresent(RENDU);
        SDL_UpdateWindowSurface(fenetre1);

        SDL_FreeSurface(bouton_quitter10);
        SDL_DestroyTexture(Texture_quit10);

        SDL_FreeSurface(jouer1);
        SDL_DestroyTexture(Texture4);
      break;
        }
        else
        {
        SDL_Surface* jouer2 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/PLAY_1.JPG");
        SDL_Texture* Texture5 = SDL_CreateTextureFromSurface(RENDU,jouer2);
        SDL_Rect rectangle3 = {350,250,500,100};// Préparation du spriteSDL_Rect rectangle3 = {600,350,336,82};
        SDL_RenderCopy(RENDU,Texture5,NULL,&rectangle3);

       SDL_FreeSurface(jouer2);
       SDL_DestroyTexture(Texture5);
     ///  break;  /// eviter de zapper les infos suivante !!! tres important !!!
       }

    if (event.motion.x >= quitter1.x && event.motion.x <= quitter1.x + quitter1.w && event.motion.y >= quitter1.y && event.motion.y <= quitter1.y + quitter1.h)
    {
        SDL_Surface* bouton_quitter2 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/latest2.JPG");
        SDL_Texture* Texture_quit2 = SDL_CreateTextureFromSurface(RENDU,bouton_quitter2); // Préparation du sprite
        SDL_Rect quitter2 = {420,550,360,90};
        SDL_RenderCopy(RENDU,Texture_quit2,NULL,&quitter2);

        SDL_Surface* jouer2 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/PLAY_1.JPG");
        SDL_Texture* Texture5 = SDL_CreateTextureFromSurface(RENDU,jouer2);
        SDL_Rect rectangle3 = {350,250,500,100}; // Préparation du spriteSDL_Rect rectangle3 = {600,350,336,82};
        SDL_RenderCopy(RENDU,Texture5,NULL,&rectangle3);

        SDL_RenderPresent(RENDU);

        SDL_FreeSurface(bouton_quitter2);
        SDL_DestroyTexture(Texture_quit2);

        SDL_FreeSurface(jouer2);
        SDL_DestroyTexture(Texture5);
       break;
    }
    else
    {
        SDL_Surface* bouton_quitter10 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/latest.JPG");
        SDL_Texture* Texture_quit10 = SDL_CreateTextureFromSurface(RENDU,bouton_quitter10); // Préparation du sprite
        SDL_Rect quitter10 = {420,550,360,90};
        SDL_RenderCopy(RENDU,Texture_quit10,NULL,&quitter10);

        SDL_RenderPresent(RENDU);
        SDL_UpdateWindowSurface(fenetre1);

        SDL_FreeSurface(bouton_quitter10);
        SDL_DestroyTexture(Texture_quit10);
    }

    if (event.motion.x >= setty1.x && event.motion.x <= setty1.x + setty1.w && event.motion.y >= setty1.y && event.motion.y <= setty1.y + setty1.h)
    {

    SDL_Surface* bouton_setty2 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sety2.JPG");
    SDL_Texture* Texture_setty2 = SDL_CreateTextureFromSurface(RENDU,bouton_setty2); // Préparation du sprite
    SDL_Rect setty2 = {380,370,440,95};
    SDL_RenderCopy(RENDU,Texture_setty2,NULL,&setty2); // Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);
    SDL_UpdateWindowSurface(fenetre1);

    SDL_FreeSurface(bouton_setty2);
    SDL_DestroyTexture(Texture_setty2);
   break;

    }
    else
    {
    SDL_Surface* bouton_setty = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sety.JPG");
    SDL_Texture* Texture_setty = SDL_CreateTextureFromSurface(RENDU,bouton_setty); // Préparation du sprite
    SDL_Rect setty1 = {380,370,440,95};
    SDL_RenderCopy(RENDU,Texture_setty,NULL,&setty1); // Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);
    SDL_UpdateWindowSurface(fenetre1);

    SDL_FreeSurface(bouton_setty);
    SDL_DestroyTexture(Texture_setty);
    break;
    }



    case SDL_MOUSEBUTTONDOWN:

        if (event.button.x >= rectangle.x && event.button.x <= rectangle.x + rectangle.w && event.button.y >= rectangle.y && event.button.y <= rectangle.y + rectangle.h)
        {


            SDL_Surface* jouer3 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/PLAY_3.JPG");
            SDL_Texture* Texture6 = SDL_CreateTextureFromSurface(RENDU,jouer3); // Préparation du sprite
            SDL_Rect rectangle2 = {350,250,500,100};
            SDL_RenderCopy(RENDU,Texture6,NULL,&rectangle2);

            SDL_Surface* bouton_quitter10 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/latest.JPG");
            SDL_Texture* Texture_quit10 = SDL_CreateTextureFromSurface(RENDU,bouton_quitter10); // Préparation du sprite
            SDL_Rect quitter10 = {420,550,360,90};
            SDL_RenderCopy(RENDU,Texture_quit10,NULL,&quitter10);

            SDL_RenderPresent(RENDU);

            SDL_FreeSurface(bouton_quitter10); /// eviter la surcharge memoire
            SDL_DestroyTexture(Texture_quit10); /// contre surcharge memoire
            SDL_FreeSurface(jouer3); /// eviter la surcharge memoire
            SDL_DestroyTexture(Texture6); /// contre surcharge memoire

            Mix_FreeMusic(musique); //Libération de la musique
            Mix_CloseAudio();
            SDL_Delay(500);
            continuer=0;
            SDL_DestroyRenderer(RENDU);
            break;


        }
int parametre;
        if (event.button.x >= quitter1.x && event.button.x <= quitter1.x + quitter1.w && event.button.y >= quitter1.y && event.button.y <= quitter1.y + quitter1.h)
        {

            SDL_Surface* bouton_quitter11 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/latest_3.JPG");
            SDL_Texture* Texture_quit11 = SDL_CreateTextureFromSurface(RENDU,bouton_quitter11); // Préparation du sprite
            SDL_Rect quitter11 = {420,550,360,90};
            SDL_RenderCopy(RENDU,Texture_quit11,NULL,&quitter11);


            SDL_Delay(180);
            SDL_Quit();
        }

         if (event.button.x >= setty1.x && event.button.x <= setty1.x + setty1.w && event.button.y >= setty1.y && event.button.y <= setty1.y + setty1.h)
        {
                TTF_Font *police3 = NULL;
                police3 = TTF_OpenFont("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESC TXT/lapolice.ttf", 20);

        while (parametre)
            {
    SDL_Surface* bouton_setty = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/fond_sety.JPG");
    SDL_Texture* Texture_setty = SDL_CreateTextureFromSurface(RENDU,bouton_setty); // Préparation du sprite
    SDL_Rect setty1 = {0,0,1200,700};
    SDL_RenderCopy(RENDU,Texture_setty,NULL,&setty1); // Copie du sprite grâce au SDL_Renderer
   /// SDL_RenderPresent(RENDU);
    SDL_UpdateWindowSurface(fenetre1);

    SDL_FreeSurface(bouton_setty);
    SDL_DestroyTexture(Texture_setty);




            SDL_Surface *texte3 = TTF_RenderText_Blended(police, "Parametres", couleurNoire);
SDL_Texture *rect_text3 = SDL_CreateTextureFromSurface(RENDU, texte3);
SDL_Rect position_txt3 = {550,100,200,35};
SDL_RenderCopy(RENDU, rect_text3, NULL, &position_txt3);

            SDL_FreeSurface(texte3);
            SDL_DestroyTexture(rect_text3);

            SDL_Surface *volume = TTF_RenderText_Blended(police, "Volume :", couleurNoire);
SDL_Texture *rect_son = SDL_CreateTextureFromSurface(RENDU, volume);
SDL_Rect position_son = {60,200,200,35};
SDL_RenderCopy(RENDU, rect_son, NULL, &position_son);

            SDL_FreeSurface(volume);
            SDL_DestroyTexture(rect_son);

            SDL_Surface *perf = TTF_RenderText_Blended(police, "Mode de Performances:", couleurNoire);
SDL_Texture *rect_perf = SDL_CreateTextureFromSurface(RENDU, perf);
SDL_Rect position_perf = {60,300,200,35};
SDL_RenderCopy(RENDU, rect_perf, NULL, &position_perf);
            SDL_RenderPresent(RENDU);

            SDL_FreeSurface(perf);
            SDL_DestroyTexture(rect_perf);

               /// EN CONSTRUCTION <<< >>>

            }

break;

        }

    }


SDL_Surface *texte1 = TTF_RenderText_Blended(police, "v 0.0.4  beta", couleurNoire);
SDL_Texture *rect_text1 = SDL_CreateTextureFromSurface(RENDU, texte1);
SDL_Rect position_txt = {1040,660,150,35};
SDL_RenderCopy(RENDU, rect_text1, NULL, &position_txt);
SDL_FreeSurface(texte1);
SDL_DestroyTexture(rect_text1);

SDL_Surface *texte2 = TTF_RenderText_Blended(police, "   Trap-Ware Studio", couleurNoire);
SDL_Texture *rect_text2 = SDL_CreateTextureFromSurface(RENDU, texte2);
SDL_Rect position_txt2 = {25,660,200,35};
SDL_RenderCopy(RENDU, rect_text2, NULL, &position_txt2);

SDL_FreeSurface(texte2);
SDL_DestroyTexture(rect_text2);

    SDL_Surface* copyright = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/copyright.PNG");
    SDL_Texture* Texture_copyright = SDL_CreateTextureFromSurface(RENDU,copyright); // Préparation du sprite
    SDL_Rect copyright1 = {7,665,25,25};
    SDL_RenderCopy(RENDU,Texture_copyright,NULL,&copyright1); // Copie du sprite grâce au SDL_Renderer
    SDL_RenderPresent(RENDU);

SDL_FreeSurface(copyright);
SDL_DestroyTexture(Texture_copyright);


}



    SDL_Window *fenetre_jeu = NULL;   ///Déclaration de la fenêtre
    fenetre_jeu = SDL_CreateWindow("Minecraft 2D edition 0.0.4 dev_version",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1920,1080,SDL_WINDOW_BORDERLESS);
    SDL_Renderer *RENDU_JEU = SDL_CreateRenderer(fenetre_jeu,-1,SDL_RENDERER_ACCELERATED); /// Création d'un rendu graphique utilisant l'accélération matérielle

    SDL_Window *fenetre_load = NULL;   ///Déclaration de la fenêtre
    fenetre_load = SDL_CreateWindow("LOADING",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1920,1080,SDL_WINDOW_BORDERLESS);
    SDL_Renderer *RENDU_LOAD = SDL_CreateRenderer(fenetre_load,-1,SDL_RENDERER_ACCELERATED);





   /// SDL_DestroyWindow(fenetre1);





/// VOIR VARIABLES.h




/// VARIABLES TABLEAUX CARTE ! ! !

    int compteur_herbe =0;
    int compteur2_herbe =0;

    int compteur_under_herbe =0;
    int compteur2_under_herbe =0;

    int compteur_terre =0;
    int compteur2_terre =0;

    int compteur_pierre =0;
    int compteur2_pierre =0;

    int compteur_sky =0;
    int compteur2_sky =0;




/// EMPLACEMENT DANS TABLEAUX !

    int caze_x_herbe=0;
    int caze_y_herbe=0;

    int caze_x_under_herbe=0;
    int caze_y_under_herbe=0;

    int caze_x_terre=0;
    int caze_y_terre=0;

    int caze_x_pierre=0;
    int caze_y_pierre=0;

    int caze_x_sky=0;
    int caze_y_sky=0;

    float x_barre = 744.0;


srand(time(NULL));

/// TABLEAUX CARTE ! ! !

tabentier_x_herbe = calloc(2 , sizeof(int));
tabentier_y_herbe = calloc(2 , sizeof(int));

tabentier_x_under_herbe = calloc(2 , sizeof(int));
tabentier_y_under_herbe = calloc(2 , sizeof(int));

tabentier_x_terre = calloc(2 , sizeof(int));
tabentier_y_terre = calloc(2 , sizeof(int));

tabentier_x_pierre = calloc(2 , sizeof(int));
tabentier_y_pierre = calloc(2 , sizeof(int));

tabentier_x_sky = calloc(2 , sizeof(int));
tabentier_y_sky = calloc(2 , sizeof(int));


    SDL_Surface* load_gen = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/loadgen.PNG");
    SDL_Texture* loading_gen = SDL_CreateTextureFromSurface(RENDU_LOAD,load_gen);
    SDL_Rect rectangle_load_gen = {0,0,1920,1080};
    SDL_RenderCopy(RENDU_LOAD,loading_gen,NULL,&rectangle_load_gen);

    SDL_FreeSurface(load_gen);
    SDL_DestroyTexture(loading_gen);

    SDL_Surface *texte_load = TTF_RenderText_Blended(police, "GENERATION DE LA CARTE", couleurNoire);
    SDL_Texture *rect_text_load = SDL_CreateTextureFromSurface(RENDU_LOAD, texte_load);
    SDL_Rect position_txt_load = {850,510,220,35};
    SDL_RenderCopy(RENDU_LOAD, rect_text_load, NULL, &position_txt_load);

    SDL_FreeSurface(texte_load);
    SDL_DestroyTexture(rect_text_load);



    SDL_Surface* barre = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/barre.JPG");       /// collage bloque hauteur 1
    SDL_Texture* load_barre = SDL_CreateTextureFromSurface(RENDU_LOAD,barre);
    SDL_Rect rectangle_barre = {x_barre,560,3,3};
    SDL_RenderCopy(RENDU_LOAD,load_barre,NULL,&rectangle_barre);
    /// SDL_RenderPresent(RENDU_JEU);

    SDL_FreeSurface(barre);
    SDL_DestroyTexture(load_barre);

    SDL_RenderPresent(RENDU_LOAD);









int lasuite;

while(lasuite)     /// ALGO GENERATION DE MAP || A AMELIORER ||
       {


               SDL_Surface* load_gen = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/loadgen.PNG");
    SDL_Texture* loading_gen = SDL_CreateTextureFromSurface(RENDU_LOAD,load_gen);
    SDL_Rect rectangle_load_gen = {0,0,1920,1080};
    SDL_RenderCopy(RENDU_LOAD,loading_gen,NULL,&rectangle_load_gen);

    SDL_FreeSurface(load_gen);
    SDL_DestroyTexture(loading_gen);

    SDL_Surface *texte_load = TTF_RenderText_Blended(police, "GENERATION DE LA CARTE", couleurNoire);
    SDL_Texture *rect_text_load = SDL_CreateTextureFromSurface(RENDU_LOAD, texte_load);
    SDL_Rect position_txt_load = {850,510,220,35};
    SDL_RenderCopy(RENDU_LOAD, rect_text_load, NULL, &position_txt_load);

    SDL_FreeSurface(texte_load);
    SDL_DestroyTexture(rect_text_load);




    SDL_RenderPresent(RENDU_LOAD);
float frame=0;
int FPS=0;
int go1=0;
int endl1=0;
char IMGPS[3000]="";
TTF_Font *police4 = NULL;
police4 = TTF_OpenFont("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESC TXT/calibri.ttf", 200);






   /// SDL_RenderClear(RENDU_JEU);

   while (limite_sky <= 1920)
   {
       go1 = SDL_GetTicks();
       x_barre += 0.1;
    SDL_Surface* barre = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/barre.JPG");       /// collage bloque hauteur 1
    SDL_Texture* load_barre = SDL_CreateTextureFromSurface(RENDU_LOAD,barre);
    SDL_Rect rectangle_barre = {x_barre,560,3,3};
    SDL_RenderCopy(RENDU_LOAD,load_barre,NULL,&rectangle_barre);

    SDL_FreeSurface(barre);
    SDL_DestroyTexture(load_barre);

    SDL_RenderPresent(RENDU_LOAD);


                caze_x_sky = compteur_sky;
                caze_y_sky = compteur2_sky;


                tabentier_x_sky [caze_x_sky] = gen_x_sky;
                tabentier_y_sky [caze_y_sky] = gen_y_sky;

                compteur_sky++;
                compteur2_sky++;
                plus_sky++;
                plus2_sky++;

                tabentier_x_sky = realloc(tabentier_x_sky, plus_sky * sizeof(int));                 /// REALLOCATION DES TABLEAUX !
                tabentier_y_sky = realloc(tabentier_y_sky, plus2_sky * sizeof(int));

    SDL_Surface* sky = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sky.JPG");
    SDL_Texture* load_sky = SDL_CreateTextureFromSurface(RENDU_JEU,sky);
    SDL_Rect rectangle_sky = {gen_x_sky,gen_y_sky,30,30};
    SDL_RenderCopy(RENDU_JEU,load_sky,NULL,&rectangle_sky);

  ///  SDL_RenderPresent(RENDU_JEU);

    SDL_FreeSurface(sky);
    SDL_DestroyTexture(load_sky);

    limite_sky = limite_sky + 30;
    gen_x_sky = gen_x_sky + 30;

       if(limite_sky >= 1920)
          {

              limite_sky = 0;
              gen_x_sky = 0;
              gen_y_sky = gen_y_sky + 30;
          }
        if (gen_y_sky >= 730)
        {
            limite_sky = 3000;
            break;

        }


        endl1 = SDL_GetTicks();
        frame = endl1 - go1;
        FPS = 1000/frame;
        sprintf(IMGPS, "%d", FPS);



    SDL_Surface* supp_fps = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/supp_fps.JPG");
    SDL_Texture* load_supp = SDL_CreateTextureFromSurface(RENDU_LOAD,supp_fps);
    SDL_Rect rectangle_supp = {0,0,90,40};
    SDL_RenderCopy(RENDU_LOAD,load_supp,NULL,&rectangle_supp);
    SDL_RenderPresent(RENDU_LOAD);

    SDL_FreeSurface(supp_fps);
    SDL_DestroyTexture(load_supp);




    SDL_Surface *frame_p_s = TTF_RenderText_Blended(police4, IMGPS, couleurNoire);
    SDL_Texture *rect_frame = SDL_CreateTextureFromSurface(RENDU_LOAD, frame_p_s);
    SDL_Rect position_fps = {0,0,90,40};
    SDL_RenderCopy(RENDU_LOAD, rect_frame, NULL, &position_fps);
    SDL_RenderPresent(RENDU_LOAD);

    SDL_FreeSurface(frame_p_s);
    SDL_DestroyTexture(rect_frame);



   }






           while (limite_gen < 1920 && terre ==1)
        {
                   go1 = SDL_GetTicks();

    SDL_Surface* barre = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/barre.JPG");       /// collage bloque hauteur 1
    SDL_Texture* load_barre = SDL_CreateTextureFromSurface(RENDU_LOAD,barre);
    SDL_Rect rectangle_barre = {x_barre,560,3,3};
    SDL_RenderCopy(RENDU_LOAD,load_barre,NULL,&rectangle_barre);

    SDL_FreeSurface(barre);
    SDL_DestroyTexture(load_barre);

    SDL_RenderPresent(RENDU_LOAD);
























            gen_y = (rand()% (MAX-MIN +1)) +MIN;

            if(gen_y == 1)
            {
                gen_y=670;
            }

            else if (gen_y==2)
            {
                gen_y=730;
            }

            else if (gen_y==3)
            {
                gen_y=730;
            }
            else if (gen_y==4)
            {
                gen_y=670;
            }
            else if (gen_y==5)
            {
                gen_y=670;
            }
            else if (gen_y==6)
            {
                gen_y=670;
            }
            else if (gen_y==7)
            {
                gen_y=700;
            }

    /// creation des tableaux de gravité || generation ! ! ! ///



                caze_x_herbe = compteur_herbe;
                caze_y_herbe = compteur2_herbe;

                caze_x_under_herbe = compteur_under_herbe;
                caze_y_under_herbe = compteur2_under_herbe;

                tabentier_x_herbe [caze_x_herbe] = gen_x;
                tabentier_y_herbe [caze_y_herbe] = gen_y;

                compteur_herbe++;
                compteur2_herbe++;
                plus_herbe++;
                plus2_herbe++;


                tabentier_x_herbe = realloc(tabentier_x_herbe, plus_herbe * sizeof(int));                 /// REALLOCATION DES TABLEAUX !
                tabentier_y_herbe = realloc(tabentier_y_herbe, plus2_herbe * sizeof(int));






                SDL_Surface* blox = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/blox.PNG");       /// collage bloque hauteur 1
                SDL_Texture* load_blox = SDL_CreateTextureFromSurface(RENDU_JEU,blox);
                SDL_Rect rectangle_blox = {gen_x,gen_y,LONG_BLOX,LARG_BLOX};
                SDL_RenderCopy(RENDU_JEU,load_blox,NULL,&rectangle_blox);
               /// SDL_RenderPresent(RENDU_JEU);
                SDL_FreeSurface(blox);
                SDL_DestroyTexture(load_blox);


                x_barre++;      /// BARRE LOADING GEN ! ! !


                if (gen_y == 700)
                {
                    gen_y4 = 700;
                    SDL_Surface* dirt_b = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/dirt.JPG");           /// collage bloque hauteur 2
                    SDL_Texture* load_dirt = SDL_CreateTextureFromSurface(RENDU_JEU,dirt_b);
                    SDL_Rect rectangle_dirt = {gen_x,gen_y4 + 30,LONG_BLOX,LARG_BLOX};
                    SDL_RenderCopy(RENDU_JEU,load_dirt,NULL,&rectangle_dirt);
                 ///   SDL_RenderPresent(RENDU_JEU);

                    SDL_FreeSurface(dirt_b);
                    SDL_DestroyTexture(load_dirt);

                }
                else if (gen_y == 670)
                {
                    gen_y4 = 670;

                    SDL_Surface* dirt_b = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/dirt.JPG");               /// collage bloque hauteur 3
                    SDL_Texture* load_dirt = SDL_CreateTextureFromSurface(RENDU_JEU,dirt_b);
                    SDL_Rect rectangle_dirt = {gen_x,gen_y4 + 30,LONG_BLOX,LARG_BLOX};
                    SDL_RenderCopy(RENDU_JEU,load_dirt,NULL,&rectangle_dirt);
                  ///  SDL_RenderPresent(RENDU_JEU);

                    SDL_FreeSurface(dirt_b);
                    SDL_DestroyTexture(load_dirt);


                    SDL_Surface* dirt_b2 = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/dirt.JPG");            /// collage bloque hauteur 4
                    SDL_Texture* load_dirt2 = SDL_CreateTextureFromSurface(RENDU_JEU,dirt_b2);
                    SDL_Rect rectangle_dirt2 = {gen_x,gen_y4 + (2* LARG_BLOX),LONG_BLOX,LARG_BLOX};
                    SDL_RenderCopy(RENDU_JEU,load_dirt2,NULL,&rectangle_dirt2);
                 ///   SDL_RenderPresent(RENDU_JEU);

                    SDL_FreeSurface(dirt_b2);
                    SDL_DestroyTexture(load_dirt2);

                                caze_x_under_herbe = compteur_under_herbe;
                caze_y_under_herbe = compteur2_under_herbe;


                tabentier_x_under_herbe [caze_x_under_herbe] = gen_x;
                tabentier_y_under_herbe [caze_y_under_herbe] = gen_y4;

                compteur_under_herbe++;
                compteur2_under_herbe++;
                plus_under_herbe++;
                plus2_under_herbe++;

                tabentier_x_under_herbe = realloc(tabentier_x_under_herbe, plus_under_herbe * sizeof(int));                 /// REALLOCATION DES TABLEAUX !
                tabentier_y_under_herbe = realloc(tabentier_y_under_herbe, plus2_under_herbe * sizeof(int));





                }

                gen_x = (gen_x +30);
                limite_gen = (limite_gen+30);
                gen_y =0;



        endl1 = SDL_GetTicks();
        frame = endl1 - go1;
        FPS = 1000/frame;
        sprintf(IMGPS, "%d", FPS);



    SDL_Surface* supp_fps = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/supp_fps.JPG");
    SDL_Texture* load_supp = SDL_CreateTextureFromSurface(RENDU_LOAD,supp_fps);
    SDL_Rect rectangle_supp = {0,0,90,40};
    SDL_RenderCopy(RENDU_LOAD,load_supp,NULL,&rectangle_supp);
    SDL_RenderPresent(RENDU_LOAD);

    SDL_FreeSurface(supp_fps);
    SDL_DestroyTexture(load_supp);




    SDL_Surface *frame_p_s = TTF_RenderText_Blended(police4, IMGPS, couleurNoire);
    SDL_Texture *rect_frame = SDL_CreateTextureFromSurface(RENDU_LOAD, frame_p_s);
    SDL_Rect position_fps = {0,0,90,40};
    SDL_RenderCopy(RENDU_LOAD, rect_frame, NULL, &position_fps);
    SDL_RenderPresent(RENDU_LOAD);

    SDL_FreeSurface(frame_p_s);
    SDL_DestroyTexture(rect_frame);


        }



     while (limite_gen2 < 1920 && dirt ==1)
           {
            go1 = SDL_GetTicks();

                x_barre++;
    SDL_Surface* barre = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/barre.JPG");
    SDL_Texture* load_barre = SDL_CreateTextureFromSurface(RENDU_LOAD,barre);
    SDL_Rect rectangle_barre = {x_barre,560,3,3};
    SDL_RenderCopy(RENDU_LOAD,load_barre,NULL,&rectangle_barre);

    SDL_FreeSurface(barre);
    SDL_DestroyTexture(load_barre);

    SDL_RenderPresent(RENDU_LOAD);

                caze_x_terre = compteur_terre;
                caze_y_terre = compteur2_terre;


                tabentier_x_terre [caze_x_terre] = gen_x2;
                tabentier_y_terre [caze_y_terre] = gen_y2;

                compteur_terre++;
                compteur2_terre++;
                plus_terre++;
                plus2_terre++;

                tabentier_x_terre = realloc(tabentier_x_terre, plus_terre * sizeof(int));                 /// REALLOCATION DES TABLEAUX !
                tabentier_y_terre = realloc(tabentier_y_terre, plus2_terre * sizeof(int));



    SDL_Surface* dirt_b = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/dirt.JPG");
    SDL_Texture* load_dirt = SDL_CreateTextureFromSurface(RENDU_JEU,dirt_b);
    SDL_Rect rectangle_dirt = {gen_x2,gen_y2,LONG_BLOX,LARG_BLOX};
    SDL_RenderCopy(RENDU_JEU,load_dirt,NULL,&rectangle_dirt);
  ///  SDL_RenderPresent(RENDU_JEU);

    SDL_FreeSurface(dirt_b);
    SDL_DestroyTexture(load_dirt);


    limite_gen2 = limite_gen2 + 30;
    gen_x2 = gen_x2 + 30;

        endl1 = SDL_GetTicks();
        frame = endl1 - go1;
        FPS = 1000/frame;
        sprintf(IMGPS, "%d", FPS);



    SDL_Surface* supp_fps = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/supp_fps.JPG");
    SDL_Texture* load_supp = SDL_CreateTextureFromSurface(RENDU_LOAD,supp_fps);
    SDL_Rect rectangle_supp = {0,0,90,40};
    SDL_RenderCopy(RENDU_LOAD,load_supp,NULL,&rectangle_supp);
    SDL_RenderPresent(RENDU_LOAD);

    SDL_FreeSurface(supp_fps);
    SDL_DestroyTexture(load_supp);




    SDL_Surface *frame_p_s = TTF_RenderText_Blended(police4, IMGPS, couleurNoire);
    SDL_Texture *rect_frame = SDL_CreateTextureFromSurface(RENDU_LOAD, frame_p_s);
    SDL_Rect position_fps = {0,0,90,40};
    SDL_RenderCopy(RENDU_LOAD, rect_frame, NULL, &position_fps);
    SDL_RenderPresent(RENDU_LOAD);

    SDL_FreeSurface(frame_p_s);
    SDL_DestroyTexture(rect_frame);


        }


    while (limite_gen3 < 1920 + LONG_BLOX)
           {

    go1 = SDL_GetTicks();

    x_barre = x_barre + 0.2;
    SDL_Surface* barre = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/barre.JPG");
    SDL_Texture* load_barre = SDL_CreateTextureFromSurface(RENDU_LOAD,barre);
    SDL_Rect rectangle_barre = {x_barre,560,3,3};
    SDL_RenderCopy(RENDU_LOAD,load_barre,NULL,&rectangle_barre);

    SDL_FreeSurface(barre);
    SDL_DestroyTexture(load_barre);

    SDL_RenderPresent(RENDU_LOAD);

    if(limite_gen3 >= 1920 && pierre ==1)
          {

              limite_gen3 = 0;
              gen_x3 = 0;
              gen_y3 = gen_y3 + 30;
          }

                caze_x_pierre = compteur_pierre;
                caze_y_pierre = compteur2_pierre;


                tabentier_x_pierre [caze_x_pierre] = gen_x3;
                tabentier_y_pierre [caze_y_pierre] = gen_y3;

                compteur_pierre++;
                compteur2_pierre++;
                plus_pierre++;
                plus2_pierre++;

                tabentier_x_pierre = realloc(tabentier_x_pierre, plus_pierre * sizeof(int));                 /// REALLOCATION DES TABLEAUX !
                tabentier_y_pierre = realloc(tabentier_y_pierre, plus2_pierre * sizeof(int));

    SDL_Surface* stone = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/stone.PNG");
    SDL_Texture* load_stone = SDL_CreateTextureFromSurface(RENDU_JEU,stone);
    SDL_Rect rectangle_stone = {gen_x3,gen_y3,30,30};
    SDL_RenderCopy(RENDU_JEU,load_stone,NULL,&rectangle_stone);
  ///  SDL_RenderPresent(RENDU_JEU);

    SDL_FreeSurface(stone);
    SDL_DestroyTexture(load_stone);

    limite_gen3 = limite_gen3 + 30;
    gen_x3 = gen_x3 + 30;


        if(gen_y3 >= 1080)
          {
            pierre =0;
          }

          if (pierre == 0)
          {
              lasuite = 0;
          }


        endl1 = SDL_GetTicks();
        frame = endl1 - go1;
        FPS = 1000/frame;
        sprintf(IMGPS, "%d", FPS);



    SDL_Surface* supp_fps = IMG_Load("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/supp_fps.JPG");
    SDL_Texture* load_supp = SDL_CreateTextureFromSurface(RENDU_LOAD,supp_fps);
    SDL_Rect rectangle_supp = {0,0,90,40};
    SDL_RenderCopy(RENDU_LOAD,load_supp,NULL,&rectangle_supp);
    SDL_RenderPresent(RENDU_LOAD);

    SDL_FreeSurface(supp_fps);
    SDL_DestroyTexture(load_supp);




    SDL_Surface *frame_p_s = TTF_RenderText_Blended(police4, IMGPS, couleurNoire);
    SDL_Texture *rect_frame = SDL_CreateTextureFromSurface(RENDU_LOAD, frame_p_s);
    SDL_Rect position_fps = {0,0,90,40};
    SDL_RenderCopy(RENDU_LOAD, rect_frame, NULL, &position_fps);
    SDL_RenderPresent(RENDU_LOAD);

    SDL_FreeSurface(frame_p_s);
    SDL_DestroyTexture(rect_frame);

        }


    }



SDL_DestroyWindow(fenetre_load);

fenetre_jeu = SDL_CreateWindow("Minecraft 2D edition 0.0.4 dev_version",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1920,1080,SDL_WINDOW_FULLSCREEN);


SDL_RenderPresent(RENDU_JEU);

///SDL_RenderClear(RENDU_JEU);



/// ETABLISSEMENT DE VARIABLES TAMPONS ! ! !


int lebon1 = caze_x_herbe;
int lebon2 = caze_y_herbe;

int gravite;

int temps_go_fps= 0;
int temps_end_fps= 0;
int middle=0;
float frame=0;
int FPS=0;
int go1=0;
int endl1=0;
int collision=1;
int check;

const int skin_speed = 10;

int droite = 420;

char IMGPS[3000]="";
TTF_Font *police4 = NULL;
police4 = TTF_OpenFont("C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESC TXT/calibri.ttf", 30);
SDL_Event MovE;


float inertie_skin = 100;
float vy=0.0;

    while (tabentier_x_herbe[lebon1] > droite)
        {
    lebon1--;
        }

///  INVENTAIRE DES CHARGEMENT D IMAGES ///

SDL_Texture *sky =0;

SDL_Texture *sky1 =0;

SDL_Texture *sky2 =0;

SDL_Texture *sky3 =0;

SDL_Texture *sky4 =0;

SDL_Texture *skin =0;

SDL_Texture *sky5 =0;

SDL_Texture *sky6 =0;

SDL_Texture *skin2 =0;

SDL_Texture *skin3 =0;

SDL_Texture *supp_fps =0;


sky = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sky.JPG");

while (gravite)
{

temps_go_fps = SDL_GetTicks();
go1 = SDL_GetTicks();


SDL_Texture *LAMEME =NULL;

    LAMEME = sky;
    SDL_Rect rectangle_sky = {droite,inertie_skin-30,30,30};
    SDL_RenderCopy(RENDU_JEU,LAMEME,NULL,&rectangle_sky);

  ///  SDL_DestroyTexture(LAMEME);

/// NOUVELLE TECHNIQUE AVANCEE ET BEAUVOUPPLUS PERFORMATNE QUAVANT : ECONOMIE D UNE SURFACE + EVITE LE RECHARGEMENT D'IAMAGE + FAIRE ATTENTION NE PAS SUPPRIMER LA TEXTURE AVANT LE RENDERER PRESENT !!



    sky2 = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sky.JPG");
    SDL_Rect rectangle_sky2 = {droite,inertie_skin,30,30};
    SDL_RenderCopy(RENDU_JEU,sky2,NULL,&rectangle_sky2);


    SDL_DestroyTexture(sky2);




    skin = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/elskin.PNG");
    SDL_Rect rectangle_skin = {droite,inertie_skin,30,60};
    SDL_RenderCopy(RENDU_JEU,skin,NULL,&rectangle_skin);

    SDL_RenderPresent(RENDU_JEU);
    SDL_DestroyTexture(skin);


    vy+=0.08;

    if (inertie_skin >= (tabentier_y_herbe[lebon1]-63))
    {
        collision = 0;
    }
    else
    {
        collision =1;
    }


if (collision==1)
{
        inertie_skin+=1;
        inertie_skin+=vy;
}


SDL_PollEvent(&MovE);
switch(MovE.type)

{
    case SDL_KEYDOWN:
        switch(MovE.key.keysym.scancode)
        {

    case SDL_SCANCODE_S:
        {

            if ( droite + 30 >= tabentier_x_herbe[lebon1+1] &&  tabentier_x_herbe[lebon1+1] > inertie_skin)
            {
                SDL_Delay(1000);
            }




            if (droite < tabentier_x_herbe[lebon1]-28)
            {
                lebon1--;
            }
            vy=0;
            droite = (droite-1);


    sky3 = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sky.JPG");
    SDL_Rect rectangle_sky3 = {droite+1,inertie_skin+30,30,30};
    SDL_RenderCopy(RENDU_JEU,sky3,NULL,&rectangle_sky3);

    SDL_DestroyTexture(sky3);


    sky4 = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sky.JPG");
    SDL_Rect rectangle_sky4 = {droite+1,inertie_skin,30,30};
    SDL_RenderCopy(RENDU_JEU,sky4,NULL,&rectangle_sky4);

    SDL_DestroyTexture(sky4);


    skin2 = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/elskin.PNG");
    SDL_Rect rectangle_skin2 = {droite,inertie_skin,30,60};
    SDL_RenderCopy(RENDU_JEU,skin2,NULL,&rectangle_skin2);

    SDL_RenderPresent(RENDU_JEU);


    SDL_DestroyTexture(skin2);
    break;

        }

        case SDL_SCANCODE_F:

            {





            if (droite > (tabentier_x_herbe[lebon1] + 28))
            {
                lebon1++;
            }

            if (tabentier_x_herbe[lebon1+1] >= droite +30)


            vy=0;
            droite++;

    sky5 = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sky.JPG");
    SDL_Rect rectangle_sky5 = {droite-1,inertie_skin+30,30,30};
    SDL_RenderCopy(RENDU_JEU,sky5,NULL,&rectangle_sky5);

    SDL_DestroyTexture(sky5);

    sky6 = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/sky.JPG");
    SDL_Rect rectangle_sky6 = {droite-1,inertie_skin,30,60};
    SDL_RenderCopy(RENDU_JEU,sky6,NULL,&rectangle_sky6);

    SDL_DestroyTexture(sky6);




    skin3 = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/elskin.PNG");
    SDL_Rect rectangle_skin3 = {droite,inertie_skin,30,60};
    SDL_RenderCopy(RENDU_JEU,skin,NULL,&rectangle_skin3);

    SDL_RenderPresent(RENDU_JEU);

    SDL_DestroyTexture(skin3);


    break;
            }

    case SDL_SCANCODE_ESCAPE:
        {
            SDL_Quit();
        break;
        }




        }

}

/* SDL_WaitEvent(&MovE);
switch(MovE.type)

{
    case SDL_KEYUP:
        switch(MovE.key.keysym.scancode)
        {
            case SDL_SCANCODE_D:
                SDL_Quit();
                break;
        }
} */


temps_end_fps = SDL_GetTicks();
middle = (temps_end_fps - temps_go_fps);
if (middle <16)
{
   SDL_Delay(16 - middle);
}


        endl1 = SDL_GetTicks();
        frame = endl1 - go1;
        FPS = 1000/frame;
        sprintf(IMGPS, "%d", FPS);



    supp_fps = IMG_LoadTexture(RENDU_JEU,"C:/Users/pigeo/Desktop/PROGRAMMATION/DUSTER/RESSOURCES/supp_fps.JPG");
    SDL_Rect rectangle_supp = {0,0,90,40};
    SDL_RenderCopy(RENDU_JEU,supp_fps,NULL,&rectangle_supp);
    SDL_RenderPresent(RENDU_JEU);

    SDL_DestroyTexture(supp_fps);




    SDL_Surface *frame_p_s = TTF_RenderText_Blended(police4, IMGPS, couleurNoire);
    SDL_Texture *rect_frame = SDL_CreateTextureFromSurface(RENDU_JEU, frame_p_s);
    SDL_Rect position_fps = {0,0,90,40};
    SDL_RenderCopy(RENDU_JEU, rect_frame, NULL, &position_fps);
    SDL_RenderPresent(RENDU_JEU);

    SDL_FreeSurface(frame_p_s);
    SDL_DestroyTexture(rect_frame);




   }




}




