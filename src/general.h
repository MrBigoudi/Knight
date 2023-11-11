#ifndef GENERAL
#define GENERAL

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_video.h>

void nouvellePartie (SDL_Rect *positionKnight, int *pt_nbVies, int *pt_nbTableau, int *pt_avecAxe, int *pt_nvPartie);
void transition (SDL_Surface *ecran);
void tourne (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur);
void miseAJour (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur);
void miseAJourAvecAxe (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe);

void animationAtterissageD (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe);
void animationDecollageD   (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe);
void animationAtterissageG (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe);
void animationDecollageG   (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe);

void save (SDL_Surface *ecran, SDL_Rect *positionKnight, int *pt_nbVies, int *pt_nbTableau, int *pt_avecAxe);
void pause (int tpsDePause);
void majCoeurs (int *pt_nbVies, SDL_Surface **coeur);
void mortPerso (int *pt_nbVies, SDL_Surface *ecran, SDL_Surface **imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface **coeur, SDL_Rect *positionCoeur, int *pt_nbTableau, int *pt_avecAxe, int *pt_nvPartie);
void ange (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur);
void imageGameOver (SDL_Surface *ecran);
void transitionFinTableau (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int tableau);

void animationMarcheDroite (SDL_Surface **knight, int *marche);
void animationMarcheGauche (SDL_Surface **knight, int *marche);
void animationEchelle (SDL_Surface **knight, int *echelle);

void transition2Vers3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *marche);
void transition3Vers4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *marche);

void animationTrouveAxe (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite);

void histoire (SDL_Surface *ecran, TTF_Font *police);
void fonduDebut (SDL_Surface *image, SDL_Rect *positionImage, SDL_Surface *ecran);
void fonduFin (SDL_Surface *image, SDL_Rect *positionImage, SDL_Surface *ecran);

void animationAtterissageDAxeVisible (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *Axe, SDL_Rect *positionAxe);
void animationDecollageDAxeVisible (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *Axe, SDL_Rect *positionAxe);
void animationAtterissageGAxeVisible (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *Axe, SDL_Rect *positionAxe);
void animationDecollageGAxeVisible (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *Axe, SDL_Rect *positionAxe);

#endif // GENERAL
