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
	lli n,a,b;
	vector<lli> v;
	cin>>n;	
	lli x = (n+1)/2;
	set<lli> st;
	map<lli,lli> front,back;
  
	fr(i,0,n){
		cin>>a>>b;
		st.insert(a);
		st.insert(b);
		front[a]++;
		if(a != b){
			back[b]++;
		}
	}

    for(auto it = front.begin();it!=front.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
	lli minn = 1000000000;
	for(auto it = st.begin();it!=st.end();it++){
		lli p = *it;
		if(front[p] >= x){
			cout<<"0"<<endl;
			rt;
		}
		else{
			if(front[p] + back[p] >= x){
				if(x - front[p] < minn){
					minn = x - front[p];
				}
			}
		}
	}

    if(minn == 1000000000){
        cout<<"-1"<<endl;
        rt;
    }
	cout<<minn<<endl;
	rt;
}
	
