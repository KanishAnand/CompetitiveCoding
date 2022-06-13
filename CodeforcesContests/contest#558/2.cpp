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
	lli n;
	cin>>n;	
	//input(n);
