#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> vx,vy;
int main(void){
	lli n,min=1100,max=0;
	cin>>n;
	set<lli> an;
	lli x,y,king[n];
	for(int i=0;i<n;i++){
		cin>>x>>y;
		king[i] = i;
		vx.push_back(x);
		vy.push_back(y);
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(vx[j] == vx[i] || vy[j] == vy[i]){
				if(king[j] != j){
					lli k=j;
					while(king[k] != k){
						k=king[k];
					}
					king[k] = i;
				}
				else{
					king[j] = i;
				}
			}
			if(j == i){
				king[j] = i;
			}
		}
	}

	//cout<<king[0]<<king[1]<<endl;
	for(int i=0;i<n;i++){
		lli k=i;
		while(king[k] != k){
			k=king[k];
		}
		an.insert(k);
	}
	cout<<an.size()-1<<endl;
return 0;
}