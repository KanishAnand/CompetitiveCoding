#include<stdio.h>
#include<string.h>
char s[20];
int l;
int sub(int k);
int swap(int i,int j);
int main(void){
	scanf("%s",s);
	l = strlen(s);
	sub(0);
	return 0;
}

//indexing is 0;
int sub(int k){
	if(k == l - 1)
		printf("%s\n",s);
	for(int i = k ; i < l; i++){		
		if(k != i && s[k] == s[i]){  		//for removing duplicates.
			continue;
		}
		swap(k,i);
		sub(k + 1);
		swap(i,k);
	}
	return 0;
}

int swap(int i,int j){
	char temp;
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	return 0;
}


