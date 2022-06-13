#include<iostream>
using namespace std;
int main(void){
	int n,k;
	long long int min=100000000000;
	long long int val,p;
	cin>>n>>k;
	for(int i=k-1;i>=1;i--){
		if(n%i == 0 && n >= i){
			 p = n/i;
			 val = p*k + i;
			 if(val < min){
				 min = val;
			}
		}
	}
	cout<<min<<endl;
return 0;
}
