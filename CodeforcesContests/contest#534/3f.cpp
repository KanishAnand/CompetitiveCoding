#include<iostream>
#include<cstring>
using namespace std;
int main(void){
	char s[1005];
	cin>>s;
	int p=strlen(s);
	int lx=1,ly=1,rx=3,ry=1;
	for(int i=0;i<p;i++){
		if(s[i] == '1'){
			cout<<lx<<" "<<ly<<endl;
			if(ly == 3){
				ly = 1;
			}
			else{
				ly+=2;
			}
		}
		else{
			cout<<rx<<" "<<ry<<endl;
			if(ry == 4){
				ry = 1;
			}
			else{
				ry+=1;
			}
		}
	}
return 0;
}

