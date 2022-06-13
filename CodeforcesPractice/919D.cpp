#include<bits/stdc++.h>
using namespace std;
int counte=0;
int dfs_go(int a);
int dfs();

stack<int> topo;
vector<vector<int>> adj;
int maxl[300005][30]={0},letter[300005];

int arr[300005]={0},v,cycle=0;

int fun(){
	while(!topo.empty()){
		int t = topo.top();
		++maxl[t][letter[t]];
		topo.pop();
		for(int j=0;j<adj[t].size();j++){
			for(int k=0;k<27;k++){
				if(maxl[adj[t][j]][k] < maxl[t][k]){
					maxl[adj[t][j]][k] = maxl[t][k];
				}
			}
			//++maxl[adj[t][j]][letter[adj[t][j]]];
		}
	}
return 0;
}


int dfs(){
	for(int i=1;i<=v;i++){
		if(arr[i] == 0){
			arr[i] = 1;
			topo.push(dfs_go(i));
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
			cycle = 1;
			break;
		}
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
	string str;
	cin>>v>>e;
	cin>>str;
	
	adj.resize(v+1);
	
	for(int i=1;i<=v;i++){
		letter[i] = str[i-1] - 97;
		//cout<<letter[i]<<" ";
	}

	for(int i=0;i<e;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}

	dfs();
	fun();
	if(cycle == 1){
		cout<<"-1"<<endl;
	}
	else{
		int ans=0;
		for(int i=1;i<=v;i++){
			for(int j=0;j<27;j++){
				if(maxl[i][j] > ans){
					//cout<<i<<" "<<j<<endl;
					//cout<<maxl[i][j]<<endl;
					ans = maxl[i][j];
				}
			}
		}
		cout<<ans<<endl;
	}
return 0;
}