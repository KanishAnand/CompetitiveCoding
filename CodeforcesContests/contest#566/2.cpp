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
	lli w,h;
	
	cin>>h>>w;
	vector<lli> arr(h+2,0);
	vector<vector<lli>> v;
	v.resize(h+2);
	lli c=0,wt=0;
	string s;
	for(lli i=0;i<h;i++){
		cin>>s;
		for(lli j=0;j<s.length();j++){
			if(s[j] == '*'){
				arr[i]++;
				v[i].pb(j);
			}
		}
		if(arr[i] > 1){
			++c;
		}
		else if(arr[i] == 1){
			++wt;
		}
	}	
	
	if(c != 1 || wt < 2){
		cout<<"NO"<<endl;
		//cout<<wt<<endl;
		rt;
	}
	lli in=-1;
	for(lli i=0;i<h;i++){
		if(arr[i] == 1){
			in = i;
			break;
		}
	}

	if(in == -1){
		cout<<"NO"<<endl;
		rt;
	}

	lli d = v[in][0],q=0,ind=-1;

	for(lli i=in+1;i<h;i++){
		if(arr[i] == 1){
			if(v[i][0] != d){
				cout<<"NO"<<endl;
				rt;
			}
		}
		else if(arr[i] > 1){
			lli flag = 0;
			ind = i;
		//	cout<<ind<<endl;
		//	cout<<v[ind].size()<<endl;
			for(lli j=0;j<v[i].size();j++){
				if(v[i][j] == d){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				cout<<"NO"<<endl;
				rt;
			}
			else{
				break;
			}
		}
		else{
			//if(flag == 0){
				cout<<"NO"<<endl;
				rt;
		//	}
		}
	}

	lli fl=0;
	for(lli i=ind+1;i<h;i++){
		if(arr[i] == 1){
			fl = 1;
			if(v[i][0] != d){
				cout<<"NO"<<endl;
				rt;
			}
		}
		else{
			if(fl == 0){
				cout<<"NO"<<endl;
				rt;	
			}
			else{
				for(lli p=i+1;i<h;i++){
					if(arr[p] != 0){
						cout<<"NO"<<endl;
						rt;
					}
				}
				break;
			}
		}
	}

	if(fl == 0){
		cout<<"NO"<<endl;
		rt;
	}


	if(v[ind].size() < 3){
		cout<<"NO"<<endl;
		rt;
	}
	lli u;
	for(lli i=1;i<v[ind].size();i++){
		//cout<<v[ind].size()<<" ";
		if(v[ind][i] - v[ind][i-1] != 1){
			cout<<"NO"<<endl;
			rt;
		}
		if(v[ind][i] == d){
			u = i;
			break;
		}
	}

	for(lli i=1;i<v[ind].size();i++){
		//cout<<v[ind].size()<<" ";
		if(v[ind][i] - v[ind][i-1] != 1){
			cout<<"NO"<<endl;
			rt;
		}
	}


	if(u == 0){
		cout<<"NO"<<endl;
		rt;
	}
	else if(u == v.size()-1){
		cout<<"NO"<<endl;
		rt;
	}
	else{
		cout<<"YES"<<endl;
		rt;
	}
rt;
}

