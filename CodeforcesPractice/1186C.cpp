#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
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
	lli n,ans=0;
	vector<lli> v;
	string a,b;
	cin>>a>>b;
	lli na = a.length(),cntbo=0,cntbz=0;
	lli nb = b.length(),cntaz=0,cntao=0;

	for(lli i=0;i<nb;i++){
		if(a[i] == '0'){
			cntaz++;
		}
		else{
			cntao++;
		}
		if(b[i] == '0'){
			cntbz++;
		}
		else{
			cntbo++;
		}
	}
	lli k = nb%2;
	lli x = abs(cntaz - cntbo)%2;
	lli y = abs(cntao - cntbz)%2;
	if(x == k && y == k){
		ans++;
	}

	for(lli i=nb;i<na;i++){
		if(a[i-nb] == '0'){
			cntaz--;
		}
		else{
			cntao--;
		}
		if(a[i] == '0'){
			cntaz++;
		}
		else{
			cntao++;
		}
		x = abs(cntaz - cntbo)%2;
		y = abs(cntao - cntbz)%2;
		if(x == k && y == k){
			ans++;
		}
	}

	cout<<ans<<endl;
rt;
}



	
