#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli n,t;
	vector<lli> arr(5000005,0),v(5000002,0);
	cin>>t;
	lli p = sqrt(5000005);

	for(lli i=2;i<=p;i++){
		if(arr[i] == 0){
			arr[i] = i;
			for(lli j=i*i;j<=5000000;j += i){
				if(arr[j] == 0){
					arr[j] = i;
				}
			}
		}
	}		

	fr(i,0,5000001){
		if(arr[i] == 0){
			arr[i] = i;
		}
	}

	v[1] = 0;

	fr(i,2,5000001){
		v[i] = v[i/arr[i]] + 1;
	}

	for(lli i=2;i<=5000000;i++){
		v[i] += v[i-1];
	}

	lli a,b;
	while(t--){
		cin>>a>>b;
		lli ans = v[a] - v[b];
		cout<<ans<<"\n";
	}
rt;
}


	
