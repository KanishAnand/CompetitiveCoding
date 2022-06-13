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
	lli n,c,d;
	vector<pair<lli,lli>> v1,v2;
	cin>>n>>c>>d;
	lli a,b,max1=-1,max2=-1,max3=-1;
	set<lli> s1,s2;
	char x;
	fr(i,0,n){
		cin>>a>>b>>x;
		if(x == 'C'){
			if(b <= c){
				s1.insert(make_pair(a,b));
				v1.pb(make_pair(b,a));
			}
		}
		else{
			if(b <= d){
				s2.insert(make_pair(a,b));
				v2.pb(make_pair(b,a));
			}
		}
	}	

	if(s1.size() != 0 && s2.size() != 0){
		max1 = *(s2.rbegin()).first + *(s1.rbegin()).first;
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	if(s1.size() != 0){
		for(lli i=0;i<v1.size();i++){
			lli val;
			auto it = lower_bound(v1.begin().first,v1.end().first,c - v1[i]);
			if(*it == c - v[i]){
				val = it - v1.begin().first;
			}
			else{
				val = it - v1.begin().first - 1;	
			}
		}	
	}
rt;
}






	
