#include<iostream>
using namespace std;
typedef long long int lli;
int main(void){
	lli n,x,y,a,b;
	lli minx=4000000,miny=4000000,maxx = -4000000,maxy = -4000000;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(x < minx){
			minx = x;
			miny = y;
		}
		else if(x == minx){
			if(y < miny){
				miny = y;
			}
		}
	}
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a > maxx){
			maxx = a;
			maxy = b;
		}
		else if(a == maxx){
			if(b > maxy){
				maxy = b;
			}
		}
	}
	cout<<minx + maxx<<" "<<miny + maxy<<endl;
return 0;
}


