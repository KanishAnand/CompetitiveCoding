#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli input(lli n,vector<lli> &ve);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli q;
	vector<lli> v;
	cin>>q;
	while(q--){
		lli n,x,y,a,b,c,d;
		set<lli> stx1,sty1,stx2,sty2;
		cin>>n;
		fr(i,0,n){
			cin>>x>>y>>a>>b>>c>>d;
			lli s = a+b+c+d,x1=x,x2=x,y1=y,y2=y;
			if(a == 1){
				x1 = -100000;
			}
			if(b == 1){
				y2 = 100000;
			}
			if(c == 1){
				x2 = 100000;
			}
			if(d == 1){
				y1 = -100000;
			}

			stx1.insert(x1);
			sty1.insert(y1);
			stx2.insert(x2);
			sty2.insert(y2);
		}

		auto it = stx1.end();
		auto it2 = sty1.end();
		--it2;
		--it;

		if(*it > *stx2.begin()){
			cout<<"0"<<endl;
		}
		else if(*sty2.begin() < *it2){
			cout<<"0"<<endl;
		}
		else{
			cout<<"1"<<" "<<*it<<" "<<*it2<<endl;
		}
			// if(s == 0){	
			// 	x1 = x;
			// 	y1 = y;
			// 	x2 = x;
			// 	y2 = y;
			// }
			// else if(s == 1){
			// 	if(a == 1){
			// 		x1 = -100000;
			// 		x2 = x;
			// 		y1 = y;
			// 		y2 = y;
			// 	}
			// 	else if(b == 1){
			// 		x1 = x;
			// 		x2 = x;
			// 		y2 = 100000;
			// 		y1 = y;
			// 	}
			// 	else if(c == 1){
			// 		x2 = 100000;
			// 		x1 = x;
			// 		y1 = y;
			// 		y2 = y;
			// 	}
			// 	else{
			// 		x1 = x;
			// 		x2 = x;
			// 		y1 = -100000;
			// 		y2 = y;
			// 	}
			// }
			// else if(s == 2){
			// 	if(a + b == 2){
			// 		x1 = -100000;
			// 		y1 = y;
			// 		x2 = x;
			// 		y2 = 100000;
			// 	}
			// 	else if(a + c == 2){

			// 	}
			// 	else if(a + d == 2){

			// 	}
			// 	else if(b + c == 2){

			// 	}
			// 	else if(b + d == 2){

			// 	}
			// 	else if(c + d == 2){

			// 	}
			// }
			// else if(s == 3){

			// }
			// else{

			// }
		//}
	}	
rt;
}
