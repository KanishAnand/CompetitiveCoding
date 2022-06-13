#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> v;
int main(void){
	lli n,c,t,a;
	cin>>n>>t>>c;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	lli count=0,ans=0;
	for(int i=0;i<c;i++){
		if(v[i] <= t){
			++count;
		}
	}

	if(count == c){
		ans++;
	}

	lli be=0;
	for(int i=c;i<n;i++){
		if(v[be] <= t){
			--count;
		}
		if(v[i] <= t){
			++count;
		}
		if(count == c){
			++ans;
		}
		++be;
	}
	cout<<ans<<endl;
return 0;
}