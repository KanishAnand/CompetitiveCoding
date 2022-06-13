#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> v;
vector<vector<lli>> adj;
int main(void){
	lli n,m,a,b;
	cin>>n>>m;
	adj.resize(n+4);
	v.push_back(0);
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	set<pair<lli,lli>> st;
	for(int i=1;i<=n;i++){
		st.insert(make_pair(v[i]*adj[i].size(),i));
	}

	lli ans=0;
	lli arr[n+2];

	
	// for(auto itr = st.end();itr != st.begin();itr--)
	auto x=st.begin();
	auto itr=st.end();
	
	while(itr != x){
		auto a = (*itr).second;
		for(int i=0;i<adj[a].size();i++){
			if(arr[adj[a][i]] == 0){
				arr[adj[a][i]] == 1;
				ans += v[adj[a][i]];
			}
		}
		arr[a]=1;
	--itr;
	}
	cout<<ans<<endl;

return 0;
}