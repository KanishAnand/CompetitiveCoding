#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli btn(string a){
	lli no=0,t=1;
	for(lli i = a.length()-1;i>=0;i--){
		no += (a[i] - '0')*t;
		t *= 2;
	}
return no;
}

string ntb(lli a){
	string arr;
	while(a > 0){
		int t = a%2;
		char p;
		//cout<<p<<endl;
		// if(a % 2 == 0){
		// 	p = '0';
		// }
		// else{
		// 	p = '1';
		// }
		//cout<<p<<endl;
		arr.pb(p);
		a /= 2;
	}
return arr;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	vector<lli> v;
	cin>>t;
	string x,y;
	while(t--){
		cin>>x>>y;
		lli x1 = btn(x);
		lli y1 = btn(y);
		//cout<<x1<<" "<<y1<<endl;
		lli ans,t=1,maxx = 1000000000000,an=0;
		for(lli i=0;i<=4;i++){
			ans = x1 + y1*t;
			t *= 2;
			//cout<<ans<<endl;
			string s = ntb(ans);
			lli p = btn(s);
			if(p < maxx){
				maxx = p;
				cout<<s<<" "<<ans<<endl;
				cout<<p<<endl;
				an = i;
			}
		}
		cout<<an<<endl;
	}	
rt;
}
	
