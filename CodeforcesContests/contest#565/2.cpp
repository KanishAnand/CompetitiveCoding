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
	lli n,q;
	vector<lli> v;
	cin>>q;
	fr(i,0,q){
		cin>>n;
		lli a;
		lli on=0,tw=0,th=0;
		fr(j,0,n){
			cin>>a;
			if(a%3 == 1){
				++on;
			}
			else if(a%3 == 2){
				tw++;
			}
			else{
				++th;
			}
		}
		lli on1 = on,tw1 = tw;
		lli ans = min(on1,tw1);
		on -= min(on1,tw1);
		tw -= min(on1,tw1);
		if(on > 0){
			ans += on/3;
		}
		else if(tw > 0){
			ans += tw/3;
		}
		// lli ans2 = on1/3 + tw1/3;
		// on1 -= (on1/3)*3;
		// tw1 -= (tw1/3)*3;
		// ans2 += min(on1,tw1);
		// lli an = max(ans,ans2);
		//lli an=ans;
		cout<<ans + th<<endl;
	}	
rt;
}
	
