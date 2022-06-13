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
	lli n,a,b,maxx = 0;
	string st;
	vector<lli> v1,v2;
	cin>>n;	
	cin>>st;
	fr(i,0,n){
		cin>>a>>b;
		v1.pb(a);
		v2.pb(b);
	}

	for(int time = 0;time <= 200;time++){
		vector<lli> v(102,0);
		for(int i=0;i<n;i++){
			if(time < v2[i]){
				if(st[i] == '1'){
					v[i] = 1;
				}
				else{
					v[i] = 0;
				}
			}
			else{
				lli p = time - v2[i];
				lli q = p / v1[i];
				// cout<<p<<" "<<q<<endl;
				if(q % 2 == 0){
					if(st[i] == '1'){
						v[i] = 0;
					}
					else{
						v[i] = 1;
					}
				}
				else{
					if(st[i] == '1'){
						v[i] = 1;
					}
					else{
						v[i] = 0;
					}
				}
				// cout<<"K"<<v[i]<<endl;
			}
		}

		lli temp = 0;
		for(int i=0;i<n;i++){
			// cout<<v[i]<<" "<<i<<endl;
			if(v[i] == 1){
				temp++;
			}
			// else{
			// 	if(temp > maxx){
			// 		maxx = temp;
			// 	}
			// 	temp = 0;
			// }
		}
		if(temp > maxx){
			maxx = temp;
		}
	}

	cout<<maxx<<endl;
rt;
}
