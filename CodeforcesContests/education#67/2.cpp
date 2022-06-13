#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
lli input(lli n,vector<lli> &ve);
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
	lli n,m;
	vector<vector<lli>> v;
	v.resize(27);
	cin>>n;	
	string st;
	cin>>st;
	cin>>m;
	fr(i,0,st.length()){
		v[st[i]-'a'].pb(i);
	}

	fr(i,0,m){
		string s;
		cin>>s;
		lli maxx = -1;
		vector<lli> arr(26,0);
		fr(i,0,s.length()){
			lli a = v[s[i]-'a'][arr[s[i]-'a']];	
			//cout<<a<<endl;
			arr[s[i]-'a']++;
			++a;
			if(a > maxx){
				maxx = a;
			}
		}
		cout<<maxx<<endl;
	}
rt;
}
