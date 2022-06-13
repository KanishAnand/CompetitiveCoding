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
	lli n,a;
	lli arr[200005],sumodd[200030]={0},sumeven[200030]={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=n;i>=1;i--){
		if(i % 2 == 1){
			sumodd[i] = sumodd[i+2] + arr[i];
			sumeven[i] = sumeven[i+1];
		}
		else{
			sumeven[i] = sumeven[i+2] + arr[i];
			sumodd[i] += sumodd[i+1];
		}
	}
	lli sumo =0,sume=0,count=0;

	for(int i=1;i<=n;i++){
		// if(i == 2){
		// 	cout<<sumo<<" "<<sume<<" "<<sumodd[i+1]<<" "<<sumeven[i+1]<<endl;
		// }
		if(sumo + sumeven[i+1] == sume + sumodd[i+1]){
			++count;
			//cout<<i<<endl;
		}

		if(i % 2 == 1){
			sumo += arr[i];
		}
		else{
			sume += arr[i];
		}
	}

	cout<<count<<endl;
return 0;
}