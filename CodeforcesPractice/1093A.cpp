#include<iostream>
using namespace std;
int main(void){
	int n,a,count=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=7;j>=2;j--){
			count += a/j;
			a %= j;
			if(a == 1){
				count--;
				a = a + j;
			}
		} 
		cout<<count<<endl;
		count=0;
	}
return 0;
}

