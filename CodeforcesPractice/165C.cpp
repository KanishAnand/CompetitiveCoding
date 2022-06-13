#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long int llu;
llu arr[1000005] = {0};
int main(void){
	int k;
	char s[1000005];
	cin>>k>>s;
	arr[0] = 1;
	llu l = strlen(s),sum=0;
	for(int i=0;i<l;i++){
		s[i] -= '0';
		sum += s[i];
	}
	if(sum < k){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<l;i++){
		s[i] += s[i-1];
	}
	long long int p;
	llu count=0;
	for(int i = 0;i < l; i++){
		p = s[i] - k;
		if(p >=0){
			if(arr[p] != 0){
				count += arr[p];
			}
		}
		++arr[s[i]];
	}

	cout<<count<<endl;
return 0;
}


