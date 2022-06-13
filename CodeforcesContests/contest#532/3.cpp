#include<bits/stdc++.h>
double pi = 3.14159265;
using namespace std;
int main(void){
	double n,r;
	cin>>n>>r;
	double ans = sin(pi/n);
	double ansp = ans*r/(1.00-ans);
	cout<<fixed<<setprecision(7)<<ansp<<endl;
return 0;
}

