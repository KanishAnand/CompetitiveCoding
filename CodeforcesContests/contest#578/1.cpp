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
	lli n,a;
	vector<lli> arr(11,0);
	cin>>n;	
	string st;
	cin>>st;
	set<lli> left,right;
	for(lli i=0;i<10;i++){
		left.insert(i);
		// right.insert(i);
	}	

	for(lli i=0;i<n;i++){
		//cout<<i<<endl;
		if(st[i] == 'L'){
			auto it = left.begin();
			left.erase(it);
			// right.erase(it);
			lli k = *it;
			arr[k] = 1;
		}
		else if(st[i] == 'R'){
			auto it = left.end();
			--it;
			// right.erase(it);
			left.erase(it);
			lli k = *it;
			arr[k] = 1;
		}
		else{
			arr[st[i]-'0'] = 0;
			left.insert(st[i]-'0');
			// right.insert(st[i]-'0');
		}
	}

	fr(i,0,10){
		cout<<arr[i];
	}
	cout<<endl;
rt;
}


