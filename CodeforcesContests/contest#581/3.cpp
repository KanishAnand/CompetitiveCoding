#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
vector<vector<lli>> arr,dis;
lli n;
lli flyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}

return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a,inf=10000000000,m;
	vector<lli> v;
	cin>>n;	
	string st;
	arr.resize(n+3);
	dis.resize(n+3);
	for(lli i=1;i<=n+1;i++){
		for(lli j=1;j<=n+1;j++){
			dis[i].pb(inf);
		}
	}

	for(lli i=1;i<=n;i++){
		cin>>st;
		for(lli j=1;j<=n;j++){
			if(st[j-1] == '1'){
				dis[i][j] = 1;
				arr[i].pb(j);
			}
		}
	}

// 	fr(i,1,n+1){
// 		fr(j,1,n+1){
// 			cout<<dis[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// cout<<"DF"<<endl;
	flyd();
	// fr(i,1,n+1){
	// 	fr(j,1,n+1){
	// 		cout<<dis[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"DF"<<endl;

	cin>>m;
	for(lli i=0;i<m;i++){
		cin>>a;
		v.pb(a);
	}

	lli ans=1,r=m-1;
	vector<lli> pr;
	pr.pb(v[m-1]);
//cout<<endl;
	for(lli i=m-2;i>=0;i--){
		if(i == 0){
			break;
		}
		lli d = dis[v[i-1]][v[r]];
		//cout<<d<<" "<<r-(i-1)<<" "<<i<<" "<<r<<endl;
		if(d < r - (i-1)){
			//cout<<"DF"<<d<<" "<<r-(i-1)<<" "<<i<<" "<<r<<endl;
			ans++;
			pr.pb(v[i]);
			r = i;
		}
		else if(v[i-1] == v[r]){
			ans++;
			pr.pb(v[i]);
			r = i;	
		}
	}
	ans++;
	pr.pb(v[0]);
	reverse(pr.begin(),pr.end());
	cout<<ans<<endl;
	for(lli i=0;i<pr.size();i++){
		cout<<pr[i]<<" ";
	}
	cout<<endl;

rt;
}