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
	lli n,a,pref[300000],check[300000]={0};
	cin>>n;
	vector<lli> v;	

	for(int i=0;i<n-1;i++){
		cin>>a;
		v.push_back(a);
		//cout<<"k"<<endl;
	}

	//cout<<v[0]<<endl;
	//cout<<"k"<<endl;
	lli sum=0;
	//cout<<v[0];
	//cout<<"k"<<endl;
	//cout<<v[0]<<" "<<pref[0];
	pref[0] = v[0];
	//cout<<"k"<<endl;
	sum = v[0];
	//cout<<"k"<<endl;
	for(int i=1;i<n-1;i++){
		pref[i] = pref[i-1] + v[i];
		sum += pref[i];
	}
	//cout<<"k"<<endl;

	lli h= (n*(n+1))/2;
	//cout<<"KK"<<endl<<sum<<endl<<h<<endl;
	lli p = h - sum;
	if(p < 0){
		cout<<"-1"<<endl;
		return 0;
	}

	//cout<<"fd"<<endl<<p<<endl;
	if(p % n != 0){
		cout<<"-1"<<endl;
		return 0;
	}
	//cout<<"k"<<endl;
	lli firstno = p/n;
	//cout<<p<<endl<<n<<endl;
	//cout<<firstno<<endl;

	lli val[300000];
	val[0] = firstno;
//cout<<val[0]<<endl;
	for(int i=1;i<n;i++){
		val[i] = val[i-1] + v[i-1];
	}
//cout<<"k1"<<endl;
//cout<<val[0]<<endl;
	for(int i=0;i<n;i++){
	//	cout<<val[i]<<endl;
		check[val[i]] = 1;
	}
//cout<<"k2"<<endl;
	for(int i=1;i<=n;i++){
		if(check[i] == 0){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	//cout<<"k"<<endl;

	for(int i=0;i<n;i++){
		cout<<val[i]<<" ";
	}
	cout<<endl;

return 0;
}

