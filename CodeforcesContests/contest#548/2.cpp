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
	lli n,arr[300000];
	cin>>n;	
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	lli sum = 0;
	lli min = 2000000000;

	for(int i=n;i>=1;i--){

		if(arr[i] < min){
			sum += arr[i];
			min = arr[i];
		}

		else{
			if(min <= 1){
				sum += 0;
				min = 0;
			}
			else{
				sum += (min - 1);
				min -= 1;
			}
		}
	}

	cout<<sum<<endl;
return 0;
}
