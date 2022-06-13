#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,v;
	cin>>n>>v;
	long long int cost=0,p=n-1,i=1;

/*	while(p > 0){
		if(p > v && i == 1){
			cost+= i*v;
			p -= v;
			v == 1;
		}
		else{
			cost += p*i;
			p=0;
			break;
		}
		++i;
	}
*/
	if( p <= v){
		cost += p*1;
	}
	else{
		cost += v*1;
//		cout<<cost<<endl;
		i=2;
		p -= v;
		v=1;
//		cout<<p<<endl;
		while( p > 0){
			cost += i;
//			cout<<cost<<endl;
			++i;
			--p;
//			cout<<p<<endl;
		}
	}

	cout<<cost<<endl;
return 0;
}


