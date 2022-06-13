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
	lli n,t,w,sum1=0,sum2=0;
	vector<lli> v1,v2;
	cin>>n;	
	fr(i,0,n){
		cin>>t>>w;
		if(t == 1){
			sum1 += w;
			v1.pb(w);
		}
		else{
			sum2 += w;
			v2.pb(w);
		}
	}

	sort(v1.rbegin(),v1.rend());
	sort(v2.rbegin(),v2.rend());
	if(n == 1){
		cout<<t<<endl;
		rt;
	}

	if(v1.size() > 1){
		fr(i,1,v1.size()){
			v1[i] += v1[i-1];
		}
	}
	if(v2.size() > 1){
		fr(i,1,v2.size()){
			v2[i] += v2[i-1];
		}
	}

	lli a=0,b=0,minn=100000000000;
	//cout<<v1.size()<<endl<<v2.size()<<endl;
	for(lli i=0;i<=v1.size();i++){
		//cout<<"f";
		a = i;
		for(lli j=0;j<=v2.size();j++){
			b = j;
		//	cout<<"D"<<endl;
			lli an = 0;	
			if(a != 0){
				an += v1[a-1];
			}
			if(b != 0){
				an += v2[b-1];
			}

			if(sum1 + sum2  - an <= a + 2*b){
				if(a + 2*b < minn){
					minn = a+2*b;
				}
			}
		}
	}

	cout<<minn<<endl;
rt;
}
	