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
	fr(i,0,n){
		cin>>a;
		lli q,rem;
		q = a/4;
		rem = a%4;
		if(rem == 0){
			cout<<q<<endl;
		}
		else if(rem == 1){
			if(q >= 2){
				q -= 1;
				cout<<q<<endl;
			}
			else{
				cout<<"-1"<<endl;
			}
		}
		else if(rem == 2){
			if(q >= 1){
				cout<<q<<endl;
			}
			else{
				cout<<"-1"<<endl;
			}
		}
		else{
			if(q >= 3){
				q -= 1;
				cout<<q<<endl;
			}
			else{
				cout<<"-1"<<endl;
			}
		}
	}
rt;
}
	
