#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int arr[300000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	

	int left,right;

	for(int i=n-1;i>=0;i--){
		if(arr[i] == 0){
			left = i;
			break;
		}
	}

	for(int i=n-1;i>=0;i--){
		if(arr[i] == 1){
			right = i;
			break;
		}
	}

	int min = left < right ? left:right;
	cout<<min+1<<endl;
return 0;
}