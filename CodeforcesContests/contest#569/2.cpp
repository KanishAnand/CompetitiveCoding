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
	lli n,a;
	vector<lli> v;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		if(a >= 0){
			a = -1*(a+1);
			v.pb(a);
		}
		else{
			v.pb(a);
		}
	}
	lli max = 0,ind=-1;

	if(n % 2 == 0){
		fr(i,0,n){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		rt;
	}
	else{
		fr(i,0,n){
			if(v[i] < max && v[i] != -1){
				max = v[i];
				ind  = i;
			}
		}
	}

	if(ind != -1){
		v[ind] = -1*(v[ind] + 1);
	}
	else{
		v[0] = 0;
	}

	fr(i,0,n){
		cout<<v[i]<<" ";
	}
	cout<<endl;
rt;
}
	
