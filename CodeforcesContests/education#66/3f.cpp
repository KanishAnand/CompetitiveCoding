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
	lli t,n,k;
	cin>>t;
	fr(p,0,t){
		cin>>n>>k;
		lli a;
		vector<lli> v;
		fr(i,0,n){
			cin>>a;
			v.pb(a);
		}
		lli beg=0,endd=k,mid,min=1000000000000,ans;
		while(1){	
			mid = (v[beg] + v[endd])/ 2;
			if(-v[beg] + mid > v[endd] - mid){
				if(-v[beg] + mid < min){
					min = -v[beg] + mid;
					ans = mid;
				}
			}
			else{
				if(v[endd] - mid < min){
					min = v[endd] - mid;
					ans = mid;
				}
			}
			++beg;
			++endd;
			if(endd >= n){
				break;
			}
		}
		cout<<ans<<endl;	
	}	
rt;
}
	
