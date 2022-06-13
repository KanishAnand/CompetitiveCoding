#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
lli  arr[101][26] = {0};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;
	// vector<vector<lli>> arr(n+1);
	string st;
	cin>>st;

	fr(i,0,n){
		for(lli j=n;j>=2;j--){
			lli q=0;
			fr(p,0,26){
				q += arr[j-1][p];
			}
			arr[j][st[i]-'a'] = q;
		}
		arr[1][st[i] - 'a'] = 1;
	}

	lli cost=0;
	for(lli i=n;i>=1;i--){
		fr(j,0,26){
			lli c = arr[i][j];
			if(c != 0){
				//cout<<i<<" "<<char(j+'a')<<" "<<c<<endl;
				if(c < k){
					cost += (n-i)*c;
				//	cout<<cost<<endl;
					k -= c;
				}
				else{
					cost += (n-i)*k;
				//	cout<<cost<<endl;
					//cout<<i<<" "<<char(j+'a')<<" "<<c<<endl;
					k = 0;
					break;
				}
			}
		}
		if(k == 0){
			break;
		}
	}

	if(k != 0){
		--k;
		cost += n;
	}

	if(k != 0){
		cout<<"-1\n";
	}
	else{
		cout<<cost<<"\n";
	}
rt;
}

		
