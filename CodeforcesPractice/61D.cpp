#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}
struct edge{
	lli des,wt;
};

vector<lli> vis,ans;
vector<vector<struct edge>> adj;

lli fun(lli a,lli cst){
	for(lli i=0;i<adj[a].size();i++){
		lli d = adj[a][i].des;
		lli w = adj[a][i].wt;
		if(vis[d] == 0){
			cst += w;
			ans[d] += cst;
			vis[d] = 1;
			fun(d,cst);
			cst -= w;
		}
	}
rt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a,b,w;
	lli sum=0;
	cin>>n;	
	struct edge t,p;
	adj.resize(n+2);
	vis.resize(n+1,0);
	ans.resize(n+1,0);
	fr(i,0,n-1){
		cin>>a>>b>>w;
		t.des = b;
		t.wt = w;
		p.des = a;
		p.wt = w;
		sum += w;
		adj[a].pb(t);
		adj[b].pb(p);
	}

	vis[1] = 1;
	fun(1,0);
	sum = 2*sum;
	lli pq=0,an;

	fr(i,1,n+1){
		an = max(pq,ans[i]);
		pq = an;
	}

	cout<<sum-an<<endl;
rt;
}




	
