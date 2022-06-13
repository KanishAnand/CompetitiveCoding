#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
string st;
lli n,total_no=0,maxx = -1,minn = 1000000000;
lli mod = 1000000007;
vector<lli> dpp;
vector<lli> arr(26,0);

lli dp(lli index,lli no_of_sbstng,lli length,lli val){
	// cout<<index<<" "<<length<<endl;
	if(length > maxx){
		maxx = length;
	}

	if(index == n){
		if(no_of_sbstng < minn){
			minn = no_of_sbstng;
		}
		++total_no;
		total_no %= mod;
		return total_no;
	}

	if(arr[st[index] - 'a'] < val){
		val = arr[st[index]-'a'];
	}

	if(val >= length + 1){
		++length;
		//cout<<index<<" "<<val<<" "<<length<<endl;
		//cout<<length<<" "<<st[index]<<endl;
		//cout<<st[index]<<" "<<length<<endl;
		dp(index+1,no_of_sbstng,length,val);
		//if(index < n-1){
		if(dpp[index] == -1){
			lli a = total_no;
			lli b = dp(index+1,no_of_sbstng+1,1,arr[st[index]-'a']);
			if(b - a < 0 ){
				//cout<<b<<" "<<a<<" "<<index<<endl;
				dpp[index] = b - a + mod;
				//cout<<dpp[index]<<endl;
			}
			else{
				dpp[index] = b-a;
			}
		}
		else{
			total_no += dpp[index];
			total_no %= mod;
			//cout<<total_no<<" "<<dpp[index]<<" "<<index<<endl;
		}
		//}
	}
	else{
		if(dpp[index] == -1){
			lli a = total_no;
			lli b = dp(index+1,no_of_sbstng+1,1,arr[st[index]-'a']);
			if(b - a < 0 ){
				//cout<<b<<" "<<a<<" "<<index<<endl;
				dpp[index] = b - a + mod;
			}
			else{
				dpp[index] = b-a;
			}
		}
		else{
			total_no += dpp[index];
			total_no %= mod;
			//cout<<total_no<<" "<<dpp[index]<<" "<<index<<endl;
		}
	}
return total_no;
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a;
	cin>>n;	
	cin>>st;
	fr(i,0,26){
		cin>>a;
		arr[i] = a;
	}
	dpp.resize(n+2,-1);
	dp(1,1,1,arr[st[0]-'a']);
	cout<<total_no<<"\n";
	cout<<maxx<<"\n";
	cout<<minn<<"\n";
rt;
}

