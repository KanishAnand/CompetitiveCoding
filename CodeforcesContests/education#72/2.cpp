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
	lli n,a,t,x,b;
	// vector<lli> v;
	cin>>t;
	while(t--){
		lli maxx = -2,flag = 0,curr,l=-2;
		cin>>n>>x;
		fr(i,0,n){
			cin>>a>>b;
			if(a > l){
				l = a;
			}
			if(a >= x){
				flag = 1;
				// break;
			}
			if(a > b){
				if(a - b > maxx){
					maxx = a-b;
					curr = a;
				}
			}
		}

		if(maxx == -2 && flag == 0){
			cout<<"-1"<<endl;
		}
		else if(flag == 1){
			cout<<"1"<<endl;
		}
		else{
			// cout<<x<<" "<<curr<<" "<<maxx<<endl;
			// lli y = (x - curr)/maxx;
			lli y;
			lli p = x - l;
			if(p % maxx == 0){
				y = p/maxx;
				++y;
			}
			else{
				y = p/maxx + 1;
				y++;
			}
			cout<<y<<endl;
		}
	}	
rt;
}
	
