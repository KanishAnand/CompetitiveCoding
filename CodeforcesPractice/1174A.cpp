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
	lli n,a;
	vector<lli> v;
	cin>>n;	
	fr(i,0,2*n){
		cin>>a;
		v.pb(a);
	}

	sort(v.begin(),v.end());
	lli sum1=0,sum2=0;
	fr(i,0,n){
		sum1 += v[i];
		//cout<<v[i]<<" ";
	}
	fr(i,n,2*n){
		sum2 += v[i];
		//cout<<v[i]<<" ";
	}
	if(sum1 == sum2){
		cout<<"-1";
	}
	else{
		fr(i,0,2*n){
		//sum += v[i];
		cout<<v[i]<<" ";
	}
	}
	cout<<endl;
rt;
}