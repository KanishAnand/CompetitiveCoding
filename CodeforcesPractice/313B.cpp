#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
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
	vector<lli> v;
	v.resize(st.length()+2);
	lli m;
	cin>>m;
	fr(i,0,st.length()-1){
		if(st[i] == st[i+1]){
			v[i]=1;
		}
		else{
			v[i]=0;
		}
	}

	fr(i,1,st.length()){
		v[i] += v[i-1];
	}

	lli l,r,a=0;
	fr(i,0,m){
		cin>>l>>r;
		--l;
		--r;
		a=v[r-1] - v[l];
		if(st[l] == st[l+1]){
			a++;
		}
		cout<<a<<endl;
	}
rt;
}