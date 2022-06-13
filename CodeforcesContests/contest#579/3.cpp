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

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a;
	vector<lli> v;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}
	lli val;
	if(n > 1){
		val = gcd(v[0],v[1]);
		for(lli i=2;i<n;i++){
			val = gcd(val,v[i]);
		}
	}
	else{
		val = v[0];
	}

	lli p = sqrt(val),ans=0;
	for(lli i=1;i<=p;i++){
		if(val % i == 0){
			if(i != val/i){
				ans += 2;
			}
			else{
				++ans;
			}
		}
	}

	cout<<ans<<endl;
rt;
}
	
