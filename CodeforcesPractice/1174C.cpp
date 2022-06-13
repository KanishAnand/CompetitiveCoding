#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
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
	lli n;
	lli k=0;
	cin>>n;
	vector<lli> arr(n+5,0);
	arr[1] = 1;
	for(lli i=2;i<=n;i++){
		if(arr[i] == 0){
			++k;
			arr[i] = k;
			for(lli j=i*i;j<=n;j += i){
				if(arr[j] == 0){
					arr[j] = k;
				}
			}
		}
	}

	fr(i,2,n+1){
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
rt;
}
	
