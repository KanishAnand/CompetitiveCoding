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

	vector<lli> ans(n+1,0);
	lli in=100000000;
	lli prev;

	fr(i,0,v1.size()){
		lli x = v1[i].first;
		lli y = v1[i].second;
		for(lli j = x-1;j < y;j++){
			if(ans[j] == 0){
				ans[j] = in;
			}
			else{
				in = ans[j];
			}
		}
		prev = v1[i].first-1;
		if(i != v1.size() -1){
			if(v1[i+1].first > prev){
				in = in - (v1[i+1].first - prev) -5;
			}
		}
	}

	if(ans[0] == 0){
		lli i=0;
		while(i < n && ans[i] == 0){
			++i;
		}
		if(ans[i] == 0){
			t = n+5;
			fr(i,0,n){
				if(ans[i] == 0){
					ans[i] = t;
					--t;
				}
				else{
					break;
				}
			}
		}
		else{
			lli t = ans[i];
			t = t + i + 5;
			fr(i,0,n){
				if(ans[i] == 0){
					ans[i] = t;
					--t;
				}
				else{
					break;
				}
			}
		}
	}

	lli q;
	for(lli i=0;i<n;i++){
		if(ans[i] == 0){
			ans[i] = q;
			--q;
		}
		else{
			q = ans[i];
			--q;
		}
	}

	for(lli i=0;i<v0.size();i++){
		lli x = v0[i].first;
		lli f = 0;
		lli y = v0[i].second;
		for(lli j=x-1;j<y-1;j++){
			if(ans[j] > ans[j+1]){
				f = 1;
				break;
			}
		}
		if(f == 0){
			cout<<"NO"<<endl;
			rt;
		}
	}

	for(lli i=0;i<v1.size();i++){
		lli x = v1[i].first;
		lli f = 0;
		lli y = v1[i].second;
		for(lli j=x-1;j<y-1;j++){
			if(ans[j] > ans[j+1]){
				f = 1;
				break;
			}
		}
		if(f == 1){
			cout<<"NO"<<endl;
			rt;
		}
	}


	cout<<"YES"<<endl;
	fr(i,0,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
rt;
}
	
