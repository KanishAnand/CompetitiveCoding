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
lli cntv[1001][1001] = {0},cnth[1001][1001] = {0};
lli minn(lli a,lli b,lli c){
	if(a <= b && a <= c){
		return a;
	}
	else if(b <= a && b <= c){
		return b;
	}
	else{
		return c;
	}
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m;
	vector<lli> v;
	cin>>n>>m;
	char a;
	vector<vector<char>> arr;
	arr.resize(n+1);
	fr(i,0,n){
		fr(j,0,m){
			cin>>a;
			arr[i].pb(a);
		}
	}	

	if(n < 3){
		cout<<"0"<<endl;
		rt;
	}

	fr(i,0,m){
		//fr(j,0,n){
		for(lli j=n-2;j>=0;j--){
			if(arr[j][i] == arr[j+1][i]){
				cntv[j][i] += cntv[j+1][i] + 1;
			}
		}
			// char a = arr[j][i];
			// lli c=0;
			// for(lli k=j+1;k<n;k++){
			// 	if(arr[k][i] == a){
			// 		++c;
			// 	}
			// 	else{
			// 		break;
			// 	}
			// }
			// cntv[j][i] = c;
			// lli t=1;
			// for(lli k=j+1;k<=j+c;k++){
			// 	cntv[k][i] = c - t;
			// 	++t;
			// }
			// j = j + c;
		//}
	}
	if(m > 1){
		fr(i,0,n){
			for(lli j=m-2;j>=0;j--){
				if(arr[i][j] == arr[i][j+1]){
					cnth[i][j] += cnth[i][j+1] + 1;
				}
			}	
			// fr(j,0,m){
			// 	char a = arr[i][j];
			// 	lli c = 0;
			// 	for(lli k=j+1;k<n;k++){
			// 		if(arr[i][k] == a){
			// 			++c;
			// 		}
			// 		else{
			// 			break;
			// 		}
			// 	}
			// 	cnth[i][j] = c;
			// 	lli t=1;
			// 	for(lli k=j+1;k<=j+c;k++){
			// 		cnth[i][k] = c - t;
			// 		++t;
			// 	}
			// 	j += c;
			// }
		}
	}

	lli ans=0;

	fr(i,0,n){
		fr(j,0,m){
			lli c = cntv[i][j];
			if(i + c + 1 < n-1 && cntv[i+c+1][j] == c){
				if(i + 2*c + 2 <= n-1 && cntv[i+2*c+2][j] >= c){
					// ans += minn(cnth[i][j],cnth[i+c+1][j],cnth[i+2*c+2][j]);
					//cerr<<i<<" "<<j<<endl;
					// ++ans;
					lli minn = 10000000000;
					for(lli k=i;k<i+3*c+3;k++){
						if(cnth[k][j] < minn){
							minn = cnth[k][j];
						}
					}
					//cout<<minn<<endl;
					ans = ans + minn + 1;
				}
			}
		}
	}
	cout<<ans<<endl;
rt;
}

