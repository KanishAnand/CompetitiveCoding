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
	lli n,q,a,m;
	vector<lli> v;
	cin>>q;
	while(q--){
		cin>>n>>m;
		vector<lli> arr(12,0);
		
		lli x = n/m;
		for(lli i=1;i<=10;i++){
			arr[i] = (m*i)%10;
			if(i != 1){
				arr[i] += arr[i-1];
			}
		}

		if(x <= 10){
			cout<<arr[x]<<endl;
		}
		else{
			lli t = x/10;
			lli p = x%10;
			cout<<arr[10]*t + arr[p]<<endl;
		}
	}	
rt;
}
	
