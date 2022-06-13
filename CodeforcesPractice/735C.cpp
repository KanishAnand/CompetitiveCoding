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
	lli n;
	cin>>n;	
	// dp[i] means if i want to get point i then how many person are req
	vector<lli> dp(100,0);
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	if(n == 2){
		cout<<"1"<<endl;
		rt;
	}
	lli an;
	lli org=n-1;
	if(n >= 3){
		an=3;
		n -= 3;
		while(1){
			if(n >= dp[an-2] + 1){
				n = n - dp[an-2] - 1;
				//cout<<n<<endl;
				dp[an] = org - n;
				++an;
			}
			else{
				break;
			}
		}
	}

	cout<<an-1<<endl;
rt;
}
