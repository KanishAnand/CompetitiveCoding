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
	lli n,k;
	vector<lli> v;
	cin>>n>>k;
	string st;
	cin>>st;
	if(st.length() == 1){
		cout<<"0"<<endl;
		cout<<st<<endl;
	}
	else if(k == 2){
		lli w=0,e=0;
		fr(i,0,n){
			if(st[i] - 'A' != i % 2){
				++w;
			}
			else{
				++e;
			}
		}

		if(w < e){
			cout<<w<<endl;
			fr(i,0,n){
				cout<<char(i%2 + 'A');
			}
			cout<<endl;
		}
		else{
			cout<<e<<endl;
			fr(i,0,n){
				cout<<char((i+1)%2 + 'A');
			}
			cout<<endl;
		}
	}
	else{
		lli ans=0;
		fr(i,1,n){
			if(st[i] == st[i-1]){
				++ans;
				lli t = st[i-1] - 'A';
				++t;
				t %= k;
				if(i < n-1){
					if(t == st[i+1] - 'A'){
						++t;
						t %= k;
					}
				}
				st[i] = t + 'A';
			}
		}
		cout<<ans<<endl;
		cout<<st<<endl;
	}	
rt;
}
	
