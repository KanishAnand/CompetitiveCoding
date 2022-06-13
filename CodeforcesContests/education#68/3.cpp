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
	lli q;
	
	cin>>q;
	while(q--){
		//cout<<"K"<<endl;
		string s,t,p;
		cin>>s>>t>>p;
		vector<lli> as(26,0),at(26,0),ap(26,0);
		fr(i,0,s.length()){
			as[s[i] - 'a']++;
		}
		fr(i,0,t.length()){
			at[t[i] - 'a']++;
		}
		fr(i,0,p.length()){
			ap[p[i] - 'a']++;
		}
		if(s.length() > t.length()){
			cout<<"NO"<<endl;
		}
		else{
			lli flag = 0;
			for(lli i=0;i<26;i++){
				if(as[i] > at[i]){
					flag = 1;
					break;
				}
				if(as[i] + ap[i] < at[i]){
					flag = 1;
					break;
				}
			}

			if(flag == 1){
				cout<<"NO"<<endl;
			}
			else{
				lli in = t.length()-1;
				lli f=0;
				for(lli i=s.length()-1;i>=0;i--){
					char ch = s[i];
					as[ch - 'a']--;
					lli j = in;
					for(j = in;j >=0;j--){
						if(t[j] != ch){
							at[t[j]-'a']--;
						}
						else{
							break;
						}
					}

					in = j-1;
					if(t[j] != ch){
						cout<<"NO"<<endl;
						f=1;
						break;
					}
					else{
						at[ch - 'a']--;
						fr(j,0,26){
							if(at[j] < as[j]){
								f = 1;
								break;
							}
						}
						if(f == 1){
							cout<<"NO"<<endl;
							break;
						}
					}
				}

				if(f == 0){
					cout<<"YES"<<endl;
				}
			}
		}
	}
rt;
}




	
