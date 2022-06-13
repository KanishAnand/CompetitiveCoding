#include<iostream>
using namespace std;
int main(void){
	int n,a,key,flag=1;
	cin>>n;
	cin>>a;
	while(a%2==0){
		a /= 2;
	}
	while(a%3==0){
		a /= 3;
	}
	key = a;
	for(int i=1;i<n;i++){
		cin>>a;
		while(a % 2==0){
			a /= 2;
		}
		while(a % 3 == 0){
			a /= 3;
		}
		if(a == key){
			flag = 1;
		}
		else{
			flag  = 0;
			break;
		}
	}
	if(flag == 0){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
return 0;
}
