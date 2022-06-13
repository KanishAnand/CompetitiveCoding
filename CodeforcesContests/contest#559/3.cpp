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
	lli n,m,a;
	lli ans=0;
	cin>>n>>m;	
	lli min=1000000000,max=-1;
	vector<lli> b,g;
	//input(n);
	for(int i=0;i<n;i++){
		cin>>a;
		b.push_back(a);
		if(a > max){
			max = a;
		}
		ans += a;
	}

	ans *= m;
	//cout<<ans<<endl;
	sort(b.begin(),b.end());
	lli x = b[n-1];

	for(int i=0;i<m;i++){
		cin>>a;
		g.push_back(a);
		if(a < min){
			min  = a;
		}
	}
	sort(g.begin(),g.end());

	if(min < max){
		cout<<"-1"<<endl;
		return 0;
	}

	for(int i=m-1;i>=1;i--){
//		cout<<g[i]<<" "<<x<<endl;
		ans += g[i] - x;
	}
//cout<<ans<<endl;
	if(g[0] - x != 0){
		ans += -b[n-2] + g[0];
	}

	cout<<ans<<endl;
return 0;
}



