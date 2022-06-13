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
	lli a,b,q;
	cin>>a>>b;
	lli p = b%a;
	if(p != 0){
		cout<<"-1"<<endl;
		return 0;
	}	
	else{
		q=b/a;
	}
	lli count=0;
	while(q %2 == 0){
		q /= 2;
		++count;
	}

	while(q %3 == 0){
		q /= 3;
		++count;
	}
	if(q != 1){
		cout<<"-1"<<endl;
		return 0;
	}
	else{
		cout<<count<<endl;
	}
return 0;
}