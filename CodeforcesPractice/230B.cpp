#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<long int> v(1000005,0);
int main(void){
	long long int p,n,a;
	cin>>n;
	v[1] = 1;
	for(int i=2;i<=1000;i++){
		if(v[i] == 0){
			for(int j=i*i;j<=1000000;j+=i){
				v[j] = 1;
			}
		}
	}

	for(int i=0;i<n;i++){
		cin>>a;
		p = sqrt(a);
		if(p*p != a){
			cout<<"NO"<<endl;
		}
		else{
			if(v[p] == 0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
return 0;
}




