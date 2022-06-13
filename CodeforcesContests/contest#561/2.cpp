#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(val) for(lli i=0;i<val;i++)
#define pb push_back
#define rt return 0;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli k;
	cin>>k;
	vector<string> s;
	s.resize(10);
	//char s[10][10];
	s[0]="uaeio";
	s[1]="aeiou";
	s[2]="eioua";
	s[3]="iouae";
	s[4]="ouaei";
	
	if(k < 25){
		cout<<"-1"<<endl;
		rt;
	}	
	lli key=-1;
	for(int i=5;i<=k;i++){
		if(k % i == 0 && k/i >= 5){
			key = i;
			break;
		}
	}
	if(key == -1){
		cout<<"-1"<<endl;
		rt;
	}

	for(int i=1;i<=k/key;i++){
		for(int j=1;j<=key/5;j++){
			cout<<s[i%5];
		}
		for(int j=0;j<key%5;j++){
			cout<<s[i%5][j];
		}
	}

	//for(int i=1;i<=k/key;i++){

		//cout<<"aeiou";
	// 	for(int i=1;i<=(key)%5;i++){
	// 		cout<<"aeiou";
	// 	}

	// 	//cout<<endl;
	// 	cout<<"eioua";
	// 	for(int i=1;i<=key-5;i++){
	// 		cout<<"a";
	// 	}
	// 	//cout<<endl;
	// 	cout<<"iouae";
	// 	for(int i=1;i<=key-5;i++){
	// 		cout<<"a";
	// 	}
	// //	cout<<endl;
	// 	cout<<"ouaei";
	// 	for(int i=1;i<=key-5;i++){
	// 		cout<<"a";
	// 	}
	// //	cout<<endl;
	// 	cout<<"uaeio";
	// 	for(int i=1;i<=key-5;i++){
	// 		cout<<"a";
	// 	}
	// 	//cout<<endl;
	// 	for(int i=1;i<=k/key-5;i++){
	// 		cout<<"aeiou";
	// 		for(int j=1;j<=key-5;j++){
	// 			cout<<"a";
	// 		}
	// 	//	cout<<endl;
	// 	}
	//}
	//cout<<endl;
rt;
}
