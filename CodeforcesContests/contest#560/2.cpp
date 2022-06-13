#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr for(lli i=0;i<n;i++)
#define pb push_back
#define rt return 0;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,c=0,a;
	vector<lli> v;
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	lli j=0;
	
	for(int i=0;i<n;i++){
		while(v[i] < j + 1){
			++i;
			if(i >= n){
				break;
			}
		}
		if(i < n && v[i] >= j+1){
			++c;
			++j;
		}
	}
	cout<<c<<endl;
return 0;
}
	
