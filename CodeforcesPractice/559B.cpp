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
string s1,s2;

lli fun(lli beg1,lli end1,lli beg2,lli end2){
	lli l = 1 + end1 - beg1;
	lli flag = 0,j=beg2;
	for(lli i=beg1;i<=end1;i++){
		if(s1[i] != s2[j]){
			flag = 1;
			break;
		}
		++j;
	}

	if(flag == 0){
		return 1;
	}

	else if(l % 2 == 1){
		return 0;
	}

	else{
		lli a = fun(beg1,beg1 + l/2 -1,beg2,beg2+ l/2 -1) && fun(beg1+l/2,end1,beg2+l/2,end2);
		if(a == 0){
			lli b = fun(beg1,beg1+l/2-1,beg2+l/2,end2) && fun(beg1+l/2,end1,beg2,beg2+l/2-1);
			return b;
		}
		else{
			return a;
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	vector<lli> v;
	cin>>s1>>s2;
	lli d = fun(0,s1.length()-1,0,s2.length()-1);	
	if(d == 1){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
rt;
}
	
