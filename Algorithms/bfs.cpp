#include<bits/stdc++.h>
using namespace std;
int arr[100]={0};
vector<vector<int>> adj;
queue <int> qu;

int bfs(int a){
	for(int i=0;i<adj[a].size();i++){
		if(arr[adj[a][i]] == 0){
			qu.push(adj[a][i]);
			arr[adj[a][i]] = 1;
		}
	}
	cout<<a<<" ";
	arr[a] = 2;
	qu.pop();
	if(qu.empty()){
		return 0;
	}
	bfs(qu.front());
return 0;
}

int main(void){
	int a,b,v,e;
	cin>>v>>e;
	adj.resize(v+1);
	for(int i=0;i<e;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	//	adj[b].push_back(a);   // for undirected add this line
	}

	for(int i=1;i<=v;i++){
		if(arr[i] == 0){
			qu.push(i);
			arr[i] = 1;
			bfs(i);
		}
	}
return 0;
}