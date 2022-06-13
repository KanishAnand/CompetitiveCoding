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
	lli n;
	cin>>n;
	lli arr[500000];	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[n+i] = arr[i];
	}

	lli count=0,max=0;

	for(int i=0;i<2*n;i++){
		if(arr[i] == 1){
			count = 1;
			++i;
			while(arr[i] == 1 && i < 2*n){
				++count;
				++i;
			}
			if(count > max){
				max = count;
			}
			--i;
		}
		count=0;
	}

	cout<<max<<endl;
return 0;
}


