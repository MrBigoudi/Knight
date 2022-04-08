#include "Tableau2.h"

//gestion du deplacement vers la gauche dans le tableau 2
void gestionMvmtGauche2 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite, int *nb_Vies)
  {
  //si le personnage n'est pas collee a droite d'une plateforme physique, il se deplacer a gauche
  if ( (positionKnight->x + LARGEUR_CHEVALIER <= ABS_PLAT_1_TAB_2) || (positionKnight->x > ABS_PLAT_1_TAB_2 + LEN_PLAT_1_TAB_2 + LEN_PLAT_2_TAB_2) || (positionKnight->y + HAUTEUR_CHEVALIER <= ORD_PLAT_1_TAB_2 ) )
    positionKnight->x -= VITESSE;

  //s'il n'est pas sur un obstacle, il descend
  if (pasSurObstacle2 (positionKnight) )
    gestionDescente2 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite, nb_Vies);

  //s'il est sur un obstacle et est colle a droite d'une plateforme physique, il ne fait rien
  }

//gestion du deplacement vers la droite dans le tableau 2
void gestionMvmtDroite2 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite, int *nb_Vies)
  {
  //si le personnage n'est pas collee a gauche d'une plateforme physique, il se deplacer a droite
  if ( (positionKnight->x + LARGEUR_CHEVALIER < ABS_PLAT_1_TAB_2) || (positionKnight->x >= ABS_PLAT_1_TAB_2 + LEN_PLAT_1_TAB_2 + LEN_PLAT_2_TAB_2) || (positionKnight->y + HAUTEUR_CHEVALIER <= ORD_PLAT_2_TAB_2 ) )
    positionKnight->x += VITESSE;

  else
    {
    //si le personnage n'est pas collee a gauche d'une plateforme physique, il se deplacer a droite (il y a deux tels possibilités dans le tableau 2)
    if ( (positionKnight->y + HAUTEUR_CHEVALIER > ORD_PLAT_2_TAB_2 ) && (positionKnight->y + HAUTEUR_CHEVALIER <= ORD_PLAT_1_TAB_2 ) && (positionKnight->x + LARGEUR_CHEVALIER < ABS_PLAT_2_TAB_2 ))
      positionKnight->x += VITESSE;
    }

  if (pasSurObstacle2 (positionKnight) )
    gestionDescente2 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite, nb_Vies);
  }


//gestion de la montee dans le tableau 2
void gestionMontee2 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite)
  {
  int ordonneeAvantMontee = 0;
  ordonneeAvantMontee = positionKnight->y;

  while (ordonneeAvantMontee - positionKnight->y < HAUTEUR_SAUT)
    {
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    deplacerAir2 (positionKnight, regardVersDroite);

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


//gestion de la descente dans le tableau 2
void gestionDescente2 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite, int *nb_Vies)
  {
  //la boucle s'arrete aussi si le personnage tombe dans le vide
  while (pasSurObstacle2 (positionKnight) && (positionKnight->y < HEIGHT) )
    {
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    deplacerAir2 (positionKnight, regardVersDroite);

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
  //le personnage meurt s'il est tombé dans le vide
  if (positionKnight->y >= HEIGHT)
    *nb_Vies = 0;
  }



//fonction permettant de se deplacer dans les airs dans le tableau 2
void deplacerAir2 (SDL_Rect *positionKnight, int *regardVersDroite)
  {
  SDL_Event event;

  SDL_PollEvent (&event);

  switch (event.type)
    {
    case SDL_KEYDOWN:

      switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            //si le personnage est colle a droite d'une plateforme physique, il ne peut pas aller a gauche
            if ( (positionKnight->x + LARGEUR_CHEVALIER-DISTANCE_PIEDS <= ABS_PLAT_1_TAB_2) || (positionKnight->x+DISTANCE_PIEDS > ABS_PLAT_1_TAB_2 + LEN_PLAT_1_TAB_2 + LEN_PLAT_2_TAB_2) || (positionKnight->y + HAUTEUR_CHEVALIER <= ORD_PLAT_2_TAB_2 ) )
              positionKnight->x -= (VITESSE);
            *regardVersDroite = 0;
          break;

        case SDLK_RIGHT:
            //si le personnage est colle a gauche d'une plateforme physique, il ne peut pas aller a droite
            if ( (positionKnight->x + LARGEUR_CHEVALIER < ABS_PLAT_1_TAB_2) || (positionKnight->x >= ABS_PLAT_1_TAB_2 + LEN_PLAT_1_TAB_2 + LEN_PLAT_2_TAB_2) || (positionKnight->y + HAUTEUR_CHEVALIER <= ORD_PLAT_2_TAB_2 ) || ( (positionKnight->y + HAUTEUR_CHEVALIER > ORD_PLAT_2_TAB_2 ) && (positionKnight->y + HAUTEUR_CHEVALIER <= ORD_PLAT_1_TAB_2 ) && (positionKnight->x + LARGEUR_CHEVALIER < ABS_PLAT_2_TAB_2 )))
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


//gestion du saut dans le tableau 2
void gestionSaut2 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe, int *regardVersDroite, int *nb_Vies)
  {
  if (*regardVersDroite == 1)
    animationDecollageD (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  else
    animationDecollageG (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  gestionMontee2 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite);
  gestionDescente2 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite, nb_Vies);

  if (*regardVersDroite == 1)
    animationAtterissageD (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  else
    animationAtterissageG (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);
  }



