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
	cin>>n;	
	vector<lli> v;
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}
	if(n == 1 || n == 2){
		cout<<n<<endl;
		rt;
	}
	//lli l=0;
	vector<lli> lef,righ;
	lef.resize(n+2);
	righ.resize(n+2);
	lef[0] = 0;

	fr(i,1,n){
		if(v[i] > v[i-1]){
			lef[i] = lef[i-1]+1;
		}
		else{
			lef[i] = 0;
		}
	}

	righ[n-1] = 0;

	for(int i=n-2;i>=0;i--){
		if(v[i] < v[i+1]){
			righ[i] = righ[i+1] + 1;
		}
		else{
			righ[i] = 0;
		}
	}

	lli max;
	max = righ[1] + 2;
	if(lef[n-2] + 2 > max){
		max = lef[n-2] + 2;
	}

	fr(i,1,n-1){	
		if(v[i+1] - v[i-1] > 1){
			lli a = righ[i+1] + lef[i-1] + 3;
			if(a > max){
				max = a;
			}
		}
		else{
			lli a = righ[i+1] + 2;
			if(a > max){
				max = a;
			}
			a = lef[i-1] + 2;
			if(a > max){
				max = a;
			}
		}
	}

	cout<<max<<endl;
rt;
}

