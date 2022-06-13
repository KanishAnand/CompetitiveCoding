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
	lli q,n,m;
	cin>>q;
	while(q--){
		vector<string> st;
		cin>>n>>m;
		vector<lli> vm,vn,an,am;
		lli a,b;
		vm.resize(m+2);
		vn.resize(n+2);
		// string s;
		st.resize(n+2);
		fr(i,0,n){
			cin>>st[i];
		}

		lli maxx = -1;
		fr(i,0,n){
			lli cnt=0;
			fr(j,0,m){
				if(st[i][j] == '*'){
					cnt++;
				}
				// cout<<st[i][j]<<endl;
			}
			vn[i] = cnt;
			if(cnt > maxx){
				maxx = cnt;
			}
		}

		fr(i,0,n){
			if(vn[i] == maxx){
				an.pb(i);
			}
		}

		a = maxx;
		maxx = -1;

		fr(i,0,m){
			lli cnt=0;
			fr(j,0,n){
				if(st[j][i] == '*'){
					cnt++;
				}
			}
			vm[i] = cnt;
			if(cnt > maxx){
				maxx = cnt;
			}
		}

		fr(i,0,m){
			if(vm[i] == maxx){
				am.pb(i);
			}
		}
		b = maxx;
		lli ans = m - b + n - a,flag = 0;

		fr(i,0,an.size()){
			fr(j,0,am.size()){
				if(st[an[i]][am[j]] == '.'){
					flag = 1;
					break;
				}
			}
		}

		if(flag == 1){
			if(ans > 0){
				--ans;
			}
		}
		cout<<ans<<"\n";
	}	
rt;
}
	
