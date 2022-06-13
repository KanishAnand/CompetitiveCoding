#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
vector<lli> mm,nn;
lli arr[200][200];

lli minn(lli a,lli b){
	return a <  b ? a : b;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,h,a;
	cin>>n>>m>>h;
	for(int i=0;i<m;i++){
		cin>>a;
		mm.push_back(a);
	}	

	for(int i=0;i<n;i++){
		cin>>a;
		nn.push_back(a);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == 0){
				cout<<"0 ";
			}
			else{
				cout<<minn(mm[j],nn[i])<<" ";
			}
		}
		cout<<endl;
	}
return 0;
}