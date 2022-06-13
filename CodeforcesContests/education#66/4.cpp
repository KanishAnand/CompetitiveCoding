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
	lli n,k,a;
	vector<lli> v;
	cin>>n>>k;
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}	

	reverse(v.begin(),v.end());
	lli ans =0;

	fr(i,0,n){
		ans += v[i]*k;
		lli var=0,max=0,lst=i;
		if(k != 1){
			for(lli j=i+1;j < n-k+1;j++){
				var += v[j];
				if(var > max){
					max = var;
					lst = j;
				}
			}
			i = lst;
			ans += max*k;
			//cout<<ans<<endl;
		}
		--k;
		if(k == 0){
			fr(j,i+1,n){
				ans += v[j];
				++i;
			}
		}
	}
	cout<<ans<<endl;
rt;
}


	
