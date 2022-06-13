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
	lli n;
	cin>>n;
	vector<lli> ev;
	vector<lli> odd;
	lli a;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a % 2 == 0){
			ev.push_back(a);
		}
		else{
			odd.push_back(a);
		}
	}	

	sort(ev.begin(),ev.end());
	sort(odd.begin(),odd.end());

	lli sum=0;

	if(ev.size() > odd.size()){
		lli si = ev.size() - odd.size();	
		for(int i=0;i < si - 1;i++){
			sum += ev[i];
		}
	}
	else{
		lli si = odd.size() - ev.size();
		for(int i=0;i<si - 1;i++){
			//cout<<"DFf"<<endl;
			sum += odd[i];
		}
	}

	cout<<sum<<endl;
	
return 0;
}

