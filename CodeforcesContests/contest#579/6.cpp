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
	lli n,a;
	vector<lli> v;
	vector<int> arr(150005,0);
	arr[0]=1;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}
	lli ans=0;
	sort(v.begin(),v.end());
	for(lli i=0;i<n;i++){
		lli x = v[i];
		if(arr[x-1] == 0){
			arr[x-1]=1;
			ans++;
		}
		else if(arr[x] == 0){
			arr[x] = 1;
			ans++;
		}
		else if(arr[x+1] == 0){
			arr[x+1] = 1;
			++ans;
		}
	}
	cout<<ans<<endl;
rt;
}


	
