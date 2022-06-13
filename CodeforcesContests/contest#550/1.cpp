#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string st;
	//char st[200];
	int n;
	cin>>n;
	
	//cin>>st;
	//cout<<n;
	getline(cin,st);

	for(int i=0;i<n;i++){
		//cout<<"DF";
		getline(cin,st);
	//	cout<<st<<endl;
		int flag=1;
		//cout<<"DF"<<endl;
		//cin>>st;
		//cout<<st<<endl;
		sort(st.begin(),st.end());
		int l=st.length();

		for(int i=l-1;i>0;i--){
			if(st[i] - st[i-1] != 1){
				flag = 0;
				break;
			}
		}
		if(flag == 0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
		//cout<<st<<endl;
	}	
return 0;
}
