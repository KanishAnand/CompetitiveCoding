#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,t,key=0,a,b;
	cin>>n>>t;
	lli min = 10000000000,val;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a >= t){
			val = a;
			//cout<<val<<endl;
		}
		else{
			while(a < t){
				a += b;
			}
			val = a;
		}

		if(val < min){
			min = val;
			//cout<<i<<endl;
			key = i+1;
		}
	}

	cout<<key<<endl;
return 0;
}
