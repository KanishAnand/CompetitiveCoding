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

lli minm(lli a,lli b,lli c){
	if(a <= b && a <= c){
		return a;
	}
	if(b <= c && b <= a){
		return b;
	}
return c;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	string str;
	cin>>n;	
	//input(n);
	cin>>str;
	lli sum=0,val3,val2,val,miin = 1000000000;
	string res = "ACTG";

	for(int i=0;i< n - 3;i++){
		sum = 0;
		for(int j=0;j<4;j++){
			val = abs(res[j] - str[i+j]);
			val2 = abs(90 - str[i+j] + res[j] - 65 + 1);
			val3 = abs(str[i+j] - 65 + 90 - res[j] + 1);
			sum += minm(val,val3,val2);
			//cout<<sum<<endl;
		}

		if(sum < miin){
			miin = sum;
		}
	}

	cout<<miin<<endl;
return 0;
}
