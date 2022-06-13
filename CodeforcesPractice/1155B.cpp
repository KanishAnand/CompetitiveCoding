#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(void){
	lli n,count_8=0;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i] == '8'){
			count_8++;
		}
	}
	lli p = n-11;
	p /= 2;
	if(count_8 <= p){
		cout<<"NO"<<endl;
		return 0;
	}
	lli c=0,key;

	for(int i=0;i<n;i++){
		if(s[i] == '8'){
			c++;
		}
		if(c == p+1){
			key = i;
			break;
		}
	}

	if(key - p <= p){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
return 0;
}