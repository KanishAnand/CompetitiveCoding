#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
string st;
lli n;
string calco(lli in){
	string ans;
	lli c=0,a,t=0;
	for(lli i= in - 1;i >= 0; i--){
		lli x = st[i] - '0',y;
		if(n - 1 - t >= in){
			y = st[(n - 1) - t] - '0';
		}
		else{
			y = 0;
		}
		
		//cout<<x<<endl;
	//cout<<x<<" "<<y<<endl;
		a = x + y + c;
		//cout<<a<<endl;
		c = a/10;
		a = a%10;
		
	//	cout<<a<<endl;
		ans.pb(a + '0');
		++t;
	}
	if(c != 0){
		ans.pb(c+'0');
	}
return ans;
}



string calc(lli in){
	string ans;
	lli c=0,a;
	//cout<<in<<endl;
	//cout<<st[0]<<endl;
	for(lli i=n-1;i>=in;i--){
		lli x = st[i] - '0',y;
		if(in - (n - i) >= 0){
			y = st[in - (n - i)] - '0';
		}
		else{
			y = 0;
		}
		
		//cout<<x<<endl;
	//cout<<x<<" "<<y<<endl;
		a = x + y + c;
		//cout<<a<<endl;
		c = a/10;
		a = a%10;
		//cout<<c<<endl;
	//cout<<a<<endl;
		ans.pb(a + '0');
	}
	if(c != 0){
		ans.pb(c+'0');
	}
return ans;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;	
	cin>>st;
	string s,p;
	lli l=0;
	set<pair<lli,string>> v;
	for(lli i=0;i<n;i++){
		if(st[i] == '0'){
			++l;
		}
	}
	if(l == n-1){
		cout<<st<<endl;
		rt;
	}
	if(st[n/2] != '0'){
		if(n % 2 == 0){
			s = calc(n/2);
			reverse(s.begin(),s.end());
			//cout<<s<<endl;
			v.insert(make_pair(s.length(),s));
			
			if(n/2 + 1 < n && st[n/2 + 1] != '0' ){
				s = calco(n/2+1);
				reverse(s.begin(),s.end());
				v.insert(make_pair(s.length(),s));
			}
			if(n/2 - 1 > 0 && st[n/2 - 1] != '0'){
				s = calc(n/2 - 1);
				reverse(s.begin(),s.end());
				v.insert(make_pair(s.length(),s));
			}
			// for(auto it = v.begin();it!=v.end();it++){
			// 	cout<<(*it).second<<endl;
			// }
			cout<<(*v.begin()).second<<endl;
		}
		else{
			s = calc(n/2);
			reverse(s.begin(),s.end());
			v.insert(make_pair(s.length(),s));
			//p = calco(n/2 + 1);
			reverse(s.begin(),s.end());
			//reverse(p.begin(),p.end());
			if(n/2 + 1 < n && st[n/2+1] != '0'){
				s = calco(n/2+1);
				reverse(s.begin(),s.end());
				v.insert(make_pair(s.length(),s));
			}
			if(n/2 - 1 > 0 && st[n/2-1] != '0'){
				s = calc(n/2 - 1);
				reverse(s.begin(),s.end());
				v.insert(make_pair(s.length(),s));
			}
			if(n/2 + 2 < n && st[n/2+2] != '0'){
				s = calco(n/2+2);
				reverse(s.begin(),s.end());
				v.insert(make_pair(s.length(),s));
			}
			if(n/2 - 2 > 0 && st[n/2 - 2] != '0'){
				s = calc(n/2 - 2);
				reverse(s.begin(),s.end());
				v.insert(make_pair(s.length(),s));
			}
			// cout<<s<<endl;
			// cout<<p<<endl;
			cout<<(*v.begin()).second<<endl;
		}
	}

	else{
		lli k = n/2,p=n/2;
		string s,pq;
		while(st[k] == '0'){
			--k;
		}
		while(st[p] == '0'){
			++p;
		}
		if(k != 0){
			s = calc(k);
			reverse(s.begin(),s.end());
			v.insert(make_pair(s.length(),s));
			if(k - 1 > 0 && st[k-1] != '0'){
				s = calc(k - 1);
				reverse(s.begin(),s.end());
				v.insert(make_pair(s.length(),s));
			}
		}
		else{
			s = calco(p);
			reverse(s.begin(),s.end());
			v.insert(make_pair(s.length(),s));
			if(p  + 1 < n && st[p] != '0'){
				s = calco(p+1);
				reverse(s.begin(),s.end());
				v.insert(make_pair(s.length(),s));
			}
		}
		cout<<(*v.begin()).second<<endl;
	}
rt;
}