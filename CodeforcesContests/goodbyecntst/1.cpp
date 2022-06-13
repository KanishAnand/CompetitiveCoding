#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
	int y,b,r;
	cin>>y>>b>>r;
	while((b - y < 1) || (r - y < 2)){
		--y;
	}
	cout<<3 + 3*y<<endl;
return 0;
}
