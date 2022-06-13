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
	lli n,a,b;
	vector<pair<lli,lli>> v1,v2;
	cin>>n;	
	fr(i,0,n){
		cin>>a>>b;
		if(a < b){
			v1.pb(make_pair(b,i+1));
		}
		else{
			v2.pb(make_pair(a,i+1));
		}
	}

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	if(v1.size() > v2.size()){
		cout<<v1.size()<<endl;
		for(lli i=v1.size()-1;i>=0;i--){
			cout<<v1[i].second<<" ";
		}
		cout<<endl;
	}	
	else{
		cout<<v2.size()<<endl;
		fr(i,0,v2.size()){
			cout<<v2[i].second<<" ";
		}
		cout<<endl;
	}
rt;
}
	
