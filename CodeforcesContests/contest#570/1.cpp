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

lli fun(lli a){
	lli sum=0;
	while(a > 0){
		sum += a%10;
		a /= 10;
	}
return sum;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	vector<lli> v;
	cin>>n;	
	while(1){
		lli c = fun(n);
		if(c % 4 == 0){
			cout<<n<<endl;
			rt;
		}
		else{
			++n;
		}
	}
rt;
}
	
