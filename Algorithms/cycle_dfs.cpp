#include<bits/stdc++.h>
using namespace std;
int counte=0;
int dfs_go(int a);
int dfs();
vector<vector<int>> adj;
int arr[100]={0},v,counte=0;

int dfs(){
	for(int i=1;i<=v;i++){
		if(arr[i] == 0){
			arr[i] = 1;
			cout<<dfs_go(i)<<" ";
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
		if(arr[adj[a][i]] == 1){
			++counte;
		}
		if(arr[adj[a][i]] == 0){
			arr[adj[a][i]] = 1;
			cout<<dfs_go(adj[a][i])<<" ";
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
	for(int i=0;i<e;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	dfs();
	cout<<endl;
	if(counte != 0)
	cout<<"1"<<endl;    //no of backedges
return 0;
}