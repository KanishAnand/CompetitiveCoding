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
	lli n,m,t,a,b;
	
	vector<lli> v;
	cin>>t;
	fr(pt,0,t){
		cin>>n>>m;
		vector<lli> arr(n+2,0);
		vector<vector<lli>> adj;
		vector<lli> ve,ans;
		set<pair<lli,lli>> st;
		adj.resize(n+2);
		fr(i,0,m){
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		for(lli i=1;i<=n;i++){
			st.insert(make_pair(adj[i].size(),i));
		}
		// for(auto it=st.begin();it!=st.end();it++){
		// 	ve.pb((*it).second);
		// }
		// reverse(ve.begin(),ve.end());
		//for(lli i=0;i<ve.size();i++){
		set<pair<lli,lli>>::reverse_iterator rit;

		for(rit = st.rbegin();rit!=st.rend();rit++){
			//lli in = ve[i];
			lli in=(*rit).second;
			if(arr[in] == 0){
				arr[in] =1;
				ans.pb(in);
				for(int j=0;j<adj[in].size();j++){
					arr[adj[in][j]] = 1;
				}
			}
		}
		cout<<ans.size()<<endl;
		for(lli i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}	
rt;
}	
