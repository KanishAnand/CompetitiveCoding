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

vector<lli> one,two,three;
vector<vector<lli>> v;
lli n;

lli fun(lli a,lli cost,vector<lli> &arr){	
	lli r = n,f=1;
	for(lli i=0;i<n;i++){
		if(arr[i] == 0){
			f = 0;
		}
	}
	if(f == 1){
		//cout<<"L"<<endl;
		return cost-1;
	}
	vector<lli> ve;
	if(a == 1){
		ve = one;
	}
	else if(a == 2){
		ve = two;
	}
	else{
		ve = three;
	}
//cout<<"K"<<endl;
	while(r--){
		fr(i,0,ve.size()){
			lli t = ve[i],flag = 1;
			if(arr[t] == 0){
				for(lli j=0;j<v[t].size();j++){
					if(arr[v[t][j]] == 0){
						flag = 0;
					}
				}
				if(flag == 1){
				//	cout<<t<<" "<<a<<endl;
					arr[t] = 1;
				}
			}
		}
	}
	++cost;
	a++;
	if(a == 4){
		a = 1;
	}
	return fun(a,cost,arr);
}




int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		if(a == 1){
			one.pb(i);
		}
		else if(a == 2){
			two.pb(i);
		}
		else{
			three.pb(i);
		}
	}

	lli b;
	v.resize(n+1);
	fr(i,0,n){
		cin>>a;
		fr(j,0,a){
			cin>>b;
			v[i].pb(--b);
		}
	}

	lli c=1;
	vector<lli> arr(n+1,0);
	lli q,w,e;
	q = fun(1,0,arr);
	// arr.resize(n+1,0);
	// cout<<arr.size()<<endl;
	fr(i,0,n+1){
		arr[i] = 0;
	}
	w = fun(2,0,arr);
	//arr.resize(n+1,0);
	fr(i,0,n+1){
		arr[i] = 0;
	}
	e = fun(3,0,arr);
	//cout<<q<<w<<e<<endl;
	if(q <= w && q <= e){
		cout<<q + n<<endl;
	}
	else if(w <= q && w <= e){
		cout<<w + n<<endl;
	}
	else{
		cout<<e + n<<endl;
	}
rt;
}

	




		

