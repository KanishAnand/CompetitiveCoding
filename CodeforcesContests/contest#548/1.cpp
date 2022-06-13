#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int main(void){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	lli n,p;
	string st;
	cin>>n;
	lli no,arr[70000],i;
	cin>>st;
	//getline(cin,st);
	i = n;
	p = no;

	while(i >= 1){
		arr[i] = st[i-1] - '0';
		// p /= 10;
		--i;
	}

	lli sum=0;
	for(int j=n;j>=1;j--){
		//cout<<arr[i];
		if(arr[j] % 2 == 0){
			sum += j;
		}
	}

	cout<<sum<<endl;
return 0;
}
