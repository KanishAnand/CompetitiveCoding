#include<iostream>
using namespace std;
typedef unsigned long long int llu;
llu lcm(llu a,llu b);
llu gcd(llu a,llu b);
int main(void){
	llu n,a,b,p,q,max,min;
	cin>>n>>a>>b>>p>>q;
	if(q > p){
		max = b;
		min = a;
	}
	else{
		llu t=q;
		q = p;
		p = t;
		max = a;
		min = b;
	}
	llu ans;
	ans = (n/max)*q + (n/min - n/lcm(max,min))*p;
	cout<<ans<<endl;
return 0;
}

llu lcm(llu a,llu b){
	return (a*b)/gcd(a,b);
}

llu gcd(llu a,llu b){
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}
