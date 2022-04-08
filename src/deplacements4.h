#ifndef DEPLACEMENTS4
#define DEPLACEMENTS4

void gestionMvmtGauche4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe, int *regardVersDroite, int axeVisible);
void gestionMvmtDroite4 (SDL_Rect *positionKnight);
void gestionDescente4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe, int *regardVersDroite, int axeVisible);
void gestionMontee4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe, int *regardVersDroite, int axeVisible);
void gestionSaut4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe, int *regardVersDroite, int axeVisible);
void deplacerAir4 (SDL_Rect *positionKnight, int *regardVersDroite);

#endif // DEPLACEMENTS4
