#include<iostream>
#include<cstring>
using namespace std;
int main(void){
	int t,fl;
	char s[1200];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s;
		int l=strlen(s);
		int first = 0,last = l-1,f=1;
		while(first < last){
			if(s[first] == s[last]){
				first++;
				last--;
			}
			else{
				f = 0;
				cout<<s<<endl;
				break;
			}
		}
		if(f == 0){
			continue;
		}
		else{
			fl=0;
			for(int j=0;j<l-1;j++){
				if(s[j] != s[j+1]){
					fl=1;
					char t=s[j];
					s[j] = s[j+1];
					s[j+1] = t;
					cout<<s<<endl;
					break;
				}
			}
		}
		if(fl == 0){
			cout<<"-1"<<endl;
		}
	}
return 0;
}

