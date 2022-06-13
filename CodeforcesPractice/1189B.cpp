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
	vector<lli> v;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}

	sort(v.begin(),v.end());
	if(v[n-1] < v[n-3] + v[n-2]){
		cout<<"YES"<<endl;
		cout<<v[n-3]<<" ";
		fr(i,0,n){
			if(i != n-3){
				cout<<v[i]<<" ";
			}
		}
		cout<<endl;
	}
	
	else{
		cout<<"NO"<<endl;
	}
rt;
}
