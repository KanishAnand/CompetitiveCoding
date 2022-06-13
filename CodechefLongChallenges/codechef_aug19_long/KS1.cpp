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
	lli t,n,a;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v,an(n+3);
		vector<vector<lli>> x,y;
		x.resize(1048577);
		y.resize(1048577);
		fr(i,0,n){
			cin>>a;
			v.pb(a);
		}
		an[0] = v[0];
		x[an[0]].pb(0);
		y[an[0]].pb(0);
		//cout<<"F"<<endl;
		fr(i,1,n){
			an[i] = an[i-1]^v[i];
			if(x[an[i]].size() == 0){
				y[an[i]].pb(i);	
			}
			else{
				y[an[i]].pb(i + y[an[i]][y[an[i]].size()-1]);		
			}
			x[an[i]].pb(i);
		}
		long long int ans = 0;
		
		fr(i,1,n){
			if(an[i] == 0){
				ans += i;
			}
			//fr(j,0,x[an[i]].size()){
			if(x[an[i]].size() > 0){
				auto it=lower_bound(x[an[i]].begin(),x[an[i]].end(),i-2);
				if(it == x[an[i]].end()){
					--it;
				}

				if(*it > i-2){
					--it;
				}
				if(it >= x[an[i]].begin()){
					lli k = it - x[an[i]].begin() + 1;
					//cout<<k<<endl<<i<<endl;
					//cout<<ans<<endl;
					ans += k*i - k - y[an[i]][k-1];
					//cout<<ans<<endl;
				}
			}
				// if(x[an[i]][j] < i-1){
				// 	ans += i - x[an[i]][j] - 1;
				// }
				// else{
				// 	break;
				// }
			//}
		}
		cout<<ans<<"\n";
	}	
rt;
}
	
