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
	lli n,b,g;
	vector<lli> v;
	cin>>b>>g>>n;
	lli beg=1,end=n+1;

	while(beg <= end){	
		// cout<<beg<<" "<<end<<endl;
		lli l = (beg + end)/2,flag=0;

		for(lli j=0;j<=n+1-l;j++){
			lli sumb = 0,sumg=0;
			for(lli i=j;i<j+l;i++){
				sumb += i;
				sumg += n - i;
			}
			// cout<<sumb<<" "<<sumg<<" "<<j<<endl;
			if(sumb >= b && sumg >= g){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			end = l - 1;
		}
		else{
			beg = l + 1;
		}
	}
	cout<<beg<<endl;
rt;
}
