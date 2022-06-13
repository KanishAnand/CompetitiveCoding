#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long int n,min,flag=0,count=0,a[200005],total=0,b[200005],arr[200005];
	cin>>n;
	for(long int i=1;i<=n;i++){
		cin>>a[i];
		arr[a[i]] = i;
	}

	for(long int i=1;i<=n;i++){
		cin>>b[i];
		if(flag == 0){
			min = arr[b[1]];
			flag=1;
		}
		count = arr[b[i]] - total;
		if(arr[b[i]] < min){
			cout<<"0 ";
		}
		else{
			min = arr[b[i]];
			cout<<count<<" ";
			total = arr[b[i]];
		}
	}
	cout<<endl;
return 0;
}

	
