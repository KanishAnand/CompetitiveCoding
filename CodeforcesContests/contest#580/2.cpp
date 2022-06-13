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
	cin>>n;	
	lli sum=0,zero=0,minus=0;
	fr(i,0,n){
		cin>>a;
		if(a > 1){
			sum += a-1;
		}
		else if(a < -1){
			sum += -1 - a;
			++minus;
		}
		else if(a == 0){
			zero++;
		}
		else if(a == -1){
			minus++;
		}
	}

	if(minus % 2 == 0){
		sum += zero;
		cout<<sum<<endl;
	}
	else{
		if(zero != 0){
			sum += zero;
			cout<<sum<<endl;
		}
		else{
			sum += 2;
			cout<<sum<<endl;
		}
	}
rt;
}




	
