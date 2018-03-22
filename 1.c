#include <stdlib.h>
#include <stdio.h>
void menu(){
	int x; FILE*f;
	int n=0, i;
	char*a[12];
	printf ("выберите категорию:\n");
	printf ("наука --1\nживотные --2\nрастения --3\nспорт --4\n");
	scanf ("%d",&x);
	if (x==1) {
		f=fopen("science.txt", "r");
	}
	if (x==2) {
		f=fopen("animals.txt", "r");
	}
	if(x==3) {
		f=fopen("plants.txt", "r");
	}
	if(x==4) {
		f=fopen("sport.txt", "r");
	}
	if ((x<1)||(x>4)) menu();
	if(f==NULL){
		printf("error"); 
		return; 
	}
	i=1+rand()%20;
	while(i<=x){
		fscanf(f,"%s",a);
		}
	return a;
}


int main(){
	menu;
	
}