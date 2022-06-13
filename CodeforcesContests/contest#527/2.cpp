#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	vector<int> v;
	int n,a,count=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i+=2){
		count += v[i+1] - v[i];
	}
	cout<<count<<endl;

return 0;
}
