#include<stdio.h>
#include<string.h>
int main(void){
	int n;
	char s[201][201],a[210],b[210];
	int f=0,p,arr[200]={0},c[210]={0},arr2[200]={0},c2[210]={0};
	scanf("%d",&n);
	p = 2*n - 2;

	for(int i=0;i<p;i++){
		scanf("%s",s[i]);
	}

	for(int j=0;j<p;j++){
		if(strlen(s[j]) == n-1){
			if(f == 0){
				strcpy(a,s[j]);
				f = 1;
				continue;
			}
			if(f == 1){
				strcpy(b,s[j]);
				break;
			}
		}
	}
	a[n-1] = b[n-2];         //either of these two is final string
		
	int w[220];
	int l,m;
	for(int j=0;j<p;j++){
		l = strlen(s[j]);
		if(arr[l] == 1){
			if(c[l] == 1){
				w[j] = 'S';
			}
			else{
				w[j] = 'P';
			}
			continue;
		}
		else{
			m = strncmp(s[j],a,l);
			if(m == 0){
				w[j] = 'P';
				c[l] = 1;
			}
			else{
				w[j] = 'S';
				c[l] = 2;
			}
		arr[l] = 1;
		}
	}

	int flag = 1;
	for(int i=0;i<p;i++){
		if(w[i] == 'P'){
			int c=strncmp(a,s[i],strlen(s[i]));	
			if(c != 0){
				flag = 0;
				break;
			}
		}
		else if(w[i] == 'S'){
			int c = strncmp(s[i],a+n-strlen(s[i]),strlen(s[i]));
			if(c != 0){
				flag = 0;
				break;
			}
		}
	}

	if(flag == 0){
		int l,m;
	        for(int j=0;j<p;j++){
        	        l = strlen(s[j]);
                	if(arr2[l] == 1){
                        	if(c2[l] == 1){
					w[j] = 'S';
        	                }
                	        else{
                        	        w[j] = 'P';
	                        }
        	                continue;
                	}
	                else{
        	                m = strncmp(s[j],b,l);
                	        if(m == 0){
					w[j] = 'P';
        	                        c2[l] = 1;
                	        }
                        	else{
                                	w[j] = 'S';
                	                c2[l] = 2;
                        	}
	                arr2[l] = 1;
        	        }
	        }
	}
	
	for(int i=0;i<p;i++){
		printf("%c",w[i]);
	}
	printf("\n");
return 0;
}
