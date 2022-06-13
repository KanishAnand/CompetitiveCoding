#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
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
	lli n,m,t,l,r;
	vector<pair<lli,lli>> v1,v0;
	cin>>n>>m;	
	fr(i,0,m){
		cin>>t>>l>>r;
		if(t == 0){
			v0.pb(make_pair(l,r));
		}
		else{
			v1.pb(make_pair(l,r));	
		}
	}

	sort(v0.begin(),v0.end());
	sort(v1.begin(),v1.end());
	lli flag = 0;

	// fr(i,0,v0.size()){
	// 	fr(j,0,v1.size()){
	// 		lli a=v0[i].first;
	// 		lli b = v0[i].second;
	// 		lli c = v1[j].first;
	// 		lli d = v1[j].second;
	// 		if(a >= c && b <= d){
	// 			//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	// 			flag = 1;
	// 			break;
	// 		}
	// 	}
	// }

	// if(flag == 1){
	// 	cout<<"NO"<<endl;
	// 	rt;
	// }
	vector<lli> ans(n+1,0);
	lli in=10000;
	lli q=100000001;
	fr(i,0,v1.size()){
		lli x = v1[i].first;
		lli y = v1[i].second;
		for(lli j=x-1;j<y;j++){
			if(ans[j] == 0){
				ans[j] = in;
			}
			else{
				in = ans[j];
			}
		}
		--in;
	}

	// fr(i,0,v0.size()){
	// 	lli x = v0[i].first;
	// 	lli y = v0[i].second;

	// }
	for(lli i=0;i<n;i++){
		if(ans[0] == 0){
			ans[0] = q;
			--q;
		}
		else if(ans[i] == 0){
			ans[i] = q;
			--q;
		}
		else{
			q = ans[i];
			--q;
		}
	}

	// for(lli i=0;i<v0.size();i++){
	// 	lli x = v0[i].first;
	// 	lli f = 0;
	// 	lli y = v0[i].second;
	// 	for(lli j=x-1;j<y-1;j++){
	// 		if(ans[j] > ans[j+1]){
	// 			f = 1;
	// 			break;
	// 		}
	// 	}
	// 	if(f == 0){
	// 		cout<<"NO"<<endl;
	// 		rt;
	// 	}
	// }
	// for(lli i=0;i<v1.size();i++){
	// 	lli x = v1[i].first;
	// 	lli f = 0;
	// 	lli y = v1[i].second;
	// 	for(lli j=x-1;j<y-1;j++){
	// 		if(ans[j] > ans[j+1]){
	// 			f = 1;
	// 			break;
	// 		}
	// 	}
	// 	if(f == 1){
	// 		cout<<"NO"<<endl;
	// 		rt;
	// 	}
	// }


	cout<<"YES"<<endl;
	fr(i,0,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
rt;
}
	
