#include "fichier.h"

void testFile(void){
  File f = creerFileVide();
  int n;
  int n1 = 12;
  int n2 = 2;
  Booleen ok;
  
  if(!estFileVide(f)) 
    printf("ERREUR : la deque devrait etre vide !!!");
  
  enfilerEnTete(&f,n1);  
  enfilerEnTete(&f,n2);

  printf("Affichage TvQ : ");
  afficherFileTvQ(f); 
  printf("\n");


  printf("Affichage QvT: ");
  afficherFileQvT(f); 
  printf("\n");


  ok = teteFile(f,&n);
  printf("tete : %d",n);
  printf("\n");

  ok = queueFile(f,&n);
  printf("queue : %d",n);
  printf("\n");
  
  
  ok = defilerEnQueue(&f,&n);
  if(!ok) printf("ERREUR : on n'a pas pu défiler en queue\n");
  else{
    printf("nombre défilé en queue : %d",n); 
    printf("\n");
  }
  
  ok = defilerEnQueue(&f,&n);
  if(!ok) printf("ERREUR : on n'a pas pu défiler en queue\n");
  else{
    printf("nombre défilé en queue : "); 
    printf("\n");
  }
  
  ok = defilerEnQueue(&f,&n);
  if(!ok) printf("on n'a pas défilé en queue\n");
  else{
    printf("ERREUR : on n'aurait pas du défiler en queue: "); 
    printf("\n");
  }

  enfilerEnQueue(&f,n1);  
  enfilerEnQueue(&f,n2);

  printf("Affichage TvQ :");
  afficherFileTvQ(f); 
  printf("\n");

  ok = defilerEnTete(&f,&n);
  if(!ok) printf("ERREUR : on n'a pas pu défiler en tete\n");
  else{
    printf("nombre défilé en tete : ");
    printf("\n");
  }
  
  ok = defilerEnTete(&f,&n);
  if(!ok) printf("ERREUR : on n'a pas pu défiler en tete\n");
  else{
    printf("nombre défilé en tete : "); 
    printf("\n");
  }
  
  ok = defilerEnTete(&f,&n);
  if(!ok) printf("on n'a pas défilé en tete\n");
  else{
    printf("ERREUR : on n'aurait pas du défiler en tete: "); 
    printf("\n");
  }
}

int main(void){
    testFile();
    return 0;
}