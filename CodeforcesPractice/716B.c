#include<stdio.h>
#include<string.h>
char s[52000],arr[250],k=0,p[27],counter=0;
void print();
int firstcheck();
int main(void){
	int n,c;
	scanf("%s",s);
	n = strlen(s);
	c = firstcheck();
	if(c == 0){
		k = 0;
		print();
	}
	else{
		c = check(i+1);
		if(c == 0){
			print();
		}
		else{
			check(i+1);
		}
	}
return 0;
}

void print(){
	for(int i = 0; i < 26; i++){
		if(s[i] != '?'){
			printf("%c",arr[i]);
		}
		else{
			printf("%c",p[k]);
			k++;
		}
	}
	printf("\n");
exit 0;
}

int firstcheck(){
	for(int i = 0;i < 26; i++){
		arr[s[i]]++;
	}

	for(int i = 'A';i <= 'Z';i++){
		if(arr[i] == 0){
			k++;
			p[k] = i;
		}
		if(arr[i] > 1){
			counter++;
		}
	}

	if(counter == 0){
	       return 0;
	}

return 1;
}







