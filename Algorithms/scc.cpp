#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int dfs_go(int a);
int dfs();
int dfs_go_trans(int a);
int dfs_trans();
int v;

stack<int> topo;
vector<vector<int>> adj;
vector<vector<int>> trans;

int arr[100005]={0};

//memset
//fill

int dfs_trans(){
	int i,cnt=1;
	while(cnt <= v){
		if(arr[topo.top()] == 0){
			i=topo.top();
			arr[i] = 1;
			cout<<dfs_go_trans(i)<<" ";
			cout<<endl;
			arr[i] = 2;
		}
		topo.pop();
		++cnt;
	}

return 0;
}

int dfs_go_trans(int a){
	
	if(trans[a].size() == 0){
		arr[a] = 2;
		return a;
	}

	for(int i=0;i<trans[a].size();i++){

		if(arr[trans[a][i]] == 0){
			arr[trans[a][i]] = 1;
			cout<<dfs_go_trans(trans[a][i])<<" ";
			arr[trans[a][i]] = 2;
		}
	}
	arr[a] = 2;
return a;
}

int dfs(){
	for(int i=1;i<=v;i++){
		if(arr[i] == 0){
			arr[i] = 1;
			// start_time[i] = t;
			// ++t;
			topo.push(dfs_go(i));
			// finish_time.insert(t,i);
			// ++t;
			arr[i] = 2;
		}
	}
return 0;
}

int dfs_go(int a){
	
	if(adj[a].size() == 0){
		arr[a] = 2;
		return a;
	}

	for(int i=0;i<adj[a].size();i++){
		if(arr[adj[a][i]] == 0){
			arr[adj[a][i]] = 1;
			topo.push(dfs_go(adj[a][i]));
			arr[adj[a][i]] = 2;
		}
	}
	arr[a] = 2;
return a;
}

int main(void){
	int a,b,e;
	cin>>v>>e;
	
	// 0 = white;
	//1 = grey;
	// 2 = black;

	adj.resize(v+1);
	trans.resize(v+1);
	for(int i=0;i<e;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		trans[b].push_back(a);
	}

	dfs();
	for(int i=1;i<=v;i++){
		arr[i] = 0;
	}
	dfs_trans();
	
return 0;
}