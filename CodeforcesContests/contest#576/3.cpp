#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	double n,I,a;
	vector<lli> v,ve;
	cin>>n>>I;
	vector<lli> pref(n+5,0),suff(n+5,0);
	set<lli> st;
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	//	arr[a]++;
		st.insert(a);
	}	

	sort(v.begin(),v.end());
	for(auto it=st.begin();it!=st.end();it++){
		ve.pb(*it);
	}
	pref[0] = 0;
	suff[0] = 0;

	for(lli i=1;i<=st.size();i++){
		auto it1 = lower_bound(v.begin(),v.end(),ve[i-1]);
		auto it2 = upper_bound(v.begin(),v.end(),ve[i-1]);
		lli q = it2 - it1;
		pref[i] = pref[i-1] + q;
	}
	lli j=1;
	for(lli i=st.size();i > 0;i--){
		auto it1 = lower_bound(v.begin(),v.end(),ve[i-1]);
		auto it2 = upper_bound(v.begin(),v.end(),ve[i-1]);
		lli q = it2 - it1;
		suff[j] = suff[j-1] + q;
		++j;
		//cout<<j<<" "<<suff[j]<<" "<<arr[ve[i-1]]<<" "<<i-1<<endl;
	}

	double y = 8*I;
	double t = y/n;
	//lli beg = 1,end = n;
	// while(beg <= end){
	lli an = n,flag;

	//cout<<t<<endl;
	// for(lli i=1;i<=n;i++){
	// 	double p = log2(i);
	// 	p = ceil(p);
	// 	if(p <= t){
	// 		flag = 1;
	// 		an = i;
	// 		//continue;
	// 	}
	// 	else{
	// 		an = i-1;
	// 		break;
	// 	}
	// }

	//cout<<an<<endl;
	lli x = t;
	if(t > 20){
		x = 20;
	}
	an = pow(2,x);
	if(st.size() <= an){
		cout<<"0\n";
		rt;
	}
	else{
		lli x = st.size() - an,ans,minn = 10000000000;
		//cout<<x<<endl;
		for(lli i=0;i<=x;i++){
			//cout<<pref[i]<<" "<<suff[x-i]<<endl;
			ans = pref[i];
			ans += suff[x-i];
			if(ans < minn){
				minn = ans;
			}
		}		
		cout<<minn<<"\n";
	}
rt;
}
