#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int a,n;
	vector<int> v;
	cin>>n>>a;
	int rem;
	for(int i=0;i<n;i++){
		rem = a%10;
		v.push_back(rem);
		a /= 10;
	}
	int sum1=0,sum2=0;

	for(int i = 1;i < n;i++){
		sum1 = 0;
		sum2 = 0;
		for(int j=0;j<n-i;j++){
			sum1 += v[j];
		}
		for(int k=n-i;k<n;k++){
			sum2 += v[k];
			if(sum2 == sum1){
				if(k == n-1){
					cout<<"YES"<<endl;
					return 0;
				}
				sum2 = 0;
			}
			else if(sum2 > sum1){
				sum2 = 0;
				sum1 =0;
				break;
			}
		}
	}
	
	cout<<"NO"<<endl;
return 0;
}
