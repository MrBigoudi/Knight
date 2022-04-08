#ifndef DEPLACEMENTS1
#define DEPLACEMENTS1


void gestionMvmtGauche1 (SDL_Rect *positionKnight);
void gestionMvmtDroite1 (SDL_Rect *positionKnight);
void gestionDescente1 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite);
void gestionMontee1   (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite);
void gestionSaut1 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe, int *regardVersDroite);
void deplacerAir1 (SDL_Rect *positionKnight, int *regardVersDroite);


#endif // DEPLACEMENTS1
