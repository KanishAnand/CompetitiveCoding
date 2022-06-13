#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli input(lli n,vector<lli> &ve);
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
	lli q,k,a,n;
	
	cin>>q;	
	while(q--){
		cin>>n>>k;
		vector<lli> v,an;
		fr(i,0,n){
			cin>>a;
			v.pb(a);
		}

		//lli in=0,i=0;
		// while(k > 0 && i < n){
		// 	lli od = 0;
		// 	//cout<<k<<endl;
		lli od=0;
			for(lli i = 0;i < n; i++){
				if(v[i] % 2 == 1){
					++od;
				}
				if(od % 2 == 1){
					an.pb(i+1);
					//in = i+1;
					//--k;
					od = 0;
					//break;
				}
			}
		//}
			//cout<<an.size()<<endl;
		if(an.size() < k){
			cout<<"NO"<<endl;
		}
		else{
			if(an.size() == k){
				cout<<"YES"<<endl;
				fr(j,0,k-1){
					cout<<an[j]<<" ";
				}
				cout<<n<<endl;
			}
			else{
				lli x = an.size() - k;
				if(x % 2 == 1){
					cout<<"NO"<<endl;
				}
				else{
					cout<<"YES"<<endl;
					fr(j,0,k-1){
						cout<<an[j]<<" ";
					}
					cout<<n<<endl;
				}
			}
		}
	}
rt;
}
	
