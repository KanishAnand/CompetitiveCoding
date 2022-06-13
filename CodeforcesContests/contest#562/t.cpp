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
	lli n,m,a,b;
	cin>>n>>m;
	vector<pair<lli,lli>> v;
	fr(i,0,m){
		cin>>a>>b;
		v.pb(make_pair(a,b));
	}	
	
	lli x=(*v.begin()).first;
	lli y1,y2,flag=1;

	for(auto it=v.begin();it!=v.end();it++){
		if((*it).first != x && (*it).second != x){
			y1=(*it).first;
			y2=(*it).second;
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		cout<<"YES"<<endl;
		rt;
	}
	flag = 1;

	for(auto it = v.begin();it != v.end();it++){
		lli m=(*it).first;
		lli n=(*it).second;
		if(m != x && m != y1 && n != x && n != y1){
			flag =0;
			break;
		}
	}

	if(flag == 1){
		cout<<"YES"<<endl;
		rt;
	}

	if(flag == 0){
		flag=1;
		for(auto it = v.begin();it != v.end();it++){
			lli m=(*it).first;
			lli n=(*it).second;
			if(m != x && m != y2 && n != x && n != y2){
				flag =0;
				break;
			}
		}
	}

	if(flag == 1){
		cout<<"YES"<<endl;
		rt;
	}

	flag=1;
	x=(*v.begin()).second;

	for(auto it=v.begin();it!=v.end();it++){
		if((*it).first != x && (*it).second != x){
			y1=(*it).first;
			y2=(*it).second;
			flag=0;
			break;
		}
	}

	if(flag == 1){
		cout<<"YES"<<endl;
		rt;
	}
	flag = 1;

	for(auto it = v.begin();it != v.end();it++){
		lli m=(*it).first;
		lli n=(*it).second;
		if(m != x && m != y1 && n != x && n != y1){
			flag =0;
			break;
		}
	}

	if(flag == 1){
		cout<<"YES"<<endl;
		rt;
	}

	if(flag == 0){
		flag = 1;
		for(auto it = v.begin();it != v.end();it++){
			lli m=(*it).first;
			lli n=(*it).second;
			if(m != x && m != y2 && n != x && n != y2){
				flag =0;
				break;
			}
		}
	}

	if(flag == 1){
		cout<<"YES"<<endl;
		rt;
	}
	else{
		cout<<"NO"<<endl;
	}
rt;
}