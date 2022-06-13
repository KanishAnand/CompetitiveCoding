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
	lli n,a;
	vector<lli> v1,v2,f1,f2;
	cin>>n;	
	f1.resize(n+1);
	f2.resize(n+2);
	fr(i,0,n){
		cin>>a;
		v1.pb(a);
	}
	fr(i,0,n){
		cin>>a;
		v2.pb(a);
	}
	
	f1[n] = v1[n-1];
	f2[n] = v2[n-1];
	// cout<<f1[n]<<" "<<f2[n]<<
	
	for(lli i=n-1;i>=1;i--){
		if(i + 2 <= n){
			f1[i] = v1[i-1] +  max(f2[i+1],f2[i+2]);
			f2[i] = v2[i-1] +  max(f1[i+1],f1[i+2]);
		}
		else{
			f1[i] = v1[i-1] + f2[i+1];
			f2[i] = v2[i-1] +  f1[i+1];
		}
		//cout<<f1[i]<<" "<<f2[i]<<endl;
	}


	cout<<max(f1[1],f2[1])<<endl;
rt;
}
