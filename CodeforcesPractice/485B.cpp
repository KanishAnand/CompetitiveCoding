#include<iostream>

using namespace std;
int main(void){
	int n,x,y,minx=1e9,miny=1e9,maxx=-1e9,maxy=-1e9;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(x < minx){
			minx = x;
		}
		if(x > maxx){
			maxx = x;
		}
		if(y < miny){
			miny = y;
		}
		if(y > maxy){
			maxy = y;
		}
	}
	int a,b;
	a = maxx - minx;
	b = maxy - miny;
	long long int c = a > b ? a : b;
	cout<<c*c<<"\n";
return 0;
}
