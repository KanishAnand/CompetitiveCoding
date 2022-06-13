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
	vector<lli> v;
	cin>>n;
	if(n < 6){
		cout<<n<<endl;
		rt;
	}	

	lli a;
	vector<lli> arr(50,0);
	fr(i,0,n){
		cin>>a;
		if(a == 4){
			arr[4]++;
		}
		else if(a == 8){
			if(arr[4] > arr[8]){
				arr[8]++;
			}
		}
		else if(a == 8){
			if(arr[4] > arr[8]){
				arr[8]++;
			}
		}
		else if(a == 15){
			if(arr[8] > arr[15]){
				arr[15]++;
			}
		}
		else if(a == 16){
			if(arr[15] > arr[16]){
				arr[16]++;
			}
		}
		else if(a == 23){
			if(arr[16] > arr[23]){
				arr[23]++;
			}
		}
		else if(a == 42){
			if(arr[23] > arr[42]){
				++arr[42];
			}
		}
	}

	cout<<n-arr[42]*6<<endl;
rt;
}

	
