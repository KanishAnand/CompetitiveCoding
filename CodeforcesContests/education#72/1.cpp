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
	lli t,a,b,c;
	cin>>t;
	while(t--){
		lli flag = 0;
		cin>>a>>b>>c;
		if(a <= b){
			lli x = b - a + 1;
			if(c < x){
				// cout<<"0"<<endl;
				flag = 1;
			}
			else{
				c -= x;
				a += x;
			}
		}

		if(flag == 0){
			lli x = a - b;
			// cout<<c<<" "<<x<<endl;
			lli val = (c + x)/2;
			val = min(val,c);
			// ++val;
			//val += 10;
			// if((c+x)%2 == 0){
			// 	--val;
			// }
			while(val + b >= a + c - val){
				--val;
			}
			lli ans = val + 1;
			cout<<ans<<endl;
		}
		else{
			cout<<"0"<<endl;
		}
	}	
rt;
}
	
