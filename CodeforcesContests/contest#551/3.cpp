#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
vector<char> ans,ans2;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	string st;
	cin>>n;
	cin>>st;
	if(st[0] == ')' || st[n-1] == '(' || n % 2 == 1){
		cout<<":("<<endl;
		return 0;
	}

	lli op=0,cl=0;

	for(int i=0;i<n;i++){
		if(st[i] == '?'){
			++op;
		}
		else if(st[i] == ')'){
			++cl;
			ans.push_back(')');
		}
		else{
			++op;
			ans.push_back('(');
		}
	}

return 0;
}