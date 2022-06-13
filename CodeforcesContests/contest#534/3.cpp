#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int arr[4][4]={0};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	char s[1005];
	cin>>s;
	int p=strlen(s);
	for(int i=0;i<p;i++){
		int f=0;
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(arr[j][k] == 0){
					if(s[i] == '1'){
						if(arr[j][k+1] == 0 && k < 3){
							arr[j][k+1]=1;
							arr[j][k]=1;
							f=1;
							cout<<j+1<<" "<<k+1<<endl;
						}
					}
					else{
						if(arr[j+1][k]==0 && j < 3){
							arr[j+1][k]=1;
							arr[j][k]=1;
							f=1;
							cout<<j+1<<" "<<k+1<<endl;
						}
					}
				}
				if(f==1){
					break;
				}
			}
			if(f==1){
				break;
			}
		}
		
		int flag=0,k=0,j=0;
		int key;
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				if(arr[j][k]==1){
					flag=1;
				}
				else{
					flag=0;
					break;
				}
			}
			if(flag == 1 && k == 4){
				key=j;
				break;
			}
		}

		if(flag == 1){
			for(k=0;k<4;k++){
				arr[key][k]=0;
			}
		}
		else{
			flag=0;
			for(k=0;k<4;k++){
				for(j=0;j<4;j++){
					if(arr[j][k] == 1){
						flag=1;
					}
					else{
						flag=0;
						break;
					}
				}
				if(flag == 1 && j == 4){
					key = k;
					break;
				}
			}

			if(flag == 1){
				for(j=0;j<4;j++){
					arr[j][key] = 0;
				}
			}
		}
	}
return 0;
}
