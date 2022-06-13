#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,sum=0;
	cin>>n;
	for(int i=2;i<=n-1;i++){
		sum += i*(i+1);
	}	

	cout<<sum<<endl;
return 0;
}
