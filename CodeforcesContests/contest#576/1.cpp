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
	lli n,a,x,y;
	vector<lli> v;
	cin>>n>>x>>y;	
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}

	for(lli i=0;i<n;i++){
		lli t = v[i],flag = 0;
		lli p = i-x;
		if(i - x < 0){
			p = 0;
		}
		if(i != 0){
			for(lli j = p;j<i;j++){
				if(v[j] <= t){
					flag = 1;
					break;
				}
			}
		}

		if(i != n-1){
			for(lli j=i+1;j<min(i+y+1,n);j++){
				if(v[j] <= t){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0){
			cout<<i+1<<endl;
			rt;
		}
	}
rt;
}
	
