#include<iostream>
using namespace std;
int main(void){
	int n,m,a,b,ans=0;
	cin>>n>>m>>a>>b;
	
	if(m*a <= b){
		cout<<n*a<<endl;
		return 0;
	}

	else{
		int min;
		min = (n%m)*a < b ? (n%m)*a : b;
		ans = (n/m)*b + min;
		cout<<ans<<endl;
	}

return 0;
}



