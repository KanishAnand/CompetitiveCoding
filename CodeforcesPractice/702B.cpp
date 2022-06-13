#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
	int a,n,arr[50],p,s;
	long long int count=0;
	cin>>n;
	vector<int> v;
	arr[0] = 1;
	for(int i=1;i<40;i++){
		arr[i] = 2*arr[i-1];;
	}

	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		int p = 2*v[i];
		int c = binary_search(arr,arr+40,p);
		if(c == 1){
			--count;
		}
	}

	//cout<<count<<endl;
	for(int i=0;i<n;i++){
		p = v[i];
		for(int j=0;j<40;j++){
			s = arr[j];
			if(s > p){
				int m = s - p;
				vector<int>::iterator low,up;
				if(binary_search(v.begin(),v.end(),m)){
				       	up = upper_bound(v.begin(),v.end(),m);
					low = lower_bound(v.begin(),v.end(),m);
					count += up - low;
				}
			}
		}
	}
	
	cout<<count/2<<endl;
return 0;
}




