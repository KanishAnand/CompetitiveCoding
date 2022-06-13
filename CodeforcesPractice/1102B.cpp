#include<iostream>
using namespace std;
int main(void){
	int n,k;
	cin>>n>>k;
	int sum=0,arr[n+2],count[5005]={0};
	int max=0,c=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i] > max){
			max = arr[i];
		}
		if(count[arr[i]] == 0){
			++c;
		}
		++count[arr[i]];
	}

	if(c < k){
		cout<<"NO"<<endl;
		return 0;
	}

	int maxc=0;
	for(int i=1;i<=max;i++){

		if(count[i] > k){
			cout<<"NO"<<endl;
			return 0;
		}
		sum += count[i];
	}

	if(sum < k){
		cout<<"NO"<<endl;
		return 0;
	}

	else{
	
		cout<<"YES"<<endl;
		for(int i = 0;i < n; i++){
			if(count[arr[i]] > maxc){
				maxc = count[arr[i]];
			}

			int j = n-i-1;
			if(j == k - maxc && maxc != k){
				cout<<j<<endl;
				j = maxc+1;
				while(j != k){
					cout<<j<<" ";
					++j;
				}
			cout<<endl;
			return 0;
			}
			cout<<count[arr[i]]<<" ";
			--count[arr[i]];
		}
	}
	cout<<endl;
return 0;
}



	



