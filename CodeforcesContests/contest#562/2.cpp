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
	lli n,m,a,b;
	set<pair<lli,lli>> st1,st2;
	cin>>n>>m;
	fr(i,0,m){
		cin>>a>>b;
		st1.insert(make_pair(a,b));
		st2.insert(make_pair(a,b));
	}	
	lli flag=1,c=0;

	lli x=(*st1.begin()).first;
	for(auto it=st1.begin();it!=st1.end();){
		auto p = *it;
		if(p.first == x || p.second == x){
			st1.erase(it);
			it=st1.begin();
			for(int i=0;i<c;i++){
				++it;
			}
		}
		else{
			++c;
			++it;
		}
	}

	if(st1.size() != 0){
		lli y=(*st1.begin()).second;
		for(auto it=st1.begin();it!=st1.end();it++){
			auto p=*it;
			if(p.second != y && p.first != y){
				flag = 0;
				break;
			}
		}
		if(flag == 0){
			flag=1;
			y=(*st1.begin()).first;
			for(auto it=st1.begin();it!=st1.end();it++){
				auto p=*it;
				if(p.second != y && p.first != y){
					flag = 0;
					break;
				}
			}
		}
	}

	if(flag == 1){
		cout<<"YES"<<endl;
		rt;
	}
	
	else{
		flag=1;
		c=0;
		lli y=(*st2.begin()).second;
		for(auto it=st2.begin();it!=st2.end();){
			auto p = *it;
			if(p.second == y || p.first == y){
				st2.erase(it);
				it=st2.begin();
				for(int i=0;i<c;i++){
					++it;
				}
			}
			else{
				++c;
				++it;
			}
		}

		if(st2.size() != 0){
			lli x=(*st2.begin()).first;
			for(auto it=st2.begin();it!=st2.end();it++){
				auto p=*it;
				if(p.first != x && p.second != x){
					flag = 0;
					break;
				}
			}
			//cout<<st2.size()<<endl;
			if(flag == 0){
				flag=1;
				x=(*st2.begin()).second;
				for(auto it=st2.begin();it!=st2.end();it++){
					auto p=*it;
					if(p.second != x && p.first != x){
						flag = 0;
						break;
					}
				}
			}
		}
	}

	if(flag == 1){
		cout<<"YES"<<endl;
		rt;
	}
	else{
		cout<<"NO"<<endl;
	}
rt;
}
