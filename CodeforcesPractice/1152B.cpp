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

lli check(lli a){
	for(auto it=st.begin();it != st.end(); it++){
		auto p = (*it).first;
		if(p == a){
			return 1;
		}
	}
return 0;
}

lli fin(lli a){
	for(auto it=st.begin();it != st.end(); it++){
		auto p = (*it).first;
		if(p >= a){
			return 1;
		}
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	set<pair<lli,lli>> st;	
	st.insert(make_pair(1,0));
	lli x=1;
	for(int i=1;i<=31;i++){
		st.insert(make_pair(x*2,i));
		x*=2;
	}

	lli c=0;
	while(1){
		int a=check(n+1);
		if(a == 1){
			break;
		}
		else{
			++c;
			fin(n);
		}
	}
	
