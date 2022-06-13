#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
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
	lli n,q,a;
	vector<lli> v;
	cin>>q;
	while(q--){
		cin>>n;
		vector<lli> v;
		vector<lli> arr(n+2,0);
		fr(i,0,n){
			cin>>a;
			arr[a]++;
		}
		fr(i,1,n+2){
			if(arr[i] != 0){
				v.pb(arr[i]);
			}
		}
		sort(v.begin(),v.end(),greater<>());
		lli sum=0,t = v[0];

		fr(i,0,v.size()){
			if(t <= 0){
				break;
			}
			if(v[i] == t){
				sum += v[i];
				--t;
			}
			else if(v[i] > t){
				sum += t;
				--t;
			}
			else{
				sum += v[i];
				t = v[i] - 1;
			}
		}
		cout<<sum<<"\n";
	}	
rt;
}

	
