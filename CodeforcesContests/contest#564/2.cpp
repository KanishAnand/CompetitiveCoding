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
	lli x;
	if(n%2 == 0){
		x = n+1;
	}
	else{
		x=n;
	}
	cout<<(x+1)/2<<endl;
	cout<<"1 1"<<endl;
	lli r=1,c=1;
	for(lli i=2;i<=n;i++){
		if(i % 2 == 1){
			++r;
		}
		else{
			++c;
		}
		cout<<r<<" "<<c<<endl;
	}
rt;
}