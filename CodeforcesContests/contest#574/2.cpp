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
	lli n,k;
	vector<lli> v;
	cin>>n>>k;
	lli beg = 1,end = n,mid;
	while(beg <= end){
		mid = (beg + end)/2;
		lli ans = mid*(mid+1)/2;
		ans -= n - mid;
		if(ans > k){
			end = mid-1;
		}
		else if(ans < k){
			beg = mid+1;
		}
		else{
			cout<<n - mid<<endl;
			rt;
		}
	}	
rt;
}
	
