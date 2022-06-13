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
	lli n;
	cin>>n;
	string s,p;
	while(n--){
		lli x=0,y=0;
		cin>>s>>p;
		vector<pair<lli,lli>> v1,v2;
		if(p.length() < s.length()){
			cout<<"NO"<<endl;
		}
		else{
			for(lli i=0;i<s.length();i++){
				lli c=1;
				while(i <= s.length() - 2 && s[i] == s[i+1]){
					++i;
					++c;
				}
				++x;
				v1.pb(make_pair(s[i]-'a',c));
			}
			for(lli i=0;i<p.length();i++){
				lli c=1;
				while(i <= p.length() - 2 && p[i] == p[i+1]){
					++i;
					++c;
				}
				++y;
				//cout<<i<<endl;
				v2.pb(make_pair(p[i]-'a',c));
			}
//cout<<x<<y<<endl;
			if(x != y){
				cout<<"NO"<<endl;
			}
			else{
				lli flag = 1;
				for(lli i=0;i<x;i++){
					if(v1[i].first != v2[i].first || v1[i].second > v2[i].second){
						cout<<"NO"<<endl;
						flag = 0;
						break;
					}
				}
				if(flag == 1){
					cout<<"YES"<<endl;
				}
			}
		}
	}

rt;
}