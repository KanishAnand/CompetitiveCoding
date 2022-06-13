#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,c=0,d=0,a;
	vector<lli> v1,v2;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		v1.pb(a);
		c += a;
	}

	fr(i,0,n){
		cin>>a;
		v2.pb(a);
		d += a;
	}
	
	if( d <= c){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
rt;
}
