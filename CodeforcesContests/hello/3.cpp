#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int min(int a,int b);
int main(void){
	int n;
	char s[600000];
	int arra[600000]={0},arrb[600000]={0};
	cin>>n;
	int perfect = 0,max=0;

	for(int i=0;i<n;i++){
		cin>>s;
		int a=0,b=0,sumb=0,suma=0;
		int p = strlen(s);
		for(int j=0;j<p;j++){
			if(s[j] == '('){
				++a;
			}
			else{
				++b;
				if(a >= b){
					a -= b;
					b = 0;
				}
				else{
					//b -= a;
					//a = 0;
					sumb += b;
					b = 0;
				}
			}
		}
		suma += a;
	/*	if(suma > max){
			max = suma;
		}
		if(sumb > max){
			max = sumb;
		}
	
	*/	if(suma == 0 && sumb == 0){
			++perfect;
		}
		else if(suma == 0){
			++arrb[sumb];
		}
		else if(sumb == 0){
			++arra[suma];
		}
	}

	int ans=0;
	ans += perfect/2;

	for(int i=1;i<=550000;i++){
		ans += min(arra[i],arrb[i]);
	}
	cout<<ans<<endl;
return 0;
}

int min(int a,int b){
	return a < b ? a : b;
}
