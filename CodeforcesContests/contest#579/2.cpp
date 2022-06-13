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
	lli n,a,q;
	cin>>q;
	while(q--){
		cin>>n;
		vector<lli> v;
		fr(i,0,4*n){
			cin>>a;
			v.pb(a);
		}
		sort(v.begin(),v.end());

		lli beg=0,end=4*n-1;
		lli flag = 0;
		if(v[beg] == v[beg+1] && v[end] == v[end-1]){
				lli x = v[beg]*v[end],y;
				beg += 2;
				end -= 2;
				//cout<<"df"<<endl;
				for(lli i=2;i<=n;i++){
					//cout<<"df"<<endl;
					if(v[beg] == v[beg+1] && v[end] == v[end-1]){
						y = v[beg]*v[end];
						beg += 2;
						end -= 2;
						if(x != y){
							flag = 1;
							break;
						}
					}
					else{
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
		}
		else{
			//cout<<"df"<<endl;
			cout<<"NO"<<endl;
		}
	}	
rt;
}
	
