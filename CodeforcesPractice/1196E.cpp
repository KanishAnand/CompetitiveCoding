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
	lli q,b,w;
	vector<lli> v;
	cin>>q;
	while(q--){
		cin>>b>>w;
		if(b >= w){
			lli x = w;
			lli e = b-w;
			if(e > 2*w + 1){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
				lli a = 1;
				fr(i,0,2*x){
					cout<<"2 "<<a<<endl;
					++a;
				}
				b -= w;
				if(b != 0){
					cout<<"2 "<<a<<endl;
					--b;
				}
				lli t = x;
				a=2;
				while(b > 0 && t > 0){
					cout<<"1 "<<a<<endl;	
					a += 2;
					--t;
					--b;
				}

				t = x,a=2;
				while(b > 0 && t > 0){
					cout<<"3 "<<a<<endl;	
					a += 2;
					--t;
					--b;
				}

			}
		}
		else{
			lli x = b;
			lli e = w-b;
			if(e > 2*b + 1){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
				lli a = 1;
				fr(i,0,2*x){
					cout<<"3 "<<a<<endl;
					++a;
				}
				w -= b;
				if(w != 0){
					cout<<"3 "<<a<<endl;
					--w;
				}
				lli t = x;
				a=2;
				while(w > 0 && t > 0){
					cout<<"2 "<<a<<endl;	
					a += 2;
					--t;
					--w;
				}

				t = x,a=2;
				while(w > 0 && t > 0){
					cout<<"4 "<<a<<endl;	
					a += 2;
					--t;
					--w;
				}
			}
		}
	}	
rt;
}
