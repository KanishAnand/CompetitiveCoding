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
	lli n,a,l,r;
	vector<lli> v;
	cin>>n>>l>>r;	
	lli p=1,min_ans=0,max_ans=0;

	for(lli i=0;i<l;i++){
		min_ans += p;
		p *= 2;
	}
	p = 1;
	for(lli i=0;i<r;i++){
		max_ans += p;
		p *= 2;
	}
	p /= 2;

	min_ans += n - l;
	max_ans += p*(n-r);
	cout<<min_ans<<" "<<max_ans<<endl;
rt;
}

