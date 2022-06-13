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
	a = n%4;
	lli b = (n+1)%4;
	lli c = (n+2)%4;
	if(a == 1 || b == 1 || c == 1){
		if(a == 1){
			cout<<"0"<<" "<<"A"<<endl;
		}
		else if(b == 1){
			cout<<"1"<<" "<<"A"<<endl;
		}
		else{
			cout<<"2"<<" "<<"A"<<endl;
		}
	}
	else if(a == 3 || b == 3 || c == 3){
		if(a == 3){
			cout<<"0"<<" "<<"B"<<endl;
		}
		else if(b == 3){
			cout<<"1"<<" "<<"B"<<endl;
		}
		else{
			cout<<"2"<<" "<<"B"<<endl;
		}
	}
	else if(a == 2 || b == 2 || c == 2){
		if(a == 2){
			cout<<"0"<<" "<<"C"<<endl;
		}
		else if(b == 2){
			cout<<"1"<<" "<<"C"<<endl;
		}
		else{
			cout<<"2"<<" "<<"C"<<endl;
		}
	}
	else{
		if(a == 3){
			cout<<"0"<<" "<<"D"<<endl;
		}
		else if(b == 3){
			cout<<"1"<<" "<<"D"<<endl;
		}
		else{
			cout<<"2"<<" "<<"D"<<endl;
		}
	}
rt;
}
