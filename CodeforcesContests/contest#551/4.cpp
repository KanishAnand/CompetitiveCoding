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
	if(st[0] == ')' || st[n-1] == '(' || n % 2 == 1 || st[n-3] == '(' || st[2] == ')'){
		cout<<":("<<endl;
		return 0;
	}
	
	int p = n-2,flag=0,op=0,cl=0;
	ans.push_back('(');
	ans.push_back('(');
	if(n > 4){
		for(int i=2;i<n-2;i++){
			if(st[i] == '('){
				++op;
			}
			if(st[i] == ')'){
				++cl;
			}
		}
	}
	ans.push_back(')');
	ans.push_back(')');
	cout<<endl;
return 0;
}