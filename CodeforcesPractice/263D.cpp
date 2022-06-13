#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<vector<int>> adj;
lli n,m,k,col[100005]={0},flag=0,len[100005],src,t=1;
lli dfs();
lli dfs_go(lli v,lli l);

lli dfs(){
	for(int i=1;i<=n;i++){
		if(col[i] == 0){
			lli l=0;
			len[i] = l;
			col[i] = 1;
			lli y=dfs_go(i,l);
			if(flag == 1){
				cout<<y<<" ";
				flag = 0;
				return 0;
			}
		}
	}
return 0;
}

lli dfs_go(lli v,lli l){
	// if(adj[v].size() == 0){
	// 	return v;
	// }

	for(int i=0;i<adj[v].size();i++){
		if(col[adj[v][i]] == 0){
			col[adj[v][i]] = 1;
			++l;
			len[adj[v][i]] = l;
			lli y = dfs_go(adj[v][i],l);
			if(flag == 1){
				if(y == src){
					flag = 0;
					t = 0;
				}
				cout<<y<<" ";
				return v;
			}
			--l;
		}
		else{
			//cout<<"F"<<v<<endl;
			//cout<<"FD"<<adj[v][i]<<" "<<len[adj[v][i]]<<v<<" "<<len[v]<<endl;
			if(len[v] - len[adj[v][i]]  >= k && t == 1){
				flag=1;
				src = adj[v][i];
				//cout<<v<<adj[v][i];
				cout<<len[v] - len[adj[v][i]] + 1<<endl;
				return v;
			}
		}
	}
return v;
}


int main(void){
	cin>>n>>m>>k;
	adj.resize(n+2);
	lli a,b;
	for(int i=1;i<=n;i++){
		col[i] = 0;
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs();
	cout<<endl;
return 0;
}