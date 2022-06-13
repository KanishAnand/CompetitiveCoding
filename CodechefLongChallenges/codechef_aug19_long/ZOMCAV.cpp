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
	lli t,n,a;
	cin>>t;
	while(t--){
		cin>>n;
		vector<lli> c,h,l,r,arr;
		arr.resize(n+3,0);
		fr(i,0,n){
			cin>>a;
			lli z=0;
			l.pb(max(z,i-a));
			r.pb(min(n-1,i+a));
		}
		fr(i,0,n){
			cin>>a;
			h.pb(a);
		}
		sort(h.begin(),h.end());

		fr(i,0,n){
			arr[l[i]]++;
			arr[r[i]+1]--;
		}

		fr(i,1,n){
			arr[i] += arr[i-1];
		}
		fr(i,0,n){
			c.pb(arr[i]);
		}
		sort(c.begin(),c.end());
		lli flag = 0;
		fr(i,0,n){
			if(c[i] != h[i]){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}	
rt;
}
	
