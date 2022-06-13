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
	string a,b,c;
	vector<lli> vm,vs,vp;
	cin>>a>>b>>c;
	if(a[1] == 'm'){
		vm.pb(a[0]-'0');
	}
	else if(a[1] == 's'){
		vs.pb(a[0]-'0');
	}	
	if(a[1] == 'p'){
		vp.pb(a[0]-'0');
	}

	if(b[1] == 'm'){
		vm.pb(b[0]-'0');
	}
	else if(b[1] == 's'){
		vs.pb(b[0]-'0');
	}	
	if(b[1] == 'p'){
		vp.pb(b[0]-'0');
	}
	if(c[1] == 'm'){
		vm.pb(c[0]-'0');
	}
	else if(c[1] == 's'){
		vs.pb(c[0]-'0');
	}	
	if(c[1] == 'p'){
		vp.pb(c[0]-'0');
	}

	sort(vs.begin(),vs.end());
	sort(vm.begin(),vm.end());
	sort(vp.begin(),vp.end());

	if(vs.size() == 3 || vm.size() == 3 || vp.size() == 3){
		vector<lli> v;
		
		if(vm.size() == 3){
			v = vm;	
		}
		else if(vs.size() == 3){
			v = vs;
		}
		else{
			v = vp;
		}
		
		if(v[0] == v[1] && v[1] == v[2]){
			cout<<"0"<<endl;
			rt;
		}

		else{
			if(v[2] - v[1] == 1 && v[1] - v[0] == 1){
				cout<<"0"<<endl;
				rt;
			}
			else if(v[0] == v[1] || v[1] == v[2] || v[2] == v[0]){
				cout<<"1"<<endl;
				rt;
			}
			else if(v[1] - v[0] == 1 || v[2] - v[1] == 1 || v[2] - v[0] == 1){
				cout<<"1"<<endl;
				rt;
			}
			else if(v[2] - v[0] == 2 || v[2] - v[1] == 2 || v[1] - v[0] == 2){
				cout<<"1"<<endl;
				rt;
			}
			else{
				cout<<"2"<<endl;
				rt;
			}
		}
	}

	else if(vm.size() == 2 || vs.size() == 2 || vp.size() == 2){
		vector<lli> v;
		if(vm.size() == 2){
			v = vm;	
		}
		else if(vs.size() == 2){
			v = vs;
		}
		else{
			v = vp;
		}

		if(v[0] == v[1]){
			cout<<"1"<<endl;
			rt;
		}
		else if(v[1] - v[0] == 1 || v[1] - v[0] == 2){
			cout<<"1"<<endl;
			rt;	
		}
		else{
			cout<<"2"<<endl;
			rt;
		}
	}

	else{
		cout<<"2"<<endl;
		rt;
	}
rt;
}