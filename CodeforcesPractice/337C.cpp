#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
#define mod 1000000009;
lli fun(lli y){
	// lli ans=2;
	// while(x > 1){
	// 	ans *= ans;
	// 	ans %=  mod;
	lli x = 2;
	// 	x /= 2;
	// }
	lli ans = 1;
	while(y > 0){
		if(y % 2 == 1){
			ans = ans*x;
			ans %= mod;
		}
		y /= 2;
		// ans *= ans;
		x = x*x;
		x %= mod;
		ans %= mod;
	}
return ans;
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,k;
	vector<lli> v;
	cin>>n>>m>>k;	
	if(m/(k-1) <= n - m){
		m %= mod;
		cout<<m<<endl;
	}
	else{
		lli x = m/(k-1) - (n-m);
		lli y = (n-m)*(k-1);
		lli ans = 0;
		ans += y;
		ans %= mod;
		m -= y;
		x = m/k;
		ans += m % k;		
		ans %= mod;
		lli ans2=0;
		// cout<<ans<<endl;
		// cout<<x<<endl;
		if(x == 1){
			ans2 = 2*k;
		}
		else if(x > 1){
			ans2 = fun(x);
			ans2 %= mod;
			ans2 -= 1;
			ans2 += mod;
			ans2 %= mod;
			ans2 *= k;
			ans2 %= mod;
			ans2 *= 2;
			ans2 %= mod;
		}
		//cout<<x<<endl;
		// fr(i,0,x){
		// 	ans2 += k;
		// 	ans2 %= mod;
		// 	ans2 *= 2;
		// 	ans2 %= mod;
		// }
		ans += ans2;
		ans %= mod;
		cout<<ans<<endl;
	}
rt;
}
	
