#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
lli cnt[300000]={0};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	vector<lli> v,inc,dec;
	lli a,max=0;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a > max){
			max = a;
		}
		v.push_back(a);
		cnt[a]++;
	}	

	sort(v.begin(),v.end());

	for(int i=0;i<=max;i++){
		if(cnt[i] > 2){
			cout<<"NO"<<endl;
			return 0;
		}
	}

	for(int i=0;i<n;i++){
		if(cnt[v[i]] == 2){
			inc.push_back(v[i]);
			--cnt[v[i]];
		}
		else{
			dec.push_back(v[i]);
		}
	}

	cout<<"YES"<<endl;
	cout<<inc.size()<<endl;
	for(int i=0;i<inc.size();i++){
		cout<<inc[i]<<" ";
	}
	cout<<endl;
	cout<<dec.size()<<endl;
	for(int i=dec.size()-1;i>=0;i--){
		cout<<dec[i]<<" ";
	}
	cout<<endl;
return 0;
}