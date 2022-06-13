#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli m = 10000000000000000;

lli fun(lli k,lli st,lli en,lli val,lli ans,vector<lli> v,lli n){
	//cout<<st<<" "<<en<<endl;
	if(k < 0){
		if(ans < m){
			m = ans;
		}
		return 0;
	}
	if(st != -1 && en != -1){
		ans += val;
		v[st] = val;
		v[en] = -1;
	}

	//for(lli i=0;i<k;i++){
		lli minn = 100000000000,ind,ind2;
		fr(j,0,n){
			if(v[j] != -1){
				lli x = (j+1) % n;
				while(v[x] == -1){
					++x;
					x %= n;
				}
				lli val = v[j] + v[x];
				if(val < minn){
					minn = val;
				}
			}
		}

		fr(j,0,n){
			if(v[j] != -1){
				lli x = (j+1) % n;
				while(v[x] == -1){
					++x;
					x %= n;
				}
				lli val = v[j] + v[x];
				if(val == minn){
					fun(k-1,j,x,minn,ans,v,n);
				}
			}
		}
	//}
return 0;	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t,n,a;
	cin>>t;
	while(t--){
		cin>>n;
		m = 10000000000000000;
		vector<lli> v;
		fr(i,0,n){
			cin>>a;
			v.pb(a);
		}
		//lli ans=0;
		fun(n-1,-1,-1,0,0,v,n);

		// for(lli i=0;i<n-1;i++){
		// 	lli minn = 100000000000,ind,ind2;
		// 	fr(j,0,n){
		// 		if(v[j] != -1){
		// 			lli x = (j+1) % n;
		// 			while(v[x] == -1){
		// 				++x;
		// 				x %= n;
		// 			}
		// 			lli val = v[j] + v[x];
		// 			if(val < minn){
		// 				minn = val;
		// 				ind = j;
		// 				ind2 = x;
		// 			}
		// 		}
		// 	}
		// 	ans += minn;
		// 	v[ind] = minn;
		// 	v[ind2] = -1;
		// }
		cout<<m<<"\n";
	}	
rt;
}