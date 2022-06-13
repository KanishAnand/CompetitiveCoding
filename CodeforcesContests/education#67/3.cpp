#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
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
	lli n,m,t,l,r;
	vector<pair<lli,lli>> v1,v0;
	cin>>n>>m;	
	fr(i,0,m){
		cin>>t>>l>>r;
		if(t == 0){
			v0.pb(make_pair(l,r));
		}
		else{
			v1.pb(make_pair(l,r));	
		}
	}

	sort(v0.begin(),v0.end());
	sort(v1.begin(),v1.end());
	lli flag = 0;

	fr(i,0,v0.size()){
		fr(j,0,v1.size()){
			lli a=v0[i].first;
			lli b = v0[i].second;
			lli c = v1[j].first;
			lli d = v1[j].second;
			// if(c >= a && d <= b){
			// 	//cout<<"k";
			// 	flag = 1;
			// 	break;
			// }
			if(a >= c && b <= d){
				//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
				flag = 1;
				break;
			}
			// else if(c < b && d >= b){
			// 	flag = 1;
			// 	break;
			// }
			// else if(a < d && b >= d){
			// 	flag = 1;
			// 	break;
			// }
			// else if(c < a && d > a){
			// 	flag = 1;
			// 	break;
			// }
			// else if(a < c && b > c){
			// 	flag = 1;
			// 	break;
			// }
		}
	}

	vector<lli> ans;
	ans.resize(n+1);
	lli in=10000,g=0,h=0;

	if(flag == 1){
		cout<<"NO"<<endl;
		rt;
	}
	else{
		lli x = 0,y = 0,x2,y2;
		if(v0.size() != 0){
			x = v0[0].first;
			x2 = v0[0].second;
		}
		else{
			x = -1;
		}
		if(v1.size() != 0){
			y = v1[0].first;
			y2 = v1[0].second;
		}
		else{
			y = -1;
		}

		while(x != -1 || y != -1){
			if(x == -1){
				for(lli i=y-1;i<y2;i++){
					ans[i] = in;
				}
				if(h == v1.size() - 1){
						y = -1;
				}
				else{
					++h;
					y = v1[h].first;
					y2 = v1[h].second;
				}
			}
			else if(y == -1){
				for(lli i=x-1;i<x2;i++){
					ans[i] = in;
					--in;
				}
				if(g == v0.size()-1){
						x = -1;
				}
				else{
					++g;
					x = v0[g].first;
					x2 = v0[g].second;
				}
			}
			else{
				if(x < y){
					for(lli i = x-1;i<x2;i++){
						ans[i] = in;
						--in;
					}
					if(g == v0.size()-1){
						x = -1;
					}
					else{
						++g;
						x = v0[g].first;
						x2 = v0[g].second;
					}
				}
				else{
					for(lli i=y-1;i<y2;i++){
						ans[i] = in;
					}
					if(h == v1.size() - 1){
						y = -1;
					}
					else{
						++h;
						y = v1[h].first;
						y2 = v1[h].second;
					}
				}
			}
		}	
	}

	cout<<"YES"<<endl;
	fr(i,0,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
rt;
}
	
