#include "pile.h"

Pile creerPileVide(void){
  return NULL;
}

Booleen estPileVide(Pile p){
  if(p==NULL)return TRUE;
  return FALSE;
}

void empiler(Pile *ptp, int nombre){
  maillon_pile* tmp;
  tmp=(maillon_pile*)malloc(sizeof(maillon_pile));
  if(tmp==NULL){
    printf("Problème d'allocation mémoire !\n");
    exit(1);
  }
  tmp->nombre = nombre;
  tmp->suiv = *ptp;
  *ptp = tmp;
}

Booleen depiler(Pile *ptp, int *nombre){
  maillon_pile *tmp;
  if(estPileVide(*ptp)){
    printf("dépiler impossible car la pile est vide !\n");
    return FALSE;
  }
  tmp = *ptp;
  *ptp = tmp->suiv;
  *nombre = tmp->nombre;
  free(tmp);
  return TRUE;
}

Booleen sommetPile(Pile p, int *nombre){
  if(estPileVide(p)){
    printf("impossible car la liste est vide !\n");
    return FALSE;
  }
  *nombre = p->nombre;
  return TRUE;
}

void afficherPile(Pile p){
	while(!estPileVide(p)){
	
		printf("%d ",p->nombre);
		p=p->suiv;
	}
	printf("\n");
}