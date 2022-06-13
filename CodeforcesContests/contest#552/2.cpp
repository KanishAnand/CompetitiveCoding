#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
lli arr[200]={0};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<lli> v;
	lli n,cnt=0,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(arr[a] == 0){
			arr[a] = 1;
			v.push_back(a);
			//++cnt;
		}
	}	

	sort(v.begin(),v.end());

	if(v.size() > 3){
		cout<<"-1"<<endl;
	}
	else if(v.size() == 1){
		cout<<"0"<<endl;
	}
	else if(v.size() == 2){
		if((v[1] - v[0]) % 2 == 0){
			cout<<(v[1]-v[0])/2<<endl;
		}
		else{
			cout<<v[1]-v[0]<<endl;	
		}
	}
	else{
		if(v[2] - v[1] == v[1] - v[0]){
			cout<<v[2] - v[1]<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
return 0;
}
