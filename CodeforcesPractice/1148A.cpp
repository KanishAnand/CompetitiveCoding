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
	lli a,b,c;
	vector<lli> v;
	cin>>a>>b>>c;
	lli ans =0;
	if(a > b){
		ans = 2*b+1+c*2; 
	}	
	else if(b > a){
		ans = 2*a +1+ c*2;
	}
	else{
		ans = 2*a + 2*c;
	}
	cout<<ans<<endl;
rt;
}
	
