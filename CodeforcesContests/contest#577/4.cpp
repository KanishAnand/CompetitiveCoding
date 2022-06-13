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
	lli n,a;
	vector<lli> v;
	cin>>n;	
	lli sum=0;
	fr(i,0,n){
		cin>>a;
		v.pb(a);
		sum += a;
	}
	// if(sum % 2 == 1){
	// 	cout<<"NO"<<endl;
	// 	rt;
	// }

	sort(v.begin(),v.end());
	fr(i,1,n){
		// if(i < n-1){
		v[i] -= v[i-1];
	}
	//v[n-1] -= v[n-2];

	if(v[n-1] <= 0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

	// lli c,d;
	// c=0;
	// d=1;
	// set<lli> st;
	// while(c < n && d < n){
	// 	lli x;
	// 	//lli x = min(v[c],v[d]);
	// 	if(v[c] < v[d]){
	// 		x = v[c];
	// 	}
	// 	else{
	// 		x = v[d];
	// 	}
	// 	v[c] -= x;
	// 	v[d] -= x;

	// 	if(v[c] == 0){
	// 		st.insert(c);
	// 		if(v[d] == 0){
	// 			st.insert(d);
	// 			c = d+1;
	// 			d += 2;
	// 		}
	// 		else{
	// 			c = d;
	// 			d++;
	// 		}
	// 	}
	// 	else{
	// 		st.insert(d);
	// 		d++;
	// 	}
	// 	if(c == d){
	// 		++d;
	// 	}
	// }

	// for(auto it = st.begin();it != st.end();it++){
	// 	cout<<*it<<" ";
	// }
	// if(st.size() == n){
	// 	cout<<"YES"<<endl;
	// }
	// else{
	// 	cout<<"NO"<<endl;
	// }
rt;
}

	
