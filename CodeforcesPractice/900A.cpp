#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,x,y,neg=0,pos=0;
	vector<lli> v;
	cin>>n;	
	fr(i,0,n){
		cin>>x>>y;
		if(x < 0){
			neg++;
		}
		else{
			pos++;
		}
	}
		
	if(pos == 0 || neg == 0){
		cout<<"Yes"<<"\n";
	}
	else{
		if(pos == 1 || neg == 1){
			cout<<"Yes"<<"\n";
		}
		else{
			cout<<"No"<<"\n";
		}
	}
rt;
}
