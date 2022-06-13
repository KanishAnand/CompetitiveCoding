#include<iostream>
#include<cstring>
using namespace std;
int main(void){
	char s[100];
	cin>>s;
	int n = strlen(s);
	int p = (n - 1)/2,f=1;
	int r=p,l=p;
	for(int i=p;i<n&&i>=0;){
		cout<<s[i];
		if(f == 1){
			f=0;
			++r;
			i = r;
			continue;
		}
		if(f == 0){
			f=1;
			--l;
			i = l;
			continue;
		}
	}
	cout<<endl;
return 0;
}
