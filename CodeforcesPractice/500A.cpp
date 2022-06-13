#include<iostream>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,t,arr[30005],fin=0;
	cin>>n>>t;
	for(int i=1;i<n;i++){
		cin>>arr[i];
	}
	int i=1;
	while(fin < t){
		fin = i + arr[i];
		i = fin;
		if(fin == t){
			cout<<"YES\n";
			return 0;
		}
	}
		cout<<"NO\n";
return 0;
}

