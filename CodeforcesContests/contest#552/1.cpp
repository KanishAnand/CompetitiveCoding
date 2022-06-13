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
	vector<lli> v;
	lli a,b,c,k,d,max=0;
	for(int i=0;i<4;i++){
		cin>>a;
		if(a > max){
			max = a;
			k = i;
		}
		v.push_back(a);
	}
	for(int i=0;i<4;i++){
		if(i != k){
			cout<<max  - v[i]<<" ";
		}
	}
	cout<<endl;
return 0;
}

