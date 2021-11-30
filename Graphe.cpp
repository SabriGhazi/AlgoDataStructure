#include<stdio.h>
#include<stdlib.h>

typedef struct elm* Arc;
struct elm{
       int nom;
       Arc suiv;
       };
typedef  struct sommet * graphe;
struct sommet{
       int nom;
       Arc listArc;
       graphe suiv;
       };
       

void insert(Arc* a,int x){
     
     Arc q,p;
     p=new(elm);
     p->nom=x;
     p->suiv=NULL;
     if(*a==NULL){
                  *a=p;
                  }
     else {
          q=*a;
          while(q->suiv!=NULL){
                               q=q->suiv;
                               }
          q->suiv=p;
          }
}

void creation(graphe * g, int n){
   
     graphe p,q;
     for(int i=1;i<=n;i++){
               p=new(sommet);
               p->listArc=NULL;
               p->nom=i;
               p->suiv=NULL;
               if(*g==NULL){
                            *g=p;
                            q=p;
                            }
               else {
                    q->suiv=p;
                    q=p;
                    }
     }// fin for
     graphe l,s;
     l=*g;
     s=*g;
     while(l!=NULL){
                    while(s!=NULL){

                                   if((l->nom!=s->nom)&&((l->nom%s->nom)==0)){
                                          insert(&l->listArc,s->nom);

                                       }
                                   s=s->suiv;
                                   }//fin while
                    l=l->suiv;
                    s=*g;
                    }// fin while
     }// fin fonction.
void afficher(graphe g){
     Arc a;
     while(g!=NULL){
          a=g->listArc;
          if(a==NULL) printf("(%d)\n",g->nom);
          else while (a!=NULL){
                    printf("%d--->%d\n",g->nom,a->nom);
                    a=a->suiv;
               }
           g=g->suiv;
          }
     }//

bool circuitExist(graphe g, int s, bool t[]){
     
     if(g==NULL) return false;
     else {
          if(g->nom==s) return true;
          Arc a=g->listArc;
          while (a!=NULL){
                
                }
          
          }
     
     }     


     
int main(){
     graphe g=NULL;
     bool t[6];
     creation(&g,6);
     afficher(g);
     getchar();
     }
