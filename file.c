#include "file.h"


File creerFileVide(void){
	return NULL;
}

Booleen estFileVide(File ptq){
	Booleen code = FALSE;
	if(ptq==NULL){
		code = TRUE;
	}
	return code;
}

Booleen enfilerEnTete(File *ptq, int nombre){
	Booleen code = TRUE;
	maillon_file *tmp = (maillon_file*)malloc(sizeof(maillon_file));
	if(tmp==NULL){
		code = FALSE;
	}
	else {
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
	return code;
}

Booleen enfilerEnQueue(File *ptq, int nombre){
    Booleen code = TRUE;
	maillon_file *tmp = (maillon_file*)malloc(sizeof(maillon_file));
	if(tmp==NULL){
		code = FALSE;
	}
	else {
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
	return code;
}


Booleen defilerEnTete(File *ptq, int *nombre){
	Booleen code = TRUE;
	if(estFileVide(*ptq))code = FALSE;
	else {
		maillon_file *tmp;
		tmp = (*ptq)->suiv;
		*nombre = tmp->nombre;
		if(((*ptq)->suiv) == *ptq && ((*ptq)->prec) == *ptq){
			*ptq = NULL;
		}
		else {
			(*ptq)->suiv = tmp->suiv;
			((*ptq)->suiv)->prec = *ptq;
			free(tmp);
		}
		return code;
	}
}

Booleen defilerEnQueue(File *ptq, int *nombre){
	Booleen code = TRUE;
	if(estFileVide(*ptq))code = FALSE;
	else {
		maillon_file *tmp;
		tmp = *ptq;
		*nombre = tmp->nombre;
		if(((*ptq)->suiv) == *ptq && ((*ptq)->prec) == *ptq){
			*ptq = NULL;
		}
		else {
			*ptq = tmp->prec;
			(*ptq)->suiv = tmp->suiv;
			((*ptq)->suiv)->prec = *ptq;
			free(tmp);
		}
	}
	return code;
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
	maillon_file *tmp = ptq->suiv;
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
	maillon_file *tmp = ptq;
	printf("%d ",tmp->nombre);
	tmp = tmp->suiv;
	while(tmp != ptq){
		printf("%d ",tmp->nombre);
		tmp = tmp->suiv;
	}
}