#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0

struct qu{
	lli a,b,c;
};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,q,a,x,p,k;
	vector<lli> v,mx,ans;
	vector<struct qu> ve;
	cin>>n;
	ans.resize(n+1,-1);
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}	
	cin>>q;
	mx.resize(q+2,0);
	while(q--){
		cin>>k;
		struct qu s;
		s.a = k;
		if(k == 1){
			cin>>p>>x;
			s.b = p;
			s.c = x;
		}
		else{
			cin>>x;
			s.b = 0;
			s.c = x;
		}
		ve.pb(s);
	}

	lli m = -1;
	for(lli i=ve.size()-1;i>=0;i--){
		if(ve[i].a == 2){
			if(ve[i].c > m){
				m = ve[i].c;
			}
		}
		else{
			mx[i] = m;
		}
	}

	for(lli i=0;i<ve.size();i++){
		lli t = ve[i].c;
		if(ve[i].a == 1){
			if(mx[i] > ve[i].c){
				t = mx[i];
			}
			ans[ve[i].b-1] = t;
		}
	}

	for(lli i=0;i<n;i++){
		if(ans[i] == -1){
			if(v[i] > m){
				cout<<v[i]<<" ";
			}
			else{
				cout<<m<<" ";
			}
		}
		else{
			cout<<ans[i]<<" ";
		}
	}
	cout<<endl;
rt;
}


	
