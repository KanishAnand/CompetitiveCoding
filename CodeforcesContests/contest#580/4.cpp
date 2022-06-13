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
	lli n,odd=0;
	vector<lli> v;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		if(a % 2 == 1){
			++odd;
		}
		lli o = a;
		lli c=1;
		while(a > 0){
			lli rem = a%2;
			a /= 2;
			if(rem == 1){
				v[c].pb(o);
			}
			++c;
		}
	}

	for(lli k=1;k<=60;k++){
		if(v[k].size() > 1){
			for(lli i=1;i<v.size();i++){
				for(lli j=i+1;j<v.size();j++){
					adj[v[i]].pb(v[j]);
					adj[v[j]].pb(v[i]);
				}
			}
		}
	}

		
	
