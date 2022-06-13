#include<iostream>
int main(void){
	int n,a,d,arr[];
	cin>>n>>d;
	vector<int> v,b;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<n;i++){
		cin>>a;
		b.push_back(a);
	}
	int p=v[d-1] + b[0];
	int min=a[n-1],rank=0;
	int x=n-1;
	for(int i=0;i<n;i++){
		if(i != d-1){
			if(v[i] + min > p){
				rank++;
				min = a[--x];
			}
			else if(v[i] + min == p){
				min = a[--x];
			}
			else{
				it = lower_bound(b.begin()+1,b.end(),p-v[i]);
				it = it - b.begin();
				if(arr[it] >= p-v[i]){
					--it;
				}
				arr[i] = 1;
			}
		}
	}
	cout<<rank+1<<endl;
return 0;
}
		
