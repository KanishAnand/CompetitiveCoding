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
	// lli n;
	vector<lli> v;
	string s,t;
	cin>>s>>t;
	lli x = s.length(),y=t.length(),maxx=0;
	for(lli i=0;i<x;i++){
		for(lli j=i;j<x;j++){
			lli p=0,flag=0;
			//cout<<i<<" "<<j<<endl;
			for(lli k=0;k<x;k++){
				//cout<<k<<endl;
				if(k < i || k > j){
					//cout<<s[k]<<" "<<t[p]<<endl;
					if(s[k] == t[p]){
						++p;
					}
				}
				if(p == y){
					flag = 1;
					break;
				}
			}
			//cout<<i<<" "<<j<<" "<<p<<endl;
			if(flag == 1){
				lli a = j-i+1;
				if(a > maxx){
					//cout<<a<<" "<<i<<" "<<j<<endl;
					maxx = a;
				}
			}
		}
	}

	cout<<maxx<<endl;
rt;
}
	
