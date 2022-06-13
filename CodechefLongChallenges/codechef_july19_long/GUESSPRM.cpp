#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli input(lli n,vector<lli> &ve);

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t,n;
	cin>>t;
	//cout<<endl;
	
	while(t--){
		lli p = 100000,a;
		cout<<"1"<<" "<<p<<endl;
		cout.flush();
		cin>>a;	
		lli x = p*p - a,maxx=0;
		vector<lli> v;
		lli k = sqrt(x);

		for(lli i=2;i<=k;i++){
			if(x % i == 0){
				if(((p*p) % i) == a){
					v.pb(i);
					if(i > maxx){
						maxx = i;
					}
				}
				while(x % i == 0){
					x /= i;
				}
			}
			if(x == 1){
				break;
			}
		}

		if(x != 1){
			if((p*p) % x == a){
				if(x > maxx){
					maxx = x;
				}
				v.pb(x);
				x=1;
			}
		}

		lli c = maxx+1;
		//lli c = 2;

		while(1){
			set<lli> st;
			for(lli i=0;i<v.size();i++){
				lli r = (c*c)%v[i];
				st.insert(r);
			}
			if(st.size() == v.size()){
				break;
			}
			else{
				++c;
				continue;
			}
		}

		cout<<"1"<<" "<<c<<endl;
		cout.flush();
		cin>>a;
		for(lli i=0;i<v.size();i++){
			if(((c*c) % v[i]) == a){
				cout<<"2"<<" "<<v[i]<<endl;
				cout.flush();
				break;
			}
		}
		string st;
		cin>>st;
	}	
rt;
}
		
