#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c;
	int x,y,z;
	cin>>x>>y>>z;
	cin>>a>>b>>c;
	if(a < x ){
		cout<<"NO"<<endl;
		return 0;
	}
	a = a - x;
	if(a + b < y ){
		cout<<"NO"<<endl;
		return 0;
	}
	int p = a + b -y;
	if(p + c < z ){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
return 0;
}

