#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long int llu;
llu arr[500000];
int main(void){
	llu n,count=0;
	cin>>n;
	vector<llu> v;
	for(llu i=1;i<=n/2;i++){
		llu pos=1,sum=0,f=0;
		while(pos != 1 || f == 0){
			//pos = 1;
			f = 1;
			pos += i;
			if(pos > n){
				pos -= n;
			}
			sum += pos;
		}
		if(arr[sum] != 1){
			v.push_back(sum);
			count++;
			arr[sum] = 1;
		}
	}
	
	sort(v.begin(),v.end());
	cout<<"1 ";
	for(llu i=0;i<count;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
return 0;
}
