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
	lli n;
	vector<lli> v(1000002);
	cin>>n;	
	v[1] = 2;
	// v[n] = (n-1)*3 + 2;

	fr(i,2,1000001){
		v[i] = v[i-1] + (i-1)*3 + 2;
	}
	//cout<<v[1000000]<<endl;
	lli ans = 0;
	fr(i,1,10000001){
		if(n >= v[i]){
			if((n - v[i])%3 == 0){
				++ans;
			}
		}
		else{
			break;
		}
	}
	cout<<ans<<endl;

rt;
}
