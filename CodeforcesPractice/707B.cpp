#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct box{
	lli val;
	lli cost;
};

int main(void){
	lli n,m,k,a,b,c;
	cin>>n>>m>>k;
	if(k == 0 || k == n){
		cout<<"-1"<<endl;
		return 0;
	}
	vector<vector<struct box>> adj;
	adj.resize(n+2);

	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		struct box m,p;
		m.val = b;
		m.cost = c;
		p.val = a;
		p.cost=c;
		adj[a].push_back(m);
		adj[b].push_back(p);
	}
	vector<lli> v;
	lli arr[n+4]={0};

	for(int i=0;i<k;i++){
		cin>>a;
		arr[a] = 1;
		v.push_back(a);
	}
	lli min=100000000000;

	for(auto a : v){
		for(int i=0;i<adj[a].size();i++){
			if(arr[adj[a][i].val] != 1){
				if(adj[a][i].cost < min){
					min = adj[a][i].cost;
				}
			}
		}
	}
	if(min == 100000000000){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<min<<endl;
return 0;
}