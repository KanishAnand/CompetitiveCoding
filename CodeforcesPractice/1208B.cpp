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
	lli n,a;
	set<lli> st;
	vector<map<lli,lli>> mp;
	cin>>n;	
	lli beg=1,end=n,mid;
	mp.resize(n+3);
	fr(i,0,n){
		cin>>a;
		mp[i][a]++;
		st.insert(a);
	}

	lli len = n - st.size();
	if(st.size() == n){
		cout<<"0"<<endl;
		rt;
	}

	fr(i,1,n){
		for(auto it = mp[i-1].begin();it != mp[i-1].end();it++){
			lli val = it->first;
			mp[i][val] += it->second;
		}
	}

	a = n;
	
	while(beg < end){
		mid = (beg + end)/2;
		if(mid == 0){
			break;
		}
		lli flag;
		for(lli i=0; i <= n-mid; i++){
			flag = 0;
			lli j = i + mid -1;
			for(auto it = mp[n-1].begin();it != mp[n-1].end();it++){
				lli val = it->first;
				lli c = 0;
				if(i != 0){
					auto it1 = mp[i-1].find(val);
					if(it1 != mp[i-1].end()){
						c = it1->second;
					}
				}
				auto it2 = mp[j].find(val);
				lli c2 = 0;
				if(it2 != mp[j].end()){
					c2 = it2->second;
				}

				lli k = c2 - c;
				if(it->second - k > 1){
					flag = 1;
					break;
				}
			}

			if(flag == 0){
				break;
			}
		}

		if(flag == 1){
			beg = mid + 1;
		}
		else{
			end = mid ;
		}
	}

	cout<<beg<<endl;
rt;
}
