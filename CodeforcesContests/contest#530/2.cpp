#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main(void){
	int n;
	cin>>n;
	if(n == 1){
		cout<<"2"<<endl;
	}
	else if(n == 2){
		cout<<"3"<<endl;
	}
	else if(n == 3 || n == 4){
		cout<<"4"<<endl;
	}
	else{
		int side = 2;
		int p = sqrt(n);
		int ans = 0;
		ans += (p - side)*2;
		ans += 4;
		int q = n - p*p;
		if(q != 0){
			if(q <= p){
				ans += 1;
			}
			else{
				ans += 2;
			}
		}
		cout<<ans<<endl;
	}
return 0;
}
