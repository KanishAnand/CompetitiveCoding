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
	lli t,n,a;
	cin>>t;
	while(t--){
		cin>>n;
		lli sum=0;
		vector<lli> v;
		fr(i,0,n){
			cin>>a;
			sum += a;
			v.pb(a);
		}

		lli x = sum*(n-1);
		if(x % n == 0){
			x /= n;
			lli y = sum - x,flag=0;
			fr(i,0,n){
				if(v[i] == y){
					cout<<i+1<<"\n";
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				cout<<"Impossible"<<"\n";
			}
		}
		else{
			cout<<"Impossible"<<"\n";
		}
	}	
rt;
}
	
