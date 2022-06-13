#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
lli cnt[300000]={0};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,ab;
	vector<lli> v,a,b,c;
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>ab;
		v.push_back(ab);
		cnt[ab]++;
	}

	lli max=0,ind,val;

	for(int i=0;i<n;i++){
		if(cnt[v[i]] > max){
			max = cnt[v[i]];
			ind = i;
			val = v[i];
		}
	}

	lli count=0;

	for(int i=ind-1;i>=0;i--){
		if(v[i] > val){
			++count;
			a.push_back(2);
			b.push_back(i+1);
			c.push_back(i+2);
		}
		else if(v[i] < val){
			count++;
			a.push_back(1);
			b.push_back(i+1);
			c.push_back(i+2);
		}
	}

	for(int i=ind+1;i<n;i++){
		if(v[i] > val){
			++count;
			a.push_back(2);
			b.push_back(i+1);
			c.push_back(i);
		}
		else if(v[i] < val){
			count++;
			a.push_back(1);
			b.push_back(i+1);
			c.push_back(i);
		}
	}

	cout<<count<<endl;
	for(int i=0;i<count;i++){
		cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
	}
return 0;
}


