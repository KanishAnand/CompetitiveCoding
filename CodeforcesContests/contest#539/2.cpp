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
	lli n,sum=0,a;
	cin>>n;
	vector<lli> arr;
	for(int i=0;i<n;i++){
		cin>>a;
		sum += a;
		arr.push_back(a);
	}

	lli osum=sum,min=sum;

	sort(arr.begin(),arr.end());
	lli el = arr[0];
	
	for(int i=n-1;i>=1;i--){
		sum = osum;
//		cout<<arr[i]<<endl;
		for(lli j=arr[i];j>1;j--){
			sum = osum;
			if(arr[i] % j == 0){
//				cout<<j<<"  "<<arr[i]<<"  ";
				sum += el*j;
				sum -= el;
				sum -= arr[i];
				sum += arr[i]/j;
//				cout<<sum<<endl;
			}
			if(sum < min){
				min = sum;
//				cout<<"k"<<min<<endl;
			}
		}
	}		

	cout<<min<<endl;
return 0;
}
