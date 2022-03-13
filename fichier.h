#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct maillon{
	int nombre;
	struct maillon* prec;
	struct maillon* suiv;
}maillon_t;

typedef maillon_t* File;

typedef enum {FALSE, TRUE} Booleen;

File creerFileVide(void);
Booleen estFileVide(File ptq);
void enfilerEnTete(File *ptq, int nombre);
void enfilerEnQueue(File *ptq, int nombre);
Booleen defilerEnTete(File *ptq, int *nombre);
Booleen defilerEnQueue(File *ptq, int *nombre);
Booleen teteFile(File ptq, int *nombre);
Booleen queueFile(File ptq, int *nombre);
void afficherFileTvQ(File ptq);
void afficherFileQvT(File ptq);
