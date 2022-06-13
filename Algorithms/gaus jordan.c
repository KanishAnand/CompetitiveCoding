#include<stdio.h>
int main(void){
	int i,j,arr[5][5],n,c,k;
	printf("enter size and array");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++){
			scanf("%d",&arr[i][j]);
		}
	}

	for(j=1;j<=n;j++){
		for(i=1;i<=n;i++){
			if(i!=j){
				c = arr[i][j]/arr[j][j];
				for(k=1;k<=n+1;k++){
					arr[i][k] -= c*arr[j][k];
				}
			}
		}
	}

	for(i=1;i<=n;i++){
		j = n + 1;
		printf("%d ",arr[i][j] / arr[i][i]);
	}

return 0;
}
