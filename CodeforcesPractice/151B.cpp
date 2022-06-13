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
	cin>>n;	
	vector<string> v;
	vector<lli> v1(100,0),v2(100,0),v3(100,0);
	string st;
	fr(i,0,n){
		cin>>m>>st;
		v.pb(st);
		fr(j,0,m){
			string r;
			cin>>r;
			lli l=r.length();
			if(r[0] == r[1] == r[3] == r[4] == r[6] == r[7]){
				v1[i]++;
			}
			else if{
				if(r[1] < r[0] && r[4] < r[3] && r[7] < r[6] && r[3] < r[1] && r[6] < r[4]){
					v2[i]++;
				}
			}
			else{
				v3[i]++;
			}
		}
	}

	lli m=-1;
	vector<lli> an1,an2,an3;
	fr(i,0,n){
		if(v1[i] > m){
			m=v1[i];
		}
	}
	fr(i,0,n){
		if(v1[i] == m){
			an1.pb(i);
		}
	}
	fr(i,0,n){
		if(v2[i] > m){
			m=v2[i];
		}
	}
	fr(i,0,n){
		if(v2[i] == m){
			an2.pb(i);
		}
	}
	fr(i,0,n){
		if(v3[i] > m){
			m=v3[i];
		}
	}
	fr(i,0,n){
		if(v3[i] == m){
			an3.pb(i);
		}
	}

	fr(i,0,an1.size()){
		if(an1.size() == 1){
			cout<<"If you want to call a taxi, you should call:"<<an1[0]<<"."<<endl;
			rt;
		}
		else{
			
		}
	}