#include<iostream>
using namespace std;
int main(void){
	int freepolice=0,crimes=0,ans=0, n,arr[100004];
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}

	for(int i = 1; i <= n; i++){
		if(arr[i] > 0){
			freepolice += arr[i];
		}

		else{
			if(freepolice > 0){
				freepolice--;
			}
			else{
				crimes++;
			}
		}
	}

	cout<<crimes<<endl;
return 0;
}






