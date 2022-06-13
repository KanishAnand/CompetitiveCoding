#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	int n,k,t,l;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		char ch='a';
		for(l=0;l<k;l++){
			for(int j=1;j<=n/k;j++){
				ch = 97+l;
				cout<<ch;
			}
		}
		for(int l=1;l<=n%k;l++){
			cout<<"a";
		}
	cout<<endl;
	}
return 0;
}
