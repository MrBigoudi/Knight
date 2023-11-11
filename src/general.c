#include "Tableaux.h"
#include <stdio.h>
#include <stdlib.h>

//gestion d'une nouvelle partie et du chargement d'une ancienne partie
void nouvellePartie (SDL_Rect *positionKnight, int *pt_nbVies, int *pt_nbTableau, int *pt_avecAxe, int *pt_nvPartie)
  {
  //initialisation du pointeur vers le fichier texte
  FILE *fichier = NULL;

  //initialisation d'une chaine tres grande
  char chaine[100] = "";

  SDL_Event event;
  int continuer = 1;

  while (continuer)
    {
    SDL_WaitEvent (&event);
    switch (event.type)
      {
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
          {
          //cas ou le boutton N est enfonce
          case SDLK_n:

            //on ouvre le fichier de sauvegarde en mode ecriture pour en effacer le contenu
            fichier = fopen ("Save.txt", "w");

            //on reinitialise les donnees du jeu
            positionKnight->x = 0;
            positionKnight->y = ORDONNEE_SOL1 - HAUTEUR_CHEVALIER;
            *pt_nbVies = NB_VIES;
            *pt_nbTableau = 1;
            *pt_avecAxe = 0;

            //on enregistre ces donnees dans le fichier de sauvegarde
            fprintf (fichier, "%d\n%d\n%d\n%d\n%d", positionKnight->x, positionKnight->y, *pt_nbVies, *pt_nbTableau, *pt_avecAxe);

            //on ferme le fichier
            fclose (fichier);

            continuer = 0;

            //on indique que l'on a recommence une partie
            *pt_nvPartie = 1;

            break;

          //cas ou le boutton C est enfonc�
          case SDLK_c:

            //on ouvre le fichier en mode lecture seule
            fichier = fopen ("Save.txt", "r");

            //s'il n'y a pas eu d'erreurs lors de l'ouverture
            if (fichier != NULL)
              {
              //on se place au debut du fichier
              rewind (fichier);

              //on transforme les elements du fichier en entiers avec strtol et on les affectes aux variables souhait�s
              positionKnight->x = strtol (fgets (chaine, 100, fichier) , NULL, 10);
              positionKnight->y = strtol (fgets (chaine, 100, fichier) , NULL, 10);
              *pt_nbVies = strtol (fgets (chaine, 100, fichier) , NULL, 10);
              *pt_nbTableau = strtol (fgets (chaine, 100, fichier) , NULL, 10);
              *pt_avecAxe = strtol (fgets (chaine, 100, fichier) , NULL, 10);

              fclose (fichier);
              }

            continuer = 0;
            *pt_nvPartie = 0;
            break;

          default:
            break;
            }

        break;

      default:
        break;
      }
    }

  }

//gestion de la transition entre l'ecran titre et le jeu
void transition (SDL_Surface *ecran)
  {
  //on initialise les surfaces
  SDL_Surface *ecranTitre2 = NULL;
  SDL_Surface *ecranTitre3 = NULL;
  SDL_Surface *ecranTitre4 = NULL;

  //on initialise leurs positions
  SDL_Rect positionEcranTitre2;
  SDL_Rect positionEcranTitre3;
  SDL_Rect positionEcranTitre4;

  positionEcranTitre2.x = 0;
  positionEcranTitre2.y = 0;
  positionEcranTitre3.x = 0;
  positionEcranTitre3.y = 0;
  positionEcranTitre4.x = 0;
  positionEcranTitre4.y = 0;

  ecranTitre2 = SDL_LoadBMP ("EcranTitre2.bmp");
  ecranTitre3 = SDL_LoadBMP ("EcranTitre3.bmp");
  ecranTitre4 = SDL_LoadBMP ("EcranTitre4.bmp");

  //on met a jour l'ecran
  SDL_BlitSurface (ecranTitre2, NULL, ecran, &positionEcranTitre2);
  SDL_Flip (ecran);
  //on affiche l'image pendant 500 ms
  pause (500);

  SDL_BlitSurface (ecranTitre3, NULL, ecran, &positionEcranTitre3);
  SDL_Flip (ecran);
  pause (500);

  SDL_BlitSurface (ecranTitre4, NULL, ecran, &positionEcranTitre4);
  SDL_Flip (ecran);
  pause (500);

  //on libere les images
  SDL_FreeSurface (ecranTitre2);
  SDL_FreeSurface (ecranTitre3);
  SDL_FreeSurface (ecranTitre4);

  }

//animation de la mise de profil du personnage
void tourne (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur)
  {
  //on charge plusieurs faois une image dans la meme variable donc on libere cette variable avant chaque chargemet d'image pour liberer de l'espace memoire
  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight1.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause (500);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight2.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight3.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight4.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight5.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight6.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight7.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight8.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight9.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("Knight10.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
  pause(30);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightProfil.bmp");
  positionKnight->x += 48;
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

  }

//met a jour l'ecran
void miseAJour (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur)
  {
  //colle les images sur l'ecran
  SDL_BlitSurface (imageDeFond, NULL, ecran, &positionImageDeFond);
  SDL_BlitSurface (coeur, NULL, ecran, positionCoeur);
  SDL_BlitSurface (knight, NULL, ecran, positionKnight);

  //met a jour l'ecran
  SDL_Flip (ecran);
  }

//met en pause le programme
void pause (int tpsDePause)
  {
  SDL_Delay (tpsDePause);
  }

//suvegarde les donnees du programme dans le fichier Save
void save (SDL_Surface *ecran, SDL_Rect *positionKnight, int *pt_nbVies, int *pt_nbTableau, int *pt_avecAxe)
  {
  //on initialise l'image "Save ... "
  SDL_Surface *saving = NULL;
  SDL_Rect positionSaving;
  positionSaving.x = ABSCISSE_SAVE;
  positionSaving.y = 0;


  FILE *fichier = NULL;
  //on ouvre le fichier en lecture et ecriture
  fichier = fopen ("Save.txt", "r+");

  //s'il n'y a pas eu d'erreurs a l'ouverture du fichier, on sauvegarde les donnees necessaires dedans
  if (fichier != NULL)
    {
    rewind (fichier);
    fprintf (fichier, "%d\n%d\n%d\n%d\n%d", positionKnight->x, positionKnight->y, *pt_nbVies, *pt_nbTableau, *pt_avecAxe);

    //on affiche l'image "Save..."
    saving = SDL_LoadBMP ("saveInProgress.bmp");
    SDL_SetColorKey (saving , SDL_SRCCOLORKEY, SDL_MapRGB (saving->format, 0, 255, 0));
    SDL_BlitSurface (saving, NULL, ecran, &positionSaving);
    SDL_Flip (ecran);
    pause(100);

    //on libere l'image "Save..."
    SDL_FreeSurface (saving);
    }
  fclose (fichier);
  }

//animation d'atterissage si le personnage regarde a droite
void animationAtterissageD (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe)
  {
  //si le personnage ne tient pas la hache, on affiche telles images
  if (!(*pt_avecAxe))
    {
    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut8.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut7.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut5.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut3.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut1.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    }
  }

//animation decollage si le personnage regarde a droite
void animationDecollageD (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe)
  {
  if (!(*pt_avecAxe))
    {
    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut2.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut4.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut6.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut8.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSaut9.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    }
  }

//animation atterissage si le personnage regarde a gauche
void animationAtterissageG (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe)
  {
  if (!(*pt_avecAxe))
    {
    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG8.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG7.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG5.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG3.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG1.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    }
  }

//animation decollage si le personnage regarde a gauche
void animationDecollageG (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *pt_avecAxe)
  {
  if (!(*pt_avecAxe))
    {
    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG2.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG4.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG6.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG8.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("KnightSautG9.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    }
  }

//mise a jour des couers affiches selon le nombre de vies
void majCoeurs (int *pt_nbVies, SDL_Surface **coeur)
  {
  switch (*pt_nbVies)
    {
    case 3:
      SDL_FreeSurface (*coeur);
      *coeur = SDL_LoadBMP ("Heart3.bmp");
      SDL_SetColorKey (*coeur, SDL_SRCCOLORKEY, SDL_MapRGB ((*coeur)->format, 0, 255, 0));

      break;

    case 2:
      SDL_FreeSurface (*coeur);
      *coeur = SDL_LoadBMP ("Heart2.bmp");
      SDL_SetColorKey (*coeur, SDL_SRCCOLORKEY, SDL_MapRGB ((*coeur)->format, 0, 255, 0));
      break;

    case 1:
      SDL_FreeSurface (*coeur);
      *coeur = SDL_LoadBMP ("Heart1.bmp");
      SDL_SetColorKey (*coeur, SDL_SRCCOLORKEY, SDL_MapRGB ((*coeur)->format, 0, 255, 0));
      break;

    default:
      break;
    }

  }

//gestion de la mort du personnage
void mortPerso (int *pt_nbVies, SDL_Surface *ecran, SDL_Surface **imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface **coeur, SDL_Rect *positionCoeur, int *pt_nbTableau, int *pt_avecAxe, int *pt_nvPartie)
  {
  FILE *fichier = NULL;

  //si le nombre de vies restantes est inferieur ou egal a 0, on remet les variables dans leur etat initiale
  if ( (*pt_nbVies) <= 0)
    {
    *pt_nbVies = NB_VIES;
    *pt_nbTableau = 1;
    *pt_avecAxe = 0;

    //on enleve affiche une barre vide a la place des coeurs
    SDL_FreeSurface (*coeur);
    *coeur = SDL_LoadBMP ("Heart0.bmp");
    SDL_SetColorKey (*coeur, SDL_SRCCOLORKEY, SDL_MapRGB ((*coeur)->format, 0, 255, 0));

    //on gere l'apparttion de l'ange
    ange (ecran, *imageDeFond, positionImageDeFond, knight, positionKnight, *coeur, positionCoeur);

    //on affiche le gameOver
    imageGameOver (ecran);

    //on ouvre le fichier Save en mode ecriture pour en effacer le contenu
    fichier = fopen ("Save.txt", "w");

    positionKnight->x = 0;
    positionKnight->y = ORDONNEE_SOL1 - HAUTEUR_CHEVALIER;

    //on reecrit dans le fichier les valeurs initiales
    if (fichier != NULL)
      {
      fprintf (fichier, "%d\n%d\n%d\n%d\n%d", positionKnight->x, positionKnight->y, *pt_nbVies, *pt_nbTableau, *pt_avecAxe);
      fclose (fichier);
      }

    //on affiche de nouveau l'ecran titre
    SDL_Surface *ecranTitre = NULL;
    SDL_Rect positionEcranTitre;
    positionEcranTitre.x = 0;
    positionEcranTitre.y = 0;
    ecranTitre = SDL_LoadBMP ("EcranTitre1.bmp");
    SDL_FillRect (ecran, NULL, SDL_MapRGB (ecran->format, 255, 255, 255));
    SDL_BlitSurface (ecranTitre, NULL, ecran, &positionEcranTitre);
    SDL_Flip (ecran);

    //on gere le lancement d'une nouvelle partie
    nouvellePartie (positionKnight, pt_nbVies, pt_nbTableau, pt_avecAxe, pt_nvPartie);
    *imageDeFond = SDL_LoadBMP ("Tableau1.bmp");
    SDL_FreeSurface (ecranTitre);
    transition (ecran);
    *coeur = SDL_LoadBMP ("Heart3.bmp");
    SDL_SetColorKey (*coeur, SDL_SRCCOLORKEY, SDL_MapRGB ((*coeur)->format, 0, 255, 0));

    }

  }

//gestion de l'apparition de l'ange
void ange (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur)
  {
  //on affiche le persoonage allongee
  SDL_Surface *knightAllonge = NULL;
  SDL_Rect positionKnightAllongee;
  positionKnightAllongee.x = positionKnight->x;
  positionKnightAllongee.y = (positionKnight->y + 30);
  knightAllonge = SDL_LoadBMP ("KnightDown.bmp");
  SDL_SetColorKey (knightAllonge, SDL_SRCCOLORKEY, SDL_MapRGB (knightAllonge->format, 0, 255, 0));
  SDL_BlitSurface (imageDeFond, NULL, ecran, &positionImageDeFond);
  SDL_BlitSurface (coeur, NULL, ecran, positionCoeur);
  SDL_BlitSurface (knightAllonge, NULL, ecran, &positionKnightAllongee);
  SDL_Flip (ecran);
  pause (100);

  //on charge l'ange
  knight = SDL_LoadBMP ("Ange.bmp");
  SDL_SetColorKey (knight, SDL_SRCCOLORKEY, SDL_MapRGB (knight->format, 0, 255, 0));

  //on fait monter l'ange jusqu'en haut de la fenetre
  while (positionKnight->y >0)
    {
    positionKnight->y -= 8;
    SDL_BlitSurface (imageDeFond, NULL, ecran, &positionImageDeFond);
    SDL_BlitSurface (coeur, NULL, ecran, positionCoeur);
    SDL_BlitSurface (knight, NULL, ecran, positionKnight);
    SDL_BlitSurface (knightAllonge, NULL, ecran, &positionKnightAllongee);
    SDL_Flip (ecran);

    }

  SDL_FreeSurface (knightAllonge);
  knight = SDL_LoadBMP ("KnightProfil.bmp");
  SDL_SetColorKey (knight, SDL_SRCCOLORKEY, SDL_MapRGB (knight->format, 0, 255, 0));

  }

//gestion de l'affichage du gameOver
void imageGameOver (SDL_Surface *ecran)
  {

  SDL_Surface *gameOver1 = NULL;
  SDL_Surface *gameOver2 = NULL;
  SDL_Surface *gameOver3 = NULL;
  SDL_Surface *gameOver4 = NULL;
  SDL_Surface *gameOver5 = NULL;
  SDL_Surface *gameOver6 = NULL;

  SDL_Rect positionGameOver1;
  SDL_Rect positionGameOver2;
  SDL_Rect positionGameOver3;
  SDL_Rect positionGameOver4;
  SDL_Rect positionGameOver5;
  SDL_Rect positionGameOver6;

  positionGameOver1.x = 0;
  positionGameOver1.y = 0;
  positionGameOver2.x = 0;
  positionGameOver2.y = 0;
  positionGameOver3.x = 0;
  positionGameOver3.y = 0;
  positionGameOver4.x = 0;
  positionGameOver4.y = 0;
  positionGameOver5.x = 0;
  positionGameOver5.y = 0;
  positionGameOver6.x = 0;
  positionGameOver6.y = 0;

  gameOver1 = SDL_LoadBMP ("GameOver1.bmp");
  gameOver2 = SDL_LoadBMP ("GameOver2.bmp");
  gameOver3 = SDL_LoadBMP ("GameOver3.bmp");
  gameOver4 = SDL_LoadBMP ("GameOver4.bmp");
  gameOver5 = SDL_LoadBMP ("GameOver5.bmp");
  gameOver6 = SDL_LoadBMP ("GameOver6.bmp");

  SDL_BlitSurface (gameOver1, NULL, ecran, &positionGameOver1);
  SDL_Flip (ecran);
  pause (500);

  SDL_BlitSurface (gameOver2, NULL, ecran, &positionGameOver2);
  SDL_Flip (ecran);
  pause (300);

  SDL_BlitSurface (gameOver3, NULL, ecran, &positionGameOver3);
  SDL_Flip (ecran);
  pause (300);

  SDL_BlitSurface (gameOver4, NULL, ecran, &positionGameOver4);
  SDL_Flip (ecran);
  pause (300);

  SDL_BlitSurface (gameOver5, NULL, ecran, &positionGameOver5);
  SDL_Flip (ecran);
  pause (300);

  SDL_BlitSurface (gameOver6, NULL, ecran, &positionGameOver6);
  SDL_Flip (ecran);
  pause (300);

  SDL_FreeSurface (gameOver1);
  SDL_FreeSurface (gameOver2);
  SDL_FreeSurface (gameOver3);
  SDL_FreeSurface (gameOver4);
  SDL_FreeSurface (gameOver5);
  SDL_FreeSurface (gameOver6);

  }

//gestion du passage du tableau 1 au tableau 2
void transitionFinTableau (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int tableau)
  {
  //on fait avancer le personnage juqu'a ce qu'il disparaisse de l'ecran
  while (positionKnight->x < WIDTH)
    {
    positionKnight->x += 2;
    miseAJour (ecran, imageDeFond, positionImageDeFond, knight, positionKnight, coeur, positionCoeur);
    }

  //on place le personnage sur le deuxieme tableau
  positionKnight->x = 0;
  positionKnight->y = ORD_SOL_TAB_2 - HAUTEUR_CHEVALIER;


  }

//gestion de l'animation de marche si le personnage regarde a droite
void animationMarcheDroite (SDL_Surface **knight, int *marche)
  {
  //selon la valeur de marche, on charge telle ou telle image
  switch (*marche)
    {
    case 1:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 2:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 3:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 4:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 5:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 6:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfil.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 7:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfil.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 8:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfil.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 9:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfil.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 10:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfil.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche = 1;
      break;
    }

  }

//gestion de l'animation de marche si le personnage regarde a gauche
void animationMarcheGauche (SDL_Surface **knight, int *marche)
  {
  switch (*marche)
    {
    case 1:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarcheGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 2:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarcheGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 3:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarcheGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 4:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarcheGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 5:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightMarcheGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 6:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfilGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 7:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfilGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 8:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfilGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 9:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfilGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche += 1;
      break;

    case 10:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("knightProfilGauche.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *marche = 1;
      break;
    }

  }

//gestion du passage du tableau 2 au tableau 3
void transition2Vers3 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *marche)
  {
  //on initialisse l'image du poteau
  SDL_Surface *poteau = NULL;
  SDL_Rect positionPoteau;
  positionPoteau.x = 1641;
  positionPoteau.y = 96;
  poteau = SDL_LoadBMP ("pontTab2.bmp");
  SDL_SetColorKey (poteau, SDL_SRCCOLORKEY, SDL_MapRGB (poteau->format, 0, 255, 0));

  //on deplace le personnage jusq'au bord du tableau en affichant le poteau devant lui pour donner l'impression que le personnage est sur le pont
  while (positionKnight->x < WIDTH)
    {
    positionKnight->x += 5;
    SDL_BlitSurface (imageDeFond, NULL, ecran, &positionImageDeFond);
    SDL_BlitSurface (coeur, NULL, ecran, positionCoeur);
    SDL_BlitSurface (*knight, NULL, ecran, positionKnight);
    SDL_BlitSurface (poteau, NULL, ecran, &positionPoteau);
    SDL_Flip (ecran);
    animationMarcheDroite (knight, marche);
    }

  SDL_FreeSurface (poteau);
  positionKnight->y = ORD_PLAT_1_TAB_3 - HAUTEUR_CHEVALIER;
  positionKnight->x = 0;

  }

//chargement des differentes images du chevlier s'il est sur une echelle
void animationEchelle (SDL_Surface **knight, int *echelle)
  {
  //selon la valeur de echelle on affiche telle ou telle image pour donner l'impression que le peronnage monte ou descend une echelle
  switch (*echelle)
    {
    case 1:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle1.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 2:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle1.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 3:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle1.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 4:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle1.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 5:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle1.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 6:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle2.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 7:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle2.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 8:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle2.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 9:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle2.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle += 1;
      break;

    case 10:
      SDL_FreeSurface (*knight);
      *knight = SDL_LoadBMP ("KnightEchelle2.bmp");
      SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
      *echelle = 1;
      break;
    }

  }

//gestion du passage du tableau 3 au tableau 4
void transition3Vers4 (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *marche)
  {
  while (positionKnight->x > 0)
    {
    positionKnight->x -= 5;
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    animationMarcheGauche (knight, marche);
    }

  positionKnight->y = ORD_PLAT_1_TAB_4 - HAUTEUR_CHEVALIER;
  positionKnight->x = WIDTH - LARGEUR_CHEVALIER;

  }

//gestion de la mise a jour de l'ecran s'il y une hache a l'ecran
void miseAJourAvecAxe (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface *knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *axe, SDL_Rect *positionAxe)
  {
  SDL_BlitSurface (imageDeFond, NULL, ecran, &positionImageDeFond);
  SDL_BlitSurface (coeur, NULL, ecran, positionCoeur);
  SDL_BlitSurface (axe, NULL, ecran, positionAxe);
  SDL_BlitSurface (knight, NULL, ecran, positionKnight);
  SDL_Flip (ecran);
  }


//animation de recuperation de la hache selon l'orientation du personnage
void animationTrouveAxe (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, int *regardVersDroite)
  {
  if (*regardVersDroite)
    {
    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD11.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD10.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD9.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD8.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD7.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD6.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD5.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD4.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD3.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD2.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD1.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(500);

    }

  else
    {
    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG10.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG9.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG8.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG7.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG6.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG5.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG4.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG3.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG2.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeG1.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(50);

    SDL_FreeSurface (*knight);
    *knight = SDL_LoadBMP ("trouveAxeD1.bmp");
    SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
    miseAJour (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur);
    pause(500);

    }

  }

//gestion de l'ceriture de l'introduction
void histoire (SDL_Surface *ecran, TTF_Font *police)
  {
  //on definit une couleure
  SDL_Color couleurBlanche = {255, 255, 255};

  //on initialise une surface de texte
  SDL_Surface *texte = NULL;

  FILE *fichier = NULL;

  //variable contenant le caractere actuel
  int carActuel = 0;

  //tableau contenant la lettre a ecrire
  char tab[20] = "";

  //initialisation des images de fond
  SDL_Surface *intro1 = NULL;
  SDL_Surface *intro2 = NULL;
  SDL_Surface *intro3 = NULL;
  SDL_Surface *intro4 = NULL;
  SDL_Surface *intro5 = NULL;
  SDL_Surface *intro6 = NULL;

  SDL_Rect positionEcranIntro;
  SDL_Rect positionTexte;

  //on ouvre le fichier Intro contenant le texte de l'introduction en lecture seule
  fichier = fopen ("Intro.txt", "r");
  rewind (fichier);

  positionEcranIntro.x = 0;
  positionEcranIntro.y = 0;

  positionTexte.x = 288;
  positionTexte.y = 640;

  intro1 = SDL_LoadBMP ("Intro1.bmp");
  intro2 = SDL_LoadBMP ("Intro2.bmp");
  intro3 = SDL_LoadBMP ("Intro3.bmp");
  intro4 = SDL_LoadBMP ("Intro4.bmp");
  intro5 = SDL_LoadBMP ("Intro5.bmp");
  intro6 = SDL_LoadBMP ("Intro6.bmp");

  //on affiche la premiere image en fondu
  fonduDebut (intro1, &positionEcranIntro, ecran);
  SDL_Flip (ecran);

  //on lit le premier caractere du fichier
  carActuel = fgetc (fichier);

  do
    {
    //on ecrit dans tab le caractere actuel
    sprintf (tab, "%c", carActuel);

    //on ecrit le contenu de tab dans la surface texte
    texte = TTF_RenderText_Blended (police, tab, couleurBlanche);

    //on affiche la surface texte
    SDL_BlitSurface (texte, NULL, ecran, &positionTexte);
    SDL_Flip (ecran);
    SDL_FreeSurface (texte);

    //on decale la position de texte pour afficher la lettre suivante
    if (positionTexte.x < 1559 )
      (positionTexte.x) += 40;

    //on retourne a la ligne s'il on a depace une certaine abscisse
    else
      {
      positionTexte.x = 288;
      (positionTexte.y) += 40;
      }

    //on met en pause le proramme pour gerer la vitesse d'apparition des lettres
    pause (50);

    //on lit la lettre suivante
    carActuel = fgetc (fichier);

    }while (carActuel != '\n');//tant que l'on est pas arriv� en fin de ligne

  //on laisse le texte et l'image pendant un certain temps
  pause (2000);

  //on fait un fondu pour faire disparaitre l'image
  fonduFin (intro1, &positionEcranIntro, ecran);

  //on recommence pour chaque images de l'intro
  positionTexte.x = 288;
  positionTexte.y = 640;

  fonduDebut (intro2, &positionEcranIntro, ecran);
  SDL_Flip (ecran);
  carActuel = fgetc (fichier);

  do
    {
    sprintf (tab, "%c", carActuel);
    texte = TTF_RenderText_Blended (police, tab, couleurBlanche);
    SDL_BlitSurface (texte, NULL, ecran, &positionTexte);
    SDL_Flip (ecran);
    SDL_FreeSurface (texte);

    if (positionTexte.x < 1559)
      (positionTexte.x) += 40;
    else
      {
      positionTexte.x = 288;
      (positionTexte.y) += 40;
      }

    pause(50);
    carActuel = fgetc (fichier);

    }while (carActuel != '\n');

  pause (2000);
  fonduFin (intro2, &positionEcranIntro, ecran);

  positionTexte.x = 288;
  positionTexte.y = 640;

  fonduDebut (intro3, &positionEcranIntro, ecran);
  SDL_Flip (ecran);
  carActuel = fgetc (fichier);

  do
    {
    sprintf (tab, "%c", carActuel);
    texte = TTF_RenderText_Blended (police, tab, couleurBlanche);
    SDL_BlitSurface (texte, NULL, ecran, &positionTexte);
    SDL_Flip (ecran);
    SDL_FreeSurface (texte);

    if (positionTexte.x < 1559)
      (positionTexte.x) += 40;
    else
      {
      positionTexte.x = 288;
      (positionTexte.y) += 40;
      }

    pause(50);
    carActuel = fgetc (fichier);

    }while (carActuel != '\n');

  pause (2000);
  fonduFin (intro3, &positionEcranIntro, ecran);

  positionTexte.x = 288;
  positionTexte.y = 640;

  fonduDebut (intro4, &positionEcranIntro, ecran);
  SDL_Flip (ecran);
  carActuel = fgetc (fichier);

  do
    {
    sprintf (tab, "%c", carActuel);
    texte = TTF_RenderText_Blended (police, tab, couleurBlanche);
    SDL_BlitSurface (texte, NULL, ecran, &positionTexte);
    SDL_Flip (ecran);
    SDL_FreeSurface (texte);

    if (positionTexte.x < 1599)
      (positionTexte.x) += 40;
    else
      {
      positionTexte.x = 288;
      (positionTexte.y) += 40;
      }

    pause(50);
    carActuel = fgetc (fichier);

    }while (carActuel != '\n');

  pause (2000);
  fonduFin (intro4, &positionEcranIntro, ecran);

  positionTexte.x = 288;
  positionTexte.y = 640;

  fonduDebut (intro5, &positionEcranIntro, ecran);
  SDL_Flip (ecran);
  carActuel = fgetc (fichier);

  do
    {
    sprintf (tab, "%c", carActuel);
    texte = TTF_RenderText_Blended (police, tab, couleurBlanche);
    SDL_BlitSurface (texte, NULL, ecran, &positionTexte);
    SDL_Flip (ecran);
    SDL_FreeSurface (texte);

    if (positionTexte.x < 1599)
      (positionTexte.x) += 40;
    else
      {
      positionTexte.x = 288;
      (positionTexte.y) += 40;
      }

    pause(50);
    carActuel = fgetc (fichier);

    }while (carActuel != '\n');

  pause (2000);
  fonduFin (intro5, &positionEcranIntro, ecran);

  positionTexte.x = 288;
  positionTexte.y = 640;

  fonduDebut (intro6, &positionEcranIntro, ecran);
  SDL_Flip (ecran);
  carActuel = fgetc (fichier);

  do
    {
    sprintf (tab, "%c", carActuel);
    texte = TTF_RenderText_Blended (police, tab, couleurBlanche);
    SDL_BlitSurface (texte, NULL, ecran, &positionTexte);
    SDL_Flip (ecran);
    SDL_FreeSurface (texte);

    if (positionTexte.x < 1559)
      (positionTexte.x) += 40;
    else
      {
      positionTexte.x = 288;
      (positionTexte.y) += 40;
      }

    pause(50);
    carActuel = fgetc (fichier);

    }while (carActuel != EOF);//tant que l'on n'est pas a la fin du fichier

  pause (2000);
  fonduFin (intro6, &positionEcranIntro, ecran);

  SDL_FreeSurface (intro1);
  SDL_FreeSurface (intro2);
  SDL_FreeSurface (intro3);
  SDL_FreeSurface (intro4);
  SDL_FreeSurface (intro5);

  }


//gestion de l'apparition des images de l'intor
void fonduDebut (SDL_Surface *image, SDL_Rect *positionImage, SDL_Surface *ecran)
  {
  int k = 0;

  //on applique des transparences croissantes et on blit l'image
  for (k=0; k<=255; k+=15)//attention, on ne peut pas afficher trop d'image rapidement, d'ou le k+=15 au lieu de k++
    {
    SDL_SetAlpha (image, SDL_SRCALPHA, k);
    SDL_BlitSurface (image, NULL, ecran, positionImage);
    SDL_Flip (ecran);
    pause(30);
    }
  }

//gestion de la disparition des images de l'intro
void fonduFin (SDL_Surface *image, SDL_Rect *positionImage, SDL_Surface *ecran)
  {
  int k = 0;

  //on applique des transparences decroissantes et on blit l'image
  for (k=255; k>=0; k-=15)
    {
    SDL_SetAlpha (image, SDL_SRCALPHA, k);
    SDL_BlitSurface (image, NULL, ecran, positionImage);
    SDL_Flip (ecran);
    pause(30);
    }
  }



//animation d'atterissage si le personnage regarde a droite et si la hache est visible a l'ecran
void animationAtterissageDAxeVisible (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *Axe, SDL_Rect *positionAxe)
  {
  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut8.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut7.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut5.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut3.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut1.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  }

//animation decollage si le personnage regarde a droite et si la hache est visible a l'ecran
void animationDecollageDAxeVisible (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *Axe, SDL_Rect *positionAxe)
  {
  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut2.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut4.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut6.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut8.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSaut9.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  }

//animation atterissage si le personnage regarde a gauche et si la hache est visible a l'ecran
void animationAtterissageGAxeVisible (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *Axe, SDL_Rect *positionAxe)
  {
  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG8.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG7.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG5.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG3.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG1.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  }

//animation decollage si le personnage regarde a gauche et si la hache est visible a l'ecran
void animationDecollageGAxeVisible (SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionImageDeFond, SDL_Surface **knight, SDL_Rect *positionKnight, SDL_Surface *coeur, SDL_Rect *positionCoeur, SDL_Surface *Axe, SDL_Rect *positionAxe)
  {
  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG2.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG4.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG6.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG8.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);

  SDL_FreeSurface (*knight);
  *knight = SDL_LoadBMP ("KnightSautG9.bmp");
  SDL_SetColorKey (*knight, SDL_SRCCOLORKEY, SDL_MapRGB ((*knight)->format, 0, 255, 0));
  miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, *knight, positionKnight, coeur, positionCoeur, Axe, positionAxe);
  }





