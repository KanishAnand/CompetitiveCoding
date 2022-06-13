#include<iostream>
using namespace std;
int main(void){
	int n;
	cin>>n;
	for(int i = 1;i <= n/4; i++){
		cout<<"aabb";
	}
	if(n%4 == 1){
		cout<<"a";
	}
	if(n%4 == 2){
		cout<<"aa";
	}
	if(n%4 == 3){
		cout<<"aab";
	}
	cout<<"\n";
return 0;
}
