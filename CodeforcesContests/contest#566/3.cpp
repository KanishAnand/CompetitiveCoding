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
	lli n;
	vector<vector<lli>> v(100003);
	vector<vector<vector<string>>> an(100003);
	for(lli i=0;i<100003;i++){
		v[i].resize(30);
		for(lli j=0;j<30;j++){
			v[i][j]=0;
		}
	}
	for(lli i=0;i<100003;i++){
		an[i].resize(30);
	}

	cin>>n;	
	lli maxx = -1;
	string st;
	fr(p,0,n){
		cin>>st;
		char ans;
		lli c=0;
		for(lli i=0;i<st.length();i++){
			if(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' ||st[i] == 'o' ||st[i] == 'u'){
				ans = st[i];
				++c;
			}
		}
		if(c > maxx){
			maxx = c;
		}
		v[c][ans - 'a']++;
		an[c][ans - 'a'].pb(st);
	}

	
	//lli c=0,d=0;
	lli a=0,b=0;
	vector<string> an1,an2;
	vector<string> an3;	

	for(lli i=1;i<=maxx;i++){
		lli d=0;	
		for(lli j=0;j<30;j++){
			if(v[i][j] > 1){
				b += v[i][j]/2;
				for(lli p=0;p<2*(v[i][j]/2);p++){
					an2.pb(an[i][j][p]);
				}
				if(v[i][j]%2 == 1){
					d += v[i][j]%2;
					an1.pb(an[i][j][2*(v[i][j]/2)]);
				}
			}
			else if(v[i][j] == 1){
				++d;	
				an1.pb(an[i][j][0]);		
			}
		}
		if(d % 2 == 1){
			an3.pb(an1[an1.size()-1]);
			an1.pop_back();
		}
		a += d/2;
	}


	lli ans=0;
	ans += min(a,b);
	a - ans;
	b -= ans;
	lli k=0,l=0;

	if(b == 0){
		cout<<ans<<endl;
	}
	else{
		cout<<ans+b/2<<endl;
	}
	//cout<<an1[1]<<endl;
	for(lli i=0;i<ans;i++){
		cout<<an1[k]<<" "<<an2[l]<<endl;
		++k;++l;
		cout<<an1[k]<<" "<<an2[l]<<endl;
		++k;++l;
	}

	if(b != 0){
		for(lli i=0;i<b/2;i++){
			cout<<an2[l+2]<<" "<<an2[l]<<endl;
			cout<<an2[l+3]<<" "<<an2[l+1]<<endl;
			l += 4;
		}
	}
	
rt;
}

	
