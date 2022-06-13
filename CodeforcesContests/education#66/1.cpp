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
	lli n,k,t;
	cin>>t;
	fr(i,0,t){
		cin>>n>>k;
		lli c=0;
		while(1){
			if(n == 0){
				break;
			}
			if(n % k == 0){
				n = n / k;
				++c;
			}
			else{
				//--n;
				
				c = c + n%k;
				n -= n%k;
			}
		}
		cout<<c<<endl;
	}		
rt;
}
