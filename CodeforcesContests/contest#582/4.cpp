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
	lli n,k,a;
	vector<lli> v;
	cin>>n>>k;	
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}

	sort(v.begin(),v.end());
	lli minn = 1000000000;

	for(lli i=0;i<=200000;i++){
		lli ans = 0;
		lli c = k;
		
		for(lli j=0;j<n;j++){
			if(c == 0){
				break;
			}
			if(v[j] == i){
				--c;
			}
			else if(v[j] > i){
				if(v[j] >= 2*i){
					lli x = v[j];
					lli d = 0;
					while(x > i){
						x /= 2;
						++d;
					}
					if(x == i){
						ans += d;
						--c;
					}
				}
				
			}
		}

		if(ans < minn){
//	cout<<"p"<<ans<<endl;
			if(c == 0){
//				cout<<"L"<<ans<<endl;
				minn = ans;
			}
		}
	}
	cout<<minn<<endl;
rt;
}

	
