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
	string s,t;
	cin>>s>>t;
	vector<lli> cnt(27,0);
	vector<vector<lli>> cnts,cnt2s;
	cnts.resize(s.length()+3);
	cnt2s.resize(s.length()+3);

	fr(i,0,s.length()+2){
		fr(j,0,27){
			cnts[i].pb(0);
			cnt2s[i].pb(0);
		}
	}

	for(lli i=0;i<t.length();i++){
		cnt[t[i]-'a']++;
	}
	
	lli last = t[t.length()-1] - 'a';

	for(lli i=s.length()-1;i>=0;i--){
		for(lli j=0;j<26;j++){
			cnts[i][j] += cnts[i+1][j];
		}
		cnts[i][s[i]-'a']++;
	}

	cnt2s[0][s[0]-'a']++;
	for(lli i=1;i<s.length();i++){
		for(lli j=0;j<26;j++){
			cnt2s[i][j] += cnt2s[i-1][j];
		}
		cnt2s[i][s[i]-'a']++;
	}
	
	lli maxx = 0;
	for(lli i=0;i<s.length();i++){
		if(s[i] == t[0]){
			lli flag=0;
			for(lli j=0;j<27;j++){
				if(cnts[i][j] < cnt[j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				if(i > maxx){
					maxx = i;
				}
			}
		}
	}

	for(lli i=s.length()-1;i>=0;i--){
		if(s[i] == t[t.length()-1]){
			lli flag=0;
			for(lli j=0;j<27;j++){
				if(cnt2s[i][j] < cnt[j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				lli v = s.length()-1;
				if(v - i > maxx){
					maxx = v-i;
				}
			}
		}
	}

	cout<<maxx<<endl;
rt;
}