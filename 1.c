#include <stdlib.h>
#include <stdio.h>
int menu(){
	int x;
	printf ("выберите категорию:\n");
	printf ("наука --1\n");
	printf ("животные --2\n");
	printf ("растения --3\n");
	printf ("спорт --4\n");
	scanf ("%d",&x);
	return x;
}
int main(){
	x=menu;
	
}