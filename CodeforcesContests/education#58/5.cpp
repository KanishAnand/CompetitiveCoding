#include<iostream>
using namespace std;
int f=1;
int main(void){
	/*int n,x,y,maxx=0,a=1,mx=0,my=0,maxy=0;
	char c;
	cin>>n;*/
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x,y,maxx=0,a=1,mx=0,my=0,maxy=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>x>>y;
		if(c == '+'){
			if(x > maxx){
				maxx = x;
				my = y;
			}
			else if(x == maxx){
				if(y > my){
					my = y;
				}
			}
			
			if(y > maxy){
				maxy = y;
				mx = x;
			}
			else if(y == maxy){
				if(x > mx){
					mx = x;
				}
			}
		
		}

		else if(c == '?'){
			if(((maxx <= x && my <= y) || (maxx <= y && my <= x))&&((maxy <= y && mx <= x) || (maxy <= x && mx <= y))){
						cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
return 0;
}



