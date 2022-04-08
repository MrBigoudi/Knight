#include "Tableaux.h"

int main (int argc, char *argv[])
  {
  //initialisation des surfaces
  SDL_Surface *ecran = NULL;
  SDL_Surface *knight = NULL;
  SDL_Surface *imageDeFond = NULL;
  SDL_Surface *ecranTitre = NULL;
  SDL_Surface *coeur = NULL;
  SDL_Surface *axe = NULL;

  //initialisation du gestionnaire d'évènements
  SDL_Event event;

  //initialisation de la police d'écriture
  TTF_Font *police = NULL;

  //initialisation des variables utilisees pour savoir quelles images afficher
  int continuer = 1;
  int tableau = 0;
  int axeVisible = 1;
  int avecAxe = 0;
  int dejaTourne = 0;
  int marche = 1;
  int echelle = 1;
  int regardVersDroite = 1;
  int nvPartie = 0;
  int nbVies = NB_VIES;

  //initialisation des positions des premières images
  SDL_Rect positionKnight;
  SDL_Rect positionImageDeFond;
  SDL_Rect positionEcranTitre;
  SDL_Rect positionCoeur;
  SDL_Rect positionAxe;

  positionImageDeFond.x = 0;
  positionImageDeFond.y = 0;
  positionEcranTitre.x = 0;
  positionEcranTitre.y = 0;
  positionCoeur.x = ABSCISSE_COEUR;
  positionCoeur.y = ORDONNEE_COEUR;
  positionAxe.x = ABS_AXE;
  positionAxe.y = ORD_AXE-LEN_AXE;

  //initialisation de la video
  SDL_Init (SDL_INIT_VIDEO);

  //initialisation de la gestion du texte
  TTF_Init();

  //création d'une icone
  SDL_WM_SetIcon(SDL_LoadBMP("Knight.bmp"), NULL);

  //initialisation de l'ecran avec les differents flags
  ecran = SDL_SetVideoMode (WIDTH, HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);

  //titre de la fenetre
  SDL_WM_SetCaption ("Knight", NULL);

  //chargement des premières images et de la police d'ecriture
  police = TTF_OpenFont ("times.ttf", 40);
  knight = SDL_LoadBMP ("KnightProfil.bmp");
  imageDeFond = SDL_LoadBMP ("Tableau1.bmp");
  ecranTitre = SDL_LoadBMP ("EcranTitre1.bmp");

  //met l'ecran de fond noir
  SDL_FillRect (ecran, NULL, SDL_MapRGB (ecran->format, 0, 0, 0));

  //empeche de voir le curseur a l'ecran
  SDL_ShowCursor (SDL_DISABLE);

  //affiche l'ecran titre
  SDL_BlitSurface (ecranTitre, NULL, ecran, &positionEcranTitre);
  SDL_Flip (ecran);

  //demande au joueur s'il veut continuer sa partie ou recommencer une nouvelle partie
  nouvellePartie (&positionKnight, &nbVies, &tableau, &avecAxe, &nvPartie);

  //libere en memoire la surface ecranTitre
  SDL_FreeSurface (ecranTitre);

  //animation de transition entre l'ecran titre et le jeu
  transition (ecran);

  //affiche l'histoire si le joueur veut faire une nouvelle partie
  if (nvPartie)
    histoire (ecran, police);

  //rend transparent le fond vert de l'image du chevalier
  SDL_SetColorKey (knight, SDL_SRCCOLORKEY, SDL_MapRGB (knight->format, 0, 255, 0));

  //permet de laisser une touche enfoncée
  SDL_EnableKeyRepeat (10, 10);

  //boucle principale du programme
  while (continuer)
    {

    //debut de boucle pour le tableau 1
    while (continuer && (tableau==1))
      {
      //animation du chevalier se mettant de profil si ce dernier ne l'est pas deja
      if (!dejaTourne)
        {
        tourne (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur);
        dejaTourne = 1;
        }

      //progrmme en pause tant que l'utilisateur n'a pas realise une action
      SDL_WaitEvent(&event);

      switch (event.type)
        {
        //si l'utilisateur a enfoncer une touche
        case SDL_KEYDOWN:

          //quelle touche a ete enfoncee
          switch (event.key.keysym.sym)
            {
            //cas de la touche fleche du haut
            case SDLK_UP:

              //gestion du saut pour le tableau 1
              gestionSaut1 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &avecAxe, &regardVersDroite);

              //met a jour l'ecran avec les objets dans leur noouvelle position
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);

              //variable permettant de gerer l'animation de marche
              marche = 1;
              break;

            //cas de la touche fleche de gauche
            case SDLK_LEFT:

              //variable permettant de gerer l'orientation du chevalier
              regardVersDroite = 0;
              gestionMvmtGauche1 (&positionKnight);
              animationMarcheGauche (&knight, &marche);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            //cas de la touche fleche de droite
            case SDLK_RIGHT:
              regardVersDroite = 1;
              gestionMvmtDroite1 (&positionKnight);
              animationMarcheDroite (&knight, &marche);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            //cas de la touche S
            case SDLK_s:

              //permet de sauvegarder la partie
              save (ecran, &positionKnight, &nbVies, &tableau, &avecAxe);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            // cas de la touche espace
            case SDLK_ESCAPE:

              //permet de sortir de la boucle principale
              continuer = 0;
              break;

            default:
              break;

            }

          break;
        }

      //détermine le nombre de coeurs a afficher a l'ecran
      majCoeurs (&nbVies, &coeur);

      //on verifie que le personnage n'est pas mort
      mortPerso (&nbVies, ecran, &imageDeFond, positionImageDeFond, knight, &positionKnight, &coeur, &positionCoeur, &tableau, &avecAxe, &nvPartie);

      miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);

      //si le personnage depasse une certaine distance, on passe au tableau suivant
      if (positionKnight.x + LARGEUR_CHEVALIER + 32 >= WIDTH)
        {
        //animation de passage du tableau 1 au tableau 2
        transitionFinTableau (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur, tableau);
        tableau ++;
        }

      }
    // fin de boucle pour le tableau 1

    //chargement du deuxieme tableau
    if (continuer && (tableau==2))
      {
      SDL_FreeSurface (imageDeFond);
      imageDeFond = SDL_LoadBMP ("Tableau2.bmp");
      miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
      }

    // debut de boucle pour le tableau 2
    while (continuer && (tableau==2))
      {

      SDL_WaitEvent(&event);

      switch (event.type)
        {
        case SDL_KEYDOWN:

          switch (event.key.keysym.sym)
            {

            case SDLK_UP:
              gestionSaut2 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &avecAxe, &regardVersDroite, &nbVies);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              marche = 1;
              break;

            case SDLK_LEFT:
              regardVersDroite = 0;
              gestionMvmtGauche2 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &regardVersDroite, &nbVies);
              animationMarcheGauche (&knight, &marche);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            case SDLK_RIGHT:
              regardVersDroite = 1;
              gestionMvmtDroite2 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &regardVersDroite, &nbVies);
              animationMarcheDroite (&knight, &marche);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            case SDLK_s:
              save (ecran, &positionKnight, &nbVies, &tableau, &avecAxe);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            case SDLK_ESCAPE:
              continuer = 0;
              break;

            default:
              break;

            }

          break;
        }

      majCoeurs (&nbVies, &coeur);
      miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);

      //si le personnage est sur la derniere plateforme, on passe au tableau suivant
      if ( surPlat10Tab2 (&positionKnight) )
        {
        //animation de transition entre les tableaux 2 et 3
        transition2Vers3 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &marche);
        tableau ++;
        }

      mortPerso (&nbVies, ecran, &imageDeFond, positionImageDeFond, knight, &positionKnight, &coeur, &positionCoeur, &tableau, &avecAxe, &nvPartie);
      }
    // fin de boucle pour le tableau 2

    if (continuer && (tableau==3))
      {
      SDL_FreeSurface (imageDeFond);
      imageDeFond = SDL_LoadBMP ("Tableau3.bmp");
      miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
      }

    // debut de boucle pour le tableau 3
    while (continuer && (tableau==3))
      {

      SDL_WaitEvent(&event);

      switch (event.type)
        {
        case SDL_KEYDOWN:

          switch (event.key.keysym.sym)
            {

            case SDLK_UP:

              //si le personnage est en bas d'une echelle, la touche fleche du haut le fait monter a l'echelle
              if (basEchelleTab3 (&positionKnight) )
                {
                //animation de montee a l'echelle
                monteLadder3 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &echelle);
                miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
                marche = 1;
                }

              //sinon, la touche fleche du haut le fait sauter
              else
                {
                gestionSaut3 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &avecAxe, &regardVersDroite, &nbVies);
                miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
                marche = 1;
                }
              break;

            //cas du boutton fleche du bas
            case SDLK_DOWN:

              //si le personnage est en haut d'une echelle, il descend
              if (hautEchelleTab3 (&positionKnight) )
                {
                descendLadder3 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &echelle);
                miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
                marche = 1;
                }
              break;

            case SDLK_LEFT:
              regardVersDroite = 0;
              gestionMvmtGauche3 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &regardVersDroite, &nbVies);
              animationMarcheGauche (&knight, &marche);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            case SDLK_RIGHT:
              regardVersDroite = 1;
              gestionMvmtDroite3 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &regardVersDroite, &nbVies);
              animationMarcheDroite (&knight, &marche);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            case SDLK_s:
              save (ecran, &positionKnight, &nbVies, &tableau, &avecAxe);
              miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              break;

            case SDLK_ESCAPE:
              continuer = 0;
              break;

            default:
              break;

            }

          break;
        }

      majCoeurs (&nbVies, &coeur);
      miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);

      if ( surPlat12Tab3 (&positionKnight) )
        {
        transition3Vers4 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &marche);
        tableau ++;
        }

      mortPerso (&nbVies, ecran, &imageDeFond, positionImageDeFond, knight, &positionKnight, &coeur, &positionCoeur, &tableau, &avecAxe, &nvPartie);

      }
    // fin de boucle pour le tableau 3

    if (continuer && (tableau==4))
      {
      SDL_FreeSurface (imageDeFond);
      imageDeFond = SDL_LoadBMP ("Tableau4.bmp");

      //on charge l'image de la hache plantee au sol
      axe = SDL_LoadBMP ("Axe.bmp");

      //on rend le fond vert transparent
      SDL_SetColorKey (axe, SDL_SRCCOLORKEY, SDL_MapRGB (axe->format, 0, 255, 0));

      //on met a jour l'ecran en affichant la hache
      miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur, axe, &positionAxe);
      }

    // debut de boucle pour le tableau 4
    while (continuer && (tableau==4))
      {

      SDL_WaitEvent(&event);

      switch (event.type)
        {
        case SDL_KEYDOWN:

          switch (event.key.keysym.sym)
            {

            case SDLK_UP:
              gestionSaut4 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, axe, &positionAxe, &regardVersDroite, axeVisible);

              //si le joueur a recuperer la hache, on n'affiche plus la hache
              if (!axeVisible)
                miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);

              //sinon on l'affiche toujours
              else
                miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur, axe, &positionAxe);

              marche = 1;
              break;

            case SDLK_LEFT:
              regardVersDroite = 0;
              gestionMvmtGauche4 (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, axe, &positionAxe, &regardVersDroite, axeVisible);
              animationMarcheGauche (&knight, &marche);

              if (!axeVisible)
                miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              else
                miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur, axe, &positionAxe);

              //si le joueur est sur la hache il la recupere
              if (surAxe (&positionKnight) && axeVisible )
                {
                axeVisible = 0;
                animationTrouveAxe (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &regardVersDroite);
                tableau ++;
                continuer = 0;
                }

              break;

            case SDLK_RIGHT:
              regardVersDroite = 1;
              gestionMvmtDroite4 (&positionKnight);
              animationMarcheDroite (&knight, &marche);

              if (!axeVisible)
                miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              else
                miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur, axe, &positionAxe);

              if (surAxe (&positionKnight) && axeVisible )
                {
                axeVisible = 0;
                animationTrouveAxe (ecran, imageDeFond, positionImageDeFond, &knight, &positionKnight, coeur, &positionCoeur, &regardVersDroite);
                tableau ++;
                continuer = 0;
                }

              break;

            case SDLK_s:
              save (ecran, &positionKnight, &nbVies, &tableau, &avecAxe);

              if (!axeVisible)
                miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
              else
                miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur, axe, &positionAxe);

              break;

            case SDLK_ESCAPE:
              continuer = 0;
              break;

            default:
              break;

            }

          break;
        }

      majCoeurs (&nbVies, &coeur);

      if (!axeVisible)
        miseAJour (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur);
      else
        miseAJourAvecAxe (ecran, imageDeFond, positionImageDeFond, knight, &positionKnight, coeur, &positionCoeur, axe, &positionAxe);

      mortPerso (&nbVies, ecran, &imageDeFond, positionImageDeFond, knight, &positionKnight, &coeur, &positionCoeur, &tableau, &avecAxe, &nvPartie);
      }
      // fin de boucle pour tableau 4

    }

  //on libere les images et la police
  SDL_FreeSurface (knight);
  SDL_FreeSurface (imageDeFond);
  SDL_FreeSurface (coeur);
  TTF_CloseFont (police);

  //on ferme la gestion du texte
  TTF_Quit();

  //on ferme la fenetre
  SDL_Quit();

  //on renvoie un succes
  return EXIT_SUCCESS;
  }













