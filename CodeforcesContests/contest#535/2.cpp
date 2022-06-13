#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
int arr[10005];
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	int a,n,max=0;
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
		if(a > max){
			max = a;
		}
	}

	for(int i=0;i<n;i++){
		if(max % v[i] == 0 && arr[v[i]] != 1){
			arr[v[i]] = 1;
			v[i]=0;
		}
	}

	int max2=0;
//	cout<<v[1]<<endl;
	for(int i=0;i<n;i++){
		if(v[i]!= 0){
			if(v[i] > max2){
				max2=v[i];
			}
		}
	}
	cout<<max<<" "<<max2<<endl;
return 0;
}
