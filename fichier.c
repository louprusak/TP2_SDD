#include "fichier.h"


File creerFileVide(void){
	return NULL;
}

Booleen estFileVide(File ptq){
	if(ptq==NULL)return TRUE;
	else return FALSE;
}

void enfilerEnTete(File *ptq, int nombre){
	maillon_t *tmp = (maillon_t*)malloc(sizeof(maillon_t));
	if(tmp==NULL){
		printf("Erreur allocation mémoire\n");
		exit(1);
	}
	tmp->nombre = nombre;
	if(*ptq == NULL){
		*ptq = tmp;
		tmp->suiv = tmp;
		tmp->prec = tmp;
	}
	else{
		tmp->prec = *ptq;
		tmp->suiv = (*ptq)->suiv;
		(tmp->suiv)->prec = tmp;
		(*ptq)->suiv = tmp;
	}	
}

void enfilerEnQueue(File *ptq, int nombre){
    maillon_t *tmp = (maillon_t*)malloc(sizeof(maillon_t));
	if(tmp==NULL){
		printf("Erreur allocation mémoire\n");
		exit(1);
	}
	tmp->nombre = nombre;
	if(*ptq == NULL){
		*ptq = tmp;
		tmp->suiv = tmp;
		tmp->prec = tmp;
	}
	else{
		tmp->suiv=(*ptq)->suiv;
		(tmp->suiv)->prec = tmp;
		tmp->prec = *ptq;
		(*ptq)->suiv = tmp;
		*ptq = tmp;
	}
}


Booleen defilerEnTete(File *ptq, int *nombre){
	if(estFileVide(*ptq))return FALSE;
	maillon_t *tmp;
	tmp = (*ptq)->suiv;
	*nombre = tmp->nombre;
	if(((*ptq)->suiv) == *ptq && ((*ptq)->prec) == *ptq){
		*ptq = NULL;
		return TRUE;
	}
	(*ptq)->suiv = tmp->suiv;
	((*ptq)->suiv)->prec = *ptq;
	free(tmp);
	return TRUE;
}

Booleen defilerEnQueue(File *ptq, int *nombre){
	if(estFileVide(*ptq))return FALSE;
	maillon_t *tmp;
	tmp = *ptq;
	*nombre = tmp->nombre;
	if(((*ptq)->suiv) == *ptq && ((*ptq)->prec) == *ptq){
		*ptq = NULL;
		return TRUE;
	}
	*ptq = tmp->prec;
	(*ptq)->suiv = tmp->suiv;
	((*ptq)->suiv)->prec = *ptq;
	free(tmp);
	return TRUE;
}

Booleen teteFile(File ptq, int *nombre){
	if(estFileVide(ptq))return FALSE;
	*nombre = (ptq->suiv)->nombre;
	return TRUE;
}

Booleen queueFile(File ptq, int *nombre){
	if(estFileVide(ptq))return FALSE;
	*nombre = ptq->nombre;
	return TRUE;
}

void afficherFileTvQ(File ptq){
	if(estFileVide(ptq)){
		printf("File vide !\n");
		return;
	}
	maillon_t *tmp = ptq->suiv;
    printf("%d ",tmp->nombre);
	tmp = tmp->suiv;
	while(tmp != ptq->suiv){
		printf("%d ",tmp->nombre);
		tmp = tmp->suiv;
	}
}

void afficherFileQvT(File ptq){
	if(estFileVide(ptq)){
		printf("File vide !\n");
		return;
	}
	maillon_t *tmp = ptq;
	printf("%d ",tmp->nombre);
	tmp = tmp->suiv;
	while(tmp != ptq){
		printf("%d ",tmp->nombre);
		tmp = tmp->suiv;
	}
}