#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct bukva{
	
	int val;//сама буква приведенная к инту
	struct bukva* left;
	struct bukva* right;
	int num;//номер буквы в массиве слов
	
};
struct word{
	struct bukva* root;
};
char* menu();
void CHELprint(int v);
int search(struct word*word, char letter);
struct bukva* searchNode(struct bukva* cur, int val);
void treeAdd (struct word *word, char n, int num);
void printword(char* a, int num);
void game(char *a);
int my_strlen(char* a);
int main(){
	
	char* word;
	word=menu();
	game(word);
	return 0;
}
char* menu(){

	int x; FILE*f;
	int n=0, i;
	char* a[12];
	char*c[12];
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
	srand(time(0));
	i=1+rand()%20; 
	printf("%d\n", i);
	while(n<=i){
		fscanf(f,"%s",a);
		n++;
		}
		printf("%s", a);
		return a;
}
void CHELprint(int v){FILE*f;//печать человека(++)
	if (v== 0){f=fopen("0.txt", "r");}
	if (v== 1){f=fopen("1.txt", "r");}
	if (v== 2){f=fopen("2.txt", "r");}
	if (v== 3){f=fopen("3.txt", "r");}
	if (v== 4){f=fopen("4.txt", "r");}
	if (v== 5){f=fopen("5.txt", "r");}
	if (v== 6){f=fopen("6.txt", "r");}
	if (v== 7){f=fopen("7.txt", "r");}
	char c[128];
	while(fscanf(f,"%s",&c)==1){
	printf("%s\n", c);
	}
	fclose(f);
}
int search(struct word*word, char letter){
	
	int k =(int)letter;
	struct bukva * cur=word->root;
	struct  bukva* res;
	res=searchNode(cur,k);
	if(res==NULL){return -1;}
	else return res->num;
}

struct bukva* searchNode(struct bukva* cur, int val){
	
	struct bukva* res=NULL;
	/*if(cur==NULL){return NULL;}
	else if(val>cur->val){res=searchNode(cur->right,val);}
	else if (val<cur->val){res=searchNode(cur->left,val);}
	else {return cur;};
	*/return res;
}
void treeAdd (struct word *word, char n, int num) {
	
	struct bukva *cur = (*word).root;
	struct bukva **curAdd = &((*word).root);
	struct bukva *node = malloc(sizeof(struct bukva));
    int k;
	
	k=(int)n;
	(*node).left=NULL;
	(*node).right=NULL;
	(*node).val=k;
	(*node).num=num;
	
	while (cur!=NULL) {
		if ((*cur).val<k) {
			curAdd = &((*cur).right);
			cur = (*cur).right;
		}
		else {
			curAdd = &((*cur).left);
			cur = (*cur).left;
		}
	}
	
	*curAdd = node;
	
} 

void printword(char* a, int num){ //печать слова
	
	int i;
	printf("\n");
	for(i=0;i<num;i++){
		printf("%c",a[i]);
	}
}
int my_strlen(char* a){
	int count, i;
	i = 0;
		printf("2");
	count = 0;
	printf("3");
	while(a[i]!='\0'){
		count++;
		i++;
	}
	printf("%d",count);
	return count;
}
void game(char * a) {  //передаем нашу строку со словом

	int num;// i, v=0, n=0, k=0, w; 
	int try=7;
	char used[33]; 
	char letter; //v- cчетчик файла; n-счетчик для used, used - уже использованные буквы, letter - буква для считывания
	num=my_strlen(a); 
	printf("%d",num);
	char b[12]; //массив который мы печатаем
	struct word * word;
	/*word->root=NULL;
	
	while(k<num){
		treeAdd(word, a[k], k);
		k++;}
	
	for(i=0; i<num; i++){ 	//массив такой же длины как и наша строка заполняем звездочками, потом будем менять на буквы
		b[i]=(char)42;
	}
	printf("%d букв\n", num);
	printword(b, num); 	//отдельная функция для печати слова
	printf("\nпопыток осталось: %d", try);
	
	while(try>0){ 	//сам игровой процесс
		
		printf("\nвведите букву");
	    scanf("%c", &letter);
		n++;
		used[n]=letter;
		w=search(word, letter);
		if(w==-1){try--;
		CHELprint(v);
		v++;		
		}
		else {b[w]=letter;
		printword(b, num);}
		printf ("\nUSED:");
		printword (used,n);
	}*/
}