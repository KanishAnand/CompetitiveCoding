#include<iostream>
using namespace std;
int m,s;
int min(int s2,int m2);
int max(int s1,int m1);
int main(void){
	cin>>m>>s;
	if(s == 0 && m == 1){
		cout<<"0 0";
		cout<<endl;
	return 0;
	}
	if(s < 1 || s > 9*m){
		cout<<"-1 -1"<<endl;
	}
	else{
		min(s,m);
		cout<<" ";
		max(s,m);
		cout<<endl;
	}
return 0;
}

int max(int s1,int m1){
	int i;
	if(m1 == 0){
		return 0;
	}
	if(s1 >= 9){
		cout<<"9";
		max(s1-9,m1-1);
	}
	else if(s1 < 9){
		cout<<s1;
		max(0,m1-1);
	}
return 0;
}


int min(int s2,int m2){
	static int k=1;
	int i;
	if(m2 == 0){
		return 0;
	}
	for(i=k;i<=9;i++){
		if(s2 - i > 9*(m2-1)){
			continue;
		}
	cout<<i;
	break;
	}
	k=0;
	min(s2-i,m2-1);
return 0;
}
	
