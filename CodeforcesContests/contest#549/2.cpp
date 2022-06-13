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
	lli n,max,arr[20];
	cin>>n;
	lli cnt=0,p=n;
	while(p > 0){
		cnt++;
		p /= 10;
	}
	lli q=n,co=1;

	while(q > 0){
		arr[cnt - co] = q % 10;
		co++;
		q /= 10;
	}

	lli nine[20];
	nine[0]=1;
	for(int i=1;i<=cnt;i++){
		nine[i] = nine[i-1]*9;
	}

	if(cnt == 1){
		cout<<n<<endl;
		return 0;
	}
	
	else{
		llu ans=1;
		for(int i=0;i<cnt;i++){
			ans *= arr[i];
		}
		max = ans;
		if(arr[0] == 1){
			if(nine[cnt - 1] > max){
				max = nine[cnt-1];
			}
		}
		
		for(int i=0;i<cnt;i++){
			ans = 1;
			if(arr[i] != 0){
				for(int j=0;j<i;j++){
					ans *= arr[j];
				}
				ans*= (arr[i]-1);
				ans *= nine[cnt - i - 1];
				//cout<<ans<<endl;
				if(ans > max){
					max = ans;
				}
			}
		}
	}

	cout<<max<<endl;
return 0;
}

