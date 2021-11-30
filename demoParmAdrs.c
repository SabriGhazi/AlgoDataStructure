#include<stdio.h>

void f1(int p){
	p=10;
}

void f2(int* p){
	*p=10;
}

int main(){
 int x=0;
 printf("valeur de X %d \n",x);
 f1(x);
 printf("valeur de après appel de f1 X %d \n",x);
 f2(&x);
 printf("valeur de après appel de f2 X %d \n",x);
}
