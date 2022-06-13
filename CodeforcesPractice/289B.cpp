#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,a,d,p,q,f=1;
	cin>>n>>m>>d;
	vector<int> b;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a;
			p = a%d;
			if(f == 1){
				q = a%d;
				f = 0;
			}
			if(p != q){
				cout<<"-1"<<endl;
				return 0;
			}
			b.push_back(a);
			q = a%d;
		}
	}

	sort(b.begin(),b.end());
	int sum=0,mid;
	int l = n*m;
	mid = (l-1)/2;
	for(int i=0;i<l;i++){
		sum += (fabs(b[mid] - b[i]))/d;
	}

	cout<<sum<<endl;
return 0;
}


