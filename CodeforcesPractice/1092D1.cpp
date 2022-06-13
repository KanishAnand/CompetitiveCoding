#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int a,n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	int key,key2,f=0;
	for(int i=0;i<n;i++){
		if((v[i]%2 == v[i+1]%2) && i < n-1){
			i++;
			continue;
		}
		else{
			key = v[i]%2;
			if(f == 0){
				f = 1;
				key2 = key;
				continue;
			}
			if(key != key2){
				cout<<"NO"<<endl;
				return 0;
			}
			key2 = key;
		}
	}
	cout<<"YES"<<endl;
return 0;
}



