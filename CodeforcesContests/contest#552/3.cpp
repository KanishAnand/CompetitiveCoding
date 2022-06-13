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
	lli a,b,c,k,min;
	cin>>a>>b>>c;
	int p = a/3,q=b/2,r=c/2;
	if(p <= q && p <= r){
		min = p;
		k = 3;
	}	
	else if(q <= p && q <= r){
		min = q;
		k = 2;
	}
	else if(r <= p && r <= q){
		min = r;
		k = 2;
	}

	p = a -  min*3;
	q = b -  min*2;
	r = c - min*2;

	lli cp=p,cq=q,cr=r;
	lli ans=0;
	ans += min*7;	
	int mm=0;
	int arr[10];
	arr[0] = 1;
	arr[1]=1;
	arr[2]=2;
	arr[3]=3;
	arr[4]=1;
	arr[5]=3;
	arr[6] = 2;
	//cout<<p<<q<<r<<endl;
	int val=0;
	//cout<<ans<<endl;

	for(int j=0;j<7;j++){
		cp=p;cq=q;cr=r;
		int i=j;

	//cout<<cp<<cq<<cr<<endl;

		int flag = 1;
		val = 0;

		while(flag  == 1){
			if(arr[i] == 1){
				//cout<<"a"<<endl;
				if(cp <= 0){
					flag = 0;
					//break;
				}
				cp -= 1;
			}

			else if(arr[i] == 2){
				//cout<<"b"<<endl;
				if(cq <= 0){
					flag = 0;
					//break;
				}
				cq -= 1;
			}
			else{
				//cout<<"c"<<endl;
				//cout<<cr<<endl;
				if(cr <= 0){
					flag = 0;
					//break;
				}
				cr -= 1;
			}
			if(flag == 1){
				++i;
				i %=7;
				//cout<<i<<endl;
				val += 1;
				//break;
			}
		}
		//cout<<val<<endl;
		if(val > mm){
			 mm = val;
		}
		//cout<<mm<<endl;
	}
	//cout<<ans<<endl<<mm<<endl;
	cout<<ans+mm<<endl;
return 0;
}
