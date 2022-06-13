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
	string st;
	lli n;
	cin>>n;	
	cin>>st;
	if(st[0] == ')' || st[n-1] == '(' || n % 2 == 1){
		cout<<":("<<endl;
		return 0;
	}
	
	int p = n-2,flag=0;

	for(int i=1;i<=p/2;i++){
		if(st[i] == ')'){
			flag = 1;
		}
	}
	
	for(int i=p/2+1;i<n-1;i++){
		if(st[i] == '('){
			flag = 1;
		}
	}

	if(flag == 1){
		cout<<":("<<endl;
		return 0;
	}
	else{
		for(int i=0;i<=p/2;i++){
			cout<<"(";
		}
		for(int i=p/2+1;i<n;i++){
			cout<<")";
		}
	}
	cout<<endl;
return 0;
}