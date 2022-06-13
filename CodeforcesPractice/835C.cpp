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
	lli n,q,c,x,y,s;
	vector<vector<lli>> sum,arr;
	sum.resize(102);
	arr.resize(102);
	cin>>n>>q>>c;
	fr(i,1,101){
		fr(j,1,101){
			sum[i].pb(0);
			arr[i].pb(0);
		}
	}

	fr(i,0,n){
		cin>>x>>y>>s;
		arr[x][y]++;
		sum[x][y] += s;
	}

	for(lli j=1;j<=100;j++){
		for(lli i=99;i>=1;i--){
			sum[j][i] += sum[j][i+1];
			arr[j][i] += arr[j][i+1];
		}
	}

	++c;
	lli t,x2,x1,y1,y2;
	while(q--){
		cin>>t>>x1>>y1>>x2>>y2;
		lli an=0;
		for(lli i=x1;i<=x2;i++){
			lli ans=0,cnt=0;
			ans = sum[i][y1];
			cnt = arr[i][y1];
			if(y2 != 100){
				ans -= sum[i][y2+1]; 	
				cnt -= arr[i][y2+1];
			}
			t %= c;
			cnt %= c;
			an = (ans%c + (cnt*t)%c)%c;
		}
		cout<<an<<endl;
	}
rt;
}
	
