#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
vector<vector<lli>> adj;
vector<lli> v1,v2;
int itn=200005;
int col[200005],flag=0;
//vector<vector<int>> arr;
lli in[300000],out[300000];


lli color(lli in){
	//cout<<in<<endl;
	if(col[in] == 1){
		for(int j=0;j<adj[in].size();j++){
			if(col[adj[in][j]] == 1){
				flag = 1;
				return 0;
			}
			if(col[adj[in][j]] == 3){
				col[adj[in][j]] = 0;
				color(adj[in][j]);	
			}
		}
	}
	else{
		for(int j=0;j<adj[in].size();j++){
			if(col[adj[in][j]] == 0){
				flag = 1;
				return 0;
			}
			if(col[adj[in][j]] == 3){
				col[adj[in][j]] = 1;
				color(adj[in][j]);
			}
		}
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	lli n,m,a,b;
	cin>>n>>m;

	adj.resize(n+2);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v1.push_back(a);
		//v2.push_back(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	

	for(int i=0;i<=n;i++){
		col[i] = 3;
	}

	for(int i=1;i<=n;i++){
		
		if(col[i] == 3){
			col[i] = 1;
			color(i);
		}
	}

	if(flag == 1){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		for(int i=0;i<m;i++){
			cout<<col[v1[i]];
		}
	}
	cout<<endl;
return 0;
}
