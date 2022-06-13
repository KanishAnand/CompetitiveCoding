#include<iostream>
using namespace std;
typedef long long int lli;
int main(void){
	lli q,l,r,x;
	cin>>q;
	for(lli i = 0;i<q;i++){
		cin>>l>>r>>x;
		if(l/x != 0){
			if(x != l)
			cout<<x<<endl;
			else
			cout<<(r/x + 1)*x<<endl;	
		}
		else{
			cout<<(r/x +1)*x<<endl;
		}
	}
return 0;
}



