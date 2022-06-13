#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr for(lli i=0;i<n;i++)
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
	lli n,x,y;
	cin>>n>>x>>y;
	string st;
	int str[1000000];
	cin>>st;
	lli a = n - (n/x)*x;
	lli val=0,p=1,c=0;
	// for(int i=n-1;i>;i--){
	// //	val += p*st[i];
	// //	p *= 10;
	// }

	for(int i=0;i<n;i++){
		str[i] = st[n-i-1];
	}
	//cout<<str<<endl;
	// if(str[x] == 1){

	//}

	for(int i=0;i<y;i++){
		if(str[i] != '0'){
			++c;
		}
	}
	if(str[y] != '1'){
		++c;
	}
	for(int i=y+1;i<x;i++){
		if(str[i] != '0'){
			++c;
		}
	}
	cout<<c<<endl;
return 0;
}
	
