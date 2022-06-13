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
lli t,n,k,a,beg,endd,mid;
vector<lli> v;
lli fun(lli in){
	lli an;
	vector<lli> g;
	fr(i,0,n){
		an = in - v[i];
		if(an < 0){
			an = 0 - an;
		}
		g.pb(an);
	}
	sort(g.begin(),g.end());
return g[k];
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(lli p=0;p<t;p++){
		cin>>n>>k;	
		lli ans,minn = 10000000000000;
		v.resize(0);
		//cerr<<v.size()<<endl;
		for(lli i=0;i<n;i++){
			cin>>a;
			v.pb(a);
		}
		beg = v[0];
		endd = v[n-1];
		if(k == 0){
			cout<<v[0]<<endl;
		}
		else{
			while(beg < endd){
				mid = (beg + endd)/2;
				lli b,m,e;
				b=fun(mid-1);
				m=fun(mid);
				e=fun(mid+1);
				if(m <= b && m <= e){
					if(m < minn){
						ans = mid;
						minn = m;
						break;
					}
					//break;
				}
				else if(m < b && m > e){
					beg = mid + 1;
					if(e < minn){
						ans = endd;
						minn = e;
					}
				}
				else{
					endd = mid - 1;
					if(b < minn){
						minn = b;
						ans = beg;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
rt;
}
	
