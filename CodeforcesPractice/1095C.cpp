#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	int n,k,v,i=0,c=0;
	cin>>n>>k;
	int arr[50] = {0};
	if(n < k){
		cout<<"NO"<<endl;
		return 0;
	}
	if(n == k){
		cout<<"YES"<<endl;
		int t=1;
		while(t <= n){
			cout<<"1 ";
			t++;
		}
		cout<<endl;
		return 0;
	}
	else{
		int a=n,rem;
		while(a > 0){
			rem = a%2;
			if(rem == 1){
				++c;
			}
			++i;
			arr[i] = rem;
			a = a/2;
		}
	}
	v = i;
	//cout<<i<<endl<<c<<endl;
	if(c > k){
		cout<<"NO"<<endl;
		return 0;
	}
	else{
		int count = c;
		while(count < k){
			while(arr[i] == 0){
				--i;
			}
			--arr[i];
			arr[i-1] += 2;
			++count;
			/*if(arr[i] == 0){
				--i;
			}*/
		}
	}
	cout<<"YES"<<endl;
	int p;
	for(int j=1;j<=v;j++){
		if(arr[j] != 0){
			p = pow(2,j-1);
			int t=1;
			while(t <= arr[j]){
				cout<<p<<" ";
				++t;
			}
		}
	}
	cout<<endl;
return 0;
}



