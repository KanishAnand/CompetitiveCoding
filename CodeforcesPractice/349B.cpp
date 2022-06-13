#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a,minn=100000000,no=0;
	vector<lli> arr(10);
	cin>>n;	
	fr(i,0,9){
		cin>>a;
		if(a < minn){
			minn = a;
		}
		arr[i+1] = a;
	}

	fr(i,0,9){
		if(arr[i+1] == minn){
			if(i + 1 > no){
				no = i+1;
			}
		}
	}

	if(n < minn){
		cout<<"-1"<<"\n";
		rt;
	}

	vector<lli> an;
	lli ans=0;
	ans = n/minn;
	n = n%minn;

	fr(i,0,ans){
		lli val = no,t=0;
		fr(j,1,10){
			if(arr[j] <= n + minn){
				// cerr<<j<<endl;
				if(j > val){
					val = j;
					t = arr[j] - minn;
				}
			}
		}
		n -= t;
		an.pb(val);
	}

	fr(i,0,ans){
		cout<<an[i];
	}
	cout<<"\n";
rt;
}



	
