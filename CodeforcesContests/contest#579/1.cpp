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
	lli n,a,q;	
	cin>>q;
	while(q--){
		cin>>n;
		vector<lli> v;
		lli flag=0;
		lli in;
		fr(i,0,n){
			cin>>a;
			if(a == 1){
				in = i;
			}
			v.pb(a);
		}
		lli x = (in + 1)%n;
		if(v[x] == n){
			lli t = x;
			t %= n;
			lli c = n;
			while(t != in){
				if(v[t] != c){
					flag = 1;
					//cout<<"NO"<<endl;
					break;
				}
				--c;
				++t;
				t %= n;
			}
		}
		else if(v[x] == 2){
			lli t=x,c=2;
			while(t != in){
				if(v[t] != c){
					flag = 1;
					//cout<<"NO"<<endl;
					break;
				}
				++c;
				++t;
				t %= n;
			}
		}
		else{
			flag = 1;
			// cout<<"NO"<<endl;
			// break;
		}

		if(flag == 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}	
rt;
}
	
