#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a;
	cin>>n;	
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}

	lli count=0;
	lli max = v[0];

	for(int i=0;i<n;i++){
		max = v[i];
		while(i+1 != max){
			++i;
			if(v[i] > max){
				max = v[i];
			}
		}
		++count;
		//cout<<i<<" "<<count<<endl;
	}
	// for(int i=0;i<n;i++){
	// 	if(i >= n-1){
	// 		break;
	// 	}
	// 	while(i < n && i != v[i] - 1){
	// 		if(i == n-1){
	// 			break;
	// 		}
	// 		i = v[i] - 1;
	// 	}
	// 	++count;
	// }

	cout<<count<<endl;
return 0;
}
