#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int put(int l,int r);
//vector<int> arr(200005,0);
int arr[200005];
int main(void){
	char s[200005],key;
	int l,c=0,flag=0,count=1,f=0;
	cin>>s;
	l = strlen(s);
	key = s[l-1];

	for(int i=l-2;i>=0;i--){
		if(s[i] == key){
		//	--c;
			++count;
			f=0;
			c=0;
		}
		else{
			++c;
			if(count > 2){
				if(flag == 1){
					put(i+2,i+2);
					//cout<<"K";
					flag = 0;
					f = 1;
				}
				put(i+3,i+count);
				if(f != 1){
					flag = 1;
				}
			}
		
			else if(count == 2){
				if(flag == 1){
					put(i+1,i+1);
					flag = 0;
				}	
				else{
					flag = 1;
				}
			}
			count=1;
			f = 0;
			key = s[i];
		}

		if(c >= 2){
			flag = 0;
			c=0;
		}
		if(i == 0){
			if(count > 2){
				if(flag == 1){
					put(i,i);
				}
				put(i+2,i+count-1);
			}
			if(count == 2){
				if(flag == 1){
					put(i,i);
				}
			}
		}
	}
	
	for(int i=0;i<l;i++){
		if(arr[i] == 0){
			cout<<s[i];
		}
	}
	cout<<endl;

return 0;
}

int put(int l,int r){
	//cout<<l<<" "<<r<<endl;
	for(int i=l;i<=r;i++){
		arr[i] = 1;
	//	arr.insert(i,1);
	}
return 0;
}
