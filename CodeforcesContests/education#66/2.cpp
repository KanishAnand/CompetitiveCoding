#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
llu numb = 4294967295;
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
	llu n,fr=0,ans=0,p=1;
	cin>>n;	
	llu flag=0,var=0;
	stack<llu> sta,sta2;
	fr(i,0,n){
		string st;
		llu no;
		cin>>st;
		if(st == "for"){
			cin>>no;
			if(p*no > numb || var != 0){
				++var;
				//cout<<"FD"<<endl;
			}
			else{
				p *= no;
				sta.push(no);
			}
			++fr;
		}
		if(st == "end"){
			--fr;
			if(var == 0){
				p = p/sta.top();
				sta.pop();
			}
			else{
				--var;
			}
		}
		if(st == "add"){
			if(fr == 0){
				if(1 > numb - ans){
					flag = 1;
					break;
				}
				else{
					++ans;
				}
			}
			else{
				//p=1;
				// while(!sta.empty()){
				// 	if(p*sta.top() > numb){
				// 		flag = 1;
				// 		cout<<"OVERFLOW!!!"<<endl;
				// 		return 0;
				// 	}
				// 	else{
				// 		p *= sta.top();
				// 		sta2.push(sta.top());
				// 		sta.pop();
				// 	}
				// }
				if(var != 0){
					flag = 1;
					break;
				}
				if(p > numb - ans){
					flag = 1;
					break;
				}
				else{
					ans += p;	
				}
				// while(!sta2.empty()){
				// 	sta.push(sta2.top());
				// 	sta2.pop();
				// }
			}
		}
	}

	if(flag == 1){
		cout<<"OVERFLOW!!!"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
rt;
}
	
