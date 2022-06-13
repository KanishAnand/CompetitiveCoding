#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[100005]={0};
int main(void){
	int n,m;
	cin>>n>>m;
	vector<int> v;
	int a;
	for(int i=0;i<m;i++){
		cin>>a;
		v.push_back(a);
	}

	int f,p=1,q=1;
	
	for(int i=0;i<m;i++){
		++arr[v[i]];
		if(arr[v[i]] >= p && a[v[i]] == q){
			
		}
		
		if(f==1){
			cout<<"1";
			++p;
		/*	for(int j=1;j<=n;j++){
				--arr[j];
			}*/
		}
		else{
			cout<<"0";
		}
	}
	cout<<endl;
return 0;
}

	

