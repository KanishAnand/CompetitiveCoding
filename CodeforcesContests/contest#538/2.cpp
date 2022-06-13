#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,k;
	cin>>n>>m>>k;
	vector<lli> v,b,g;
	lli a;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
		b.push_back(a);
	}

	sort(b.begin(),b.end());
	lli key = n - m*k;
	lli ke = b[key],be,count=0,kee=ke;

	for(int i=key;i<n;i++){
		if(b[i] == ke){
			++count;
		}
		else{
			be = b[i];
			break;
		}
	}

	lli val=0,ve=0,sum=0;
	for(int i=0;i<n;i++){
		if(v[i] > ke){
			++val;
			sum += v[i];
		}
		else if(v[i] == ke){
			++val;
			sum += v[i];
			++ve;
			if(ve == count && v[i] == kee){
				ke = be;
			}
		}
		if(val == m){
			val=0;
			lli j = i+1;
			g.push_back(j);
		}
	}	

	cout<<sum<<endl;
	for(int i=0;i<k-1;i++){
		cout<<g[i]<<" ";
	}
	cout<<endl;
return 0;
}



