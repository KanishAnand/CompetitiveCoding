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
	lli n;
	string st;
	vector<lli> v;
	cin>>n;	
	cin>>st;
	lli open=0,close=0,cnt=0;
	fr(i,0,st.length()){
		if(st[i] == '('){
			cnt += close;
			close = 0;
			++open;
		}
		else{
			++close;
			lli x = min(open,close);
			close -= x;
			open -= x;
		}
	}
	cnt += close;
	// cout<<cnt<<close<<open<<endl;
	if(cnt == 0 && open == 0){
		cout<<"YES";
	}
	else if(cnt == 1){
		if(open == 1){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
	}
	else{
		cout<<"NO";
	}
	cout<<endl;
rt;
}
	
