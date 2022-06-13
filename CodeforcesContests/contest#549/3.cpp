#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<vector<lli>> adj;
	lli v;
	cin>>v;	
	lli cost[100005]={0};
	adj.resize(v+1);
	lli a,b,root;

	for(int i=0;i<v;i++){
		cin>>a>>b;
		cost[i+1] = b;
		if(a == -1){
			root = i+1;
			continue;
			//a = 0;
		}
		adj[a].push_back(i+1);
	}

	int fl,cnt=0;
	// for(int i=0;i<adj[5].size();i++){
	// 	cout<<adj[5][i]<<" ";
	// 	cout<<cost[7];
	// }

	for(int i=1;i<=v;i++){
		fl=1;
		if(cost[i] == 1){
			for(int j=0;j<adj[i].size();j++){
				if(cost[adj[i][j]] == 0){
					fl=0;
					//break;
				}
			}
			if(fl == 1){
				cnt++;
				cout<<i<<" ";
			}
		}
	}

	if(cnt == 0){
		cout<<"-1";
	}
	cout<<endl;
return 0;
}