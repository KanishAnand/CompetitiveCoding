#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli arr[1005]={0};
int main(void){
	lli n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a] = 1;
		arr[b] = 1;
	}
	lli key;
	for(int i=1;i<=n;i++){
		if(arr[i] == 0){
			key = i;
			break;
		}
	}

	cout<<n-1<<endl;
	for(int i=1;i<=n;i++){
		if(i != key){
			cout<<i<<" "<<key<<endl;
		}
	}
return 0;
}