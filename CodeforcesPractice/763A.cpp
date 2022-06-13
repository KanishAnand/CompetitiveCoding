#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a,b;
	vector<lli> col;
	vector<vector<lli>> adj,v;
	cin>>n;	
	adj.resize(n+2);
	v.resize(n+2);
	col.resize(n+1);
	fr(i,0,n-1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	fr(i,1,n+1){
		cin>>a;
		col[i]=a;
	}

	lli key=0,an,ke=0,p;

	fr(i,1,n+1){
		lli x = col[i],diff=0;
		fr(j,0,adj[i].size()){
			if(col[adj[i][j]] != x){
				diff++;
				v[i].pb(adj[i][j]);
			}
		}
		if(diff > 1){
			an = i;
			key++;
		}
		if(diff == 1){
			p = i;
			ke++;
		}
	}

	if(key > 1){
		cout<<"NO"<<"\n";
		rt;
	}

	if(key == 0){
		if(ke == 0){
			cout<<"YES"<<"\n";
			cout<<"1"<<"\n";
			rt;
		}
		else{
			if(ke == 2){
				cout<<"YES"<<"\n";
				cout<<p<<"\n";
				rt;
			}
			else{
				cout<<"NO"<<"\n";
				rt;
			}
		}
	}

	lli flag = 0;

	for(lli i=0;i<adj[an].size();i++){
		lli x = adj[an][i];
		if(v[x].size() != 0){
			if(v[x][0] != an){
				flag = 1;
				break;
			}
		}
	}

	if(flag == 1){
		cout<<"NO"<<"\n";
		rt;
	}
	else{
		cout<<"YES"<<"\n";
		cout<<an<<"\n";
		rt;
	}
rt;
}



		
