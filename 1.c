#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char* menu(){
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
	while(i>=x){
		fscanf(f,"%s",a);
		x++;
		}
	return a;
}


void game(char *a) {  //передаем нашу строку со словом
	int num, i; int try=7; char* used; char letter; //used - уже использованные буквы, letter - буква для считывания
	num=strlen(a);
	char* b[num]; 
	for(i=0; i<num; i++){ 	//массив такой же длины как и наша строка заполняем звездочками, потом будем менять на буквы
		b[i]=(char)42;
	}
	printf("%d букв\n", num);
	printword(b, num); 	//отдельная функция для печати слова
	printf("\nпопыток осталось: %d", try);
	while(try>0){ 		//сам игровой процесс
		printf("\nвведите букву");
		
	}
}

void printword(char* a, int num){ //печать слова
	int i;
	printf("\n");
	for(i=0;i<num;i++){
		printf("%c",a[i]);
	}
}

int main(){
	char* word;
	word=menu;
	game(word);
}