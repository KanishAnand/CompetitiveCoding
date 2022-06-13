#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	char s[4],p[10][5];
	cin>>s;
	for(int i=0;i<5;i++){
		cin>>p[i];
	}
	for(int i=0;i<5;i++){
		if(s[0] == p[i][0] || s[1] == p[i][1]){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;




return 0;
}
