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

lli n,m,a,t;
vector<lli> b,p;

lli check(lli in){
	lli k=a,j=0;
	for(lli i = n - in; i < n; i++){
		if(b[i] - p[j] < 0){
			if(k >= p[j] - b[i]){
				k -= p[j] - b[i];
			}	
			else{
				return 0;
			}
		}
		++j;
	}
return 1;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli x;
	cin>>n>>m>>a;
	fr(i,0,n){
		cin>>x;
		b.pb(x);
	}
	fr(i,0,m){
		cin>>x;
		p.pb(x);
	}	
	sort(b.begin(),b.end());
	sort(p.begin(),p.end());

	t = min(n,m);
	lli ans;

	//for(lli i=1;i<=t;i++){
	lli l=0,r=t;

	while(l < r){
		lli mid = (l+r+1)/2;
		lli c = check(mid);
		//cout<<l<<" "<<r<<endl;
		if(c == 1){
			l = mid;
			//ans = i;
		}
		else{
			r = mid-1;
		}
	}
	//}
	
	lli sum=0;
	ans = l;

	for(lli i=0;i<ans;i++){
		sum += p[i];
	}

	lli ans2 = sum - a;
	if(ans2 < 0){
		ans2 = 0;
	}

	cout<<ans<<" "<<ans2<<endl;
rt;
}
	
