#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int n,max=0,min=3000,sum=0;
	cin>>n;
	vector<int> v(8000);
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a > max){
			max = a;
		}
		if(a < min){
			min = a;
		}
		++v[a];
	}

	for(int i=min;i<=max;i++){
		if(v[i] > 1){
			sum += v[i] - 1;
			v[i+1] += v[i] - 1;
			if(i+1 > max){
				max = i+1;
			}
		}
	}
	cout<<sum<<endl;
return 0;
}
