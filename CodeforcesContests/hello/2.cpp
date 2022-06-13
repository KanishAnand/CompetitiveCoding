#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int v[1000000][30]={0};
int main(void){
	int n,arr[20];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int p = pow(2,n);
	for(int i=0;i<p;i++){
		int j=0,k=i;
		while(k > 0){
			v[i][j] = k%2;
			k /= 2;
			++j;
		}
	}
	
	for(int i=0;i<p;i++){
		int sum = 0;
		for(int j=0;j<n;j++){
			if(v[i][j] == 0){
				sum -= arr[j];
			}
			else{
				sum += arr[j];
			}
		}
		if(sum == 0 || sum%360 == 0){
			cout<<"YES"<<endl;
			return 0;
		}
	}	
	cout<<"NO"<<endl;

return 0;
}
