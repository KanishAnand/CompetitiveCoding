#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli input(lli n,vector<lli> &ve);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--){
		lli n,m,v,u;
		cin>>n>>m;
		vector<lli> ans;
		vector<lli> vis(3*n+2,0);
		fr(i,0,m){
			cin>>v>>u;
			if(vis[v] == 0 && vis[u] == 0){
				vis[v] = 1;
				vis[u] = 1;
				ans.pb(i+1);
			}
		}

		if(ans.size() >= n){
			cout<<"Matching"<<endl;
			fr(i,0,n){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
		else{
			lli c=0;
			cout<<"IndSet"<<endl;
			fr(i,1,3*n+1){
				if(c == n){
					break;
				}
				if(vis[i] == 0){
					cout<<i<<" ";
					++c;
				}
			}
			cout<<endl;
		}
	}	
rt;
}
	
