#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,t,q;
	cin>>t;
	while(t--){
		cin>>q;
		set<int> st;
		vector<int> vis(100000000,0);
		int o=0,e=0;
		while(q--){
			cin>>n;
			if(vis[n] == 0){
				vector<int> v;
				for(auto it = st.begin();it != st.end();it++){
					int x = (*it)^n;
					if(vis[x] == 0){
						v.pb(x);
					}
				}
				v.pb(n);
				for(int i = 0;i<v.size();i++){
					int x = v[i];
					st.insert(x);
					vis[x] = 1;
					int od=0;
					while(x > 0){
						int c = x % 2;
						if(c == 1){
							++od;
						}
						x /= 2;
					}
					if(od % 2 == 0){
						++e;
					}
					else{
						++o;
					}
				}
			}
			cout<<e<<" "<<o<<"\n";
		}
	}	
rt;
}