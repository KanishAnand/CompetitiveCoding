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
	lli n,z=0,o=0;
	vector<lli> v;
	string st;
	cin>>n;
	cin>>st;	
	fr(i,0,st.length()){
		if(st[i] == '0'){
			z++;
		}
		else{
			++o;
		}
	}

	if(z != o){
		cout<<"1"<<"\n";
		cout<<st<<endl;
		rt;
	}

	cout<<"2"<<"\n";
	cout<<st[0]<<" "<<st.substr(1,n-1)<<endl;
rt;
}
	
