#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long int llu;
llu lcm(llu a,llu b);
llu gcd(llu a,llu b);
llu check(llu p);
int main(void){
	int flag = 0;
	llu a,n;
	vector<llu> v;
	cin>>n;
	for(llu i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	llu ans = v[0];

	for(llu i=1;i<n;i++){
		ans = lcm(ans,v[i]);		
	}
	cout<<ans<<endl;
	int c;
	for(int i=0;i<n;i++){
		llu p = ans/v[i];
		c = check(p);
		if(c == 0){
			flag = 0;
			break;
		}
		else{
			flag = 1;
		}
	}
	if(flag == 1){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
return 0;
}

llu check(llu p){
	/*if(p == 1){
		return 1;
	}*/
/*	if(p % 2 == 0){
		return check(p/2);
	}
	else if(p % 3 == 0){
		return check(p/3);
	}*/
	while( p%2 == 0){
		p /= 2;
	}
	while(p%3==0){
		p /= 3;
	}
	if(p == 1){
		return 1;
	}
	else{
		return 0;
	}
}

llu lcm(llu a,llu b){
	return b*(a/gcd(a,b));
}

llu gcd(llu a,llu b){
	if(b == 0){
		return a;	
	}
return gcd(b,a%b);
}

