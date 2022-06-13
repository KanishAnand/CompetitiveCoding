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
	lli n,t;
	string s,p;
	cin>>n>>t;
	cin>>s>>p;
	string ans(n,0);
	lli x = n - t;

	fr(i,0,n){
		if(s[i] == p[i] && x > 0){
			ans[i] = s[i];
			--x;
		}
	}
	lli a=x,b=x;


	fr(i,0,n){
		if(ans[i] == 0 && a > 0){
			ans[i] = s[i];
			--a;
		}
		if(a == 0){
			break;
		}
	}

	if(a != 0){
		cout<<"-1"<<endl;
		rt;
	}

	fr(i,0,n){
		if(ans[i] == 0 && b > 0){
			ans[i] = p[i];
			--b;
		}
		if(b == 0){
			break;
		}
	}

	if(b != 0){
		cout<<"-1"<<endl;
		rt;
	}

	fr(i,0,n){
		if(ans[i] == 0){
			//cout<<i<<endl;
			if(s[i] != 'a' && p[i] != 'a'){
				ans[i] = 'a';
			}
			else if(s[i] != 'b' && p[i] != 'b'){
				ans[i] = 'b';
			}
			else{
				ans[i] = 'c';
			}
		}
	}

	cout<<ans<<endl;
rt;
}

	
