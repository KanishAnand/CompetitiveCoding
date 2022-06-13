#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0

int main(void){
	lli n,a;
	lli minn = 1000000000;
	vector<lli> v;
	cin>>n;	

	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}

	for(lli i=0;i<n;i++){
		lli c = 0;
		for(lli j=0;j<n;j++){
			lli x = v[j] - v[i];
			if(x < 0){
				x = -x;
			}
			if(x %2 == 1){
				c++;
			}
		}
		if(c < minn){
			minn = c;
		}
	}
	
	cout<<minn<<endl;
rt;
}
