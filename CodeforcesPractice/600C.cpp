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
	string s;
	vector<lli> v(30,0),ve;
	cin>>s;
	fr(i,0,s.length()){
		++v[s[i] - 'a'];
	}
	fr(i,0,26){
		if(v[i] % 2 == 1){
			ve.pb(i);
		}
	}

	lli an = ve.size(),no=-1,flag=0;
	if(an % 2 == 1){
		no = ve[an/2];
		v[no]--;
		flag = 1;
		//--an;
	}

	for(lli i=0;i<an/2;i++){
		++v[ve[i]];
	}
	for(lli i=an/2+flag;i<an;i++){
		--v[ve[i]];
	}

	string ans;
	for(lli i=0;i<26;i++){
		if(v[i] != 0){
			for(lli j=1;j<=v[i]/2;j++){
				ans.pb(i+'a');
			}
		}
	}

	string ans2 = ans;
	reverse(ans2.begin(),ans2.end());
	if(no != -1){
		ans.pb(no+'a');
	}

	cout<<ans + ans2<<endl;
rt;
}



	
