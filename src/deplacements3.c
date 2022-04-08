#include "Tableau3.h"

//gestion du mouvement vers la gauche dans le tableau 3
void gestionMvmtGauche3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite, int *nbVies)
  {
  positionKnight->x -= VITESSE;

  if (pasSurObstacle3 (positionKnight) )
    gestionDescente3 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite, nbVies);
  }

//gestion du moouvement vers la droite dans le tableau 3
void gestionMvmtDroite3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite, int *nbVies)
  {
  positionKnight->x += VITESSE;

  if (pasSurObstacle3 (positionKnight) )
    gestionDescente3 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite, nbVies);
  }

//gestion de la montee dans le tableau 3
void gestionMontee3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite)
  {
  int ordonneeAvantMontee = 0;
  ordonneeAvantMontee = positionKnight->y;

  //la SDL plante si une image a une ordonnee negative, on evite le probleme en rajoutant une condition dans la boucle
  while ( (ordonneeAvantMontee - positionKnight->y < HAUTEUR_SAUT) && (positionKnight->y >= 0) )
    {
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    deplacerAir3 (positionKnight, regardVersDroite);

    if (*regardVersDroite == 1)
      {
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightSaut9.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      }

    else
      {
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightSautGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      }

    positionKnight->y -= 2*VITESSE;
    }
  }


//gestion de la descente dans le tableau 3
void gestionDescente3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite, int *nbVies)
  {
  while (pasSurObstacle3 (positionKnight) && (positionKnight->y < HEIGHT) )
    {
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    deplacerAir3 (positionKnight, regardVersDroite);

    if (*regardVersDroite == 1)
      {
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightSaut9.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      }

    else
      {
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightSautGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      }

    positionKnight->y += VITESSE;
    }
  if (positionKnight->y >= HEIGHT)
    *nbVies = 0;
  }


//gestion du deplacement dans les airs pour le tableau 3
void deplacerAir3 (SDL_Rect *positionKnight, int *regardVersDroite)
  {
  SDL_Event event;

  SDL_PollEvent (&event);

  switch (event.type)
    {
    case SDL_KEYDOWN:

      switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            positionKnight->x -= (VITESSE);
            *regardVersDroite = 0;
          break;

        case SDLK_RIGHT:
            positionKnight->x += (VITESSE);
            *regardVersDroite = 1;
          break;

        default:
          break;
        }

    default:
      break;
    }
  }



void gestionSaut3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe, int *regardVersDroite, int *nbVies)
  {
  if (*regardVersDroite == 1)
    animationDecollageD (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  else
    animationDecollageG (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  gestionMontee3 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite);
  gestionDescente3 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite, nbVies);

  if (*regardVersDroite == 1)
    animationAtterissageD (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  else
    animationAtterissageG (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);
  }


void monteLadder3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *echelle)
  {
  if (surPlat2Tab3 (positionKnight) )
    {
    positionKnight->x = 1600;

    while ( !surPlat3Tab3 (positionKnight) )
      {
      positionKnight->y -= 8;
      animationEchelle (knight, echelle);
      miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
      }

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightProfil.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    }

  if (surPlat9Tab3 (positionKnight) )
    {
    positionKnight->x = 368;

    while ( !surPlat11Tab3 (positionKnight) )
      {
      positionKnight->y -= 8;
      animationEchelle (knight, echelle);
      miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
      }

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightProfil.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    }
  }


void descendLadder3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *echelle)
  {
  if (surPlat3Tab3 (positionKnight) )
    {
    positionKnight->x = 1600;

    while ( !surPlat2Tab3 (positionKnight) )
      {
      positionKnight->y += 8;
      animationEchelle (knight, echelle);
      miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
      }

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightProfil.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    }

  if (surPlat11Tab3 (positionKnight) )
    {
    positionKnight->x = 368;

    while ( !surPlat9Tab3 (positionKnight) )
      {
      positionKnight->y += 8;
      animationEchelle (knight, echelle);
      miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
      }

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightProfil.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    }
  }





