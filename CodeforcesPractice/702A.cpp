#include<iostream>
#include<vector>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a,count=1,max=0;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	v[n] = 0;
	for(int i=0;i<n;i++){
		if(v[i] < v[i+1]){
			count++;
		}
		else{
		//	count++;
			if(max < count){
				max = count;
			}
			count=1;
		}
	}
	cout<<max<<"\n";
return 0;
}
