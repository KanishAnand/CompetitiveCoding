#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(val) for(lli i=0;i<val;i++)
#define pb push_back
#define rt return 0
lli input(lli n);
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
	lli n;
	vector<lli> an;
	cin>>n;	
	string st;
	cin>>st;
	lli col=1;
	//red=1,blue=0;
	stack<lli> red,blue;
	fr(st.length()){
		if(st[i] == '('){
			an.pb(col);
			if(col == 1){
				red.push(1);
			}
			else{
				blue.push(0);
			}
			col = 1 - col;
		}
		else{
			if(col == 1){
				if(red.size() != 0){
					an.pb(1);
					red.pop();
				}
				else{
					an.pb(0);
					blue.pop();
				}
			}
			else{
				if(blue.size()!=0){
					an.pb(0);
					blue.pop();
				}
				else{
					an.pb(1);
					red.pop();
				}
			}
		}
	}
	fr(st.length()){
		cout<<an[i];
	}
	cout<<endl;
rt;
}
