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
	lli n,a,q,s,t;
	vector<lli> v;
	cin>>q;
	while(q--){
		cin>>n>>s>>t;
		// if(s + t == n){
		// 	cout<<n<<endl;
		// }
		// else{
		// 	lli k = s+t - n;
		// 	s -= k;
		// 	t -= k;
		// 	if(s >  t){
		// 		cout<<s+1<<endl;
		// 	}
		// 	else{
		// 		cout<<t+1<<endl;
		// 	}
		// }
		cout<<n-min(s,t)+1<<endl;
	}	
rt;
}
	
