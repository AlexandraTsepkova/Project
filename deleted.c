int mystrlen(FILE**f){
	int len=0; char a;
	while(fscanf("%c", a)==1){
		len++;
		if ((int)a==32) return len;
	}
}

for(i=0;i<MAX;i++){
		len=mystrlen(&f);
		for(j=0;j<l;j++){
			fgets(a[i][j],len,f);
		}
	}	