#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
lli input(lli n);
lli max_of_all();
vector<lli> v;
lli input(lli n){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		v.push_back(val);
	}
return 0;
}

lli max_of_all(vector<lli> &vec){
	auto itr = max_element(vec.begin(),vec.end());
return *itr;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a;
	cin>>n;	
	set<pair<lli,lli>> st;
	//input(n);
	for(int i=0;i<n;i++){
		cin>>a;
		st.insert(make_pair(a,i+1));
	}

	lli i=1,min=1000000000,key,kf;
	auto itr = st.begin();
	while(i <= n){
		++i;
		lli e = (*itr).first;
		lli r = (*itr).second;
		//cout<<e<<endl;
		lli m = r - 1 > n - r ? r-1 : n-r;
		if(e/m < min){
			key = e;
			kf = r;
			min = e/m;
		}
		++itr;
	}
	cout<<min<<endl;
return 0;
}

