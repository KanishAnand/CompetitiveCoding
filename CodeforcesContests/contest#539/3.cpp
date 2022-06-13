#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a;
	vector<lli> v,dp;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}

	dp[0]=0;
	for(int i=1;i<n;i++){
		dp[i] = dp[i-1]^v[i];
	}

	sort(dp.begin(),dp.end());
	lli val=dp[0];
	for(int i=1;i<n;i++){
		if(val == dp[i]){
			++count;
		}
		else{
			val=dp[i];
		}
	}


