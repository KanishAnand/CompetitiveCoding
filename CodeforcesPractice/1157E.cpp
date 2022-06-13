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
	lli n,a;
	vector<lli> v1,v2;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		v1.pb(a);
	}
		
	multiset<lli> st;

	fr(i,0,n){
		cin>>a;
		st.insert(a);
	}

	fr(i,0,n){
		lli y,k;
		auto it = st.begin();
		lli x = *it;
		y = (v1[i] + x)%n;
		auto itr = st.lower_bound(n - v1[i]);
		//auto itr = lower_bound(st.begin(),st.end(),n-v1[i]);
		if(itr != st.end()){
			lli z = *itr;
			k = (z+v1[i])%n;
		}
		else{
			k = n+1;
		}
		if(y < k){
			st.erase(st.begin());
			cout<<y<<" ";
		}
		else{
			st.erase(itr);
			cout<<k<<" ";
		}
	}
	cout<<endl;
rt;
}


	// sort(v2.begin(),v2.end());
	// vector<lli> arr(n+1,0);
	// lli first = 0;

	// fr(i,0,n){
	// 	auto it = lower_bound(v2.begin(),v2.end(),n-v1[i]);
	// 	if(it != v2.end()){
	// 		lli in = it - v2.begin(),x;

	// 		while(arr[in] != 0 && in < n-1){
	// 			++in;
	// 		}
			
	// 		if(!arr[in]){
	// 			x = (v1[i] + v2[in])%n;
	// 		}
	// 		else{
	// 			x = n+2;
	// 		}

	// 		while(arr[first] != 0){
	// 			++first;
	// 		}
	// 		lli val = (v1[i] + v2[first])%n;
	// 		if(val < x){
	// 			arr[first]=1;
	// 			first++;
	// 			cout<<val<<" ";
	// 		}
	// 		else{
	// 			arr[in] = 1;
	// 			cout<<x<<" ";
	// 		}
	// 	}
		
	// 	else{
	// 		while(arr[first] != 0){
	// 			++first;
	// 		}
	// 		lli val = (v1[i] + v2[first])%n;
	// 		arr[first]=1;
	// 		first++;
	// 		cout<<val<<" ";
	// 	}
	// }
	// cout<<endl;
// rt;
// }
