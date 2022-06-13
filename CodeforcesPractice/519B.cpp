#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(void){
	lli n;
	cin>>n;
	lli a,sum1=0,sum2=0,sum3=0;
	for(int i=0;i<n;i++){
		cin>>a;
		sum1 += a;
	}
	for(int i=0;i<n-1;i++){
		cin>>a;
		sum2 += a;
	}
	for(int i=0;i<n-2;i++){
		cin>>a;
		sum3 += a;
	}
	cout<<sum1-sum2<<endl;
	cout<<sum2-sum3<<endl;
return 0;
}