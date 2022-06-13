#include<stdio.h>
char arr[110][110]={0},new[110][110],c;
int n,m;
void task(int i,int j);
int check(int i,int j);
int main(void){
	int flag=1;
	scanf("%d %d",&n,&m);
	scanf("%c",&c);

	for(int i=0; i<n; i++){
		for(int j=0;j<m;j++){
		//	scanf("%1c",&arr[i][j]);
			arr[i][j] = getc(stdin);
		}
		scanf("%c",&c);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			new[i][j] = '0';
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == '*'){
			//	printf("%d %d\n",i,j);
				task(i,j);
			}
		}
	}
	

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		//	printf("div %c\n",new[0][1]);
			if(arr[i][j] != '*' && arr[i][j] != '.'){
				if(arr[i][j] != new[i][j]){
		//			printf("kan %d %d arr%c new%c",i,j,arr[i][j],new[i][j]);
					flag = 0;
					break;
				}
			}
			if(arr[i][j] == '.'){
	//			printf("%d %d\n",i,j);
				flag = check(i,j);
	//			printf("%d",flag);
				if(flag == 0){
					break;
				}
			}
		}
		if(flag == 0){
			break;
		}
	}

	if(flag == 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

return 0;
}

void task(int i,int j){
	new[i-1][j]+=1;
	new[i+1][j]+=1;
	new[i][j+1]+=1;
	new[i+1][j-1]+=1;
	new[i-1][j+1]+=1;
	new[i+1][j+1]+=1;
	new[i-1][j-1]+=1;
	new[i][j-1]+=1;
}

int check(int i,int j){
	for(int k=i-1;k<=i+1;k++){
		for(int l=j-1;l<=j+1;l++){
			if((k == i && l == j) || k < 0 || l < 0 || k >= n || l >= m){
				continue;
			}
			else{
				if(arr[k][l] == '*'){
					return 0;
				}
			}
		}
	}
return 1;
}
