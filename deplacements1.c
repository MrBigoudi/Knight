#include "Tableau1.h"

//deplace le personnage d'une distance VITESSE vers la gauche
void gestionMvmtGauche1 (SDL_Rect *positionKnight)
  {
  positionKnight->x -= VITESSE;
  }

//deplace le personnage d'une distance VITESSE vers la droite
void gestionMvmtDroite1 (SDL_Rect *positionKnight)
  {
  positionKnight->x += VITESSE;
  }

//gestion de la descente dans le tableau 1
void gestionDescente1 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite)
  {
  //tant que l'on n'est pas sur le sol on descend
  while (positionKnight->y + HAUTEUR_CHEVALIER < ORDONNEE_SOL1 )
    {
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    //pour pouvoir se deplacer dans les airs on appelle la fonction deplacerAir
    deplacerAir1 (positionKnight, regardVersDroite);

    //pour orienter le personnage dans le bon sens dans les airs on regarde vers quelle direction il est tournee
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

//gestion de la montee dans le tableau 1
void gestionMontee1 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite)
  {
  //on sauvegarde l'ordonnee du personnage avant le saut pour pouvoir comparer avec la position du personnage lors de la montee
  int ordonneeAvantMontee = 0;
  ordonneeAvantMontee = positionKnight->y;

  //tant que la difference entre l'ordonne actuelle et l'ordonnee d'avant saut est plus petite que la hauteur d'un saut, le personnage monte
  while (ordonneeAvantMontee - positionKnight->y < HAUTEUR_SAUT)
    {
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    deplacerAir1 (positionKnight, regardVersDroite);

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

//gestion du saut pour le tableau 1
void gestionSaut1 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe, int *regardVersDroite)
  {
  if (*regardVersDroite == 1)
    animationDecollageD (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  else
    animationDecollageG (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  gestionMontee1 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite);
  gestionDescente1 (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, regardVersDroite);

  if (*regardVersDroite == 1)
    animationAtterissageD (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);

  else
    animationAtterissageG (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur, pt_avecAxe);
  }

//fonction permettant de se deplacer lorsque le personnage est dans les airs
void deplacerAir1 (SDL_Rect *positionKnight, int *regardVersDroite)
  {
  SDL_Event event;

  //utilisation d'un "PollEvent" qui ne met pas en pause le programme
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
