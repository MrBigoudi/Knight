#include "Tableau4.h"

//renvoie 1 si le personnage est sur la plateforme 1 du tableau 4, 0 sinon
int surPlat1Tab4 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_1_TAB_4) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_1_TAB_4) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_1_TAB_4 + LEN_PLAT_1_TAB_4) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 2 du tableau 4, 0 sinon
int surPlat2Tab4 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_2_TAB_4) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_2_TAB_4) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_2_TAB_4 + LEN_PLAT_2_TAB_4) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage n'est pas sur une plateforme du tableau 4, 0 sinon
int pasSurObstacle4 (SDL_Rect *positionKnight)
  {
  if ( !surPlat1Tab4 (positionKnight) && !surPlat2Tab4 (positionKnight) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la hache du tableau 4, 0 sinon
int surAxe (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_AXE) && (positionKnight->x >= ABS_AXE) && (positionKnight->x < ABS_AXE + LEN_AXE) )
    return 1;
  return 0;
  }
