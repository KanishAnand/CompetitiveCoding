#include<iostream>
#include<vector>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,k,v[1000002]={0};
//	vector<int> v;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>c;
//		v.insert(v.begin()+c,1);
		v[c] = 1;
	}
	int pos = 1;
	if(v[pos] == 1){
		cout<<"1"<<endl;
		return 0;
	}
	int a,b;
	for(int i=1;i<=k;i++){
		cin>>a>>b;
		if(pos == a){
			pos = b;
		}
		else if(pos == b){
			pos = a;
		}
		if(v[pos] == 1){
			cout<<pos<<endl;
			return 0;
		}
	}
	cout<<pos<<endl;
return 0;
}




