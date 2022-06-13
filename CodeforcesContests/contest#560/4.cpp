#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr for(lli i=0;i<n;i++)
#define pb push_back
#define rt return 0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	for(int p=0;p<t;p++){
		lli n,a;
		cin>>n;
		vector<lli> v;
		lli flag=0;
		
		for(int i=0;i<n;i++){
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		lli ans=0;
		if(n != 1){
			ans = v[n-1]*v[0];
			for(int i=0;i <= n/2 ;i++){
				if(ans != v[i] * v[n-i-1]){
					flag = 1;
					ans = -1;
					break;
				}
			}
		}
		else{
			ans = v[0]*v[0];
		}

		if(ans != -1){
			lli c=0;
			for(int i=2;i<=sqrt(ans);i++){
				if(ans % i == 0){
					++c;
				}
			}
			if(c != n/2 + n%2){
				ans = -1;
			}
		}
		cout<<ans<<endl;
	}
return 0;
}	
	
