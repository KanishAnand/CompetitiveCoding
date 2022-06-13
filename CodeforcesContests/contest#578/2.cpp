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
	lli n,a,t,m,k;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		vector<lli> v;
		fr(i,0,n){
			cin>>a;
			v.pb(a);
		}
		lli flag = 0;
		fr(i,0,n-1){
			lli x = v[i] - v[i+1];
			if(x < 0){
				x = -x;
			}
			if(x <= k){
				lli y = v[i+1] - k;
				lli p=0;
				y = max(p,y);
				lli t = v[i] - y;
				m += t;
			}
			else{
				if(v[i+1] > v[i]){
					lli y = v[i+1] - k;
					lli p=0;
					y = max(p,y);
					lli t = y - v[i];
					if(m >= t){
						m -= t;
					}
					else{
						flag = 1;
						break;
					}
				}
				else{
					lli y = v[i+1] - k;
					lli p=0;
					y = max(p,y);
					lli t = v[i] - y;
					m += t;
				}
			}
		}

		if(flag == 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
rt;
}
	
	
