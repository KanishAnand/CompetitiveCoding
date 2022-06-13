#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long int llu;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	llu n;
	llu b;
	cin>>n>>b;

	llu p = sqrt(b);
	llu arr[1000005]={0};

	for(int i=2;i<=p;i++){
		if(arr[i] == 0){
			for(int j=i*i;j<=p;j+=i){
				arr[j] = 1;
			}
		}
	}
	
	llu ans;
	for(int i=p;i>=2;i--){
		if(arr[i] == 0){
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
	llu cnt=0;
	cout<<cnt<<endl;
//	
	while(b % ans ==  0 && b > 0){
		b = b/ans;
		++cnt;
	}

	llu a;
	n = n/ans;
//	cout<<n<<endl;
	a = n/cnt;
       cout<<a<<endl;
return 0;
}

