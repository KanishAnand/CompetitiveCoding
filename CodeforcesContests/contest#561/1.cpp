#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(val) for(lli i=0;i<val;i++)
#define pb push_back
#define rt return 0;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}
lli arr[30];
lli fun(lli a){
	if(a <= 0 || a == 1){
		return 0;
	}
	else{
		return (a*(a-1))/2;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	lli an=0;	
	
	string st;
	for(int i=0;i<n;i++){
		cin>>st;
		arr[st[0]-'a']++;
	}
	for(int i=0;i<26;i++){
		an += fun(arr[i]/2) + fun(arr[i] - arr[i]/2);
	}
	cout<<an<<endl;
rt;
}
