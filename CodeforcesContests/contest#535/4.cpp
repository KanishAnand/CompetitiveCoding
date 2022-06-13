#include<iostream>
#include<cstring>
using namespace std;
int main(void){
	int n;
	char s[200005];
	cin>>n;
	cin>>s;
	int count=0;
	
	for(int i=0;i<n-1;i++){
		if(s[i] == s[i+1]){
			if('G' != s[i] && ('G' != s[i+2] || i == n-2)){
				++count;
				s[i+1] = 'G';
			}
			else if('R' != s[i] && ('R' != s[i+2] || i == n-2)){
				++count;
				s[i+1] = 'R';
			}
			else{
				++count;
				s[i+1]='B';
			}
		}
	}

	cout<<count<<endl;
	cout<<s<<endl;
return 0;
}

