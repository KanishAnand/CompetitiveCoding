#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	int n;
	char s[200005];
	cin>>n;
	cin>>s;
	int min=20000000;
	char p[8][5];
	
	char c[]="RGB";
	strcpy(p[0],c);
	char d[]="RBG";
	strcpy(p[1],d);
	char e[]="GBR";
	strcpy(p[2],e);
	char f[]="GRB";
	strcpy(p[3],f);
	char g[]="BGR";
	strcpy(p[4],g);
	char h[]="BRG";	
	strcpy(p[5],h);
	int key;
	for(int i=0;i<6;i++){
		int count=0;
		for(int j=0;j<n;j++){
			int r=j%3;
			if(s[j] != p[i][r]){
				++count;
			}
		}
		if(count < min){
			min = count;
			key = i;
		}
	}

	cout<<min<<endl;
	int r = n/3;
	int l=n%3;

	for(int i=0;i<r;i++){
		cout<<p[key];
	}
	for(int j=0;j<l;j++){
		cout<<p[key][j];
	}
	cout<<endl;
	//cout<<p[key]<<endl;
return 0;
}
