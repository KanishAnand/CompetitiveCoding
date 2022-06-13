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

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string st;
	cin>>st;
	lli m,l,r,k;
	cin>>m;	
	fr(m){
		cin>>l>>r>>k;
		l--;r--;
		string tmp;
		for(int j=0;j<l;j++){
			tmp.pb(st[j]);
		}
		//cout<<tmp<<endl;
		lli c=r-l+1;
		k %= c;
		for(int j=r-k+1;j<=r;j++){
			tmp.pb(st[j]);
		}
		//cout<<tmp<<endl;
		for(int j=l;j<r-k+1;j++){
			tmp.pb(st[j]);
		}
		//cout<<tmp<<endl;
		for(int j=r+1;j<st.length();j++){
			tmp.pb(st[j]);
		}
		//cout<<tmp<<endl;
		st=tmp;
		//cout<<st<<endl;
	}	
	cout<<st<<endl;
rt;
}
