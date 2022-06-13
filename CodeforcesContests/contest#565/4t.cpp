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

lli bfs(lli a,queue<lli> &qu,vector<vector<lli>> &adj,vector<lli> &vis,vector<lli> &ans,vector<lli> &st1,vector<lli> &st2){
	while(!qu.empty()){
		a = qu.front();
		vis[a] = 1;
		for(lli i=0;i<adj[a].size();i++){
			if(vis[adj[a][i]] == 0){
				qu.push(adj[a][i]);
				vis[adj[a][i]] = 1;
				if(ans[a] == 1){
					ans[adj[a][i]] = 2;
					st2.pb(adj[a][i]);
				}
				else{
					ans[adj[a][i]] = 1;
					st1.pb(adj[a][i]);
				}
			}
		}
		qu.pop();
	}
rt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,t,m,a,b;
	vector<lli> v;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<lli>> adj;
		vector<lli> vis(n+2,0),ans(n+2,0);
		vector<lli> st1,st2;
		queue<lli> qu;
		adj.resize(n+2);
		fr(i,0,m){
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		ans[1] = 1;
		st1.pb(1);
		qu.push(1);
		bfs(1,qu,adj,vis,ans,st1,st2);
		if(st1.size() < st2.size()){
			cout<<st1.size()<<endl;
			fr(i,0,st1.size()){
				cout<<st1[i]<<" ";
			}
		}
		else{
			cout<<st2.size()<<endl;
			fr(i,0,st2.size()){
				cout<<st2[i]<<" ";
			}
		}
		cout<<endl;
	}
rt;
}	
	
