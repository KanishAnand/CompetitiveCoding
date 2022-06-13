#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char s[2000],p[2000];
	cin>>s>>p;
	int a=strlen(s);
	int b=strlen(p);
	if(a != b){
		cout<<"No"<<endl;
	}
	else{
		int flag=0;
		for(int i=0;i<a;i++){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){	
				if(p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u'){
					flag=1;
				}
				else{
					flag=0;
					break;
				}
			}

			else{	
				if(p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u'){
					flag=0;
					break;
				}
				else{
					flag=1;
				}
			}
		}
		if(flag == 1){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}	

	}
	return 0;
}
