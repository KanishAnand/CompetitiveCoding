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

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,ind=-1;
	vector<lli> v,ans,ve;
	cin>>n>>m;
	lli a,sum=0;
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}	

	fr(i,0,n){
		sum += v[i];
		if(sum <= m){
			ve.pb(v[i]);
			ans.pb(0);
		}
		else{
			sum -= v[i];
			ind = i;
			break;
		}
	}
	
	if(ind == -1){
		for(lli i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	rt;
	}


	for(lli i=ind;i<n;i++){
		sort(ve.begin(),ve.end());
		lli ch = sum + v[i] - m,c=0,s=0;
		for(lli j = ve.size() - 1;j >= 0;j--){
			s += ve[j];
			++c;
			if(s >= ch){
				ans.pb(c);
				ve.pb(v[i]);
				sum += v[i];
				break;
			}
		}
	}

	for(lli i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
rt;
}


	
