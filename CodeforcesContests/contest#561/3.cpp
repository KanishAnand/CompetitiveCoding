#include<bits/stdc++.h>
using namespace std;
#define lli double
#define llu unsigned long long int
#define fr(val) for(int i=0;i<val;i++)
#define pb push_back
#define rt return 0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a;
	vector<lli> v;
	cin>>n;	
	set<lli> st;
	fr(n){
		cin>>a;
		if(a < 0){
			a = -a;
		}
		v.pb(a);
	}


	lli ans=0;
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=1;i--){
		auto it = lower_bound(v.begin(),v.end(),v[i]/2);
		if(it != v.end()){
			int ff = it - v.begin();
			ans += i - ff;
		}
	}
	cout<<(long long int)ans<<endl;
return 0;
}

