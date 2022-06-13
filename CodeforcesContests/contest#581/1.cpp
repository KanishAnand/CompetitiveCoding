#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
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
	lli n,a,cnt=0;
	string st;
	vector<lli> v;
	cin>>st;
	lli l = st.length();
	for(lli i=0;i<l;i++){
		if(st[i] == '1'){
			++cnt;
		}
	}	
	lli x = l - 1;
	lli y = x/2 + x%2;
	if(cnt > 1 && x %2 == 0){
		cout<<y+1<<endl;
	}
	else{
		cout<<y<<endl;
	}
rt;
}
	
