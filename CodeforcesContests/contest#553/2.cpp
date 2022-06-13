#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
lli input(lli n);
lli max_of_all();
vector<lli> v;
lli input(lli n){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		v.push_back(val);
	}
return 0;
}

lli max_of_all(vector<lli> &vec){
	auto itr = max_element(vec.begin(),vec.end());
return *itr;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,a,b,c=-1,ind,ind1,ans=0;
	cin>>n>>m;	
	//input(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a;
			if(j == 0){
				b = a;
				ans ^= a;
			}
			if(a != b){
				c = a;
				ind = i;
				ind1 = j+1;
			}
		}
	}

	if(ans == 0){
		if(c == -1){
			cout<<"NIE"<<endl;
		}
		else{
			cout<<"TAK"<<endl;
			for(int i=0;i<n;i++){
				if(i == ind){
					cout<<ind1<<" ";
				}
				else{
					cout<<"1 ";
				}
			}
			cout<<endl;
		}
	}

	else{
		cout<<"TAK"<<endl;
		for(int i=0;i<n;i++){
			cout<<"1 ";
		}
		cout<<endl;
	}
return 0;
}