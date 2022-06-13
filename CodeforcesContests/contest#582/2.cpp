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
	lli n,t,a;
	cin>>t;
	while(t--){
		cin>>n;
		vector<lli> arr;
		vector<lli> v;
		arr.resize(n+2);
		fr(i,0,n){
			cin>>a;
			v.pb(a);
		}
		lli minn = 10000000;
		
		for(lli i=n-1;i>=0;i--){
			if(v[i] < minn){
				minn = v[i];
			}
			arr[i] = minn;
		}
		
		lli c = 0;
		for(lli i=0;i<n;i++){
			if(arr[i] < v[i]){
				++c;
			}
		}
		cout<<c<<endl;
	}	
rt;
}

	
