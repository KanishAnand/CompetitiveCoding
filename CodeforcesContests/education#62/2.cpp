#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t,n;
	cin>>t;
	string st;
	for(int j=0;j<t;j++){
		cin>>n;
		cin>>st;
		int a=-1,b=-1,a1=-1,b1=-1;
		for(int i=n-1;i>=0;i--){
			if(st[i] == '<'){
				a = i;
				break;
			}
		}

		for(int i=n-1;i>=a;i--){
			if(st[i] == '>'){
				b = i;
			}
		}

		for(int i=0;i<n;i++){
			if(st[i] == '>'){
				a1 = i;
				break;
			}
		}

		for(int i=0;i<=a1;i++){
			if(st[i] == '<'){
				b1 = i;
			}
		}

		if(a == -1 || b == -1 || a1 == -1 || b1 == -1){
			//cout<<a<<" "<<b<<endl;
			cout<<"0"<<endl;
		}
		else{
			cout<<"1"<<endl;
		}
	}
return 0;
}

