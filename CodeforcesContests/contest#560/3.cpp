#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr for(lli i=0;i<n;i++)
#define pb push_back
#define rt return 0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;	
	string st;
	vector<char> an;
	cin>>st;
	lli a=0,fl=0,c=0;
	for(int i=0;i<n;i++){
			if(i < n-1 && st[i] == st[i+1]){
				an.push_back(st[i]);
				++i;
				++c;
				while(i < n-1 && st[i] == st[i+1]){
					++i;
					++c;
				}
				++i;
				if(i < n){
					an.push_back(st[i]);
				}
			}
			else{
				an.push_back(st[i]);
				if(i < n-1){
					an.push_back(st[i+1]);
				}
				//cout<<"FD"<<endl;
				i+=1;
			}
		//}
	}
	if(an.size() != 0 && an.size()%2 != 0){
			an.pop_back();	
			++c;
	}
	cout<<c<<endl;
	for(int i=0;i<an.size();i++){
		cout<<an[i];
	}
	cout<<endl;
return 0;
}
	
