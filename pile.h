#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

typedef struct maillonpile{
  int nombre;
  struct maillonpile *suiv;
}maillon_pile;

typedef maillon_pile *Pile;



Pile creerPileVide(void);
Booleen estPileVide(Pile p);
void empiler(Pile *ptp, int nombre);
Booleen depiler(Pile *ptp, int *nombre);
Booleen sommetPile(Pile p, int *nombre);
void afficherPile(Pile p);