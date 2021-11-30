/*
Author: sabri.ghazi@univ-annaba.dz
Exemple d'insertion d'un noeud dans un ABR.
*/
#include<stdio.h>
#include<stdlib.h>
typedef
struct Noeud{
       int valeur;
       struct Noeud* gauche;
       struct Noeud* droite;
       }* Arbre;
//---------------------------------------------------------------------------
//Algorithme d'insertion d'un nouveau noeud dans un arbre binaire de recherche.
void insertion(Arbre *R, int x){
//creation du noeud.
Arbre nouveau= (Arbre)malloc(sizeof(struct Noeud));
nouveau->valeur=x;
nouveau->gauche=NULL;
nouveau->droite=NULL;
//si l'arbre est vide, on insert dans la racine.
if(*R==NULL)
	*R=nouveau;
//chercher la position du nouveau noeud !
else {
   Arbre pere=NULL;
   Arbre temp=*R;
   while(temp!=NULL){
     if(temp->valeur>x){
	    pere=temp;
		temp=temp->gauche;
	 }
	 else if(temp->valeur<x){
	    pere=temp;
		temp=temp->droite;
	 }
   }
//on insert le nouveau noeud!
   if(pere->valeur<x) pere->droite=nouveau;
   if(pere->valeur>x) pere->gauche=nouveau;
}
}
// cette fonction est modifiée pour pouvoir afficher chaque noued avec son niveau.
void infixe(Arbre R, int space){
     if(R!=NULL){
                 space+=2;
                 infixe(R->gauche,space);
                 for(int i=0;i<space;i++)printf("-");
                 printf("  %d \n",R->valeur);
                 infixe(R->droite,space);
                 }
     }

//----------------------------------------------
/*
      (4)
      /  \
    (2)  (5)
    / \
  (1) (3) 
*/
void creation(Arbre *R){
     *R= (Arbre)malloc(sizeof(struct Noeud));
     (*R)->valeur=4;
     (*R)->gauche=(Arbre)malloc(sizeof(struct Noeud));
     (*R)->gauche->valeur=2;
     
     (*R)->droite=(Arbre)malloc(sizeof(struct Noeud));
     (*R)->droite->valeur=5;
     (*R)->droite->gauche=NULL;
     (*R)->droite->droite=NULL;
     
     (*R)->gauche->droite=(Arbre)malloc(sizeof(struct Noeud));    
     (*R)->gauche->droite->valeur=3;
     (*R)->gauche->droite->gauche=NULL;
     (*R)->gauche->droite->droite=NULL;
     
     (*R)->gauche->gauche=(Arbre)malloc(sizeof(struct Noeud));    
     (*R)->gauche->gauche->valeur=1;
     (*R)->gauche->gauche->gauche=NULL;
     (*R)->gauche->gauche->droite=NULL;
     }
//--------
// Trouver le Minimum d'un Arbre.
Arbre min(Arbre r){
    while (r->gauche != NULL) {
        r=  r->gauche;
    }
    return r;
}

int max(Arbre R){
	if(R!=NULL){
		while(R->droite!=NULL)
			R=R->droite;
	return R->valeur;
}
}
//------------------------------------------------
void trouverPere(Arbre *A, int x, Arbre* pere)
{
    // traverse the tree and search for the key
    while (*A != NULL && (*A)->valeur != x)
    {
        *pere = *A;
        if (x < (*A)->valeur) {
            *A = (*A)->gauche;
        }
        else {
            *A = (*A)->droite;
        }
    }
}
///------------------------------------------------
Arbre pere(Arbre R, int X){
    //si l'arbre est vide.
    if(R==NULL) return NULL;
    else{
    	if(R->gauche!=NULL)
    	  if(R->gauche->valeur==X) return R;
   	    if(R->droite!=NULL)
    	       if(R->droite->valeur==X) return R;
  	     Arbre B=NULL;
         B=pere(R->gauche,X);
  		 if(B==NULL) B=pere(R->droite,X);
         return B;
    }
}

//------------------------------------------------
// supprimer un noeud dans un arbre binaire de recherche.
void supprimer(Arbre* R, int x)
{
    // Variable local
    Arbre pere = NULL;
    Arbre a = *R;
    // L'arbre est vide... rien a supprimé
    if (a == NULL) {
        return;
    }
    trouverPere(&a,x,&pere);
    // cas 1: le noeud a supprimer est une feuille
    if ((a->gauche == NULL) && (a->droite == NULL))
    {
                    
        if (a != *R)
        {
            if (pere->gauche == a) {
                pere->gauche = NULL;
            }
            else {
                pere->droite = NULL;
            }
        }
        // le noeud a supprimer c'est la racine!
        else {
            *R = NULL;
        }
        free(a);  
    }

    // Cas 2: le noeud possède deux fils !
    else if ((a->gauche!=NULL) && (a->droite!=NULL))
    {
         //Trouver le max de son sous arbre gauche.
        Arbre minDroite = min(a->droite); 
        int valeurMinDroite=minDroite->valeur;
        supprimer(&a, valeurMinDroite);
        a->valeur=valeurMinDroite;
    }
 
    // Cas 3 : le noeud possède un seul fils!
    else {
         Arbre fils;
         if(a->gauche!=NULL) fils=a->gauche;
         if(a->droite!=NULL) fils=a->droite;
        if (a != *R)
        {
            if (pere->gauche==a) {
                pere->gauche = fils;
            }
            else {
                pere->droite = fils;
            }
        }
        else {
            *R = fils;
        }
        free(a);
    }
}
//--------
int main(){
    printf("Ceci est un teste des Arbre binaires de rechercher \n");
    Arbre R=NULL;
    //creation(&R);
    printf("-------------------------INFIXE \n");
    infixe(R,2);
    printf("Entrez la valeur de X");
    int X;
    scanf("%d",&X);
    
    Arbre p=NULL;
    p=pere(R,X);
    if(p==NULL) printf("Ce neud ne possede pas de pere!");
    else printf("Le pere de %d c'est %d",X,p->valeur);
    getchar();
    char c;
    scanf("%c",&c);
    }
