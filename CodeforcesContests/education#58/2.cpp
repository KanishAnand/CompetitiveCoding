#include<iostream>
#include<cstring>
using namespace std;
int main(void){
	char s[500005];
	cin>>s;
	int l=strlen(s),left=-1,right=-1;
	for(int i=0;i<l;i++){
		if(s[i] == '['){
			left = i;
			break;
		}
	}
	for(int i=l-1;i>=0;i--){
		if(s[i] == ']'){
			right = i;
			break;
		}
	}

	if(left == -1 || right == -1 || left >= right){
		cout<<"-1"<<endl;
		return 0;
	}
	
	int leftd=-1,rightd=-1;

	for(int i=left;i<=right;i++){
//		cout<<s[i];
		if(s[i] == ':'){
			leftd = i;
			break;
		}
	}

	for(int i=right;i>=left;i--){
		if(s[i] == ':'){
			rightd = i;
			break;
		}
	}

//	cout<<leftd<<" "<<rightd<<" ";
	if(leftd == rightd || leftd == -1 || rightd == -1){
		cout<<"-1"<<endl;
		return 0;
	}
	int count=0;
	for(int i=leftd;i<=rightd;i++){
		if(s[i] == '|'){
			++count;
		}
	}

	cout<<count+4<<endl;
return 0;
}

	


