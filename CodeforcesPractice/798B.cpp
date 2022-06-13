#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(val) for(lli i=0;i<val;i++)
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
	string st;
	vector<string> v;
	fr(n){
		cin>>st;
		v.pb(st);
	}
	lli minn=100000000000,flag=0;
	fr(n){
		string st = v[i];
		lli an=0;
		for(int j=0;j<n;j++){
			flag = 1;
			string str=v[j];
			if(str != st){
				for(int k=1;k<str.length();k++){
					string ch = str.substr(k,str.length()-k);
					string chk = str.substr(0,k);
					//cout<<ch<<endl;
					ch.append(chk);
					//cout<<chk<<endl;
					//cout<<ch<<endl;
					if(st == ch){
						flag = 0;
						an += k;
						break;
					}
				}
			}
			else{
				flag = 0;
			}
			if(flag == 1){
				cout<<"-1"<<endl;
				rt;
			}
		}
	//	cout<<an<<endl;
		if(an < minn){
			minn = an;
		}
	}
	cout<<minn<<endl;
rt;
}
