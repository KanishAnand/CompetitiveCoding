#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
lli minn = 1000000000000;
lli input(lli n,vector<lli> &ve);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		if(val< minn){
			minn = val;
		}
		ve.pb(val);
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,t;
	vector<lli> v;
	cin>>n>>t;	
	input(n,v);
	lli cnt=0;
	while(t >= minn){
		lli sum=0,c=0;
		fr(i,0,n){
			if(v[i] + sum <= t){
				sum += v[i];
				++c;
			}
		}
		cnt += (t/sum)*c;
		t  = t%sum;
	}

	cout<<cnt<<endl;
rt;
}



	
