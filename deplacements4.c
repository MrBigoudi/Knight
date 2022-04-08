#include "Tableau4.h"

//gestion du deplacement vers la gauche dans le tableau 4
void gestionMvmtGauche4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe, int *regardVersDroite, int axeVisible)
  {
  positionKnight->x -= VITESSE;
  if (pasSurObstacle4 (positionKnight))
    gestionDescente4 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, axe, positionAxe, regardVersDroite, axeVisible);
  }

//gestion du deplacement vers la droite dans le tableau 4
void gestionMvmtDroite4 (SDL_Rect *positionKnight)
  {
  //si le personnage n'est pas collee a gauche d'une plateforme physique, il se deplacer a droite
  if ( (positionKnight->y + HAUTEUR_CHEVALIER < ORD_PLAT_1_TAB_4) || (positionKnight->x + LARGEUR_CHEVALIER < ABS_PLAT_1_TAB_4) )
    positionKnight->x += VITESSE;
  }

//gestion de la descente dans le tableau 4
void gestionDescente4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe, int *regardVersDroite, int axeVisible)
  {
  //si la hache est toujours visible on met a jour l'ecran a l'aide de la fonction miseAJourAvecAxe qui permet d'afficher la hache en arriere plan
  if (axeVisible)
    {
    while (pasSurObstacle4 (positionKnight) )
      {
      miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, axe, positionAxe);
      deplacerAir4 (positionKnight, regardVersDroite);

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
    }

  //sinon on met a jour l'ecran a l'aide de la fonction miseAJourAvecAxe
  else
    {
    while (pasSurObstacle4 (positionKnight) )
      {
      miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
      deplacerAir4 (positionKnight, regardVersDroite);

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
    }

  }

//gestion de la montee dans le tableau 4
void gestionMontee4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe, int *regardVersDroite, int axeVisible)
  {
  int ordonneeAvantMontee = 0;
  ordonneeAvantMontee = positionKnight->y;

  if (axeVisible)
    {
    while (ordonneeAvantMontee - positionKnight->y < HAUTEUR_SAUT)
      {
      miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, axe, positionAxe);
      deplacerAir4 (positionKnight, regardVersDroite);

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

  else
    {
    while (ordonneeAvantMontee - positionKnight->y < HAUTEUR_SAUT)
      {
      miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
      deplacerAir4 (positionKnight, regardVersDroite);

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

  }

//gestion du saut dans le tableau 4
void gestionSaut4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe, int *regardVersDroite, int axeVisible)
  {
  if (*regardVersDroite == 1)
    animationDecollageDAxeVisible (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, axe, positionAxe);

  else
    animationDecollageGAxeVisible (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, axe, positionAxe);

  gestionMontee4 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, axe, positionAxe, regardVersDroite, axeVisible);
  gestionDescente4 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, axe, positionAxe, regardVersDroite, axeVisible);

  if (*regardVersDroite == 1)
    animationAtterissageDAxeVisible (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, axe, positionAxe);

  else
    animationAtterissageGAxeVisible (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, axe, positionAxe);
  }


//gestion du deplacement dans les airs dans le tableau 4
void deplacerAir4 (SDL_Rect *positionKnight, int *regardVersDroite)
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
            //si le personnage est colle a gauche d'une plateforme physique, il ne peut pas aller a droite
            if ( (positionKnight->y + HAUTEUR_CHEVALIER < ORD_PLAT_1_TAB_4) || (positionKnight->x + LARGEUR_CHEVALIER < ABS_PLAT_1_TAB_4) )
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
