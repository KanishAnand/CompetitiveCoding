#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void){
	int n,k,sump=0,sumn=0;
	int arr[105];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i] == 1){
			++sump;
		}
		else{
			++sumn;
		}
	}

	int v;
	int sumop = sump,sumon=sumn;
	int max=0;
	for(int j=0;j<n;j++){
		int b=j;
		sump = sumop;
		sumn = sumon;
		int l = b/k;
		l = 0-l;
		for(int i=l;;i++){
	//		cout<<b<<endl;
			if(b + i*k >= 0 && b + i*k < n){
				int p=b+i*k;
				if(arr[p] == 1){
					--sump;
				}
				else{
					--sumn;
				}
			}

			else if(b + i*k >= n){
				break;
			}
		}
		v = fabs(sump - sumn);
		//cout<<v<<endl;
		if(v > max){
			max = v;
		}
	}
	cout<<max<<endl;
return 0;
}


