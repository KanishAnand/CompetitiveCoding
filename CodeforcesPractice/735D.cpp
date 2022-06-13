#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli check(lli a){
	lli x = sqrt(a);
	for(lli i=2;i<=x;i++){
		if(a % i == 0){
			return 0;
		}
	}
return 1;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	vector<lli> v;
	cin>>n;	
	if(check(n)){
		cout<<"1"<<endl;
	}
	else if(n % 2 == 0){
		cout<<"2"<<endl;
	}
	else{
		if(check(n-2)){
			cout<<"2"<<endl;
		}
		else{
			cout<<"3"<<endl;
		}
	}
rt;
}

	
