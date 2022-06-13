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
	lli n,c=0;
	vector<lli> v1,v2;
	cin>>n;	
	if(n % 2 == 0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		for(lli i=1;i<=2*n;i++){
			if(c % 2 == 0){
				v1.pb(i);
				v2.pb(i+1);
			}
			else{
				v1.pb(i+1);
				v2.pb(i);	
			}
			++i;
			++c;
		}

		for(lli i=0;i<v1.size();i++){
			cout<<v1[i]<<" ";
		}
		for(lli i=0;i<v2.size();i++){
			cout<<v2[i]<<" ";
		}
		cout<<endl;
	}
rt;
}
	
