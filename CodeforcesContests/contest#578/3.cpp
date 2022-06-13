#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli gcd(lli a,lli b){
	if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,q,a=1,b=1,x=1,y=1;
	//vector<lli> inners,outers,innere,outere;
	cin>>n>>m>>q;
	lli an = gcd(n,m);
	lli a1 = n/an;
	lli b1 = m/an;
	// while(a <= n || b <= m){
	// 	//cout<<a<<" "<<b<<endl;
	// 	double r = a*360;
	// 	double d = b*360;
	// 	if(r/n == d/m){
	// 		inners.pb(x);
	// 		innere.pb(a);
	// 		outers.pb(y);
	// 		outere.pb(b);
	// 		++a;
	// 		++b;
	// 		x = a;
	// 		y = b;
	// 	}
	// 	else{
	// 		if(a*360*m > b*360*n){
	// 			++b;
	// 		}
	// 		else{
	// 			++a;
	// 		}
	// 	}
	// }	

	// for(lli i=0;i<inners.size();i++){
	// 	cout<<inners[i]<<" "<<innere[i]<<" "<<outers[i]<<" "<<outere[i]<<endl;
	// }
	//cout<<"K"<<endl;
	//cout<<an<<" "<<a1<<" "<<b1<<endl;
	//cout<<"K"<<endl;
	while(q--){
		//cout<<q<<endl;
		//cout<<"K"<<endl;
		lli sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		int flag1 = 1,flag2=1,f=0;
		lli w,o;
		--sy;
		--ey;
		// for(lli i=0;i<inners.size();i++){
		flag1 = 1,flag2 = 1;
		if(sx == 1){
			// if(n/sy){
			w = sy/a1;
			// 	flag1 = 0;
			// }
		}
		else{
			w = sy/b1;
			// if(sy >= outers[i] && sy <= outere[i]){
			// 	flag1 = 0;
			// }	
		}
		if(ex == 1){
			// if(ey >= inners[i] && ey <= innere[i]){
			// 	flag2 = 0;
			// }
			o = ey/a1;
		}
		else{
			// if(ey >= outers[i] && ey <= outere[i]){
			// 	flag2 = 0;
			// }
			o = ey/b1;	
		}
		if(o == w){
			f = 1;
		}
//		cout<<"K"<<endl;
		//}
		if(f == 1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
rt;
}
