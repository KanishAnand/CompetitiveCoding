#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>q;
	lli n,a,b,cost;
	for(int i=0;i<q;i++){
		cin>>n>>a>>b;
		if(2 * a <= b){
			cost = a*n;
		//	cout<<cost<<endl;
		}
		else{
			cost = (n/2)*b + (n%2)*a;
		}
	cout<<cost<<endl;
	}
return 0;
}
