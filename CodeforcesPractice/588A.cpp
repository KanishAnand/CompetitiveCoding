#include<iostream>
using namespace std;
typedef unsigned long long int llu;
int main(void){
	llu n,a,p,min=200,cost=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>p;
		if(p < min){
			min = p;
		}
		cost += min*a;
	}
	cout<<cost<<endl;
return 0;
}
