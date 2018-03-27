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
	while(n<=i){
		fscanf(f,"%s",a);
		n++;
		}
	return a;
}


void game(char *a) {  //передаем нашу строку со словом

	int num, i, v=0, n=0, k=0, w; int try=7; char* used[33]; char letter; //v- четчик файла; n-счетчик для used, used - уже использованные буквы, letter - буква для считывания
	num=strlen(a);
	char* b[num]; //массив который мы печатаем
	struct word * word;
	word->root=NULL;
	
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
		used[n]=letter;
		n++;
		w=search(word, letter);
		if(w==-1){try--;
		CHELprint(v);
		v++;		
		}
	}
}
void CHELprint(int v){FILE*f;
	if (v== 0){f=fopen("0.txt", "r");}
	if (v== 1){f=fopen("1.txt", "r");}
	if (v== 2){f=fopen("2.txt", "r");}
	if (v== 3){f=fopen("3.txt", "r");}
	if (v== 4){f=fopen("4.txt", "r");}
	if (v== 5){f=fopen("5.txt", "r");}
	if (v== 6){f=fopen("6.txt", "r");}
	if (v== 7){f=fopen("7.txt", "r");}
	
}
int search(struct word*word, char letter){
	
	int k =(int)letter;
	struct bukva * cur=word->root;
	struct  bukva* res;
	res=searchNode(cur,k);
	if(res==NULL){return -1;}
	else return res->num;
}

struct bukva*searchNode(struct bukva*cur, int val){
	
	struct bukva*res=NULL;
	if(cur==NULL){return NULL;}
	else if(val>cur->val){res=searchNode(cur->right,val)}
	else if (val<cur->val){res=searchNode(cur->left,val)}
	else {return cur;};
	return res;
}
void treeAdd (struct word *word, char n, int num) {
	
	struct TreeNode *cur = (*word).root;
	struct TreeNode **curAdd = &((*word).root);
	struct TreeNode *node = malloc(sizeof(struct bukva));
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

int main(){
	
	char* word;
	word=menu;
	game(word);
}