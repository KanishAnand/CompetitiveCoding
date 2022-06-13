#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main(void){
	char s[250];
	int k,noofstar=0,noofcandy=0;
	cin>>s>>k;
	int n = strlen(s);
	for(int i=0;i<n;i++){
		if(s[i] == '*'){
			++noofstar;
		}
		if(s[i] == '?'){
			++noofcandy;
		}
	}
	int p = noofstar + noofcandy;
	if(k == n - p){
		for(int i=0;i<n;i++){
			if(s[i] != '?' && s[i] != '*'){
				cout<<s[i];
			}
		}
		cout<<endl;
	}

	else if(k > n - p){
		int f=1;
		if(noofstar == 0){
			cout<<"Impossible"<<endl;
			return 0;
		}

		int r = k - (n - p);
		for(int i=0;i<n;i++){
			if((f == 1) && (s[i] == '*')){
				for(int j=0;j<r;j++){
					cout<<s[i-1];
				}
			f = 0;
			}
			else if(s[i] != '*' && s[i] != '?'){
				cout<<s[i];
			}
		}
	cout<<endl;
	}
	
	else{
		int r = (n - p) - k,f=1,count=0;
		if(r > p){
			cout<<"Impossible"<<endl;
			return 0;
		}
		for(int i=0;i<n;i++){
			if(count == r){
				f = 0;
			}
			if(f == 1 && (s[i+1] == '*' || s[i+1] == '?')){
				count++;
			}
			else if(s[i] != '?' && s[i] != '*'){
				cout<<s[i];
			}
		}
	cout<<endl;
	}
return 0;
}
