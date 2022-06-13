#include<stdio.h>
#include<math.h>
typedef long long int lli;
lli fact(lli n);
int main(void){
	char a[12],b[12];
	lli n1,n2,p,count=0,n=0,m,countf=0;
	scanf("%s%s",a,b);
	for(int i = 0; a[i] != '\0'; i++){
		if(a[i] == '+'){
			++count;
		}
		else{
			--count;
		}
		if(b[i] == '+'){
			++countf;
		}
		if(b[i] == '-'){
			--countf;
		}
		if(b[i] == '?'){
			++n;
		}
	}
	
	m = count - countf;
	if(m > n || n + m < 0){
		printf("0.000000000\n");
		return 0;
	}
	
	else{
		p = fabs(m);
		n1 = p + (n - p)/2;
		n2 = (n-p)/2;
	}
	
	double ans = (float)fact(n)/(fact(n1)*fact(n2)*pow(2,n));
	printf("%0.9lf\n",ans);
return 0;
}

lli fact(lli n){
	lli ans=1;
	for(lli i=n;i>=1;i--){
		ans *= i;
	 }
return ans;
}


