#include<iostream>
using namespace std;
int main(void){
	int a,b,c;
	cin>>a>>b>>c;
	int d = b - a;
	if(c == 0){
		if(a == b){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	else{
		if(d % c == 0 && ((d >= 0 && c >= 0) || (d<=0 && c <= 0)) ){
			cout<<"YES"<<endl;
		}	
		else{
			cout<<"NO"<<endl;
		}
	}
return 0;
}
