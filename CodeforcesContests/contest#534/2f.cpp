#include<iostream>
#include<cstring>
int top=-1;
int push(int val);
int pop();
int stack[100005];
using namespace std;

int main(void){
	char s[100005];
	cin>>s;
	int count=0;
	int p=strlen(s);
	for(int i=0;i<p;i++){
		if(s[stack[top]] == s[i] && top != -1){
			++count;
			pop();
		}
		else{
			push(i);
		}
	}

	if(count % 2 == 0){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
return 0;
}

int push(int val){
	stack[++top] = val;
return 0;
}

int pop(){
	--top;
return 0;
}
