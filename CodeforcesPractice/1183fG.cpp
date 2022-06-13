#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
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
	lli n,q,a,b;
	
	cin>>q;
	while(q--){
		cin>>n;
		vector<pair<lli,lli>> v;
		vector<lli> arr(n+2,0),arr2(n+2,0);
		fr(i,0,n){
			cin>>a>>b;
			arr[a]++;
			if(b == 1){
				arr2[a]++;
			}
		}

		fr(i,1,n+2){
			if(arr[i] != 0){
				v.pb(make_pair(arr[i],arr2[i]));
			}
		}

		sort(v.begin(),v.end(),greater<>());
		lli sum=0,t = v[0].first,sum2=0;
		vector<lli> cnt(n+2,0);
		set<lli> st;
		lli i=0;

		while(1){
			if(t <= 0){
				break;
			}

			fr(j,i,v.size()){
				i = j;
				if(v[j].first >= t){
					st.insert(v[j].second);
					cnt[v[j].second]++;
					if(j == v.size() - 1){
						i++;
					}
				}
				else{
					break;
				}
			}

			if(st.empty() == 0){
				auto it = st.end();
				--it;
				sum += t;

				sum2 += min(*it,t);
				if(cnt[*it] > 0){
					cnt[*it]--;
				}

				if(cnt[*it] == 0){
					st.erase(it);
				}
			}
			--t;
		}
		cout<<sum<<" "<<sum2	<<"\n";

	}	
rt;
}

	
