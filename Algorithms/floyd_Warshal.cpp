#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	cin>>n;
	vector<vector<int>> arr;
	arr.resize(n+1);
	int a;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a;
			arr[i].push_back(a);
		}
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j] > arr[i][k] + arr[k][j]){
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
return 0;
}