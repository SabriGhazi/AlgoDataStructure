#include<stdio.h>
int main(){
char a;
scanf("entrez votre age %c",&a);
switch(a)
	{
	case 'a':
	printf("vous êtes un enfant");
	break;
	case 'b':
	printf("vous êtes jeune");
	break;
	case 'c':
	printf("vous êtes un homme");
	break;		
	case 'd':
	printf("vous êtes un sénior");
	break;	
	default:
	printf("aucun commentaire");
	break;
	}
}
