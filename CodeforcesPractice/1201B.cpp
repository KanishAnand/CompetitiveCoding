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
	lli n,sum=0,a,ma=-1;
	vector<lli> v;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		v.pb(a);
		sum += a;
		if(a > ma){
			ma = a;
		}
	}

	if(sum % 2 == 0 && sum - ma >= ma){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
rt;
}
	
