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
	lli q,n,k;
	vector<lli> v;
	cin>>q;
	while(q--){
		cin>>n>>k;
		string st;
		cin>>st;
		lli minn = 1000000000;
		string s1 = "RGB",s2 = "GBR",s3="BRG";
		for(lli i=0;i<n-k+1;i++){
			lli p=0,ch=0;
			for(lli j=i;j<i+k;j++){
				if(st[j] != s1[p%3]){
					++ch;
				}
				++p;
			}
			if(ch < minn){
				minn = ch;
			}
			p=0,ch=0;
			for(lli j=i;j<i+k;j++){
				if(st[j] != s2[p%3]){
					++ch;
				}
				++p;
			}
			if(ch < minn){
				minn = ch;
			}
			p=0,ch=0;
			for(lli j=i;j<i+k;j++){
				if(st[j] != s3[p%3]){
					++ch;
				}
				++p;
			}
			if(ch < minn){
				minn = ch;
			}
		}
		cout<<minn<<endl;
	}	
rt;
}	
