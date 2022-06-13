#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	int n;
	cin>>n;
	int l1,r1,l2,r2;
	for(int i=0;i<n;i++){
		cin>>l1>>r1>>l2>>r2;
		if(r2 != l1)
			cout<<l1<<" "<<r2<<endl;
		else
			cout<<r1<<" "<<l2<<endl;

	}
return 0;
}
