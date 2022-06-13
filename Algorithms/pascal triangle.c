#include<stdio.h>
int main(void){
    int n,i,j,s[100];
    
    printf("enter no of lines");
    scanf("%d",&n);
    
        for(i=0;i<n;i++){
            s[0]=1;
    
            for(j=0;j<=i;j++){
                printf("%d",s[j]);  
    
                s[j+1]=(i-j+1)/j * s[j];
            }
        
        printf("\n");
        }
return 0;
}
