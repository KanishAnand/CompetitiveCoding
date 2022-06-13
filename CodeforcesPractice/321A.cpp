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
	lli a,b;
	vector<lli> x,y;
	cin>>a>>b;
	string st;
	cin>>st;
	lli pos_x =0, pos_y=0;
	x.pb(pos_x);
	y.pb(pos_y);
	for(lli i=0;i<st.length();i++){
		if(st[i] == 'R'){
			pos_x++;
		}
		else if(st[i] == 'L'){
			--pos_x;
		}
		else if(st[i] == 'D'){
			--pos_y;
		}
		else{
			++pos_y;
		}
		x.pb(pos_x);
		y.pb(pos_y);
	}

	lli val_x = pos_x, val_y = pos_y,flag=0;

	for(lli i=0;i<x.size();i++){
		lli e,f;
		e = a - x[i];
		f = b - y[i];
		//cerr<<e<<" "<<f<<endl;
		//cerr<<val_x<<" "<<val_y<<endl;
		if(val_x != 0 && val_y != 0){
			lli p = abs(e) % abs(val_x);
			lli p1 = abs(e) / abs(val_x);
			lli q = abs(f) % abs(val_y);
			lli q1 = abs(f) / abs(val_y);
			if(p == 0 && q == 0){
				if(p1 == q1 && p1*val_x == e && q1*val_y == f){
					flag = 1;
					//cerr<<"K1"<<i<<endl;
					break;
				}
			}
		}
		else if(val_x == 0 && val_y == 0){
			if(e == 0 && f == 0){
				flag = 1;
				//cerr<<"K2"<<endl;
				break;
			}
		}
		else{
			if(val_x == 0){
				if(e == 0 && abs(f)%abs(val_y) == 0){
					lli w = abs(f)/abs(val_y);
					if(w*val_y == f){
						flag = 1;
						//cerr<<"K3"<<endl;
						break;
					}
				}
			}
			else{
				if(f == 0 && abs(e)%abs(val_x) == 0){
					lli w = abs(e)/abs(val_x);
					if(w*val_x == e){
						flag = 1;
						//cerr<<"K4"<<endl;
						break;
					}
				}
			}
		}
	}

	if(flag == 0){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
	}
rt;
}
