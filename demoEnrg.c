#include<stdio.h>
typedef
struct {
 int age;
 char* nom;
 char* prenom;
 char* email;	
} Etudiant;

int main(){
Etudiant e1;
Etudiant e2;

e1.age=20;
e1.nom="ali";
e1.prenom="mouhamed";
e1.email="ali@gmail.com";

e2.age=20;
e2.nom="ahmed";
e2.prenom="mouhamed";
e2.email="ali@gmail.com";
printf("Etudiant nom  %s \n",e1.nom);
printf("Etudiant nom  %s \n",e2.nom);
}
