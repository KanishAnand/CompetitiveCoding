#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli col[100005]={0},colt[100005]={0};
stack<lli> topo;
vector<lli> v;
lli ans=1,n,sum=0;
vector<vector<lli>> adj,adjtt;
lli mod=1000000007;
lli dfs_go1(lli a,vector<lli> &vv);
lli dfs_go(lli a);
lli dfs();
lli dfs1();
lli dfs1(){
	while(!topo.empty()){
		//cout<<"FD"<<endl;
		lli i=topo.top();
		topo.pop();
		if(colt[i] == 0){
			colt[i] = 1;
			vector<lli> vv;
			//cout<<i<<endl;
			dfs_go1(i,vv);
			vv.push_back(i);
			colt[i] = 2;
			lli min=100000000000;
			for(int i=0;i<vv.size();i++){
				if(v[vv[i] - 1] < min){
					min = v[vv[i]-1];
				}
			}
			sum += min;
			lli cnt=0;
			for(int i=0;i<vv.size();i++){
				if(v[vv[i]-1] == min){
					++cnt;
				}
			}
			ans *= cnt%mod;
			ans %= mod;
		}
		else{
			continue;
		}
	}
return 0;
}

lli dfs_go1(lli a,vector<lli> &vv){
	if(adjtt[a].size() == 0){
		return 0;
	}
	for(int i=0;i<adjtt[a].size();i++){
		if(colt[adjtt[a][i]] == 0){
			colt[adjtt[a][i]] = 1;
			vv.push_back(adjtt[a][i]);
			dfs_go1(adjtt[a][i],vv);
			colt[adjtt[a][i]] = 2;
		}
	}
return 0;
}

lli dfs(){
	for(int i=1;i<=n;i++){
		if(col[i] == 0){
			col[i] = 1;
			dfs_go(i);
			topo.push(i);
			col[i]=2;
		}
	}
return 0;
}

lli dfs_go(lli a){
	if(adj[a].size()==0){
		return 0;
	}
	for(int i=0;i<adj[a].size();i++){
		if(col[adj[a][i]] == 0){
			col[adj[a][i]] = 1;
			dfs_go(adj[a][i]);
			topo.push(adj[a][i]);
			col[adj[a][i]] = 2;
		}
	}
return 0;
}

int main(void){
	lli m,a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}	
	cin>>m;
	adj.resize(n+3);
	adjtt.resize(n+3);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adjtt[b].push_back(a);
	}
	dfs();
	//cout<<"DF"<<endl;
	dfs1();
	cout<<sum<<" "<<ans<<endl;
return 0;
}