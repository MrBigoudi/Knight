#include "Tableau2.h"

//renvoie 1 si le personnage est sur la plateforme 1 du tableau 2, 0 sinon
int surPlat1Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_1_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_1_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_1_TAB_2 + LEN_PLAT_1_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 2 du tableau 2, 0 sinon
int surPlat2Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_2_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_2_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_2_TAB_2 + LEN_PLAT_2_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 3 du tableau 2, 0 sinon
int surPlat3Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_3_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_3_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_3_TAB_2 + LEN_PLAT_3_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 4 du tableau 2, 0 sinon
int surPlat4Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_4_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_4_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_4_TAB_2 + LEN_PLAT_4_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 5 du tableau 2, 0 sinon
int surPlat5Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_5_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_5_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_5_TAB_2 + LEN_PLAT_5_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 6 du tableau 2, 0 sinon
int surPlat6Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_6_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_6_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_6_TAB_2 + LEN_PLAT_6_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 7 du tableau 2, 0 sinon
int surPlat7Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_7_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_7_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_7_TAB_2 + LEN_PLAT_7_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 8 du tableau 2, 0 sinon
int surPlat8Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_8_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_8_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_8_TAB_2 + LEN_PLAT_8_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 9 du tableau 2, 0 sinon
int surPlat9Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_9_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_9_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_9_TAB_2 + LEN_PLAT_9_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 10 du tableau 2, 0 sinon
int surPlat10Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_10_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_10_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_10_TAB_2 + LEN_PLAT_10_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 11 du tableau 2, 0 sinon
int surPlat11Tab2 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_11_TAB_2) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_11_TAB_2) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_11_TAB_2 + LEN_PLAT_11_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur le sol du tableau 2, 0 sinon
int surSol2 (SDL_Rect *positionKnight)
  {
  if ( positionKnight->y + HAUTEUR_CHEVALIER == ORD_SOL_TAB_2 && (positionKnight->x + DISTANCE_PIEDS < LEN_SOL_TAB_2) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage n'est pas sur une plateforme du tableau 2, 0 sinon
int pasSurObstacle2 (SDL_Rect *positionKnight)
  {
  if (!surSol2 (positionKnight) && !surPlat1Tab2 (positionKnight) && !surPlat2Tab2 (positionKnight) && !surPlat3Tab2 (positionKnight) && !surPlat4Tab2 (positionKnight) && !surPlat5Tab2 (positionKnight) && !surPlat6Tab2 (positionKnight) && !surPlat7Tab2 (positionKnight) && !surPlat8Tab2 (positionKnight) && !surPlat9Tab2 (positionKnight) && !surPlat10Tab2 (positionKnight) && !surPlat11Tab2 (positionKnight) )
    return 1;
  return 0;
  }


