#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<lli> v;
	lli n,b,a,c;
	cin>>n>>b>>a;
	for(int i=0;i<n;i++){
		cin>>c;
		v.push_back(c);
	}	
	int f=0;
	lli cnt=0,oa=a;
	int i;

	for(i=0;i<n;i++){
		//cout<<cnt<<endl;
		if(v[i] == 0){
			if(a > 0){
				--a;
				//++cnt;
			}
			else if(b > 0){
				//++cnt;
				--b;
			}
		}

		else{
			if(a < oa){
				if(b > 0){
					--b;
					++a;
					//++cnt;
				}
				
				else if(a > 0){
					--a;
					//++cnt;
				}
				
			}
			else if (oa == a){
				if(a > 0){
					--a;
				}
				else if(b > 0){
					--b;
				}
				//++cnt;
			}
		}
		if(a == 0 && b == 0){
			f=1;
			break;
		}
		++cnt;
	}
	if(f == 1){
		cout<<i+1<<endl;
	}
	else{
		cout<<n<<endl;
	}
return 0;
}
