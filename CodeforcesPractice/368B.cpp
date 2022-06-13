#include<iostream>
#include<vector>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,a,max = 0;
	cin>>n>>m;
	vector<int> v1,v4;
	for(int i=0;i<n;i++){      //vectors are always 0 based indexing
		cin>>a;
		if(max < a){
			max = a;
		}
		v1.push_back(a);
	}
	
/*	for(int i=0;i<m;i++){
		cin>>a;
		v4.push_back(a);
	}
*/
	vector<int> v3(max+1,0),v2(n+2,1);
	v2[n+1] = 0;

	for(int i = n-1;i>=0;i--){
		if(v3[v1[i]] == 1){
			v2[i+1] = v2[i+2];
		}
		else{
			v3[v1[i]] = 1;
			v2[i+1] = v2[i+2] + 1;
		}
	}

	for(int i=0;i<m;i++){
		cin>>a;
		cout<<v2[a]<<"\n";
	}
return 0;
}


