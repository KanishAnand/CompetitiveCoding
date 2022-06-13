#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
int arr[100005];
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	char s[100005];
	cin>>s;
	int count=0;
	int p=strlen(s);
	int key=0;

	for(int i=0;i<p-1;i++){
		if(s[i] == s[i+1]){
			arr[i]=1;
			arr[i+1]=1;
			++count;
			int l=i-1,r=i+2;
			while(s[r] == s[l] && l >= key && r < p && arr[l] != 1 ){
				++count;
				arr[l]=1;
				arr[r]=1;
				--l;
				++r;
			}
		i=r-1;
		}
	}

//	cout<<count;
	if(count % 2 == 0){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
return 0;
}

