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
	lli n,t;
	vector<lli> v;
	cin>>t;
	while(t--){
		string st;
		cin>>st;
		lli flag = 0;
		fr(i,0,st.length()){
			if(st[i] == '0'){
				flag = 1;
			}
			else{
				if(i != n - 1){
					if(st[i+1] == '0'){
						st[i+1] = '1';
					}
					else{
						st[i+1] = '0';	
					}
				}
				flag = 0;
			}
		}
		if(flag == 1){
			cout<<"LOSE\n";
		}
		else{
			cout<<"WIN\n";
		}
	}	
rt;
}
	
