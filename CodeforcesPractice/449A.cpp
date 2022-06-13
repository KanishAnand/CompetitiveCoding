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
	lli n,m,k;
	vector<lli> v;
	cin>>n>>m>>k;
	if(k > n + m - 2){
		cout<<"-1\n";
	}	
	else{
		lli val1 = m/(k+1);
		val1 *= n;
		lli val2 = n/(k+1);
		val2 *= m;
		cout<<max(val1,val2)<<endl;
	}
rt;
}
	
