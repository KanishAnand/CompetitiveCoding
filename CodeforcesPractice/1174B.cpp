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
	lli n,a,flage=0,flago=0;
	cin>>n;	
	vector<lli> v;
	fr(i,0,n){
		cin>>a;
		if(a%2==0){
			flage = 1;
		}
		else{
			flago=1;
		}
		v.pb(a);
	}

	if(flage == 1 && flago == 1){
		sort(v.begin(),v.end());
	}
	
	fr(i,0,n){
		cout<<v[i]<<" ";
	}
	cout<<endl;
rt;
}

	
