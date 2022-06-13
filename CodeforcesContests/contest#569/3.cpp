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
	lli n,qe,a;
	vector<lli> v1,v2,v;
	cin>>n>>qe;	
	lli maxx = -1,ind = -1,c=0;
	deque<lli> q;
	fr(i,0,n){
		cin>>a;
		v.pb(a);
		q.pb(a);
		if(a > maxx){
			ind = i;
			maxx = a;
		}
	}

	while(q.front() != maxx){
		lli a = q.front();
		q.pop_front();
		lli b = q.front();
		q.pop_front();
		v1.pb(a);
		v2.pb(b);
		if(a > b){
			q.push_front(a);
			q.push_back(b);
		}
		else{
			q.push_front(b);
			q.push_back(a);	
		}
		++c;
	}

	vector<lli> an;
	fr(i,0,n){
		an.pb(q.front());
		q.pop_front();
	}

	fr(i,0,qe){
		cin>>a;
		if(a <= c){
			cout<<v1[a-1]<<" "<<v2[a-1]<<endl;
		}
		else{
			lli x = a - c - 1;
			x = x%(n-1);
			cout<<maxx<<" "<<an[x+1]<<endl;
		}
	}
rt;
}

	






	
