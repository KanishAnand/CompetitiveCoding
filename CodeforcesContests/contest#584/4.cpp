#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,t;
	string st;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>st;
		vector<lli> v;
		lli last = -1;
		vector<lli> minn(n+2,10);
		vector<lli> ans(n+2,0);

		fr(i,0,n){
			v.pb(st[i] - '0');
		}

		for(int i=n-1;i>=0;i--){
			if(v[i] < minn[i+1]){
				minn[i] = v[i];
			}
			else{
				minn[i] = minn[i+1];
			}
		}
		// cout<<"K"<<endl;

		fr(i,0,n){
			if(v[i] <= minn[i]){
				// cout<<i<<" "<<v[i]<<" "<<minn[i]<<endl;
				ans[i] = 1;
				last = v[i];
			}
		}
		// cout<<"K"<<endl;
		lli prev = -1,flag=0,first = -1;

		fr(i,0,n){
			if(ans[i] != 1){
				if(first == -1){
					first = v[i];
				}
				if(v[i] < prev){
					flag = 1;
					break;
				}
				prev = v[i];
			}
		}
		// cout<<flag<<endl;
		if(flag == 1){
			cout<<"-"<<endl;
		}
		else{
			if(first == -1){
				for(int i=0;i<n;i++){
					if(ans[i] == 1){
						cout<<"1";
					}
					else{
						cout<<'2';
					}
				}
				cout<<endl;
			}
			else{
				if(first >= last){
					for(int i=0;i<n;i++){
						if(ans[i] == 1){
							cout<<"1";
						}
						else{
							cout<<'2';
						}
					}
					cout<<endl;
				}
				else{
					for(int i=0;i<n;i++){
						if(ans[i] == 1 && v[i] <= first){
							// cout<<'1';
						}
						else{
							ans[i] = 0;
						}
					}
					// cout<<endl;
					lli pre = -1,f=0;
					for(int i=0;i<n;i++){
						if(ans[i] != 1){
							if(v[i] < pre){
								f = 1;
								break;
							}
							pre = v[i];
						}
					}
					if(f == 1){
						cout<<'-'<<endl;
					}
					else{
						for(int i=0;i<n;i++){
							if(ans[i] == 1){
								cout<<"1";
							}
							else{
								cout<<'2';
							}
						}
						cout<<endl;
					}
				}

			}
		}
	}
rt;
}	
	
