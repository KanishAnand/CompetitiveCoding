#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a,b,minn = 10000000;
	vector<lli> v1,v2,v3;
	set<lli> st;
	cin>>n;	
	lli x = n/2 + n%2;
	fr(i,0,n){
		cin>>a>>b;
		v1.pb(a);
		v2.pb(b);
		st.insert(a);
		st.insert(b);
		if(a == b){
			v3.pb(a);
		}
	}	

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());

	for(auto it = st.begin();it != st.end();it++){
		lli front,back,common;
		auto a = lower_bound(v1.begin(),v1.end(),*it);
		auto b = upper_bound(v1.begin(),v1.end(),*it);
		if(a == v1.end() || *a != *it){
			front = 0;
		}
		else{
			front = b - a;
		}

		auto c = lower_bound(v2.begin(),v2.end(),*it);
		auto d = upper_bound(v2.begin(),v2.end(),*it);
		if(c == v2.end() || *c != *it){
			back = 0;
		}
		else{
			back = d - c;
		}

		if(v3.size() == 0){
			common = 0;
		}
		else{
			auto e = lower_bound(v3.begin(),v3.end(),*it);
			auto f = upper_bound(v3.begin(),v3.end(),*it);
			if(a == v3.end() || *a != *it){
				common = 0;
			}
			else{
				common = f - e;
			}
		}

		lli an;
		an = x - front;
		if(an <= 0){
			cout<<"0"<<endl;
			rt;
		}
		else{
			if(back - common >= an){
				if(an < minn){
					minn = an;
				}
			}
		}
	}

	if(minn == 10000000){
		cout<<"-1"<<endl;
		rt;
	}
	cout<<minn<<endl;
rt;
}
