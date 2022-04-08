#include "Tableau3.h"

//renvoie 1 si le personnage est sur la plateforme 1 du tableau 3, 0 sinon
int surPlat1Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_1_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_1_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_1_TAB_3 + LEN_PLAT_1_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 2 du tableau 3, 0 sinon
int surPlat2Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_2_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_2_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_2_TAB_3 + LEN_PLAT_2_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 3 du tableau 3, 0 sinon
int surPlat3Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_3_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_3_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_3_TAB_3 + LEN_PLAT_3_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 4 du tableau 3, 0 sinon
int surPlat4Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_4_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_4_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_4_TAB_3 + LEN_PLAT_4_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 5 du tableau 3, 0 sinon
int surPlat5Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_5_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_5_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_5_TAB_3 + LEN_PLAT_5_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 6 du tableau 3, 0 sinon
int surPlat6Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_6_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_6_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_6_TAB_3 + LEN_PLAT_6_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 7 du tableau 3, 0 sinon
int surPlat7Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_7_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_7_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_7_TAB_3 + LEN_PLAT_7_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 8 du tableau 3, 0 sinon
int surPlat8Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_8_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_8_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_8_TAB_3 + LEN_PLAT_8_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 9 du tableau 3, 0 sinon
int surPlat9Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_9_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_9_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_9_TAB_3 + LEN_PLAT_9_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 10 du tableau 3, 0 sinon
int surPlat10Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_10_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_10_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_10_TAB_3 + LEN_PLAT_10_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 11 du tableau 3, 0 sinon
int surPlat11Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_11_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_11_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_11_TAB_3 + LEN_PLAT_11_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est sur la plateforme 12 du tableau 3, 0 sinon
int surPlat12Tab3 (SDL_Rect *positionKnight)
  {
  if ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_PLAT_12_TAB_3) && (positionKnight->x + LARGEUR_CHEVALIER - DISTANCE_PIEDS >= ABS_PLAT_12_TAB_3) && (positionKnight->x + DISTANCE_PIEDS < ABS_PLAT_12_TAB_3 + LEN_PLAT_12_TAB_3) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage n'est pas sur une plateforme du tableau 3, 0 sinon
int pasSurObstacle3 (SDL_Rect *positionKnight)
  {
  if (!surPlat1Tab3 (positionKnight) && !surPlat2Tab3 (positionKnight) && !surPlat3Tab3 (positionKnight) && !surPlat4Tab3 (positionKnight) && !surPlat5Tab3 (positionKnight) && !surPlat6Tab3 (positionKnight) && !surPlat7Tab3 (positionKnight) && !surPlat8Tab3 (positionKnight) && !surPlat9Tab3 (positionKnight) && !surPlat10Tab3 (positionKnight) && !surPlat11Tab3 (positionKnight) && !surPlat12Tab3 (positionKnight))
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est en bas d'une echelle du tableau 3, 0 sinon
int basEchelleTab3 (SDL_Rect *positionKnight)
  {
  if ( ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_LADDER_1_TAB_3) && (positionKnight->x >= ABS_LADDER_1_TAB_3) && (positionKnight->x <= ABS_LADDER_1_TAB_3 + LEN_LADDER_1_TAB_3) ) || ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_LADDER_2_TAB_3) && (positionKnight->x >= ABS_LADDER_2_TAB_3) && (positionKnight->x <= ABS_LADDER_2_TAB_3 + LEN_LADDER_2_TAB_3) ) )
    return 1;
  return 0;
  }

//renvoie 1 si le personnage est en haut d'une echelle du tableau 3, 0 sinon
int hautEchelleTab3 (SDL_Rect *positionKnight)
  {
  if ( ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_LADDER_1_TAB_3 - HAU_LADDER_1_TAB_3) && (positionKnight->x >= ABS_LADDER_1_TAB_3) && (positionKnight->x <= ABS_LADDER_1_TAB_3 + LEN_LADDER_1_TAB_3) ) || ( (positionKnight->y + HAUTEUR_CHEVALIER == ORD_LADDER_2_TAB_3 - HAU_LADDER_2_TAB_3) && (positionKnight->x >= ABS_LADDER_2_TAB_3) && (positionKnight->x <= ABS_LADDER_2_TAB_3 + LEN_LADDER_2_TAB_3) ) )
    return 1;
  return 0;
  }
