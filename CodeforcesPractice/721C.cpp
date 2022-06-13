#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
vector<lli> vis,ans;
vector<vector<struct edge>> adj;
lli n,t,maxx = -1;
struct edge{
	lli cost;
	lli des;
};

lli dfs(lli a,lli cost,lli cnt){
	if(a == n){
		if(cnt > maxx){
			maxx = cnt;
		}
		return 0;
	}
	for(lli i=0;i<adj[a].size();i++){
		lli d = adj[a][i].des;
		lli c = adj[a][i].cost;
		if(vis[d] == 0){
			vis[d] = 1;
			if(cost + c <= t){
				cost += c;
				++cnt;
				dfs(d,cost,cnt);
				--cnt;
				cost -= c;
			}
			vis[d] = 0;
		}
	}
return 0;
}

lli dfs_t(lli a,lli cost,lli cnt){
	if(a == n){
		if(cnt == maxx){
			return 1;
		}
		return 0;
	}
	for(lli i=0;i<adj[a].size();i++){
		lli d = adj[a][i].des;
		lli c = adj[a][i].cost;
		if(vis[d] == 0){
			vis[d] = 1;
			if(cost + c <= t){
				cost += c;
				++cnt;
				//cout<<d<<endl;
				ans.pb(d);
				lli f = dfs_t(d,cost,cnt);
				if(f == 1){
					return 1;
				}
				//cout<<d<<"EM"<<endl;
				ans.pop_back();
				--cnt;
				cost -= c;
			}
			vis[d] = 0;
		}
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli m,a,b,c;
	cin>>n>>m>>t;
	vis.resize(n+1,0);
	adj.resize(n+1);
	fr(i,0,m){
		cin>>a>>b>>c;
		struct edge d;
		d.des = b;
		d.cost = c;
		adj[a].pb(d);
	}	

	vis[1] = 1;
	ans.pb(1);
	dfs(1,0,1);
	vis.resize(n+1,0);
	vis[1] = 1;
	dfs_t(1,0,1);
	cout<<maxx<<"\n";
	fr(i,0,ans.size()){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
rt;
}


		
