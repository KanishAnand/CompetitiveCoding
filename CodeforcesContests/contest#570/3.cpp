#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
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
	lli n,q,a,b,k;
	vector<lli> v;
	cin>>q;

	while(q--){
		cin>>k>>n>>a>>b;
		if(n*b < k){
			k -= n*b;
			--k;
			lli c = a - b;
			if(k == 0){
				cout<<"0"<<endl;
			}
			else{
				lli d = k/c;
				cout<<min(d,n)<<endl;
			}
		}
		else{
			cout<<"-1"<<endl;
		}
	}	
rt;
}
	
