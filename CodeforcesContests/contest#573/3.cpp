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
	lli n,m,k,a;
	vector<lli> v;
	cin>>n>>m>>k;

	fr(i,0,m){
		cin>>a;
		v.pb(a);
	}
	sort(v.begin(),v.end());

	lli start = 1,in = 0,done=0,ans=0;

	while(1){
		lli x = v[in];
		lli y = (x - start)/k;
		start += y*k;
		start += k;
		--start;
		if(in >= m){
			break;
		}
		//cout<<start<<endl;
		while(1){
			auto it = lower_bound(v.begin(),v.end(),start);
			lli ind = it - v.begin();
			if(v[ind] > start){
				--ind;
			}
			//cout<<ind<<endl;
			lli z = ind+1;
			in = z;
			z -= done;
			if(z == 0){
				break;
			}
			++ans;
			done += z;
			start += z;
			if(in >= m){
				break;
			}
			//cout<<done<<"DF"<<start<<endl;
		}
		++start;
		if(in >= m){
			break;
		}
	}

	cout<<ans<<endl;
rt;
}

	
